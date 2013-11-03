#ifndef _GL_POLYGON_WINDOW_H
#define _GL_POLYGON_WINDOW_H 1

#include <QWidget>
#include <QMenuBar>
#include <QSlider>
#include <QDial>
#include <QComboBox>
#include <QBoxLayout>
#include <QEvent>
#include <QCheckBox>
#include "GLPolygonWidget.h"
#include "Scene.h"

class GLPolygonWindow : public QWidget 
{
    Q_OBJECT

    public:
        Scene* scene;
        QMenuBar* menu;
        QMenu* fileMenu;
        QAction* actionQuit;
        QBoxLayout* windowLayout;
        GLPolygonWidget* polygonWidget;
        QCheckBox* isAnimating;
        
        GLPolygonWindow(QWidget* parent, Scene* scene);
        ~GLPolygonWindow();
        
        void resetInterface();
};
#endif
