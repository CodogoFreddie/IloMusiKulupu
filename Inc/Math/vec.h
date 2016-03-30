#ifndef VEC_H
#define VEC_H

#include <Render/renderIncludes.h>

#include <iostream>

class PosVec{
public:
	GLfloat x, y, z;
	PosVec(): x(0), y(0), z(0){}
	PosVec(GLfloat x_, GLfloat y_, GLfloat z_):
			x(x_), y(y_), z(z_){}
};
std::ostream& operator <<(std::ostream& osObject, const PosVec& v);
bool operator == (const PosVec& v1, const PosVec& v2);

class PosNorVec{
public:
	GLfloat x, y, z, xN, yN, zN;
	PosNorVec(): x(0), y(0), z(0), xN(0), yN(0), zN(0){}
	PosNorVec(GLfloat x_, GLfloat y_, GLfloat z_,
			GLfloat xN_, GLfloat yN_, GLfloat zN_):
			x(x_), y(y_), z(z_), xN(xN_), yN(yN_), zN(zN_){}
	PosNorVec(const PosVec& v):
			x(v.x), y(v.y), z(v.z), xN(0), yN(0), zN(0){}
};

class ColVec{
public:
	GLfloat r, g, b;
	ColVec(): r(0), g(0), b(0){}
	ColVec(GLfloat r_, GLfloat g_, GLfloat b_):
			r(r_), g(g_), b(b_){}
};

#endif
