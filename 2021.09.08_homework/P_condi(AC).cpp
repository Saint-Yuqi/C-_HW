#include<iostream>

using namespace std;

//Given three integers A, B, C. Determine if there is at least one even and at least one odd among them.

int main()
{
    int a , b , c ;

    cin >> a >> b >> c ;

    if ((a % 2 == 0 && b % 2 == 1) || (a % 2 == 0 && c % 2 == 1))
    {
        cout << "yes" << endl;
    }
    else if((b % 2 == 0 && a % 2 == 1) || (b % 2 == 0 && c % 2 == 1))
    {
        cout << "yes" << endl; 
    }
    else if((c % 2 == 0 && a % 2 == 1) || (c % 2 == 0 && b % 2 == 1))
    {
        cout << "yes" << endl; 
    }
    else
    {
        cout << "No" << endl;
    }

    return(0);
}
