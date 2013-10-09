#ifndef _GL_POLYGON_WINDOW_H
#define _GL_POLYGON_WINDOW_H 1

#include <QWidget>
#include <QMenuBar>
#include <QSlider>
#include <QDial>
#include <QBoxLayout>
#include "IGLPolygon.h"
#include "GLPolygonWidget.h"

class GLPolygonWindow : public QWidget 
{
    Q_OBJECT

    public:
        IGLPolygon* polygon;
        QMenuBar* menu;
        QMenu* fileMenu;
        QAction* actionQuit;
        QGridLayout* windowLayout;
        GLPolygonWidget* polygonWidget;
        QSlider* verticesSlider;
        QSlider* horizontalSlider;
        QSlider* verticalSlider;
        QDial* angleDial;
        
        GLPolygonWindow(QWidget* parent, IGLPolygon* polygon);
        ~GLPolygonWindow();
        
        void resetInterface();
};
#endif
