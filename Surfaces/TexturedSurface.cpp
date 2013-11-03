#include "TexturedSurface.h"
#include "Vector.h"
#include <math.h>
#include <iostream>

using namespace std;

TexturedSurface::TexturedSurface(string path)
{
	QImage img = QImage(path.c_str());
	QImage glImage = QGLWidget::convertToGLFormat(img);
	texture = new QImage(glImage);

    int height = texture->height();
    int width = texture->width();

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture->bits());

    /* Set clamping & interpolation */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        
}

GLuint TexturedSurface::getTexture()
{
	return textureId;
}

void TexturedSurface::setProperty(Point p, int i)
{
	Vector v = (Vector)p;
    Vector n = v.normalize();

    // HACK: only works for sphere
    float t = atan2(n.x, n.z) / (2.0 * M_PI) + 0.5;
    float u = asin(n.y) / M_PI + 0.5;
    glTexCoord2f(t, u);
}