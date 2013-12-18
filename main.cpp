#include <QApplication>
#include <QVBoxLayout>
#include "GLPolygonWindow.h"
#include "ApplicationController.h"
#include "Scene.h"
#include "Camera.h"

int main(int argc, char *argv[]) 
{
    QApplication app(argc, argv);

    Scene* scene = new Scene(new Camera());

    GLPolygonWindow* window = new GLPolygonWindow(NULL, scene);
    ApplicationController* controller = new ApplicationController(window, scene);
    
    window->resize(512, 612);
    window->show();
    app.exec();
    
    delete controller;
    delete window;
    
    return 0;
}