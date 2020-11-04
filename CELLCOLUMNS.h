#pragma once
#include "CELL.h"
class CELLCOLUMNS {
private:
    int cols_ = 6;
    CELL* data_;
public:
    CELLCOLUMNS()
    {

        cols_ = 6;
        if (cols_ == 0)
        {
            throw exception("Matrix constructor has 0 size");
        }
        data_ = new CELL[cols_];
    }
    int get_cols_() {
        return this->cols_;
    }
    CELL* get_data_() {
        return this->data_;
    }
    CELLCOLUMNS(int rows, int cols)
    {

        cols_ = cols;
        if (cols == 0)
        {
            throw exception("Matrix constructor has 0 size");
        }
        data_ = new CELL[cols];
    }
    ~CELLCOLUMNS()
    {
        delete[] data_;
    }
    CELL& operator[] (int col)
    {
        if (col >= cols_)
            throw exception("Matrix subscript out of bounds");
        return data_[col];
    }
    CELL  operator[] (int col) const
    {
        if (col >= cols_)
            throw exception("const Matrix subscript out of bounds");
        return data_[col];
    }
    CELLCOLUMNS(CELLCOLUMNS& m)
    {
        this->cols_ = m.get_cols_();
        if (this->data_ != NULL) {
            delete[] this->data_;
        }
        this->data_ = new CELL[cols_];
        for (int j = 0; j < cols_; j++)
        {
            this->data_[j] = m.get_data_()[j];
        }

    }
    CELLCOLUMNS& operator= (CELLCOLUMNS& m)
    {
        this->cols_ = m.get_cols_();
        if (this->data_ != NULL) {
            delete[] this->data_;
        }
        this->data_ = new CELL[cols_];
        for (int j = 0; j < cols_; j++)
        {
            this->data_[j] = m.get_data_()[j];
        }
        return *this;
    }
    int get_content_length() { return this->cols_; }
    friend ostream& operator<< (ostream& out, const CELLCOLUMNS& point);
    friend istream& operator>> (istream& out, CELLCOLUMNS& point);
};