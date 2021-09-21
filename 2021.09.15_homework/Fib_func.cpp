#include <iostream>

using namespace std;

int fib_Function(int n = 0)
{
     if (n <= 0)
     {
          return 1;
     } 
       
    else if (n == 1)
    {
         return 1;

    }  
    else
    {
        return fib_Function(n - 1) + fib_Function(n - 2);

    }
        

  
}

int main()
{
    int c = 0;
  
    cout << "Input a natural number" << endl;
    cin >> c;
    cout << "fib(" << c <<")"<< "=" << fib_Function(c) << endl;
    return 0;




}