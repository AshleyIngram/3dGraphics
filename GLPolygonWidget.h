#ifndef _GL_POLYGON_WIDGET_H
#define _GL_POLYGON_WIDGET_H 1

#include <QGLWidget>
#include "GL2D.h"

class GLPolygonWidget : public QGLWidget
{
    Q_OBJECT

    public:
        GLPolygonWidget(QWidget* parent, GLPolygon* polygon);
        void render();
        void mousePressEvent(QMouseEvent* event);
        void mouseMoveEvent(QMouseEvent* event);
        
    protected:
        void initializeGL();
        void resizeGL(int w, int h);
        void paintGL();
        void moveWidget(int x, int y);
        void rotateWidget(int amount);
        
    private:
        QWidget* parent;
        GLPolygon* polygon;
        void handleMouseEvent(QMouseEvent* event);
};
#endif
