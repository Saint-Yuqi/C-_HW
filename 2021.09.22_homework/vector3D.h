#pragma once
#include<iostream>

using namespace std;

struct vector_3D
{
    float x;
    float y;
    float z;


    vector_3D(); //default constructor

    vector_3D(float x, float y, float z); //parametrized constructor

    vector_3D(const vector_3D &v); //copy constuctor

    ~vector_3D(); // destructor
    
    //methods
   
    vector_3D sumVector(vector_3D v);

    vector_3D mutiVector(float n);

    vector_3D crossProduct(vector_3D v);  //it will be a vector which is perpendicular to others

    int scalarProduct(vector_3D v); //it will be a real number

    void printVector();

};