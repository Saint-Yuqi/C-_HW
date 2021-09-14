#include<iostream>

using namespace std;

//The snail crawls on a vertical pole h meters high, rising by a meters during the day, and descending by b meters during the night.

int main(){
    int a ,b,h; // a daytime to climb,  b night to descend , h the length of snail
    int d_t; 

    cout<< "a should be greater than b" <<endl;
    cin >> h >>a >>b;

    d_t=(int)(h - b)/(a-b) ;
    cout<< d_t << endl;

    return 0;

    
}
