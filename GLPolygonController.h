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
        ~GLPolygonController();
    
    public slots:
        void xChanged(int newValue);
        void yChanged(int newValue);
        void zChanged(int newValue);
        void shapeChange(int shape);
        void modeChange(int mode);
        void colourChange(int mode);
        
    private:
        GLPolygon* polygon;
        GLPolygonWindow* window;
        
        GLenum modeFromInt(int val);
};

#endif
