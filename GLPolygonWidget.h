#ifndef _GL_POLYGON_WIDGET_H
#define _GL_POLYGON_WIDGET_H 1

#include <QGLWidget>
#include "Scene.h"
#include "Camera.h"

class GLPolygonWidget : public QGLWidget
{
    Q_OBJECT

    public:
        GLPolygonWidget(QWidget* parent, Scene* scene);
        void render();
        void mouseClickEvent(QMouseEvent* e);
        void mouseMoveEvent(QMouseEvent* e);

        bool enableShader;
        
    protected:
        void initializeGL();
        void resizeGL(int w, int h);
        void paintGL();
        void loadShader();

    private:
        QWidget* parent;
        Scene* scene;
        Point rotateStartPoint;
        Point rotateBy;
        TexturedSurface* face;
        Camera* camera;
        QGLShaderProgram* shader;
};
#endif
