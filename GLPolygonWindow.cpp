#include "GLPolygonWindow.h"
#include <iostream>

GLPolygonWindow::GLPolygonWindow(QWidget* parent, GLPolygon* polygon) 
 : QWidget(parent)
{
    // Window Layout
    windowLayout = new QGridLayout(this);
    
    // Menu Bar setup
    menu = new QMenuBar(this);
    fileMenu = menu->addMenu("&File");
    actionQuit = new QAction("&Quit", this);
    fileMenu->addAction(actionQuit);
    
    this->polygon = polygon;
    
    // Add polygon to window
    polygonWidget = new GLPolygonWidget(this, polygon);
    windowLayout->addWidget(polygonWidget, 0, 0, 1, 1);
    
    // Add slider for vertical polygon position
    verticalSlider = new QSlider(Qt::Vertical);
    verticalSlider->setRange(-100, 100);
    verticalSlider->setValue(0);
    windowLayout->addWidget(verticalSlider, 0, 1, 1, 1); 
    
    // Add slider for number of vertices
    verticesSlider = new QSlider(Qt::Horizontal);
    windowLayout->addWidget(verticesSlider, 1, 0, 1, 1);
    
    // Add slider for horizontal polygon position
    horizontalSlider = new QSlider(Qt::Horizontal);
    horizontalSlider->setRange(-100, 100);
    horizontalSlider->setValue(0);
    windowLayout->addWidget(horizontalSlider, 2, 0, 1, 1);
    
    // Add angle dial
    angleDial = new QDial();
    angleDial->setWrapping(true);
    angleDial->setMaximum(630);
    windowLayout->addWidget(angleDial, 1, 1, 1, 1);
}

GLPolygonWindow::~GLPolygonWindow()
{
    delete verticesSlider;
    delete polygonWidget;
    delete windowLayout;
    delete actionQuit;
    delete fileMenu;
    delete menu;
}

void GLPolygonWindow::resetInterface()
{
    verticesSlider->setMinimum(3);
    verticesSlider->setMaximum(30);
    verticesSlider->setValue(polygon->vertices);
    
    polygonWidget->updateGL();
    
    update();
}
