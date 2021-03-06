#include <iostream>   // cout
#include <algorithm>  // copy, fill

#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;

// Задание 1
void swap_args(int *lhs, int *rhs) {
    // напишите код здесь ...
    if ((lhs) && (rhs)) {
        int x = *lhs;
        *lhs = *rhs;
        *rhs = x;
    }
}

// Задание 2
int **allocate_2d_array(int num_rows, int num_cols, int init_value) {
    // напишите код здесь ...
    if ((num_rows < 1) || (num_cols < 1)) {
        return nullptr;
    }
    int **array_2d = new int *[num_rows];
    for (int row_index = 0; row_index < num_rows; ++row_index) {
        array_2d[row_index] = new int[num_cols]{};
        for (int col_index = 0; col_index < num_cols; ++col_index) {
            array_2d[row_index][col_index] = init_value;
        }
    }
    return array_2d;
}

// Задание 3
bool copy_2d_array(int **arr_2d_source, int **arr_2d_target, int num_rows, int num_cols) {
    if ((!arr_2d_source) || (!arr_2d_target) || (num_rows < 1) || (num_cols < 1)) {
        return false;
    }
    for (int row_index = 0; row_index < num_rows; ++row_index) {
        if ((arr_2d_source[row_index]) && (arr_2d_target[row_index])) {
            for (int col_index = 0; col_index < num_cols; ++col_index) {
                arr_2d_target[row_index][col_index] = arr_2d_source[row_index][col_index];
            }
        }
        else {
            return false;
        }
    }
    return true;
}

// Задание 4
void reverse_1d_array(vector<int> &arr) {
    // напишите код здесь ...
    int x = 0;
    for (int i = 0; i < (arr.size()/2); i++) {
        x = arr[arr.size() - i - 1];
        arr[arr.size() - i - 1] = arr[i];
        arr[i] = x;
    }
}

// Задание 5
void reverse_1d_array(int *arr_begin,int *arr_end) {
    // напишите код здесь ...
    if ((arr_end) && (arr_begin))
    {
        for (int i = 0; i < (arr_end - arr_begin + 1)/2; i++)
        {
            swap_args((arr_begin + i), (arr_end - i));
        }
    }
}

// Задание 6
int *find_max_element(int *arr, int size) {
    // напишите код здесь ...
    if ((!arr) || (size <= 0)) return nullptr;
    int max = arr[0];
    int *ptr = &arr[0];
    for (int i = 0; i < size; i++){
        if (arr[i] > max){
            max = arr[i];
            ptr = &arr[i];
        }
    }
    return ptr;
}

// Задание 7
vector<int> find_odd_numbers(vector<int> &arr) {
    // напишите код здесь ...
    vector<int> odd_numbers;
    for (int i = 0; i < arr.size(); i++) {
        if (abs(arr[i]) % 2 == 1) {
            odd_numbers.push_back(arr[i]);
        }
    }
    if (!odd_numbers.empty()) {
        return odd_numbers;
    }
    return {};
}

// Задание 8
vector<int> find_common_elements(vector<int> &arr_a, vector<int> &arr_b) {
    // напишите код здесь ...
    vector<int> common_elements;
    for (int element1 : arr_a) {
        for (int element2 : arr_b) {
            if (element1 == element2) {
                common_elements.push_back(element1);
            }
        }
    }
    if (!common_elements.empty()) {
        return common_elements;
    }

    return {};
}
