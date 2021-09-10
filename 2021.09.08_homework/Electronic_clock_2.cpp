#include<iostream>
#include<iomanip>

using namespace std;

//The electronic clock shows the time in the h: mm: ss format,

int main()
{
  int n ; // means the seconds
  int h , m , s;
  cin >> n;
  h = (int) n/3600 ;
  m = (int)((n-(h*3600))/60);
  s = (int)(n-h*3600-m*60); 
  h = (h>24 ? h%24:h);
  
  cout << setfill('0')<<setw(2) << h <<":"<< setfill('0')<<setw(2) << m << ":" <<setfill('0')<<setw(2) << s <<endl ;
  


}
