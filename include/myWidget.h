//
// Created by Александр Широков on 05.02.2024.
//

#ifndef MODULE36_HW_MYWIDGET_H
#define MODULE36_HW_MYWIDGET_H

#include <QApplication>
#include <QMainWindow>
#include <QSlider>
#include <QPixmap>
#include <QVBoxLayout>


class MyWidget : public QWidget {
Q_OBJECT

private:
    QSlider *slider ;
    QVBoxLayout *layout;
    //
    QPixmap mCurrentCircle;
    QPixmap mYellowCircle;
    QPixmap mRedCircle;
    QPixmap mGreenCircle;


    bool calcRange(int startPos, int endPos, int curPos);

    bool isShowDefault = true;

public:
    MyWidget() = default;
    explicit MyWidget(QWidget *parrent);
    ~MyWidget();
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

public slots:
    void setRedCircle();
    void setYellowCircle();
    void setGreenCircle();
};



#endif //MODULE36_HW_MYWIDGET_H
