#include <math.h>
#include "GLSphere.h"
#include <iostream>

GLSphere::GLSphere() : surfaceNormal(0, 0, 0)
{
    this->textureImg = NULL;
}

void GLSphere::render()
{
    int lats = 100;
    int longs = 100;
    float r = 0.5;
    // glEnable(GL_NORMALIZE);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    
    light();
    texture();
    
    for(int i = 0; i <= lats; i++) 
    {
        double lat1 = (M_PI * 0.5) + i * (M_PI / lats);
        double sin1 = sin(lat1);
        double cos1 = cos(lat1);

        double lat2 = (double)(M_PI * 0.5) + (i + 1) * (double)(M_PI / lats);
        double sin2 = sin(lat2);
        double cos2 = cos(lat2);

        glBegin(mode);
        for(int j = 0; j <= longs; j++) 
        {
            double lng1 = j * ((double)(2 * M_PI) / (double)longs);
            double lng2 = (j + 1) * ((double)(2 * M_PI) / (double)longs);

            if ((i + j) % 3 == 0)
            {
                glColor3f(1.0, 0.0, 0.0);
            }
            else if ((i + j) % 3 == 1)
            {
                glColor3f(0.0, 1.0, 0.0);
            }
            if ((i + j) % 3 == 2)
            {
                glColor3f(0.0, 0.0, 1.0);
            }
            
            // Generate Points
            Point p1 = Point(r * cos1 * cos(lng1), r * cos1 * sin(lng1), r * sin1);
            Point p2 = Point(r * cos1 * cos(lng2), r * cos1 * sin(lng2), r * sin1);
            Point p3 = Point(r * cos2 * cos(lng2), r * cos2 * sin(lng2), r * sin2);      
            Point p4 = Point(r * cos2 * cos(lng1), r * cos2 * sin(lng1), r * sin2);      
            
            // Store textures
            std::vector<std::vector<float> > textures = std::vector<std::vector<float> >();
            textures.push_back(getTextureCoords(p1));
            textures.push_back(getTextureCoords(p2));
            textures.push_back(getTextureCoords(p3));
            textures.push_back(getTextureCoords(p4));
                        
            // Rotate sphere
            p1 = rotate(p1);
            p2 = rotate(p2);
            p3 = rotate(p3);
            p4 = rotate(p4);
                       
            // Calculate the surface norm (if necessary)
            if (this->colourMode == 1)
            {
                surfaceNormal = calculateSurfaceNormal(p3, p2, p1);
            }
            
            // Render first point
            glTexCoord2fv(&textures[0][0]);
            setNormal(p1);
            glVertex3fv(p1.toArray());
            
            // Second point
            glTexCoord2fv(&textures[1][0]);
            setNormal(p2);
            glVertex3fv(p2.toArray());
            
            // Third point
            glTexCoord2fv(&textures[2][0]);
            setNormal(p3);
            glVertex3fv(p3.toArray());
            
            // Fourth point
            glTexCoord2fv(&textures[3][0]);
            setNormal(p4);
            glVertex3fv(p4.toArray());
       }
       glEnd();
   }
    
   glPopMatrix();   
}

Vector GLSphere::calculateSurfaceNormal(Point p1, Point p2, Point p3)
{
    // Use surface normals
    Vector u = Vector(p1, p2);          
    Vector v = Vector(p2, p3);

    Vector n = u * v;
    return n.normalize();
}

void GLSphere::setNormal(Point p)
{
    if (this->colourMode == 1)
    {
        glNormal3fv(surfaceNormal.toArray());
    }
    else
    {
        Vector v = (Vector)p;
        glNormal3fv(v.normalize().toArray());
    }
}

void GLSphere::light()
{
    // 0 is alternating colour mode
    if (colourMode != 0)
    { 
        glEnable(GL_LIGHTING);
        
        if (colourMode == 1)
        {
            glShadeModel(GL_FLAT);
        }
        else if (colourMode == 2)
        {
            glShadeModel(GL_SMOOTH);
        }
        
        glEnable(GL_LIGHT0);
        
        static const GLfloat black[4] = { 0.0, 0.0, 0.0, 1.0 };
        static const GLfloat white[4] = { 1.0, 1.0, 1.0, 1.0 };
        static const GLfloat grey[4] = { 0.3, 0.3, 0.3, 1.0 };
        static const float lightPosition[] = { -100, 100, 0, 1 };
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
        glLightfv(GL_LIGHT0, GL_AMBIENT, grey);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
        glLightfv(GL_LIGHT0, GL_SPECULAR, black);
    }
    else
    {
        // Disable in case lighting was already enabled
        glDisable(GL_LIGHTING);
    }
}

void GLSphere::texture()
{
    if (colourMode == 3)
    {   
        if (this->textureImg == NULL)
        {
            QImage img = QImage("./earth.jpg");
            QImage glImage = QGLWidget::convertToGLFormat(img);
            this->textureImg = new QImage(glImage);
        }
    
        int height = this->textureImg->height();
        int width = this->textureImg->width();
    
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        GLuint textureId;
        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);
        
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, this->textureImg->bits());
        
        /* Set clamping & interpolation */
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureId);
    }
    else
    {
        // Disable any previous texturing
        glDisable(GL_TEXTURE_2D);
    }
}

std::vector<float> GLSphere::getTextureCoords(Point p)
{
    Vector v = (Vector)p;
    Vector n = v.normalize();

    std::vector<float> rp = std::vector<float>();
    float t = atan2(n.x, n.z) / (2.0 * M_PI) + 0.5;
    float u = asin(n.y) / M_PI + 0.5;
    rp.push_back(t);
    rp.push_back(u);
    
    return rp; 
}

GLSphere::~GLSphere()
{
    delete this->textureImg;
}
