#ifndef H_CAMERA
#define H_CAMERA
class Camera
{
	public:
		float getX();
		float getY();
		float getZ();
		void setX(float v);
		void setY(float v);
		void setZ(float v);
		void moveCamera();
		int totalX;
		int totalY;
		int totalZ;

	private:
		float x;
		float y;
		float z;
};
#endif