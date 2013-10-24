#include "GLPolygonWindow.h"
#include <QLabel>
#include <iostream>

GLPolygonWindow::GLPolygonWindow(QWidget* parent, GLPolygon* polygon) 
 : QWidget(parent)
{
    this->polygon = polygon;

    // Window Layout
    windowLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
    
    // Menu Bar setup
    menu = new QMenuBar(this);
    fileMenu = menu->addMenu("&File");
    actionQuit = new QAction("&Quit", this);
    fileMenu->addAction(actionQuit);
    
    // First row is the open gl canvas
    QBoxLayout* rowOneLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    polygonWidget = new GLPolygonWidget(this, polygon);
    rowOneLayout->addWidget(polygonWidget);
    windowLayout->addLayout(rowOneLayout);
    
    // Second row is X Axis
    QBoxLayout* rowTwoLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    xSlider = new QSlider(Qt::Horizontal);
    xSlider->setRange(0, 360);
    xSlider->setValue(0);
    QLabel* xLabel = new QLabel();
    xLabel->setText("Rotate the X axis");
    rowTwoLayout->addWidget(xLabel);
    rowTwoLayout->addWidget(xSlider);
    windowLayout->addLayout(rowTwoLayout); 
    
    // Third row is Y axis
    QBoxLayout* rowThreeLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    ySlider = new QSlider(Qt::Horizontal);
    ySlider->setRange(0, 360);
    ySlider->setValue(0);
    QLabel* yLabel = new QLabel();
    yLabel->setText("Rotate the Y axis");
    rowThreeLayout->addWidget(yLabel);
    rowThreeLayout->addWidget(ySlider);
    windowLayout->addLayout(rowThreeLayout);
    
    // Fourth row is Z axis
    QBoxLayout* rowFourLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    zSlider = new QSlider(Qt::Horizontal);
    zSlider->setRange(0, 360);
    zSlider->setValue(0);
    QLabel* zLabel = new QLabel();
    zLabel->setText("Rotate the Z axis");
    rowFourLayout->addWidget(zLabel);
    rowFourLayout->addWidget(zSlider);
    windowLayout->addLayout(rowFourLayout);

    // Fifth Row is shape choice
    QBoxLayout* rowFiveLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    shapeChoice = new QComboBox();
    shapeChoice->addItem(tr("Sphere"));
    shapeChoice->addItem(tr("Cylinder"));
    shapeChoice->addItem(tr("Torus"));
    rowFiveLayout->addWidget(shapeChoice);
    windowLayout->addLayout(rowFiveLayout);
    
    // Sixth row is mode choice
    QBoxLayout* rowSixLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    modeChoice = new QComboBox();
    modeChoice->addItem(tr("Quads"));
    modeChoice->addItem(tr("Lines"));
    modeChoice->addItem(tr("Points"));
    rowSixLayout->addWidget(modeChoice);
    windowLayout->addLayout(rowSixLayout);
    
    // Seventh row is lighting choice
    QBoxLayout* rowSevenLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    colourChoice = new QComboBox();
    colourChoice->addItem(tr("Alternating"));
    colourChoice->addItem(tr("Flat Lighting"));
    colourChoice->addItem(tr("Smooth Lighting"));
    colourChoice->addItem(tr("Textured"));
    rowSevenLayout->addWidget(colourChoice);
    windowLayout->addLayout(rowSevenLayout);
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

void GLPolygonWindow::changePolygon(GLPolygon* newPolygon)
{
    // Assume calling method is cleaning up
    this->polygon = newPolygon;
    polygonWidget->changePolygon(newPolygon);
}
