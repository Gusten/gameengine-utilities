#include "Float4x4.h"

namespace gameutil
{

template <typename float>
const Float4x4 make_identity<Float4x4>()
{
	Float4x4 matrix;
	matrix.elements[0] = 1.0f;
	matrix.elements[5] = 1.0f;
	matrix.elements[10] = 1.0f;
	matrix.elements[15] = 1.0f;
	return matrix;
}

const Float4x4 Float4x4::operator*(const Float4x4 & m) const
{
	return Float4x4();
};

} // namespace