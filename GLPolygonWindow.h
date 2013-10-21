#ifndef _GL_POLYGON_WINDOW_H
#define _GL_POLYGON_WINDOW_H 1

#include <QWidget>
#include <QMenuBar>
#include <QSlider>
#include <QDial>
#include <QComboBox>
#include <QBoxLayout>
#include "GLPolygon.h"
#include "GLPolygonWidget.h"

class GLPolygonWindow : public QWidget 
{
    Q_OBJECT

    public:
        GLPolygon* polygon;
        QMenuBar* menu;
        QMenu* fileMenu;
        QAction* actionQuit;
        QBoxLayout* windowLayout;
        GLPolygonWidget* polygonWidget;
        QSlider* xSlider;
        QSlider* ySlider;
        QSlider* zSlider;
        QDial* angleDial;
        QComboBox* shapeChoice;
        QComboBox* modeChoice;
        QComboBox* colourChoice;
        
        void changePolygon(GLPolygon* polygon);
        
        GLPolygonWindow(QWidget* parent, GLPolygon* polygon);
        ~GLPolygonWindow();
        
        void resetInterface();
};
#endif
