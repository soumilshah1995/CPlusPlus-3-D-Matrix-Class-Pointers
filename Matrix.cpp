/*
 * Author : Soumil Nitin Shah
 * Version: 0.0.1
 * Last Modified : 20/Sept/2019
 */

#include <iostream>
using namespace std;

class Array{

public:
    /*
     *  Declaring Variables
     */
    int size;
    int *arr;

public:
    /*
     * Declaring Constructor and Destructor
     */

    Array(int s):size{s}
    {
        arr = new int[size];

        for (int i=0; i <size; i++)
        {
            arr[i] = 0;
        }

        cout << "Constructor " << endl;
    }

    ~Array()
    {

        delete []  arr;
        arr = nullptr;
        cout << "Destructor Freeing Memory " << endl;
    }

    Array(const Array &source):Array(source.size)

    {
        for (int i=0; i<size; i++)
        {
            arr[i] = source.arr[i];
        }
        cout << "Copy Constructor " << endl;
    }

public:
    /*
     * Operator Overloading
     */
    friend std::ostream &operator<<(std::ostream &os, Array &rhs)
    {

        os << "Object: Array has Size :: " << rhs.size << endl;
        for (int i=0; i< rhs.size; i++)
        {
            os << rhs.arr[i] << " ";
        }
        return os;
    }

    void operator()(int index , int data)
    {
        arr[index]=  data;
    }

    int &operator()(int index)
    {
        return arr[index];
    }

    Array &operator=(Array &rhs)
    {
        cout << "Assignment operator" << endl;
        if(this == &rhs)
        {
            return *this;
        }else
        {
            delete [] arr;

            int *Tem;
            Tem = new int[size];

            for (int i=0; i<size;i++)
            {
                Tem[i] = rhs.arr[i];
            }
            // *Tem = *rhs.arr;

            return *this;
        }
    }



public:
    /*
     * Methods
     */

    void addElements(int index, int data)
    {
        arr[index] = data;
    }

    int getData(int index)
    {
        return arr[index];
    }


};

void print(Array a)
{
    cout << a;
}

int main() {

    Array a1(5);

    a1(0,1);
    a1(1,2);
    a1(2,4);

    cout << a1;

    Array a2(5);

    a2=a1;

    cout << a2;
    cout << "\n";

    print(a2);

    return 0;
}