#include <iostream>

using namespace std;

int bi_func(int n = 0, int k = 0)
{
    if (k == 0)
    {
        return 1;
    }
    else if (k == n)
    {
        return 1;
    }
    else
    {
        return bi_func(n - 1, k - 1) + bi_func(n - 1, k);
    }

    return EXIT_SUCCESS;
}

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;

    cout <<"Please input binomial coefficients(from n to k)" << endl;
    cin >> a >> b;

    cout << "C_n^k = " << bi_func(a, b) << endl;

    return EXIT_SUCCESS;

}