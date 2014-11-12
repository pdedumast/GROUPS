#pragma once
#include <string>
#include <math.h>
#include <iostream>
#include <fstream>
//#include <gl/glut.h>

class Vector
{
public:
	Vector(void);
	Vector(const float *v);
	Vector(const float *v1, const float *v2);
	Vector(const float v1, const float v2, const float v3);
	Vector(const int v1, const int v2, const int v3);
	~Vector(void);
	Vector cross(const Vector v);
	float norm(void);
	Vector unit(void);
	Vector operator +(const Vector &v);
	Vector operator -(const Vector &v);
	Vector operator *(const float v);
	float operator *(const Vector &v);
	Vector operator /(const float v);
	Vector operator =(const float *v);
	bool operator ==(const Vector &v) const;
	bool operator !=(const Vector &v) const;
	bool operator <(const Vector &v) const;
	bool operator >(const Vector &v) const;
	float operator [](const int id);
	const Vector &operator +=(const Vector &v);
	const Vector &operator -=(const Vector &v);
	const Vector &operator *=(const float v);
	const Vector &operator /=(const float v);
	const float *fv(void);

private:
	float m_vector[3];
};

class Vertex
{
public:
	Vertex(void);
	Vertex(const int id);
	~Vertex(void);
	void setVertex(const float *v);
	void setColor(const float *v);
	void setColor(const float r, const float g, const float b);
	float operator[] (const int id);
	const int id(void);
	const float *fv(void);
	const float *color(void);

private:
	float m_vertex[3];
	float m_color[3];
	int m_id;
};

class Normal
{
public:
	Normal(void);
	Normal(const int id);
	Normal(const float *v);
	~Normal(void);
	void setNormal(const float *v);
	void normalize(void);
	const float *fv(void);
	const Normal &operator +=(const Normal &n);
	const Normal &operator *=(const float s);
	float operator[] (const int id);

private:
	float m_normal[3];
	int m_id;
};

class Face
{
public:
	Face(void);
	Face(const int id);
	~Face(void);
	void setVertex(const Vertex **v);
	void setNormal(const Normal **v);
	void setList(const int *list);
	const int id(void);
	const int *list(void);
	const int list(const int index);
	const Vertex *vertex(const int index);
	const Normal *normal(const int index);
	const Normal faceNormal(void);
	int operator[] (const int id);

private:
	Vertex *m_vertex[3];
	Normal *m_normal[3];
	int m_list[3];
	int m_id;
};

class Mesh
{
public:
	Mesh(void);
	~Mesh(void);
	void draw(void);
	void setColor(const float *v);
	void setColor(const float r, const float g, const float b);
	void openFile(const char *filename);
	void openFile(const char *filename, const char *color);
	void saveFile(const char *filename, const char *format, bool normal = false);
	void colormap(const char *color, bool overlay = false);
	void scaling(const float factor);
	void centering(void);
	void rotation(const float *axis, float theta);
	void rotation(const float *axis, float theta, float *v);
	const int nFace(void);
	const int nVertex(void);
	const Face **face(void);
	const Face *face(const int index);
	const Vertex **vertex(void);
	const Vertex *vertex(const int index);
	const Normal **normal(void);
	const Normal *normal(const int index);

private:
	int m_nVertex;
	int m_nFace;
	int m_nNormal;
	Vertex **m_vertex;
	Normal **m_normal;
	Face **m_face;
};
