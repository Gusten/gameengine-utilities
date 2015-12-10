
class Float4x4
{
private:
	// Only used as a helpler function, no need so far to expose it
	Float4x4(
			 float, float, float, float,
			 float, float, float, float, 
			 float, float, float, float, 
			 float, float, float, float
			);

	float matrix[4][4];
public:
	const static Float4x4 DEFAULT;

	Float4x4();

	void toConsole();
	void toConsole() const;

	const Float4x4 operator +  (const Float4x4& B) const;
	const Float4x4 operator -  (const Float4x4& B) const;
	const Float4x4 operator *  (const Float4x4& B) const;

	float&  operator() (int row, int col);
	float   operator() (int row, int col) const;

	void transpose();

	static Float4x4 createIdentity();
	static Float4x4 createTransposedFrom(const Float4x4& B);
	static Float4x4 createTranslation(float x, float y, float z);
	static Float4x4 createRotationX(float v);
	static Float4x4 createRotationY(float v);
	static Float4x4 createRotationZ(float v);
	static Float4x4 createPerspective(float fov, float aspect, float near, float far);
};