#ifndef _TEXTURED_SURFACE_H
#define _TEXTURED_SURFACE_H 1

#include "Point.h"
#include "Surface.h"
#include <string>

class TexturedSurface : public Surface
{
	public:
		TexturedSurface(std::string path);
		virtual void setProperty(Point p, int i);
		GLuint getTexture();

	protected:
		QImage* texture;
		GLuint textureId;
};

#endif