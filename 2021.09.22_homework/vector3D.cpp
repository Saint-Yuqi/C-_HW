#include "vector3D.h"
#include<iostream>

//default constructor
vector_3D::vector_3D()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
 
}
//parametirized constructor
vector_3D::vector_3D(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    
}
//copy constructor
vector_3D::vector_3D(const vector_3D &v)
{
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
}
vector_3D::~vector_3D()
{

}
//methods

int vector_3D::sumVector(vector_3D v)
{
    this->x = x + v.x;
    this->y = y + v.y;
    this->z = z + v.z;
    return 0;
}

int vector_3D::mutiVector(float n)
{
    this->x = x * n;
    this->y = y * n;
    this->z = z * n;
    return 0;
}


int vector_3D::scalarProduct(vector_3D v)
{
    this->x = x * v.x;
    this->y = y * v.y;
    this->z = z * v.z;
    return 0;
}

int vector_3D::crossProduct(vector_3D v)
{
    this->x = y * v.z - v.y * z;
    this->y = z * v.x - v.z * x;
    this->z = x * v.y - v.x * y;
    return 0;
}

void vector_3D::printVector()
{
    cout << "vector( " << x << "," << y << "," << z << " )";
}


