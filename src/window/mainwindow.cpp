#ifdef USE_QT
#include "mainwindow.h"

#include <QScreen>
#include <QGuiApplication>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    QSurfaceFormat format;
    format.setVersion(4,1);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setDepthBufferSize(24);
    QSurfaceFormat::setDefaultFormat(format);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    openglWidget = new MyOpenglWidget(this);
    openglWidget->resize(height, width);
    openglWidget->setFocus();

    setCentralWidget(openglWidget);
    
}

MainWindow::~MainWindow(){}

void MainWindow::activate(unsigned int numdemo)
{
    openglWidget->activatedemo(numdemo);
}
#endif