//class for array

#include <iostream>
#include <stdio.h>

using namespace std;

template <class T>
class Array
{
private:
    T *A;
    int size;
    int length;

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new T[size];
    }

    Array(int sz){
        size = sz;
        A = new T[size];
        length = 0;
    }
    ~Array()
    {
        delete []A;
    }

    void Display();
    void Insert(int idx, T val);
    void Append(T val);
    T Delete (int index);

};

template <class T>
void Array<T>::Display()
{
    for (int i=0; i<length; i++)
        cout << A[i] << " ";
    
    cout << endl;
}



template <class T>
void Array<T>::Insert(int idx, T val)
{
    if(idx >= size) return;

    for(int i = length; i>idx; i--)
        A[i] = A[i-1];
    
    A[idx] = val;
    length++;

    return;
}

template<class T>
void Array<T>::Append(T val)
{
    if(length < size)
    {
        A[length++] = val;    //also increments length
    }
}

template<class T>
T Array<T>::Delete(int idx)
{
    T temp = A[idx];

    if(idx >=0 && idx < length)
    {
        for(int i = idx; i<length-1; i++)
            A[i]= A[i+1];
        
    
        length--;
    }
    return temp;
}






int main()
{
    Array<char> arr;
    arr.Insert(0, 'c');
    arr.Insert(1, 'r');
    arr.Insert(2, 'a');
    arr.Insert(3, 'p');

    arr.Display();

    cout << "Program Terminated \n";

    return 0;

}