//---------------------------------------------------------------------------

#ifndef vecH
#define vecH

#include <stddef.h>
#include <memory>
#include <Classes.hpp>

class HashPoint {
public:
	HashPoint() {}
	static const size_t bucket_size = 10;
	static const size_t min_buckets = (1 << 10);

	size_t operator()(const TPoint &key);
	bool operator()(const TPoint &p1, const TPoint &p2) const;
};
TPoint operator+(TPoint p1, TPoint p2) {
	return Point(p1.x + p2.x, p1.y + p2.y);
}

template<class T>
class vec2 {
public:
	vec2<T>() : x(), y() {}
	vec2<T>(T x, T y) : x(x), y(y) {}
	// Хорошо
	vec2<T> operator+(const vec2<T>& v) {
        return vec2<T>(x + v.x, y + v.y);
	}
	// Сойдет
	template<typename U>
	vec2<T>& operator+=(const vec2<U>& v) {
		x += v.x;
		y += v.y;
		return *this;
	}
	// Хорошо
	vec2<T> operator-(const vec2<T>& v) {
		return vec2<T>(x - v.x, y - v.y);
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
	vec2<T> operator*(U scalar) {
    	// vec2<T>
		return vec2<U>(x * scalar, y * scalar);
	}
	// Сомнительно
	template<typename U>
	vec2<T> operator/(U scalar) {
		// vec2<T>
		return vec2<U>(x / scalar, y / scalar);
	}
	// Трэш
	template<typename U>
	operator vec2<U>() const {
		return vec2<U>(x, y);
	}
	T x, y;
};

typedef vec2<int> vec2i;
typedef vec2<float> vec2f;
typedef vec2<double> vec2d;

//---------------------------------------------------------------------------
#endif
