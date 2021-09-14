#include<iostream>

using namespace std;

//Determine the type of triangle (acute, obtuse, rectangular) with the given sides.

int main()
{
    int a , b ,c ; // means the sides of triangel
    cin >> a >> b >> c;
   
    // hope c to be the longest side
    if (a > b)
    {
        a ^= b ^= a ^= b; // exchange a and b
    }
     
    if (b > c)
    {
         b ^= c ^= b ^= c;   // exchange b and c

    }
       
    if (a+b >= c)
    {
        if ((a*a+b*b==c*c))
        {
             cout << "it's a right triangle" << endl ;
        }
        else if ((a*a+b*b) < (c*c))
        {
            cout << "the triangle is obtuse" <<endl; 
        }
        else if ((a*a+b*b > (c*c)))
        {
            cout << "the triangle is acute" <<endl; 
        }

    }
    else
    {
        cout<<"it's not a triangel" <<endl;
    }

    return 0;

}