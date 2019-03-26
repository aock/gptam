// -*- c++ -*-
// Copyright 2008 Isis Innovation Limited

#ifndef __CAMERACALIBRATOR_H
#define __CAMERACALIBRATOR_H

#include <fstream>
#include <stdlib.h>
#include <vector>

#include <gptam/OpenCV.h>
#include <gptam/OpenGL.h>
#include <gptam/Persistence/instances.h>
#include <gptam/ATANCamera.h>
#include <gptam/GCVD/GLHelpers.h>
#include <gptam/CalibImage.h>
#include <gptam/VideoSource.h>
#include <gptam/GLWindow2.h>

namespace gptam {

class CameraCalibrator
{
public:
  
  CameraCalibrator();
  void Run();
  
protected:
  
  void Reset();
 
  
  
  void HandleFrame(cv::Mat_<uchar> imFrame);
  static void MainLoopCallback(void* pvUserData);
  void MainLoopStep();
  VideoSource mVideoSource;
  
  GLWindow2 mGLWindow;
  ATANCamera mCamera;
  bool mbDone;

  std::vector<CalibImage> mvCalibImgs;
  void OptimizeOneStep();
  
  bool mbGrabNextFrame;
  Persistence::pvar3<int> mpvnOptimizing;
  Persistence::pvar3<int> mpvnShowImage;
  Persistence::pvar3<int> mpvnDisableDistortion;
  double mdMeanPixelError;

  void GUICommandHandler(std::string sCommand, std::string sParams);
  
  static void GUICommandCallBack(void* ptr, std::string sCommand, std::string sParams);
  
};

} // namespace gptam

#endif
