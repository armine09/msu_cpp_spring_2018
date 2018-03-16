#include <vector>
#include <iostream>

#define check(cond) do { if (!(cond)) std::cout << "line " << __LINE__ << ": " << #cond << '\n'; } while(0)
#define check_throw(expr, err) do { try { expr; } catch (const err&) { break ; } catch (...) { } std::cout << "line " << __LINE__ << '\n'; } while(0)


class Line {
    size_t len_;
    std::vector<int> m;
    void swap (Line& b) {
        std::swap(len_, b.len_);
        std::swap(m, b.m);
    }
public:
    Line (int l) : len_(l) {
        m = std::vector<int> (len_, 0);
    }

    Line& operator= (Line mt) {
        mt.swap(*this);
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
        return !(mt == *this);
    }

    int& operator[] (int i) {
        if (i >= len_) {
            throw std::out_of_range("");
        }
        return m[i];
    }
};



class Matrix {
    size_t rows_;
    size_t cols_;
    std::vector<Line> m;
    void swap (Matrix& b) {
        std::swap(rows_, b.rows_);
        std::swap(cols_, b.cols_);
        std::swap(m, b.m);
    }
public:
    Matrix (int r, int c) : rows_(r), cols_(c) {
        m = std::vector<Line> (rows_, Line(cols_));
    }

    Matrix& operator= (Matrix mt) {
        mt.swap(*this);
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
        return !(mt == *this);
    }

    Line& operator[] (int i) {
        if (i >= rows_) {
            throw std::out_of_range("");
        }
        return m[i];
    }

    unsigned getRows() const{
        return cols_;
    }
    unsigned getColumns() const{
        return rows_;
    }
};