#include<iostream>
#include<string>
#include<fstream>
#include "Alist.h"
#include "CArraylist.h"
#include "CLinkedList.h"

using namespace std;

void Arr_to_link(int argc, char* argv[])
{
    class LinkedList list;
    std::fstream fin("in.txt", std::ios_base::in);

    if(!fin.fail())
    {     
        int x = 0;
        while(!fin.eof())
        { 
            fin >> x;
            list.push_back(x);
        }

    }
    else
    {
        cout << "no file was opened" << std::endl;
    }
    fin.close();
    cout << list << endl;
}

void LinkedList Link_to_Arr(const LinkedList& list)
{
    class CArraylist alist;
    int len = 0;
    while (list->next != nullptr ) //calculate the length of linkedlist
    {
        
        len += 1;
    }
    alist(len);
    Node* curr = list.head;
    int index = 0;
    while (curr != nullptr)
    {
        alist(index) = curr->data;
        index += 1;
    }

    cout << alist << endl;
}

void sort_Arr(CArraylist &alist)
{
    class CArraylist sortlist;
    int key = 0;
    for (int i = 1; i < count; ++i)
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

}

void sep_into_tfile (int argc, char* argv[])
{
    CArraylist alist;
    sort_Arr(alist);
    std::ofstream fout;

    fout.open("sort.txt", std::ios_base app);

    if(!fout.fail)
    {
        for(int i = 0, i < alist.cout , i++)
        {
            fout << alist.data[i] << endl;
        }

    }
    else
    {
        cout << "error opening file";
    }
    fout.close;

    std::fstream fbin;

    fbin.open("sort.bin", std::ios_base::binary | std::ios_base::out | std::ios_base::app)

    if(!fin.fail())
    {
        for(int i = 0, i < count , i++)
        {
            fbin.write((char*)data[i], sizeof(CArraylist));
        }
        fbin.close(); 

    }
    else
    {
        cout << "error opening file" << endl;
    }

}

int main(int argc, char* argv[])
{
    Arr_to_link(argc, argv);


}