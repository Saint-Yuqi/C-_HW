#include <iostream>

using namespace std;

//if n >= 2 
//First move (n-1) from 1 to 3
//move the last n from 1 to 2
//move (n-1) from 3 to 2

void hanoi(int n = 0, int from_peg = 0, int to_peg = 0, int tem_peg = 0)
{
    if(n == 1)
    {
        cout << "Disk 1 from " << from_peg << " to " << to_peg << endl;     

        return;   
    }

    hanoi(n-1, from_peg, tem_peg, to_peg);

    cout << "Disk " << n << " from " << from_peg << " to " << to_peg << endl;

    hanoi(n-1, tem_peg, to_peg, from_peg);

    return;

}

int main()
{
    int n = 0;
    
    cout << "Please input a number n" << endl;
    cin >> n;

    hanoi(n, 1, 2, 3);


}