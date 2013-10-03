#ifndef _GL_POLYGON_CONTROLLER_H
#define _GL_POLYGON_CONTROLLER_H 1

#include "GLPolygon.h"
#include "GLPolygonWindow.h"
#include <qobject.h>
#include <QCoreApplication>
#include <QTimer>

class GLPolygonController : public QObject
{
    Q_OBJECT
    
    public:
        GLPolygonController(GLPolygonWindow* window, GLPolygon* polygon);
        
    public slots:
        void verticesChanged(int value);
        void horizontalChanged(int x);
        void verticalChanged(int y);
        void angleChanged(int angle);
        void nextFrame();
        
    private:
        GLPolygon* polygon;
        GLPolygonWindow* window;
        QTimer* timer;
};

#endif
