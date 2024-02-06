//
// Created by Александр Широков on 05.02.2024.
//

#include "myWidget.h"
#include <QWidget>
#include <iostream>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>

#include <QPainter>
#include <QPaintEvent>




//constructor
MyWidget::MyWidget(QWidget *parrent) {

    setParent(parrent); //метод используется для установки родительского виджета
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed); //устанавливает политику размера виджета
    //setFixedSize(300,350);
    slider = new QSlider(Qt::Vertical);
    //создаеv объект QPixmap, который является растровым изображением.
    mRedCircle = QPixmap("..//img//redCircle.png");
    mYellowCircle = QPixmap("..//img//yellowCircle.png"); //создаеv объект QPixmap, который является растровым изображением.
    mGreenCircle = QPixmap("..//img//greenCircle.png"); //создаеv объект QPixmap, который является растровым изображением.
    if (isShowDefault) mCurrentCircle = mYellowCircle;
    /*Этот код устанавливает размер и положение виджета. Размер и положение задаются в виде прямоугольника (rect), который представляет собой структуру данных, содержащую координаты верхнего левого и нижнего правого углов. В данном случае размер и положение устанавливаются равными размеру и положению изображения, которое используется для кнопки.*/
    setGeometry(mCurrentCircle.rect());


    layout = new QVBoxLayout();
    slider = new QSlider(Qt::Vertical);
    layout->addWidget(slider);
    setLayout(layout);//устанавливаем этот компоновочный макет как текущий

    QObject::connect(slider, &QSlider::valueChanged, [this](int newValue){
        if (newValue%9==0)std::cout << newValue << std::endl;
        if(calcRange(0,33,newValue)) {
            setYellowCircle();
            std::cout << "showYellowCircle()" << std::endl;
        }
        if(calcRange(34,65,newValue)) {
            setRedCircle();
            std::cout << "showRedCircle()" << std::endl;
        }
        if(calcRange(66,100,newValue)) {
            setGreenCircle();
            std::cout << "showGreenCircle()" << std::endl;
        }
    });
}

//distructor
MyWidget::~MyWidget() {
   std::cerr << "Distruct MyWidget";
}

void MyWidget::paintEvent(QPaintEvent *e)
{/*
    Конструктор QPainter принимает в качестве аргумента объект, на котором нужно рисовать. В данном случае this - это указатель на текущий объект,
    то есть на виджет, в котором вызывается метод paintEvent.*/
    QPainter p(this);
    /*
     В Qt, метод drawPixmap используется для рисования растрового изображения (pixmap). В данном случае он рисует растровое изображение из переменной mCurrentCircle в прямоугольник, заданный параметром e->rect().
      e->rect() возвращает текущий прямоугольник для рисования, который обычно соответствует размерам виджета. Таким образом, это говорит QPainter нарисовать растровое изображение в текущем прямоугольнике виджета.
     */
    p.drawPixmap(e->rect(), mCurrentCircle);
}
//Метод sizeHint используется для указания рекомендуемого размера виджета.
QSize  MyWidget::sizeHint() const
{
    return QSize(100,100);
}
/*
 *Метод minimumSizeHint используется для указания минимального размера виджета. Его можно использовать, например, чтобы гарантировать, что виджет всегда будет занимать определенное количество места на экране.
 */
QSize MyWidget::minimumSizeHint() const
{
    return sizeHint();
}


void MyWidget::setRedCircle()
{
    isShowDefault= false;
    mCurrentCircle=mRedCircle;
    update();
}
void MyWidget::setYellowCircle()
{
    mCurrentCircle=mYellowCircle;
    update();
}
void MyWidget::setGreenCircle()
{
    mCurrentCircle=mGreenCircle;
    update();
}

bool MyWidget::calcRange(int startPos, int endPos, int curPos)
{
    return (curPos>=startPos && curPos<=endPos) ? true : false;
}