#include "image_procsssor.h"

void cvThreshold(const cv::Mat & srcMat, cv::Mat &dstMat,int threshold)
{
    if(!srcMat.empty())
    {
        cv::Mat grayImg;
        cv::cvtColor(srcMat, grayImg,cv::COLOR_BGR2GRAY);
        cv::threshold(grayImg,dstMat, threshold, 255, cv::THRESH_BINARY);
    }
}

void cvThresholdWithInv(const cv::Mat & srcMat, cv::Mat &dstMat,int threshold)
{
    if(!srcMat.empty())
    {
        cv::Mat grayImg;
        cv::cvtColor(srcMat, grayImg,cv::COLOR_BGR2GRAY);
        cv::threshold(grayImg,dstMat, threshold, 255, cv::THRESH_BINARY_INV);
    }
}

void cvThresholdWithOTSU(const cv::Mat & srcMat, cv::Mat &dstMat,int threshold)
{
    if(!srcMat.empty())
    {
        cv::Mat grayImg;
        cv::cvtColor(srcMat, grayImg,cv::COLOR_BGR2GRAY);
        cv::threshold(grayImg,dstMat, threshold, 255, cv::THRESH_OTSU);
    }
}
