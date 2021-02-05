#pragma once
#include<cstddef>

template<class T>
class vec2 {
public:
	vec2<T>() : x(), y() {}
	vec2<T>(T x, T y) : x(x), y(y) {}
	template<typename U>
	vec2<T>(const vec2<U>& v) : x(v.x), y(v.y) {}
	vec2<T> operator-(const vec2<T>& v) {
		return vec2<T>(x - v.x, y - v.y);
	}
	template<typename U>
	vec2<T>& operator+=(const vec2<U>& v) {
		x += v.x;
		y += v.y;
		return *this;
	}
	template<typename U>
	vec2<T>& operator-=(const vec2<U>& v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}
	template<typename U>
	vec2<U> operator*(U scalar) {
		return vec2<U>(x * scalar, y * scalar);
	}
	template<typename U>
	vec2<U> operator/(U scalar) {
		return vec2<U>(x / scalar, y / scalar);
	}
	T x, y;
};

typedef vec2<int> vec2i;
typedef vec2<float> vec2f;
typedef vec2<double> vec2d;

template<typename T>
vec2<T> operator+(const vec2<T>&& lhs, const vec2<T>&& rhs) {
	return vec2<T>(lhs.x + rhs.x, lhs.y + rhs.y);
}
template<typename T>
vec2<T> operator+(vec2<T> lhs, vec2<T>& rhs) {
	return vec2<T>(lhs.x + rhs.x, lhs.y + rhs.y);
}

class HashPoint {
public:
	HashPoint() {}
	size_t operator()(const vec2i& key) const;
};

class ComparePoint {
public:
	ComparePoint() {}
	bool operator()(const vec2i& p1, const vec2i& p2) const;
};
