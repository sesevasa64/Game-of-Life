//---------------------------------------------------------------------------

#ifndef cameraH
#define cameraH
#include"vec.h"

class Camera {
private:
	Camera() : scale(1.0f) {}
    Camera(const Camera&);  
	Camera& operator=(Camera&);
	vec2f bZoom, aZoom;
	vec2f offset;
	vec2f LMP;
	float scale;
public:
	static Camera& get() {
		static Camera camera;
		return camera;
	}
	void toWorld(vec2f cam, vec2f& world);
	void toCamera(vec2f world, vec2f& cam);
	void SetMPos(int x, int y);
	void Zoom(int x, int y, int wheeldelta);
	void Move(int x, int y);
	void ByKey(WORD &Key);
};
//---------------------------------------------------------------------------
#endif
