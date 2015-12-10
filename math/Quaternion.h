#ifndef _gameutil_Quaternion_h
#define _gameutil_Quaternion_h

#include "Float3.h"
#include "Float4x4.h"

namespace gameutil 
{

	// TODO: Add more thorough functionality to this

	class Quaternion {

	public:

		// Not sure if I should represent the Quaternion with one Float3 vector and a float w
		// or with just four float values: x, y, z, w. For now I'm going with the former.
		Float3 v;
		float w;

		void normalize();

		const Quaternion operator + (const Quaternion& q);
		const Quaternion operator + (const float& s);

		const Quaternion operator - (const Quaternion& q);
		const Quaternion operator - (const float& s);

		const Quaternion operator * (const Quaternion& q);
		const Quaternion operator * (const Float3& v);
		const Quaternion operator * (const float& s);
	};

	Quaternion createQuaternion(const Float4x4& m);

	const Float4x4 to4x4Matrix(const Quaternion& q);

} // namespace

#endif