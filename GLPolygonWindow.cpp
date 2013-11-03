#include "GLPolygonWindow.h"
#include <QLabel>
#include <iostream>

GLPolygonWindow::GLPolygonWindow(QWidget* parent, Scene* scene) 
 : QWidget(parent)
{
    this->scene = scene;

    // Window Layout
    windowLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
    
    // Menu Bar setup
    menu = new QMenuBar(this);
    fileMenu = menu->addMenu("&File");
    actionQuit = new QAction("&Quit", this);
    fileMenu->addAction(actionQuit);
    
    // First row is the open gl canvas
    QBoxLayout* rowOneLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    polygonWidget = new GLPolygonWidget(this, scene);
    rowOneLayout->addWidget(polygonWidget);
    windowLayout->addLayout(rowOneLayout);

    // Second row for animation
    QBoxLayout* rowTwoLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    isAnimating = new QCheckBox(tr("Animate"));
    isAnimating->setCheckState(Qt::Checked);
    rowTwoLayout->addWidget(isAnimating);
    windowLayout->addLayout(rowTwoLayout);
}

GLPolygonWindow::~GLPolygonWindow()
{
    delete polygonWidget;
    delete isAnimating;
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