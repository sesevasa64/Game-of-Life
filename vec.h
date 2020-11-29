//---------------------------------------------------------------------------

#ifndef vecH
#define vecH

#include <Classes.hpp>

template<class T>
class vec2 {
public:
	vec2<T>() : x(), y() {}
	vec2<T>(T x, T y) : x(x), y(y) {}
	template<typename U>
	vec2<T>(const vec2<U>& v) : x(v.x), y(v.y) {}
	// Хорошо
	vec2<T> operator+(const vec2<T>& v) {
        return vec2<T>(x + v.x, y + v.y);
	}
	// Хорошо
	vec2<T> operator-(const vec2<T>& v) {
		return vec2<T>(x - v.x, y - v.y);
	}
	// Сойдет
	template<typename U>
	vec2<T>& operator+=(const vec2<U>& v) {
		x += v.x;
		y += v.y;
		return *this;
	}
	// Сойдет
	template<typename U>
	vec2<T>& operator-=(const vec2<U>& v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}
	// Сомнительно
	template<typename U>
	vec2<U> operator*(U scalar) {
		return vec2<U>(x * scalar, y * scalar);
	}
	// Сомнительно
	template<typename U>
	vec2<U> operator/(U scalar) {
		return vec2<U>(x / scalar, y / scalar);
	}
	T x, y;
};

typedef vec2<int> vec2i;
typedef vec2<float> vec2f;
typedef vec2<double> vec2d;

vec2i operator+(vec2i v1, vec2i v2) {
	return vec2i(v1.x + v2.x, v1.y + v2.y);
}

class HashPoint {
public:
	HashPoint() {}
	static const size_t bucket_size = 32; // 10
	static const size_t min_buckets = 8192; // (1 << 10)

	size_t operator()(const vec2i &key);
	bool operator()(const vec2i &p1, const vec2i &p2) const;
};

//---------------------------------------------------------------------------
#endif
