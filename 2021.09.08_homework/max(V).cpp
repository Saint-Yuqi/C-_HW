#include<iostream>

using namespace std;

//Write a program that reads two integers a and b and outputs the largest of them. The numbers are integers from 1 to 1000.

int main()
{    
    int a,b,c,d,e,f;
    
    cout << "please input 2 numbers from 0 to 1000" << endl;
    cin >> a >> b;
    d = a ^ b;
    c = -(a < b);
    e = d & c;
    f = a ^ e;

    cout << f  << endl;
    
    return(0);
}