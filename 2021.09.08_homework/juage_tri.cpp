#include<iostream>

using namespace std;

//Determine the type of triangle (acute, obtuse, rectangular) with the given sides.

int main()
{
    int a , b ,c ; // means the sides of triangel
    cin >> a >> b >> c;

    if (a+b >= c && a+c>=b && b+c>=a)
    {
        if ((a*a+b*b==c*c)||(a*a+c*c==b*b)||(b*b+c*c==a*a))
        {
             cout << "it's a right triangle" << endl ;
        }
        else if((a>b) && (a>c) && (b*b+c*c) < (a*a))
        {
             cout << "the triangle is obtuse" <<endl;
        }
        else if ((a>b) && (a>c) && (b*b+c*c) > (a*a))
        {
             cout << "the triangle is acute" <<endl; 
        }
        else if ((b>a) && (b>c) && (a*a+c*c < b*b))
        {
             cout << "the triangle is obtuse" <<endl; 
        }
        else if ((b>a) && (b>c) && (a*a+c*c) > (b*b))
        {
            cout << "the triangle is acute" <<endl; 
        }
        else if ((c>a) && (c>b) && (a*a+b*b) < (c*c))
        {
            cout << "the triangle is obtuse" <<endl; 
        }
        else if ((c>a) && (c>b) && (a*a+b*b > (c*c)))
        {
            cout << "the triangle is acute" <<endl; 
        }
      
       
    }
    else
    {
        cout<<"it's not a triangel" <<endl;
    }

}