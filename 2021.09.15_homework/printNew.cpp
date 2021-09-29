#include<iostream>

using namespace std;

void printNew(string n = "", int i = 0, int l = 0)
{
    l = n.length();

    if(i < l)
    {
        if(n[i] != n[l - i - 1] || (i == l - 1))
        {

            cout << n[i] ;

            return printNew(n, i + 1, l - 1);
        }
        else
        {         
            return printNew(n, i + 1, l - 1);
        }

    }
    
    return;
}

int main()
{
    string text;
    cout << "Pleas input a string" << endl;
    cin >> text;

    printNew(text);

    cout << endl;

    return EXIT_SUCCESS;
}