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

vector_3D vector_3D::sumVector(vector_3D v)
{
    vector_3D sumV;
    sumV.x = x + v.x;
    sumV.y = y + v.y;
    sumV.z = z + v.z;
    return sumV;
}

vector_3D vector_3D::mutiVector(float n)
{
    vector_3D mutiV;
    mutiV.x = x * n;
    mutiV.y = y * n;
    mutiV.z = z * n;
    return mutiV;
}


int vector_3D::scalarProduct(vector_3D v)
{
    return x * v.x + y * v.y +  z * v.z;
}

vector_3D vector_3D::crossProduct(vector_3D v)
{
    vector_3D crossP;
    crossP.x = y * v.z - v.y * z;
    crossP.y = z * v.x - v.z * x;
    crossP.z = x * v.y - v.x * y;
    return crossP;
}

void vector_3D::printVector()
{
    cout << "vector( " << x << "," << y << "," << z << " )";
    return;
}


