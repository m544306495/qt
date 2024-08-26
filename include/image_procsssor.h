#ifndef IMAGE_PROCSSSOR_H
#define IMAGE_PROCSSSOR_H

#endif // IMAGE_PROCSSSOR_H
#ifndef IMAGE_PROCESSOR_H
#define IMAGE_PROCESSOR_H

#include <opencv.hpp>
void cvThreshold(const cv::Mat & srcMat, cv::Mat &dstMat,int threshold = 50);
void cvThresholdWithInv(const cv::Mat & srcMat, cv::Mat &dstMat,int threshold = 50);
void cvThresholdWithOTSU(const cv::Mat & srcMat, cv::Mat &dstMat,int threshold = 50);



#endif// IMAGE_PROCESSOR_H
