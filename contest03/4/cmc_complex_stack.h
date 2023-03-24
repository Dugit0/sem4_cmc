//
// Created by dmitry on 3/22/23.
//

#ifndef CODE_CMC_COMPLEX_STACK_H
#define CODE_CMC_COMPLEX_STACK_H

#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <map>
#include <functional>
#include <new>
#include "cmc_complex.h"


namespace numbers
{
    class complex_stack
    {
        complex *_data;
        size_t _size;
    public:
        complex_stack()
        {
            _data = nullptr;
            _size = 0;
        }

        complex_stack(size_t size)
        {
            _data = new complex[size];
            _size = size;
        }

        complex_stack(const complex_stack &other)
        {
            _data = new complex[other.size()];
            _size = other.size();
            for (size_t i = 0; i < other.size(); i++) {
                _data[i] = other[i];
            }
        }

        complex_stack(complex_stack &&other) noexcept
        {
            _data = other._data;
            _size = other._size;
            other._data = nullptr;
            other._size = 0;
        }

        ~complex_stack()
        {
            delete[] _data;
        }

        size_t
        size() const
        {
            return _size;
        }

        complex
        operator[](size_t ind) const
        {
            return _data[ind];
        }

        complex_stack &
        operator=(const complex_stack &other)
        {
            if (this != &other) {
                delete[] _data;
                _data = new complex[other.size()];
                _size = other.size();
                for (size_t i = 0; i < other.size(); i++) {
                    _data[i] = other[i];
                }
            }
            return *this;
        }

        complex_stack
        operator<<(complex right) const
        {
            complex_stack ret(this->size() + 1);
            for (size_t i = 0; i < this->size(); i++) {
                ret._data[i] = this->_data[i];
            }
            ret._data[this->size()] = right;
            return ret;
        }

        complex
        operator+() const
        {
            return _data[_size - 1];
        }

        complex_stack
        operator~() const
        {
            complex_stack ret(this->size() - 1);
            for (size_t i = 0; i < this->size() - 1; i++) {
                ret._data[i] = this->_data[i];
            }
            return ret;
        }
    };
}
#endif //CODE_CMC_COMPLEX_STACK_H
