#include <iostream>

constexpr size_t MATRIX_SIZE = 3;
using std::cout;

class Matrix
{
    int _arr[MATRIX_SIZE][MATRIX_SIZE];
public:
    Matrix()
    {
        for (auto &row : _arr) {
            for (auto &cell : row) {
                cell = 0;
            }
        }
    }
    int &operator[](size_t i, size_t j) {
        return _arr[i][j];
    }
    auto begin()
    {
        return &_arr[0];
    }
    auto end()
    {
        return &_arr[MATRIX_SIZE];
    }
};


//int main() {
//    Matrix m;
//    m[1, 1] = 5;
//
//    for (const auto &row : m) {
//        for (auto cell : row) {
//            cout << cell << " ";
//        }
//        cout << "\n";
//    }
//}


