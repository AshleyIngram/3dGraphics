#include <QApplication>
#include <QVBoxLayout>
#include "GLPolygonWindow.h"
#include "GLPolygonController.h"
#include "GL2DPolygon.h"

int main(int argc, char *argv[]) 
{
    QApplication app(argc, argv);
    GL2DPolygon* polygon = new GL2DPolygon();
    GLPolygonWindow* window = new GLPolygonWindow(NULL, polygon);
    GLPolygonController* controller = new GLPolygonController(window, polygon);
    
    window->resize(512, 612);
    window->show();
    app.exec();
    
    delete polygon;
    delete controller;
    delete window;
    
    return 0;
}
