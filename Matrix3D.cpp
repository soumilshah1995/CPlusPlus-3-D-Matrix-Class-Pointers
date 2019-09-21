#include <iostream>
using namespace std;

class Matrix3D{

public:
    /*
     * Declaring variables and Pointers
     */
    int ***arr;
    int Dimension;
    int Row;
    int Column;

public:
    /*
     * Declaring  Constructpr and Destructor
     */

    Matrix3D(int Dimension, int Row, int Column):Dimension{Dimension},Row{Row},Column{Column}
    {
        cout << "Constructor " << endl;cout << "\n";

        arr = new int**[Dimension];     // Dimension

        for (int i=0; i<Dimension; i++)
        {
            arr[i] = new int *[Row];

            for (int j=0; j<Column; j++)
            {
                arr[i][j] = new int[Column];
            }
        }

        for (int Ndim=0;Ndim <Dimension; Ndim++)
        {
            for (int row = 0; row < Row; row ++)
            {
                for(int column = 0; column<Column;column ++)
                {
                    arr[Ndim][row][column]=0;
                }
            }
        }


    }

    ~Matrix3D()
    {
        delete [] arr;
        arr= nullptr;
        cout << "Destructor Freeing Memory " << endl;cout<<"\n";
    }

    Matrix3D(const Matrix3D &source):Matrix3D(source.Dimension, source.Row, source.Column)
    {

        for (int Ndim=0;Ndim <Dimension; Ndim++)
        {
            for (int row = 0; row < Row; row ++)
            {
                for(int column = 0; column<Column;column ++)
                {
                    arr[Ndim][row][column] = source.arr[Ndim][row][column];
                }
            }
        }
        cout << "Copy Constructor " << endl;
    }

public:
    /*
     * Operator Overloading
     */
    int &operator()(int Dimension, int Row , int Column)
    {
        return arr[Dimension][Row][Column];
    }

    void  operator()(int Dimension, int Row , int Column, int Data)
    {
        arr[Dimension][Row][Column] = Data;
    }

    Matrix3D &operator=(Matrix3D &rhs)
            {
        cout << "Assingment Operator Called  " <<endl;cout<<"\n";
                if(this == &rhs)
                {
                    return *this;
                } else
                    {
                        delete [] arr;

                        arr = new int**[Dimension];     // Dimension

                        for (int i=0; i<Dimension; i++)
                        {
                            arr[i] = new int *[Row];

                            for (int j=0; j<Column; j++)
                            {
                                arr[i][j] = new int[Column];
                            }
                        }


                        for (int Ndim=0;Ndim <Dimension; Ndim++)
                        {
                            for (int row = 0; row < Row; row ++)
                            {
                                for(int column = 0; column<Column;column ++)
                                {
                                    arr[Ndim][row][column] = rhs.arr[Ndim][row][column];
                                }
                            }
                        }

                        return *this;
                    }

            }

    friend std::ostream &operator<<(std::ostream &os, Matrix3D &rhs)

    {

        for (int i=0; i <rhs.Dimension; i++)
        {
            for (int j = 0; j < rhs.Row; j ++)
            {
                for(int k = 0; k<rhs.Column;k ++)
                {
                    os  << rhs.arr[i][j][k] << "\t|\t";
                }
                os << "\n";
            }
            os << "=====================" << "\n";cout <<"\n";
        }

        return os;
    }


public:
    /*
     * Methods
     */
};


int main()
{

    cout << "------ Matrix 3D------ " << endl;

    Matrix3D m1(3,3,3);
    Matrix3D m2(3,3,3);

    m1(0,0,0,12);
    cout << m1;cout <<"\n";
    m2 = m1;
    cout<< m2;

    return 0;
}