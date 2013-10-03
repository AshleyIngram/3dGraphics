#ifndef _GL_POLYGON_WIDGET_H
#define _GL_POLYGON_WIDGET_H 1

#include <QGLWidget>
#include "GLPolygon.h"

class GLPolygonWidget : public QGLWidget
{
    Q_OBJECT

    public:
        GLPolygonWidget(QWidget* parent, GLPolygon* polygon);
        void render();
        
    protected:
        void initializeGL();
        void resizeGL(int w, int h);
        void paintGL();
        
    private:
        QWidget* parent;
        GLPolygon* polygon;
};
#endif