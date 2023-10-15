//
//  main.cpp
//  hw30
//
//  Created by Дима on 15.10.23.
//


#include <iostream>
#include <string>

using namespace std;

class ArraySizeException {
public:
    ArraySizeException() = default;
};

class ArrayDataException {
private:
    string message;

public:
    ArrayDataException(int row, int col, const string& reason)
        : message("неверные данные в ячейке [" + to_string(row) + "][" + to_string(col) + "]") {}

    const char* getMessage() const {
        return message.c_str();
    }
};

class ArrayValueCalculator {
public:
    int doCalc(const string array[4][4]) {
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                try {
                    int value = atoi(array[i][j].c_str());
                    sum += value;
                } catch (...) {
                    throw ArrayDataException(i, j, "не удалось конвертировать");
                }
            }
        }
        return sum;
    }
};

int main() {
    ArrayValueCalculator calculator;
    string array[4][4] = {
        {"1", "2", "3", "4"},
        {"5", "6", "7", "8"},
        {"9", "10", "11", "12"},
        {"13", "14", "15", "16"}
    };

    try {
        int result = calculator.doCalc(array);
        cout << "результат расчёта: " << result << endl;
    } catch ( ArraySizeException&) {
        cout << "ошибка размера массива" << endl;
    } catch ( ArrayDataException& e) {
        cout << "ошибка данных в массиве: " << e.getMessage() << endl;
    }

    return 0;
}

