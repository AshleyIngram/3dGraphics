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
    
    glEnable(GL_DEPTH_TEST);
    
    // Add polygon to window
    polygonWidget = new GLPolygonWidget(this, polygon);
    windowLayout->addWidget(polygonWidget, 0, 0, 1, 1);
}

GLPolygonWindow::~GLPolygonWindow()
{
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
