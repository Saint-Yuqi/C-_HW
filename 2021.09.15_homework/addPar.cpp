#include<iostream>
#include<string>

using namespace std;

void addPar(string n = "", int i = 0)
{
    int l = 0;
    l = n.length();

    if(i < l)
    {
        if (l % 2 == 0)
        {
            if(i < l / 2 )
            {
            
                cout << '(' << n[i];
                addPar(n, i + 1);
            }
            else
            {
                cout << n[i] << ")";
                addPar(n, i + 1);
            }
        }
        else
        {
           if(i <= l / 2 )
           {          
                cout << "(" << n[i];
                if(i == (l - 1)/2)
                {
                    cout << ")";
                }
                addPar(n, i + 1);
           } 
           else
           {
               cout << n[i] << ")";
               addPar(n, i + 1);
           }
        }
        

    }
    
    return;
}

int main(int argc, char* argv[])
{
    string text = "";

    cout << "Please input a string!" << endl;
    cin >> text;
    addPar(text);

    cout << endl;

    return EXIT_SUCCESS;
}

