/*
 * Soumil Nitin SHah
 * Github: https://github.com/soumilshah1995
 */

#include <iostream>

using namespace std;

class Matrix{

public:
    /*
     * Declare the Row and Column
     *
     */
    int r_size;
    int c_size;
    int **arr;

public:
    /*
     * Constructor and Destructor
     */

    Matrix(int r_size, int c_size):r_size{r_size},c_size{c_size}
    {
        arr = new int*[r_size];
        // This Creates a 2-D Pointers
        for (int i=0 ;i < r_size; i++)
        {
            arr[i] = new int[c_size];
        }

        // Initialize all the Vector to 0 initially
        for (int row=0; row<r_size; row ++)
        {
            for (int column=0; column < c_size; column ++)
            {
                arr[row][column] = 0;
            }
        }
        std::cout << "Constructor -- creating Array Size ::" << r_size << " " << c_size << endl;
    }

    ~Matrix()
    {
        std::cout << "Destructpr  -- Deleting  Array Size ::" << r_size <<" " << c_size << endl;

    }

    Matrix(const Matrix &source):Matrix(source.r_size, source.c_size)

    {
        for (int row=0; row<source.r_size; row ++)
        {
            for (int column=0; column < source.c_size; column ++)
            {
                arr[row][column] = source.arr[row][column];
            }
        }

        cout << "Copy Constructor " << endl;
    }


public:
    /*
     * Operator Overloading
     */

    friend std::ostream &operator<<(std::ostream &os, Matrix & rhs)
    {
        int rowCounter = 0;
        int columnCOUNTER = 0;
        int globalCounter = 0;

        for (int row =0; row < rhs.r_size; row ++)
        {
            for (int column=0; column < rhs.c_size ; column++)
            {
                globalCounter = globalCounter + 1;
            }
            rowCounter = rowCounter + 1;
        }


        os << "Total There are " << globalCounter << " Elements" << endl;
        os << "Array Elements are as follow -------" << endl;
        os << "\n";

        for (int row =0; row < rhs.r_size; row ++)
        {
            for (int column=0; column < rhs.c_size ; column++)
            {
                os << rhs.arr[row][column] << " ";
            }
        os <<"\n";
        }
        return os;
    }

    void operator()(int row, int column , int Data)
    {
        arr[row][column] = Data;
    }

    int &operator()(int row, int column)
    {
        return arr[row][column];
    }

    Matrix &operator=(Matrix &rhs)
            {
                cout << "Assingment Operator called " << endl;cout <<"\n";
                if(this == &rhs)
                {
                    return *this;
                } else
                    {
                    delete [] arr;

                        arr = new int*[r_size];
                        // This Creates a 2-D Pointers
                        for (int i=0 ;i < r_size; i++)
                        {
                            arr[i] = new int[c_size];
                        }

                        // Initialize all the Vector to 0 initially
                        for (int row=0; row<r_size; row ++)
                        {
                            for (int column=0; column < c_size; column ++)
                            {
                                arr[row][column] = rhs.arr[row][column];
                            }
                        }

                        return *this;
                    }

            }

};

void print(Matrix m)
{
    cout << "Inside print function" << endl;
    for (int row=0; row<m.r_size; row ++)
    {
        for (int column=0; column < m.c_size; column ++)
        {
            cout << m.arr[row][column] << " ";
        }
        cout << "\n";
    }

}

int main()
{

    Matrix m1(3,3);         // Initialize Matrix 3x3

    cout << m1;cout << "\n";

    m1(0,0,1);
    m1(0,1,2);
    m1(0,2,3);

    m1(1,0,4);
    m1(1,1,5);
    m1(1,2,6);

    m1(2,0,7);
    m1(2,1,8);
    m1(2,2,9);

    cout << m1;cout <<"\n";             // print Matrix
    cout << "Element at Position (1,2) : " << m1(1,2) << endl;

    Matrix m2(3,3);
    m2 = m1;
    cout << m2;cout <<"\n";

    print(m2);

    return 0;
}