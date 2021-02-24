#pragma once
#include<cstddef>

template<class T>
class vec2 {
public:
	vec2<T>() : x(), y() {}
	vec2<T>(T x, T y) : x(x), y(y) {}
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
    explicit operator vec2<U>() {
        return vec2<U>(x, y);
    }
	T x, y;
};

typedef vec2<int> vec2i;
typedef vec2<float> vec2f;
typedef vec2<double> vec2d;

template<typename T, typename U>
auto operator+(const vec2<T>& lhs, const vec2<U>& rhs) {
    return vec2<decltype(lhs.x + rhs.x)>(lhs.x + rhs.x, lhs.y + rhs.y);
}

template<typename T, typename U>
auto operator-(const vec2<T>& lhs, const vec2<U>& rhs) {
    return vec2<decltype(lhs.x - rhs.x)>(lhs.x - rhs.x, lhs.y - rhs.y);
}

template<typename T, typename U>
auto operator*(const vec2<T>& lhs, U scalar) {
    return vec2<decltype(lhs.x * scalar)>(lhs.x * scalar, lhs.y * scalar);
}

template<typename T, typename U>
auto operator/(const vec2<T>& lhs, U scalar) {
    return vec2<decltype(lhs.x / scalar)>(lhs.x / scalar, lhs.y / scalar);
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
