// -*- c++ -*-
// Copyright 2008 Isis Innovation Limited
//
// System.h
//
// Defines the System class
//
// This stores the main functional classes of the system, like the
// mapmaker, map, tracker etc, and spawns the working threads.
//
#ifndef __SYSTEM_H
#define __SYSTEM_H

#include <stdlib.h>

#include <gptam/VideoSource.h>
#include <gptam/GLWindow2.h>
#include <gptam/OpenCV.h>
#include <gptam/OpenGL.h>
#include <gptam/Persistence/instances.h>
#include <gptam/ATANCamera.h>
#include <gptam/MapMaker.h>
#include <gptam/Tracker.h>
#include <gptam/ARDriver.h>
#include <gptam/MapViewer.h>

namespace gptam {


class System
{
public:
  System();
  void Run();
  
private:
  VideoSource mVideoSource;
  GLWindow2 mGLWindow;
  cv::Mat mimFrameRGB;
  cv::Mat_<uchar> mimFrameBW;
  
  Map *mpMap; 
  MapMaker *mpMapMaker; 
  Tracker *mpTracker; 
  ATANCamera *mpCamera;
  ARDriver *mpARDriver;
  MapViewer *mpMapViewer;
  
  bool mbDone;

  static void GUICommandCallBack(void* ptr, std::string sCommand, std::string sParams);
};

} // namespace gptam

#endif
