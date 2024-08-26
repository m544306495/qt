#include "widget.h"
#include "image_procsssor.h"
#include "menubar.h"
#include "opencv_binary.h"
widget::widget(QWidget *parent)
    : QWidget(parent)
{
    // QWidget * centralWidget = new QWidget(this);
    // setCentralWidget(centralWidget);  //??????????

    //垂直布局
    QVBoxLayout  *wholeLayout = new QVBoxLayout(this);

    //创建包含菜单的布局
    QHBoxLayout  *Imglayout = new QHBoxLayout(this);
    //创建菜单
    MenuBar *menubar =  new MenuBar(this);

    //将菜单加入到整体布局中
    Imglayout->addWidget(menubar);

    //创建显示原图和处理图的label
    srcImageLabel = new QLabel(this);
    dstImageLabel = new QLabel(this);

    //加入到图片布局中
    Imglayout->addWidget(srcImageLabel);
    Imglayout->addWidget(dstImageLabel);
    //将菜单的按键进行绑定

    //----------------------这边的路径没有穿进去
    fileName = new QString();
    //这里只能值传递，那怎么把得到的地址传给fileName呢？ 目前采用的方式是将数据存到同一个类的成员变量里面，还有什么解决办法吗
    connect(menubar->openFile, &QAction::triggered, this,[=](){ menubar->onOpenImageChoose(srcImageLabel);});
    qDebug()<<*fileName<<"success";
    //connect(menubar->, &QMenu::aboutToShow, this,[=](){ menubar->onBinaryImageChoose(dstImageLabel);});
    connect(menubar->saveFile, &QAction::triggered, this, [=](){ menubar->onSaveImageChoose(dstImageLabel,this);});
    //connect(menubar->, &QAction::triggered, this, [=](){ menubar->onSaveImageChoose(dstImageLabel,this);});
    connect(menubar->binaryMenu->thresholdInv,&QAction::triggered, this,[=](){menubar->binaryMenu->onBinaryImageWithThresholdInv(srcImageLabel,dstImageLabel);});
    connect(menubar->binaryMenu->thresholdBinary,&QAction::triggered, this,[=](){menubar->binaryMenu->onBinaryImageWiththreshold(srcImageLabel,dstImageLabel);});
    connect(menubar->binaryMenu->thresholdOTSU,&QAction::triggered, this,[=](){menubar->binaryMenu->onBinaryImageWiththresholdOTSU(srcImageLabel,dstImageLabel);});

    //将图片布局加入到整体布局中
    wholeLayout->addLayout(Imglayout);



    setWindowTitle("Image Viewer");

    resize(1000,1000);
    setLayout(wholeLayout);

}

widget::~widget()
{

}

void widget::onChooseImageClicked()
{
    // fileName = QFileDialog::getOpenFileName(this,tr("Open Image"));
    // if(!fileName.isEmpty())
    // {
    //     // QPixmap pixmap(fileName);
    //     QImage image(fileName);
    //     // imageLabel->resize(image.size());
    //     srcImageLabel->setPixmap(QPixmap::fromImage(image));
    //     srcImageLabel->setScaledContents(true);
    //     // dstImageLabel->setPixmap(QPixmap::fromImage(image));
    //     // dstImageLabel->setScaledContents(true);

    // }
}
void widget::onOpencvImageClicked()
{
    // QImage qImage;
    // if (!fileName.isEmpty())
    // {
    //     cv::Mat processedImage = processImage(fileName.toStdString());
    //     QImage::Format format = processedImage.channels() == 1?QImage::Format_Grayscale8:QImage::Format_BGR888;
    //     qImage = QImage(processedImage.data, processedImage.cols, processedImage.rows,
    //                            processedImage.step, format);
    //     dstImageLabel->setPixmap(QPixmap::fromImage(qImage));
    //     dstImageLabel->setScaledContents(true);
    // }else
    // {
    //     qDebug()<<"未选择图片";
    // }

    // Set QImage to QLabel


}







