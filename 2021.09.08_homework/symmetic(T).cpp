#include <iostream>


using namespace std;

//A four-digit number is given. Determine if its decimal notation is symmetric.

int main(){
    int n ; 

    cin>>n ; //the numbers

    //means every digit
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0; 

    a = int(n/100);
    b = int(n%100);

    c = (b/10)+(b%10)*10;
    d = (a == c);
    cout << d <<endl;

    return 0;


}

