#include<iostream>
#include "vector3D.h"

using namespace std;

int main()
{
    int value_of_scalar = 0;
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
        value_of_scalar = v1.scalarProduct(v2);
        cout << value_of_scalar << endl;

    }

    {
        v3 = v1.crossProduct(v3);
        v3.printVector();
    }


    

    return EXIT_SUCCESS;
   

}