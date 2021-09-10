#include <iostream>
#include <cstdlib>

using namespace std;

//The length of the Moscow ring road is 109 kilometers. 
//Biker Vasya starts from the zero kilometer of the Moscow Ring Road and travels at a speed of V kilometers per hour. 
//At what point will it stop in T hours?

int main()
{
   int v ,t ,a,b;
   int d = 109; // means the whole road
   int c ;  // means the point which center
   cout<<"please input the speed and time" <<endl;
   cin >> v >> t ;
   a =(v*t)%d ; 
   b = ((v*t)%d)+ (d) ;
   c = (v > 0 ? a:b);
   cout << c << endl;
   
  
}
