#include <iostream>
#include <cstdlib>
#include<iomanip>

using namespace std;

//A four-digit number is given. Determine if its decimal notation is symmetric.

int main(){
    int n ; 
    cin>>n ;
    int a , b, c, d; // a means the first and second digit, b means the third and forth digit,swap the location of b
    a = int(n/100);
    b = int(n%100);
    c = (b/10)+(b%10)*10;
    d = (a == c ? 1 : rand() );
    cout << d <<endl;


}

