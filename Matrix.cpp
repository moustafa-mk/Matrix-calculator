#include "Matrix.h"

using namespace std;

void cpyData(valarray<int>&, const valarray<int>&);

valarray<int> data;
int row, col;

Matrix::Matrix(){
}

Matrix::Matrix(const Matrix& mat){
    row = mat.row;
    col = mat.col;
    cpyData(data, mat.data);
}

Matrix::Matrix(int r, int c, int num[])  //constructor
{
    row = r;
    col = c;
    data.resize (row * col);
    for (int i = 0; i < row * col; i++)
        data [i] = num [i];
}

Matrix::Matrix(int r, int c, valarray<int>& myData){
    row = r;
    col = c;
    data = myData;
}

void Matrix::setRow (int r)
{
    row = r;
}
void Matrix::setCol (int c)
{
    col = c;
}
int Matrix::getRow ()
{
    return row;
}
int Matrix::getCol()
{
    return col;
}
void Matrix::setData(int d[], int arr_sz)
{

    if(arr_sz == row*col)
        for(int i=0; i < row * col; i++)
            data[i] = d[i];

    else
        cout << "Size Error!!\n";
}
void Matrix::printData()
{
    for(auto i : data)
        cout << i << " ";
    cout << endl;
}

void Matrix::resizeData(int sz){
    data.resize(sz);
}

void Matrix::setData(valarray<int> val){
    data = val;
}

int Matrix::getDataElement(int idx){
    return data[idx];
}

Matrix Matrix::operator=(Matrix& mat){
    row = mat.getRow();
    col = mat.getCol();
    cpyData(data, mat.data);
}

Matrix Matrix::operator- (Matrix& mat)
{
    if(mat.getRow() != row || mat.getCol() != col){
        cout << "Size Error!!\n";
        Matrix ret(row, col, data);
        return ret;
    }

    Matrix ret;
    ret.setRow(row);
    ret.setCol(col);
    ret.resizeData(ret.getRow() * ret.getCol());

    valarray<int> val;
    val.resize(row * col);

    for(int i=0; i < row * col; i++)
    {
        val[i] = data[i] - mat.getDataElement(i);
    }

    ret.setData(val);
    return ret;
}

Matrix Matrix::operator+ (Matrix& mat)
{
    if(mat.getRow() != row || mat.getCol() != col){
        cout << "Size Error!!\n";
        Matrix ret(row, col, data);
        return ret;
    }

    Matrix ret;
    ret.setRow(row);
    ret.setCol(col);
    ret.resizeData(ret.getRow() * ret.getCol());

    valarray<int> val;
    val.resize(row * col);

    for(int i=0; i < row * col; i++)
    {
        val[i] = data[i] + mat.getDataElement(i);
    }

    ret.setData(val);
    return ret;
}

void cpyData(valarray<int>& val1, const valarray<int>& val2){
    val1.resize(val2.size());
    for(int i = 0; i < val2.size(); i++){
        val1[i] = val2[i];
    }
}

//Matrix::Matrix(const Matrix& other)
//{
//    //copy ctor
//}
