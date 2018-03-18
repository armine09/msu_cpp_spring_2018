#include <vector>
#include <iostream>
#include <algorithm>

class Line {
    size_t len_;
    std::vector<int> m;

public:
    Line(int l) : len_(l), m(len_, 0) {}

    Line& operator= (const Line& mt) {
        len_ = mt.len_;
        m = mt.m;
        return *this;
    }

    bool operator== (const Line& mt) const{
        if (mt.len_ != len_) {
            return false;
        }
        for (int i = 0; i < len_; ++i) {
            if (m[i] != mt.m[i]) {
                return false;
            }
        } 
        return true;
    }

    bool operator!= (const Line& mt) const{
        return !operator==(mt);
    }

    int& operator[] (int i) {
        if (i >= len_) {
            throw std::out_of_range("");
        }
        return m[i];
    }

    const int& operator[] (int i) const{        
        if (i >= len_) {
            throw std::out_of_range("");
        }
        return m[i];
    }

    void swap (Line& b) {
        std::swap(len_, b.len_);
        std::swap(m, b.m);
    }
};



class Matrix {
    size_t rows_;
    size_t cols_;
    std::vector<Line> m;

public:
    Matrix(int r, int c) : rows_(r), cols_(c), m(rows_, Line(cols_)) {}

    Matrix& operator= (const Matrix& mt) {
        m = mt.m;
        rows_ = mt.rows_;
        cols_ = mt.cols_;
        return *this;
    }

    Matrix& operator*= (int number) {
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                m[i][j] *= number;
            }
        }
        return *this;
    }

    bool operator== (const Matrix& mt) const{
        if (mt.rows_ != rows_) {
            return false;
        }
        for (int i = 0; i < rows_; ++i) {
            if (m[i] != mt.m[i]) {
                return false;
            }
        } 
        return true;
    }

    bool operator!= (const Matrix& mt) const{
        return !operator==(mt);
    }

    Line& operator[] (int i) {
        if (i >= rows_) {
            throw std::out_of_range("");
        }
        return m[i];
    }

    const Line& operator[] (int i) const {
        if (i >= rows_) {
            throw std::out_of_range("");
        }
        return m[i];
    }

    void swap (Matrix& b) {
        std::swap(rows_, b.rows_);
        std::swap(cols_, b.cols_);
        std::swap(m, b.m);
    }

    unsigned getRows() const{
        return cols_;
    }
    unsigned getColumns() const{
        return rows_;
    }
};
