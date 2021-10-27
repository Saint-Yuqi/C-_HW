#include<iostream>

using namespace std;

struct Complex
{
    //fields
    int re;
    int im;
    
    //default constructor and paramatrized constructor
    Complex(int re = 0, int im = 0) : re(re), im(im) {}

/*
    Complex()
    {
        this->re = 0;
        this->im = 0;
    }

    //parametrized constructor
    Complex(int re, int im)
    {
        this->re = re;
        this->im = im;
    }
*/

    //copy constructor
    Complex(const Complex& z) : re(z.re), im(z.im) {}

    //destructor
    ~Complex() {}

    //define operator
    Complex operator+(Complex z1)
    {
        
        return Complex(re + z1.re, im + z1.im);
    }

    Complex operator-()
    {
        return Complex(-re, -im);
    }

    Complex operator-(Complex z1)
    {
        return Complex(re - z1.re, im - z1.im);
    }

    
    friend Complex operator*(int a, Complex z1)
    {
        return Complex(a * z1.re, a * z1.im);
    }

    friend Complex operator*(Complex z1, int a)
    {
        return Complex(a * z1.re, a * z1.im);
    }

    friend Complex operator/(Complex z1, int a)
    {
        return Complex(z1.re / a, z1.im / a);
    }

    Complex crossProduct(Complex z1)
    {
        Complex z2;
        z2.re = (re * z1.re) - (im * z1.im);
        z2.im = (re * z1.im) + (im * z1.re);
        return z2;
    }

    void print()
	{
		cout << re;
		if (im < 0)
		{
			cout << " - " << -im;
		}
		else
		{
			cout << " + " << im;
		}
		cout << " * i" << endl;
	} 


};

void printComplexNumber(Complex z)
{
	z.print();
}

int main(int argc, char* argv[])
{

    Complex z1(1,2);
    Complex z2(6,0);
   
    z2 = z1 + z2;
    printComplexNumber(z2);

    z2 = 2 * z1;
    printComplexNumber(z2);

    z2 = z1 * 9;
    printComplexNumber(z2);

    z2 = -z2;
    printComplexNumber(z2);

    z2 = z2 - z1;
    printComplexNumber(z2);

    z2 = z2 / 5;
    printComplexNumber(z2);

    Complex z3(1,1);
    Complex z4(1,2);
    z3 = z4.crossProduct(z3);
    printComplexNumber(z3);

    //z^3 - (2 + 5i)z^2 - (17 - 4i)z + (34 - 63i) = 0
    cout << "Let's find the answer of z^3 - (2 + 5i)z^2 - (17 - 4i)z + (34 - 63i) = 0 " << endl;
    for (int a = 0; a < 10; a++)
    {
        for (int b = 0; b < 10; b++)
        {
            Complex z5(a, b);
            Complex z6(a, b);
            Complex z7(a, b);
            Complex z8(2, 5);
            Complex z9(17, -4);
            Complex z10(34, -63);
            Complex z11(a, b);
            Complex z12(a, b);
            Complex z13(a, b);

            z6 = z5.crossProduct(z5); // z6 = z5^2
            z7 = z6.crossProduct(z5); // z7 = z5^3
            z12 = z8.crossProduct(z6);
            z13 = z9.crossProduct(z5);
            z11 = z7 - z12 - z13 + z10;
           
            if(z11.re == 0 && z11.im == 0 )
            {
                printComplexNumber(z5);
            }
                       
        }
        
    }
    


    return EXIT_SUCCESS;
}