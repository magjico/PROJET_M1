#ifdef USE_QT
#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <memory>

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include "../openglObject/openglObject.h"

class MyOpenglWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    public:
        explicit MyOpenglWidget(QWidget *parent = 0);
        ~MyOpenglWidget();

        QSize minimumSizeHint() const override;
        QSize sizeHint() const override;

        void activatedemo(unsigned int numdemo);

    public slots:
        void cleanup();

    protected:
        void initializeGL() override;
        void resizeGL(int width, int height) override;
        void paintGL() override;

    private:
        std::unique_ptr<OpenglObject> _openglObject;
        using openglConst = std::function<OpenglObject*(int, int)>;
        std::vector<openglConst> _openglconst;

        std::int64_t _lastime;
};

#endif
#endif