#include<iostream>

using namespace std;

// I want to using insertion sort to arrange
// Three numbers are given, written on separate lines.

int main()
{
    int i;
    int key;

    cout << "Please input three integers numbers" << endl;
    int origin[3];
    
    for (int i = 0;i < 3; ++i)
    {
        cin >> origin[i];
    }
    for (int j = 1; j < 3; ++j)
    {

        key = origin[j];
        i = j - 1;
        while (i >= 0 && origin[i] > key)
        {
            origin[i+1] = origin[i];
            i = i -1;
        } 
        origin[i+1] = key;
    }
    for (int i = 0; i < 3; ++i)
    {
        cout << origin[i];
    }
    
    cout << endl;

    

    

   



  

}
