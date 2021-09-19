#include<iostream>

using namespace std;

string printNew(string n, string reNew = "", int i = 0)
{
    int l = n.length();

    if (i == l)
    {
        if(l%2 == 1)
        {
            
            return reNew;
        }
        else
        {
            return reNew;
        }    
    }

    if(l%2 == 0)
    {
        if(n[i] != n[l-1-i])
        {                       
            return printNew(n,reNew + n[i],i+1);
        }
        else
        {
            return printNew(n,reNew,i+1);
        }

    }

    if(l%2 == 1)
    {
       if(n[i] != n[l-1-i])
       {

           return printNew(n,reNew+n[i],i+1);
       }
       else
       {
           if (i == l-1-i)
           {
               return printNew(n,reNew + n[i],i+1);
           }
           return printNew(n,reNew,i+1);
       }

    }
    
    return n;
}

int main()
{
    string text;
    cout << "Pleas input a string" << endl;
    cin >> text;

    cout << printNew(text) << endl;
}