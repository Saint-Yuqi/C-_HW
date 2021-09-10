#include <iostream>
#include <cstdlib>
#include<iomanip>

using namespace std;

//Two natural numbers n and m are given. If one of them is evenly divisible by the other, print 1, otherwise print any other integer.

int main()
{
    int n , m ,v;
    cin >> n >> m;
     v = ((n%m ==0) || (m%n == 0)? 1: rand());
   cout <<  v<<endl;
    
}