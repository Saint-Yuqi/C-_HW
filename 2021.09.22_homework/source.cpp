#include<iostream>
#include "vector3D.h"

using namespace std;

int main()
{
    int n = 2;
    vector_3D v1(1, 2, 3);
    vector_3D v2(1, 2, 3);
    vector_3D v3;
    {
        v3 = v1.sumVector(v2);
        v3.printVector();
    }
    
    {
        v3 = v1.mutiVector(n);
        v3.printVector();
    }

    {
        v3 = v1.scalarProduct(v2);
        v3.printVector();

    }

    {
        v3 = v1.crossProduct(v3);
        v3.printVector();
    }


    

    return EXIT_SUCCESS;
   

}