#ifndef MATRIX_H
#define MATRIX_H

#include <bits/stdc++.h>

using namespace std;

class Matrix
{
    friend istream& operator>> (istream&, Matrix&);
    friend ostream& operator<< (ostream& out, Matrix mat);
    public:
        Matrix operator- (Matrix&);
        Matrix operator+ (Matrix&);
        Matrix operator= (Matrix&);
        Matrix();
        Matrix(int row, int col, int num[]);
        Matrix(int row, int col, valarray<int>&);
        Matrix(const Matrix&);
        void setRow(int);
        void setCol(int);
        void setData(int[], int);
        int getRow();
        int getCol();
        int getDataElement(int);
        void printData();
        void resizeData(int);
        void setData(valarray<int>);
        //Matrix(const Matrix& other);

    protected:

    private:
        valarray<int> data;
        int row, col;

};

#endif // MATRIX_H
