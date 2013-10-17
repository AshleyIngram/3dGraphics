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
    
    // Add rotation sliders
    zSlider = new QSlider(Qt::Horizontal);
    zSlider->setRange(0, 360);
    zSlider->setValue(0);
    
    ySlider = new QSlider(Qt::Horizontal);
    ySlider->setRange(0, 360);
    ySlider->setValue(0);
    
    xSlider = new QSlider(Qt::Horizontal);
    xSlider->setRange(0, 360);
    xSlider->setValue(0);
    
    // Choose your shape
    shapeChoice = new QComboBox();
    shapeChoice->addItem(tr("Tetrahedron"));
    shapeChoice->addItem(tr("Cube"));
    
    this->polygon = polygon;
    
    // Add polygon to window
    polygonWidget = new GLPolygonWidget(this, polygon);
    windowLayout->addWidget(polygonWidget, 0, 0, 1, 1);
    
    windowLayout->addWidget(zSlider, 1, 0, 1, 1);
    windowLayout->addWidget(ySlider, 2, 0, 1, 1);
    windowLayout->addWidget(xSlider, 3, 0, 1, 1);
    
    windowLayout->addWidget(shapeChoice, 4, 0, 1, 1);
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
    polygonWidget->updateGL();
    
    update();
}
