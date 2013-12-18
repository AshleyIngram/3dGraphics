#ifndef _GL_POLYGON_CONTROLLER_H
#define _GL_POLYGON_CONTROLLER_H 1

#include "GLPolygonWindow.h"
#include <qobject.h>
#include <QCoreApplication>
#include <QTimer>
#include "Scene.h"

class ApplicationController : public QObject
{
    Q_OBJECT
    
    public:
        ApplicationController(GLPolygonWindow* window, Scene* polygon);
        ~ApplicationController();

    public slots:
    	void nextFrame();
    	void setAnimation(bool animate);
        void setShaderState(bool state);
        
    private:
        Scene* scene;
        GLPolygonWindow* window;
        QTimer* timer;
        bool isAnimating;
};

#endif
