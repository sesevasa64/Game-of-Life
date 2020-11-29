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
	vec2f bZoom, aZoom;
	vec2f offset;
	vec2f LMP;
	float scale;
public:
	static Camera& get() {
		static Camera camera;
		return camera;
	}
	template<class T, class U>
	void Camera::toWorld(vec2<T>& cam, vec2<U>& world) {
		world = vec2<U>(cam / scale + offset);
	}
	template<class T, class U>
	void Camera::toCamera(vec2<T>& world, vec2<U>& cam) {
		cam = vec2<U>((world - offset) * scale);
	}
	void SetMPos(const TPoint& pos);
	void Zoom(const TPoint& pos, int wheeldelta);
	void Move(const TPoint& pos);
	void ByKey(WORD &Key);
	void SelectCell(const TPoint& pos);
};
//---------------------------------------------------------------------------
#endif
