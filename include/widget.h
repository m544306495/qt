#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QLabel>
#include <QPushButton>
#include<QVBoxLayout>
#include <QMainWindow>
#include <QFileDialog>


namespace Ui {
class widget;
}

class widget : public QWidget
{
    Q_OBJECT

public:
    void setText(QString text);
    explicit widget(QWidget *parent = nullptr);
    ~widget();



private slots:
    void onChooseImageClicked();
    void onOpencvImageClicked();

private:
    QString *fileName;
    QLabel * srcImageLabel;
    QLabel * dstImageLabel;
    QPushButton * chooseButton;
    QPushButton * OpencvButton;
};

// void widget::setText(QString text)
// {

// }
#endif // WIDGET_H
