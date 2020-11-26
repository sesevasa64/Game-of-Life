//---------------------------------------------------------------------------

#ifndef cameraH
#define cameraH
#include"vec.h"

class Camera {
private:
	Camera() : scale(1.0f) {}
    Camera(const Camera&);  
	Camera& operator=(Camera&);
	vec2i bZoom, aZoom;
	vec2f offset;
	vec2i LMP;
	float scale;
public:
	static Camera& getInstance() {
		static Camera camera;
		return camera;
	}
	template<typename T, typename U>
	void toWorld(vec2<T> cam, vec2<U>& world);
	template<typename T, typename U>
	void toCamera(vec2<T> world, vec2<U>& cam);
	void SetMPos(vec2i pos);
	void Zoom(vec2i MPos, int wheeldelta);
	void Move(vec2i pos);
	vec2f& Offset();
};
//---------------------------------------------------------------------------
#endif
