#ifdef USE_QT
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QOpenGLWidget>
#include "../widget/mywidget.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

    public :
        explicit MainWindow(QWidget *parent = 0);
        MainWindow(const MainWindow&) = delete;
        MainWindow &operator=(const MainWindow&) = delete;
        ~MainWindow();

        void activate(unsigned int numdemo);

    private :
        Ui::MainWindow  *ui;
        MyOpenglWidget  *openglWidget;
        
};

#endif
#endif