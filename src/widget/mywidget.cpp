#ifdef USE_QT
#include "mywidget.h"

#include <iostream>

#include <QMessageBox>
#include <QApplication>
#include <QDateTime>

#include "../hello_triangles/hellotriangles.h"

MyOpenglWidget::MyOpenglWidget(QWidget *parent) : QOpenGLWidget(parent), _openglObject(nullptr), _lastime(0)
{
    
    _openglconst.push_back( [](int width, int height)->OpenglObject*{
        std::cout << "pushing new basic openglObject constructor" << std::endl;
        return new OpenglObject(width, height);
    });

    _openglconst.push_back(  [](int width, int height) -> OpenglObject*{
        std::cout << "pushing new constructor hello_triangles" << std::endl;
        return new SimpleTriangle(width, height);
    });
}

MyOpenglWidget::~MyOpenglWidget(){}

QSize MyOpenglWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize MyOpenglWidget::sizeHint() const
{
    return QSize(512, 512);
}

void MyOpenglWidget::cleanup()
{
    _openglObject.reset(nullptr);
}

void MyOpenglWidget::initializeGL()
{
    connect(context(), &QOpenGLContext::aboutToBeDestroyed, this, &MyOpenglWidget::cleanup);

    initializeOpenGLFunctions();

    // Initialize OpenGL and all OpenGL dependent stuff below
    _openglObject.reset(_openglconst[0](width(), height()));
}

void MyOpenglWidget::paintGL() 
{
    std::int64_t starttime = QDateTime::currentMSecsSinceEpoch();
    _openglObject->draw();
    glFinish();
    std::int64_t endtime = QDateTime::currentMSecsSinceEpoch();
    _lastime = endtime-starttime;
}

void MyOpenglWidget::resizeGL(int width, int height)
{
    _openglObject->resize(width, height);
}

void MyOpenglWidget::activatedemo(unsigned int numdemo) 
{
    if (numdemo < _openglconst.size()) {
        std::cout << "Activating demo " << numdemo << " : ";
        makeCurrent();
        _openglObject.reset(_openglconst[numdemo](width(), height()));
        std::cout << "trace 2.2" << std::endl;
        doneCurrent();
        std::cout << "trace 2.3" << std::endl;
        update();
    }
    std::cout << "trace 2.4" << std::endl;
}

#endif