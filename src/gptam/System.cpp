// ************ George Terzakis 2016 **************
//
//          University of Portsmouth
//
//
// Based on the original PTAM code by Klein and Murrary (Copyright 2008 Isis Innovation Limited)
//
//

#include "gptam/System.h"
#include "gptam/OpenGL.h"

#include "gptam/Persistence/instances.h"

#include <stdlib.h>
#include "gptam/ATANCamera.h"
#include "gptam/MapMaker.h"
#include "gptam/Tracker.h"
#include "gptam/ARDriver.h"
#include "gptam/MapViewer.h"


using namespace std;

namespace gptam {

using namespace Persistence;


System::System() : mGLWindow(mVideoSource.getSize(), "PTAM")
{
  GUI.RegisterCommand("exit", GUICommandCallBack, this);
  GUI.RegisterCommand("quit", GUICommandCallBack, this);
  
  // First, check if the camera is calibrated.
  // If not, we need to run the calibration widget.
  cv::Vec<float, NUMTRACKERCAMPARAMETERS> vTest = PV3::get<cv::Vec<float, NUMTRACKERCAMPARAMETERS> >("Camera.Parameters", ATANCamera::mvDefaultParams, HIDDEN);
  mpCamera = new ATANCamera("Camera");
  cv::Vec2f v2(0 , 0);
  if(v2==v2) ;
  if(vTest == ATANCamera::mvDefaultParams) {
      cout << endl;
      cout << "! Camera.Parameters is not set, need to run the CameraCalibrator tool" << endl;
      cout << "  and/or put the Camera.Parameters= line into the appropriate .cfg file." << endl;
      exit(1);
    }
 
  cout << "Got passed the preliminary camera test... Now need to create: "<<endl;
  cout << "a. The Map!" <<endl;
  mpMap = new Map;
  cout <<"DONE"<<endl;
  cout << "b. The Mapmaker Threadf!" <<endl;
  mpMapMaker = new MapMaker(*mpMap, *mpCamera);
  cout <<"DONE"<<endl;
  cout << "c. The Tracker!" <<endl;
  mpTracker = new Tracker(mVideoSource.getSize(), *mpCamera, *mpMap, *mpMapMaker);
  cout <<"DONE"<<endl;
  cout << "d. The The AR Driver!" <<endl;
  mpARDriver = new ARDriver(*mpCamera,  mGLWindow);
  cout <<"DONE"<<endl;
  cout << "e. The Map Viewer!" <<endl;
  mpMapViewer = new MapViewer(*mpMap, mGLWindow);
  cout <<"DONE"<<endl;
  
  
  GUI.ParseLine("GLWindow.AddMenu Menu Menu");
  GUI.ParseLine("Menu.ShowMenu Root");
  GUI.ParseLine("Menu.AddMenuButton Root Reset Reset Root");
  GUI.ParseLine("Menu.AddMenuButton Root Spacebar PokeTracker Root");
  GUI.ParseLine("DrawAR=0");
  GUI.ParseLine("DrawMap=0");
  GUI.ParseLine("Menu.AddMenuToggle Root \"View Map\" DrawMap Root");
  GUI.ParseLine("Menu.AddMenuToggle Root \"Draw AR\" DrawAR Root");
  
  mbDone = false;
};

void System::Run()
{
  while(!mbDone) {
      
      // We use two versions of each video frame:
      // One black and white (for processing by the tracker etc)
      // and one RGB, for drawing.

      // Get a new frame
      mVideoSource.GetAndFillFrameBWandRGB(mimFrameBW, mimFrameRGB);  
      static bool bFirstFrame = true;
      // its the first frame, initialize the AR driver 
      if(bFirstFrame) {
	  mpARDriver->Init();
	  bFirstFrame = false;
      }
      
      // configure the OpenGL display stuff...
      mGLWindow.SetupViewport();
      mGLWindow.SetupVideoOrtho();
      mGLWindow.SetupVideoRasterPosAndZoom();
      
      // if Map is BAD (more comments to follow), then reset the AR driver
      if(!mpMap->IsGood()) mpARDriver->Reset();
      
      // Drawing flags (GUI has buttons)
      static pvar3<int> pvnDrawMap("DrawMap", 0, HIDDEN|SILENT);
      static pvar3<int> pvnDrawAR("DrawAR", 0, HIDDEN|SILENT);
      
      bool bDrawMap = mpMap->IsGood() && *pvnDrawMap;
      bool bDrawAR = mpMap->IsGood() && *pvnDrawAR;
      
      // The actual SLAM module is the Tracker...
      mpTracker->TrackFrame(mimFrameBW, !bDrawAR && !bDrawMap, mimFrameRGB);
      
      if(bDrawMap) 
	mpMapViewer->DrawMap(mpTracker->GetCurrentPose());
      else if(bDrawAR)
	mpARDriver->Render(mimFrameRGB, mpTracker->GetCurrentPose());

      // mGLWindow.GetMousePoseUpdate();
      string sCaption;
      if(bDrawMap)
	sCaption = mpMapViewer->GetMessageForUser();
      else
	sCaption = mpTracker->GetMessageForUser();
      mGLWindow.DrawCaption(sCaption);
      mGLWindow.DrawMenus();
      mGLWindow.swap_buffers();
      mGLWindow.HandlePendingEvents();
    }
}

void System::GUICommandCallBack(void *ptr, string sCommand, string sParams)
{
  if(sCommand=="quit" || sCommand == "exit") static_cast<System*>(ptr)->mbDone = true;
}



} // namespace gptam 




