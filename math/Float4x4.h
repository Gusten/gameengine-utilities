#ifndef _gameutil_Float4x4_h
#define _gameutil_Float4x4_h

#include <array>

namespace gameutil 
{

template <typename float>
class Float4x4
{
public:
	std::array<float, 16> elements;

	const Float4x4 operator * (const Float4x4& m) const;
};

template <typename float>
const Float4x4 make_identity<Float4x4>();



} // namespace

#endif // _gameutil_Float4x4_h