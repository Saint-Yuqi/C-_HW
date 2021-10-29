#include<iostream>

using namespace std;

void randomizeArray(int* a, int n, int min = 10, int max = 99)
{
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand() % (max - min + 1) + min;
	}
}

void printArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main(int argc, char* argv[])
{ 
    int n = 0;
    int min = 10;
    int max = 99;

    cin >> n;

    int* a = new int[n]; // if i use int* a = new int[n] {0}; the terminal say "expected ';' at end of declaration"

    randomizeArray(a, n);
	printArray(a, n);

    //the sum of elements

    int totalsum = 0;

    for (int i = 0; i < n; ++i)
    {
        totalsum += a[i];
    }

    cout << "To show the sum of elements: " << totalsum << endl;

    //the product of negative elements
    int productSum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] < 0)
        {
            productSum *= a[i];
        }

    }

    cout << "the product of negative elements: " << productSum << endl;

    //the number of even numbers
    int evenNumber = 0;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] % 2 == 0)
        {
            evenNumber += 1;
        }

    }

    cout << "The number of even numbers: " << evenNumber << endl;
    
    //get the same array from above
    int* t = new int[n]; 
    for (int i = 0; i < n; ++i)
	{
		t[i] = a[i];
	}

    //choose the second minimum number
    //Firstly i sort the whole array from minumun to max
    int key = 0;
    int j = 0;
    for (int i = 1; i < n; ++i)
    {
        key = a[i]; // insert a[i] into the sorted sequence
        j = i - 1;
        while(j > 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }

    cout << "The second minimum number: " << a[1] << endl;

    //index of the second maximum number

    int index = 0;
    cout << "The second maximum number: " << a[n - 2] << endl;
    int scondNum = a[n - 2];
             
    for (int i = 0; i < n; ++i)
    {
        if(t[i] == scondNum)
        {
            index = i + 1; 

        }
    }

    cout << "Index of the second maximum number: " << index << endl << endl; // i mean the real position
    
    //Modify the array 

    //Swap the elements in pair
    cout << "Swap the elements in pair" << endl;

    randomizeArray(a, n);
	printArray(a, n);

    
    for (int i = 1; i < n; ++i)
    {
        if(i % 2 == 1)
        {
            a[j] = a[i - 1];
            a[i - 1] = a[i];
            a[i] = a[j];
        }
    }

	printArray(a, n);

    //reverse the array
    cout << "reverse the array" << endl;

	printArray(a, n);

    int start = 0;
    int end = n - 1;
    for (int i = 0; i < (end - start + 1) / 2; ++i)
	{
		int c = a[start + i];
		a[start + i] = a[end - i];
		a[end - i] = c;
	}

	printArray(a, n);

    //delete the elements between max and min
    cout << "delete the elements between max and min " << endl;

    randomizeArray(a, n);
	printArray(a, n);

    for (int i = 0; i < n; ++i)
	{
		t[i] = a[i];
	}

    for (int i = 1; i < n; ++i)
    {
        key = t[i]; // insert a[i] into the sorted sequence
        j = i - 1;
        while(j > 0 && t[j] > key)
        {
            t[j + 1] = t[j];
            j = j - 1;
        }
        t[j + 1] = key;
    }

    int tMax = t[0];
    int tMin = t[n-1];
    int indexMax = 0;
    int indexMin = 0;
    for (int i = 0; i < n; ++i)
    {
        if(a[i] == tMin)
        {
            indexMin = i + 1; 
        }
        if(a[i] == tMax)
        {
            indexMax = i + 1; 
        }
        
    }

    if (indexMin > indexMax)
    {
        j = indexMin; // exchange a and b
        indexMin = indexMax;
        indexMax = j;
    }

    for (int i = 0; i < n ; i++)
    {
        if(i <= indexMin - 1 || i >= indexMax - 1)
        {
            cout << a[i] << " ";
        }   
    }
    cout << endl;
    
    //insert zero in the middle of the array
    cout << "Insert zero in the middle of the array" << endl;
    randomizeArray(a, n);
	printArray(a, n);
    
    for (int i = 0; i < n ; ++i)
	{
        if(n % 2 == 0)
        {
            if (i == (n / 2))
            {
                cout << "0" << " ";
            }            
        }
        if(n % 2 == 1)
        {
            if (i == (n / 2))
            {
                cout << "0" << " ";
            }            
        }

		cout << a[i] << " ";
	}
    cout << endl;

    delete[] t;
    delete[] a;
    return EXIT_SUCCESS;


}