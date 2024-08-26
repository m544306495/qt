#include "opencv_binary.h"
#include "image_procsssor.h"
#include <QPixmap>
#include <QImage>
BinaryMenu::BinaryMenu(QWidget *binaryMenu):QMenu("二值化",binaryMenu)
{
    thresholdInv = new QAction("thresholdInv");
    thresholdBinary = new QAction("threshold");
    thresholdOTSU = new QAction("thresholdOTSU");
    this->addAction(thresholdInv);
    this->addAction(thresholdBinary);
    this->addAction(thresholdOTSU);


}

void BinaryMenu::onBinaryImageWithThresholdInv(QLabel * srcImageLabel,QLabel *dstImageLabel)
{

    QPixmap pixmap = srcImageLabel->pixmap();
    QImage image = pixmap.toImage();
    cv::Mat srcImage = cv::Mat(image.height(),image.width(),CV_8UC3,(void *)image.bits(), image.bytesPerLine());
    cv::Mat dstImage;
    cvThresholdWithInv(srcImage,dstImage);
    QImage::Format Format =  QImage::Format_Grayscale8;
    if(dstImage.type() == CV_8UC3)
    {
        Format = QImage::Format_RGB888;
    }else if(dstImage.type() == CV_8UC1)
    {
        Format = QImage::Format_Grayscale8;
    }
    image = QImage(dstImage.data, dstImage.cols, dstImage.rows, static_cast<int>(dstImage.step), Format);
    dstImageLabel->setPixmap(QPixmap::fromImage(image));
    dstImageLabel->setScaledContents(true);
}
void BinaryMenu::onBinaryImageWiththreshold(QLabel * srcImageLabel,QLabel *dstImageLabel)
{
    QPixmap pixmap = srcImageLabel->pixmap();
    QImage image = pixmap.toImage();
    cv::Mat srcImage = cv::Mat(image.height(),image.width(),CV_8UC3,(void *)image.constBits(), image.bytesPerLine());
    cv::Mat dstImage;
    cvThreshold(srcImage,dstImage);
    QImage::Format Format =  QImage::Format_Grayscale8;
    if(dstImage.type() == CV_8UC3)
    {
        Format = QImage::Format_RGB888;
    }else if(dstImage.type() == CV_8UC1)
    {
        Format = QImage::Format_Grayscale8;
    }
    image = QImage(dstImage.data, dstImage.cols, dstImage.rows, static_cast<int>(dstImage.step), Format);
    dstImageLabel->setPixmap(QPixmap::fromImage(image));
    dstImageLabel->setScaledContents(true);
}
void BinaryMenu::onBinaryImageWiththresholdOTSU(QLabel * srcImageLabel,QLabel *dstImageLabel)
{
    QPixmap pixmap = srcImageLabel->pixmap();
    QImage image = pixmap.toImage();
    cv::Mat srcImage = cv::Mat(image.height(),image.width(),CV_8UC3,(void *)image.constBits(), image.bytesPerLine());
    cv::Mat dstImage;
    cvThresholdWithOTSU(srcImage,dstImage);
    QImage::Format Format =  QImage::Format_Grayscale8;
    if(dstImage.type() == CV_8UC3)
    {
        Format = QImage::Format_RGB888;
    }else if(dstImage.type() == CV_8UC1)
    {
        Format = QImage::Format_Grayscale8;
    }
    image = QImage(dstImage.data, dstImage.cols, dstImage.rows, static_cast<int>(dstImage.step), Format);
    dstImageLabel->setPixmap(QPixmap::fromImage(image));
    dstImageLabel->setScaledContents(true);
}
BinaryMenu::~BinaryMenu()
{

}
