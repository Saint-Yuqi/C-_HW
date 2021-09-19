#include<iostream>

using namespace std;

string addPar(string n, string newS = "", int a = 0)
{
    int l = n.length();

    if (a == l)
    {
        if(l%2 == 1)
        {
            return newS + ")";
        }
        else
        {
            return newS;
        }
    }
    
    if(l%2 == 1)
    {
        if(a < (l+1)/2)
        {
            return addPar(n,newS+"("+n[a],a+1);
        }
        else
        {
            return addPar(n,newS+")"+n[a],a+1);
        }
    }
    if(l%2 == 0)
    {
        if(a < l/2)
        {
            return addPar(n,newS+"("+n[a],a+1);
        }
        else
        {
            return addPar(n,newS+n[a]+")",a+1);
        }
    }
    return n;
}

int main()
{
    string text;

    cout << "Please input a string!" << endl;
    cin >> text;
    cout << addPar(text) << endl;
    
    return 0;
}