// George Terzakis 2016
//
// University of Portsmouth
//
// Code based on PTAM by Klein and Murray (Copyright 2008 Isis Innovation Limited)


#include <fstream>
#include <stdlib.h>
#include <gptam/Persistence/instances.h>

#include "CameraCalibrator.h"

using namespace std;
using namespace gptam;
using namespace Persistence;

int main(int argc, char** argv)
{
  cout << "  Welcome to CameraCalibrator for Visual Tracking and Mapping" << endl;
  cout << "  ----------------------------------------------------------------- " << endl;

  cout << "  A deep code adaptation of the original 'Parallel tracking and Mapping' by Klein and Murray" << endl;
  cout << "  This code is purely OpenCV based and does not require libCVD, TooN and GVars (although you will need openGL)" << endl;
  cout << " *"<<endl;
  cout << " For interoperability with OpenCV methods and structures,"<<endl;
  cout << " Partial functionality of TooN, libCVD and GVars was retained based "<<endl
    <<"on the latest code by Rosten, Klein and others."<<endl<<endl;
  
  cout << "  	*		George Terzakis 2016 " <<endl;
  cout << " 	*	 University of Portsmouth " <<endl;
  cout << endl;  
  cout << "  Parsing calibrator_settings.cfg ...." << endl;
  
  GUI.LoadFile("calibrator_settings.cfg");

  GUI.StartParserThread();
  atexit(GUI.StopParserThread); // Clean up readline when program quits
  
  
  try {
    
      CameraCalibrator c;
      
      c.Run();
    }
    catch(cv::Exception e)
    {
      cout << endl;
      cout << "!! Failed to run CameraCalibrator; got exception. " << endl;
      cout << "   Exception was: " << endl;
      //cout << e.what << endl;
      cout <<"At line : " << e.line << endl << e.msg << endl;
    }
}