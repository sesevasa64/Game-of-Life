//---------------------------------------------------------------------------

#ifndef cameraH
#define cameraH
#include"Unit1.h"
#include"vec.h"

class Camera {
private:
	Camera() : scale(1.0f) {}
    Camera(const Camera&);  
	Camera& operator=(Camera&);
	vec2f beforeZoom, afterZoom;
	vec2f offset;
	vec2f lastMousePosition;
	float scale;
public:
	static Camera& get() {
		static Camera camera;
		return camera;
	}
	template<class T>
	vec2<T> Camera::toWorld(vec2<T>& cam) {
		return cam / scale + offset;
	}
	template<class T>
	vec2<T> Camera::toCamera(vec2<T>& world) {
		return (world - offset) * scale;
	}
	void SetMousePosition(const TPoint& pos);
	void Zoom(const TPoint& pos, int wheeldelta);
	void Move(const TPoint& pos);
	void MoveByKey(WORD &Key);
	float getScale() { return scale; }
};

//---------------------------------------------------------------------------
#endif
