#include <QApplication>
#include <QVBoxLayout>
#include "GLPolygonWindow.h"
#include "GLPolygonController.h"
#include "GLCube.h"
#include "GLTetra.h"
#include "GLSphere.h"

int main(int argc, char *argv[]) 
{
    QApplication app(argc, argv);
    GLSphere* polygon = new GLSphere();
    polygon->mode = GL_QUADS;
    polygon->colourMode = 0;
    GLPolygonWindow* window = new GLPolygonWindow(NULL, polygon);
    GLPolygonController* controller = new GLPolygonController(window, polygon);
    
    window->resize(512, 612);
    window->show();
    app.exec();
    
    delete controller;
    delete window;
    
    return 0;
}
