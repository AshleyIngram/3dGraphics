#include <QApplication>
#include <QVBoxLayout>
#include "GLPolygonWindow.h"
#include "GLPolygonController.h"
#include "GLCube.h"
#include "GLTetra.h"

int main(int argc, char *argv[]) 
{
    QApplication app(argc, argv);
    GLTetra* polygon = new GLTetra();
    polygon->mode = GL_TRIANGLES;
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
