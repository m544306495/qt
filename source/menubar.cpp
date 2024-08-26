
#include "image_procsssor.h"
#include "menubar.h"
MenuBar::MenuBar(QWidget * parent):QWidget(parent)
{
    menubar = new QMenuBar(this);

    fileMenu = new QMenu("文件",menubar);
    //QMenu  * binaryMenu = static_cast<QMenu * >(new BinaryMenu());
    binaryMenu = new BinaryMenu(menubar);
    morphologyMenu = new QMenu("形态学",menubar);

    helpMenu = new QMenu("帮助",menubar);

    //添加二值化的选项到菜单栏


    menubar->addMenu(binaryMenu);
    menubar->addMenu(fileMenu);
    menubar->addMenu(morphologyMenu);
    menubar->addMenu(helpMenu);


    //文件子菜单
    openFile = new QAction("open",fileMenu);

    saveFile = new QAction("save to",fileMenu);

    //添加文件子菜单项

    fileMenu->addAction(openFile);
    fileMenu->addAction(saveFile);


    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setMenuBar(menubar);
    layout->setSpacing(0); // 设置控件间的间距
    layout->setContentsMargins(0,0,50,0);
    setLayout(layout);

}

void MenuBar::onOpenImageChoose(QLabel * imageLabel)
{
    //-------------------这里指针无法直接接受getOpenFileName的返回结果--------------
    //* filename
    fileName= QFileDialog::getOpenFileName(this,tr("Open Image"));

    if(!fileName.isEmpty())
    {
        if (!imageLabel) {
            qDebug() << "imageLabel is not initialized!";
            return;
        }
        // QPixmap pixmap(fileName);
        QImage image(fileName);
        imageLabel->setPixmap(QPixmap::fromImage(image));
        imageLabel->setScaledContents(true);


    }
}

void MenuBar::onSaveImageChoose(QLabel *label, QWidget * parent)
{
    QString saveFilenName = QFileDialog::getSaveFileName(parent, "保存文件", "","Images(*.png *.xpm *.jpg);; All Files(*)");
    if(!fileName.isEmpty())
    {
        QPixmap pixmap = label->pixmap();
        QImage image = pixmap.toImage();
        if(image.save(saveFilenName))
        {
            qDebug()<< "图片保存成功"<<saveFilenName;
        }else
        {
            qDebug()<<"图片保存失败";
        }
    }
}
MenuBar::~MenuBar()
{

}

