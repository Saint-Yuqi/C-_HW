#include<iostream>

using namespace std;

//Given the number X. It is required to translate this number into the Roman numeral system.


int main()
{
    int A_num[] = {1,4,5,9,10,40,50,90,100}; // Arbric number
	string R_m[] = {"I","IV","V","IX","X","XL","L","XC","C"}; // roman numbers

	int i=8;
    int a ;
    cout << "Input a number from 0 to 100" << endl << "it will be conveted to a Roman numbers"<< endl;
    cin >> a ;

	while(a > 0)
	{
        int b;
	    b = a/A_num[i];
	    a = a%A_num[i];
	   while(b--)
	   {
		cout<<R_m[i];    
	   }
	   i--;
	}

    cout << endl;

	return 0;
}
