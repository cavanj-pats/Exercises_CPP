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
    T min;
    T max;

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new T[size];
        min = 0;
        max = 0;
    }

    Array(int sz){
        size = sz;
        A = new T[size];
        length = 0;
        min = 0;
        max = 0;
    }
    ~Array()
    {
        delete []A;
    }
    int getSize(){return length;}

    //function headers
    void Display();
    void Insert(int idx, T val);
    void Append(T val);
    T Delete (int index);
    T elementSum();
    T targetSum();
    int singleMissingElement();
    void multMissingElements();
    void setMinMax();
    void findMissingHash();
    void findDuplicatesHash();
    void findDuplicatesUnsorted();

    void findPairSumKsorted(int k);
    
    

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


template<class T>
T Array<T>::elementSum()
{
    T runningSum = 0;
    for (int i=0; i<length; i++)
    {
        runningSum += A[i];
    }

    return runningSum;
}

template<class T>
T Array<T>::targetSum()
{
    //dangerous is T is non numeric
    T n = A[length -1];
    return (n * (n+1)/2);
}

template<class T>
int Array<T>::singleMissingElement()
{
    if (length == 0) return -1;
    T diff = A[0]-0;
    for (int i = 1; i < length; i++)
    {
        if (A[i]-i != diff)
        {
            //actually should be diff + i
            cout << "Missing Element: " << diff + i << endl;
            break;
        }
    }

    return -1;
}

template<class T>
void Array<T>::multMissingElements()
{
    if (length == 0) return ;
    T diff = A[0]-0;
    for (int i = 1; i < length; i++)
    {
        if (A[i]-i != diff)
        {
            while (diff < A[i]-i)
            {
            //as i thought need a loop here in case more than one missing between 
            //two elements.  this code only works for a single missing element.
                cout << "Missing Element Found: " << diff + i << endl;
                diff++;
            }
        }
    }

    return ;
}

template<class T>
void Array<T>::setMinMax()
{
    min = A[0];
    max = A[0];
    
    for(int i=1; i<length; i++)
    {
        if(A[i]<min) 
            min = A[i];
        else if(A[i] > max) 
            max = A[i];
    }

    return;
}

template<class T>
void Array<T>::findMissingHash()
{
    setMinMax();
    Array<int> hash(max+1);
    for(int i=0; i<max+1;i++)
    {
        hash.Append(0);
    }

    for(int j=0; j<length; j++)
    {
        hash.A[A[j]]++;
    }
    
    cout << "Missing values from " << min << " to "<<max << endl;
    cout << "Values: ";
    for(int k=0; k<hash.length;k++)
    {
        if(k>=min && hash.A[k]==0)
        {
            cout << k <<", ";
        }
    }

    
    return;

}

template<class T>
void Array<T>::findDuplicatesHash()
{
    setMinMax();
    Array<int> hash(max+1);
    for(int i=0; i<max+1;i++)
        hash.Append(0);
    
    for(int j=0; j<length; j++)
        hash.A[A[j]]++;
    
    cout << "Duplicate values from " << min << " to "<<max << endl;
    cout << "Duplicates: ";
    for(int k=0; k<hash.length;k++)
    {
        if(k>=min && hash.A[k]>1)
        {
            cout << k <<", ";
        }
    }

}

template<class T>
void Array<T>::findDuplicatesUnsorted()
{
    //O(n^2) function to find duplicates in unsorted array.
    //if a duplicate is found,  mark it as -1
    int count;

    for(int i=0; i<length-1; i++)
    {
        count = 1;
        if(A[i]!=-1)
        {
            for(int j = i+1; j<length; j++)
            {
                if(A[i] == A[j])
                {
                    count++;
                    A[j]= -1;

                }
            }
        }

        if (count > 1)
            cout << "Count of "<<A[i]<< " = "<< count << endl;
        
    }

    return;

}

/*
    finding a pair unsorted
    desired sum given as k
    psuedo code    O(n^2)
    for(int i = 0; i <length-1; i++)
    {

        for(int j = i+1; j<length; j++)
        {
            if(A[i]+A[j]== k)
            {
                cout << A[i] <<" + " << A[j] << "= "<< k << endl;
            }
        }
    }
*/

template<class T>
void Array<T>::findPairSumKsorted(int k)
{
    int i = 0;
    int j = length-1;
    int sum;
    while (i < j)
    {
        sum = A[i]+A[j];
        if (sum == k)
        {
            i++;
            j--;
            cout << A[i] << "+" << A[j] << "= " << k << endl;
        } else if(sum < k)
            i++;
        else 
            j--;

    }
}


int main()
{
    Array<int> arr;
    arr.Insert(0, 1);
    arr.Insert(1, 3);
    arr.Insert(2, 7);
    arr.Insert(3, 8);
    arr.Insert(4 ,9);

    arr.Display();

    

    if (arr.elementSum() != arr.targetSum())
    {
        cout << "Missing Element from Sorted Array: " << arr.targetSum()-arr.elementSum() << endl;
    }
    else
        cout << "No missing Elements" << endl;

    
    cout << "Missing Element method 2: " << arr.singleMissingElement() << endl;

    arr.multMissingElements();
    cout << endl;

    arr.findMissingHash();




    cout << "Program Terminated \n";

    return 0;

}