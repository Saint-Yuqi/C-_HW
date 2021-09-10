#include<iostream>

using namespace std;

//Write a program that reads two integers a and b and outputs the largest of them. The numbers are integers from 1 to 1000.

int main()
{    
    int a,b,c;
    
    cout << "please input 2 numbers from 0 to 1000" << endl;
    cin >> a >> b;
    c = (a >= b ? a:b );

    cout << c << endl;

}