#ifndef MENUBAR_H
#define MENUBAR_H
#include <QMenuBar>
#include <QMenu>
#include<QVBoxLayout>
#include<QFileDialog>
#include<QLabel>
#include <opencv.hpp>
#include "opencv_binary.h"

class MenuBar: public QWidget
{
    Q_OBJECT

public:
    // MenuBar(QWidget *parent = nullptr);
    explicit MenuBar(QWidget *parent=nullptr);

    ~MenuBar();
    // fileMenu->addAction(openFile);
    // fileMenu->addAction(saveFile);




public:
    QMenuBar *menubar;
    QMenu *fileMenu;
    BinaryMenu *binaryMenu;
    QMenu *morphologyMenu;
    QMenu *helpMenu;
    QAction *openFile;
    QAction *saveFile;
    QString fileName;

public slots:
    void onOpenImageChoose(QLabel * imageLabel);


    //void onBinaryImageChoose(QLabel * imageLabel);
    void onSaveImageChoose(QLabel *label, QWidget *parent = nullptr);

};

#endif // MENUBAR_H
