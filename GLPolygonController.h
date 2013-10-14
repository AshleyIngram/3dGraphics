#ifndef _GL_POLYGON_CONTROLLER_H
#define _GL_POLYGON_CONTROLLER_H 1

#include "GLPolygonWindow.h"
#include <qobject.h>
#include <QCoreApplication>
#include <QTimer>
#include "GLPolygon.h"

class GLPolygonController : public QObject
{
    Q_OBJECT
    
    public:
        GLPolygonController(GLPolygonWindow* window, GLPolygon* polygon);
        
    private:
        GLPolygon* polygon;
        GLPolygonWindow* window;
};

#endif
