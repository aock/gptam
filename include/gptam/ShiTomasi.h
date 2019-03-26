// Copyright 2008 Isis Innovation Limited
#ifndef __SHI_TOMASI__H
#define __SHI_TOMASI__H

#include "OpenCV.h"

namespace gptam {

double FindShiTomasiScoreAtPoint(cv::Mat_<uchar> &image,
				 int nHalfBoxSize,
				 cv::Point2i irCenter);

} // namespace gptam

#endif
