#ifndef _Vector3_inl
#define _Vector3_inl

#include "Vector3.h"

namespace gameutil
{
// Vector addition between both vector + vector and vector + scalar.
template <typename T>
inline const Vector3<T> Vector3<T>::operator + (const Vector3<T>& v) const 
{
	return make_vector<T>(x + v.x, y + v.y, z + v.z);
}
template <typename T>
inline const Vector3<T> Vector3<T>::operator +  (const T& s) const {
	return make_vector<T>(x + s, y + s, z + s);
}
template <typename T>
inline const Vector3<T>& Vector3<T>::operator += (const Vector3<T>& v) {
	x += v.x; 
	y += v.y;
	z += v.z;
	return *this;
}
template <typename T>
inline const Vector3<T>& Vector3<T>::operator += (const T& s) {
	x += s;
	y += s;
	z += s;
	return *this;
}


// Vector subtraction between both vector + vector and vector + scalar.
template <typename T>
inline const Vector3<T> Vector3<T>::operator -  (const Vector3<T>& v) const {
	return make_vector<T>(x - v.x, y - v.y, z - v.z);
}
template <typename T>
inline const Vector3<T> Vector3<T>::operator -  (const T& s) const {
	return make_vector<T>(x - s, y - s, z - s);
}
template <typename T>
inline const Vector3<T>& Vector3<T>::operator -= (const Vector3<T>& v) {
	x -= v.x; 
	y -= v.y;
	z -= v.z;
	return *this;
}
template <typename T>
inline const Vector3<T>& Vector3<T>::operator -= (const T& s) {
	x -= s;
	y -= s;
	z -= s;
	return *this;
}


// Vector multiplication between both vector + vector and vector + scalar.
template <typename T>
inline const Vector3<T> Vector3<T>::operator *  (const Vector3<T>& v) const {
	return make_vector<T>(x * v.x, y * v.y, z * v.z);
}
template <typename T>
inline const Vector3<T> Vector3<T>::operator *  (const T& s) const {
	return make_vector<T>(x * s, y * s, z * s);
}
template <typename T>
inline const Vector3<T>& Vector3<T>::operator *= (const Vector3<T>& v) {
	x *= v.x; 
	y *= v.y;
	z *= v.z;
	return *this;
}
template <typename T>
inline const Vector3<T>& Vector3<T>::operator *= (const T& s) {
	x *= s;
	y *= s;
	z *= s;
	return *this;
}


// Vector division between both vector + vector and vector + scalar.
template <typename T>
inline const Vector3<T> Vector3<T>::operator /  (const Vector3<T>& v) const {
	return make_vector<T>(x / v.x, y / v.y, z / v.z);
}
template <typename T>
inline const Vector3<T> Vector3<T>::operator /  (const T& s) const {
	return make_vector<T>(x / s, y / s, z / s);
}
template <typename T>
inline const Vector3<T>& Vector3<T>::operator /= (const Vector3<T>& v) {
	x /= v.x; 
	y /= v.y;
	z /= v.z;
	return *this;
}
template <typename T>
inline const Vector3<T>& Vector3<T>::operator /= (const T& s) {
	x /= s;
	y /= s;
	z /= s;
	return *this;
}


// Get the dot product from the sum of component-wise multiplication
template <typename T>
inline const T dot(const Vector3<T>& a, const Vector3<T>& b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

// Calculate length of vector using pythagorean theorem
template <typename T>
inline const T length(const Vector3<T>& v) {
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

// Magnitude of a vector is its length
template <typename T>
inline const T magnitude(const Vector3<T>& v) {
	return length(v);
}

// Normalize vector by dividing each component by the length of the vector
// This will make the total length of the normalized vector 1.
template <typename T>
inline const T normalize(const Vector3<T>& v) {
	return v / length(v);
}

// Create a new vector 
template <typename T>
inline const Vector3<T> make_vector(const T& x, const T& y, const T& z) {
	Vector3<T> a;
	a.x = x;
	a.y = y;
	a.z = z;
	return a;
}

// Create a new uniform vector from one given value
template <typename T>
inline const Vector3<T> make_vector(const T& s) {
	Vector3<T> a;
	a.x = s;
	a.y = s;
	a.z = s;
	return a;
}

// Get the cross product vector from the two given vectors.
template <typename T>
inline const Vector3<T> cross(const Vector3<T>& a, const Vector3<T>& b) {
	return make_vector(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

} //Namespace ending

#endif
