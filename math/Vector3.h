#ifndef _Vector3_h
#define _Vector3_h

#include <math.h>

// This file represents a vector of three elements of type T

namespace gameutil
{

	template <typename T>
	class Vector3
	{
	public:
		T x;
		T y;
		T z;

		void toConsole();

		// Vector addition between both vector + vector and vector + scalar.
		const Vector3<T>  operator +  (const Vector3& v) const;
		const Vector3<T>  operator +  (const T& s) const;
		const Vector3<T>& operator += (const Vector3& v);
		const Vector3<T>& operator += (const T& s);

		// Vector subtraction between both vector + vector and vector + scalar.
		const Vector3<T>  operator -  (const Vector3& v) const;
		const Vector3<T>  operator -  (const T& s) const;
		const Vector3<T>& operator -= (const Vector3& v);
		const Vector3<T>& operator -= (const T& s);

		// Vector multiplication between both vector + vector and vector + scalar.
		const Vector3<T>  operator *  (const Vector3& v) const;
		const Vector3<T>  operator *  (const T& s) const;
		const Vector3<T>& operator *= (const Vector3& v);
		const Vector3<T>& operator *= (const T& s);

		// Vector division between both vector + vector and vector + scalar.
		const Vector3<T>  operator /  (const Vector3& v) const;
		const Vector3<T>  operator /  (const T& s) const;
		const Vector3<T>& operator /= (const Vector3& v);
		const Vector3<T>& operator /= (const T& s);
	};

	template <typename T>
	const T dot(const Vector3<T>& a, const Vector3<T>& b);

	template <typename T>
	const T length(const Vector3<T>& v);

	// Same as length
	template <typename T>
	const T magnitude(const Vector3<T>& v);

	template <typename T>
	const Vector3<T> normalize(const Vector3<T>& v);

	template <typename T>
	const Vector3<T> createVector(const T& x, const T& y, const T& z);

	template <typename T>
	const Vector3<T> createVector(const T& s);

	template <typename T>
	const Vector3<T> cross(const Vector3<T>& a, const Vector3<T>& b);

}

#include "Vector3.inl"

#endif // _Vector3_h