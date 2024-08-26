#ifndef OPENCV_BINARY_H
#define OPENCV_BINARY_H

#include <opencv.hpp>
#include<QLabel>
#include<QMenu>
#include <QMenuBar>
class BinaryMenu:public QMenu
{
    Q_OBJECT

public:
    explicit BinaryMenu(QWidget *binaryMenu = nullptr);
    ~BinaryMenu();

public:
    QAction * thresholdInv;
    QAction * thresholdBinary;
    QAction * thresholdOTSU;

public slots:
    void onBinaryImageWithThresholdInv(QLabel * srcimageLabel,QLabel *dstImageLabel);
    void onBinaryImageWiththreshold(QLabel * srcimageLabel,QLabel *dstImageLabel);
    void onBinaryImageWiththresholdOTSU(QLabel * srcimageLabel,QLabel *dstImageLabel);
};
// void matBinaryWithOTSU()

#endif // OPENCV_BINARY_H
