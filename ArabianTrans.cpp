
/*********************************
*                                *
*      Дата: 09.12.2021г.        *
*         Куликов А.М.           *
*  Название:                     *
*      Перевод арабских чисел    *
*                                *
*********************************/

#include <iostream>
#include <string>

using namespace std;

int from_symbols_to_numbers(char sign) {
    if (sign == 'I') {
        return 1;
    } else if (sign == 'V') {
        return 5;
    } else if (sign == 'X') {
        return 10;
    } else if (sign == 'L') {
        return 50;
    } else if (sign == 'C') {
        return 100;
    } else if (sign == 'D') {
        return 500;
    } else if (sign == 'M') {
        return 1000;
    } else {
        return 0;
    }
}

void inArab(string number)
{
    int symbol_1, symbol_2;
    int counter = 1;
    int sum = 0;

    symbol_1 = from_symbols_to_numbers(number[0]);

    if (number.length() == 1) {
        sum = symbol_1;
    } else {
        do {
            if (symbol_1 == 0) {
                symbol_1 = from_symbols_to_numbers(number[counter]);
            } else {
                symbol_2 = from_symbols_to_numbers(number[counter]);
                if (symbol_1 < symbol_2) {
                    sum += symbol_2 - symbol_1;
                    symbol_1 = 0;
                } else {
                    sum += symbol_1;
                    symbol_1 = symbol_2;
                }                
                symbol_2 = 0;
            }
            ++counter;
        } while (counter < number.length());
        counter = 1;
        if (symbol_2 == 0) {
            sum += symbol_1;
        }
    }

    cout << sum << endl;
}

void inRim(string number) {

    string rimNumber;
    int digit;
    int offset = 0;

    digit = stoi(number);
    
    while (digit != 0) {
        if (digit % 10 == 0) {
            digit /= 10;
            offset += 1;
        } else if ((digit % 10 == 9) and (offset == 0)) {
            rimNumber =  "IX" + rimNumber;
            digit -= 9;
        } else if ((digit % 10 == 4) and (offset == 0)) {
            rimNumber = "IV" + rimNumber;
            digit -= 4;
        } else if ((digit % 10 == 5) and (offset == 0)) {
            rimNumber = "V" + rimNumber;
            digit -= 5;
        } else if ((digit % 10 != 0) and (offset == 0)) {
            rimNumber = "I" + rimNumber;
            digit -= 1;
        } else if ((digit % 10 == 4) and (offset == 1)) {
            rimNumber = "XL" + rimNumber;
            digit -= 4;
        } else if ((digit % 10 == 9) and (offset == 1)) {
            rimNumber = "XC" + rimNumber;
            digit -= 9;
        } else if ((digit % 10 == 5) and (offset == 1)) {
            rimNumber = "L" + rimNumber;
            digit -= 5;
        } else if ((digit % 10 != 0) and (offset == 1)) {
            rimNumber = "X" + rimNumber;
            digit -= 1;
        } else if ((digit % 10 == 4) and (offset == 2)) {
            rimNumber = "CD" + rimNumber;
            digit -= 4;
        } else if ((digit % 10 == 9) and (offset == 2)) {
            rimNumber = "CM" + rimNumber;
            digit -= 9;
        } else if ((digit % 10 == 5) and (offset == 2)) {
            rimNumber = "D" + rimNumber;
            digit -= 5;
        } else if ((digit % 10 != 0) and (offset == 2)) {
            rimNumber = "C" + rimNumber;
            digit -= 1;
        } else if ((digit % 10 != 0) and (offset >= 3)) {
            rimNumber = "M" + rimNumber;
            digit -= 1;
        }
    }

    cout << rimNumber << endl;
}

int main() {

    setlocale(0, "");

    string number;

    while (true) {

        cout << "Введите арабские или римские цифры: ";
        cin >> number;

        if (((int)(number[0]) >= (int)('0')) and ((int)(number[0]) <= (int)('9'))) {
            inRim(number);
        } else {
            inArab(number);
        }
    }
}
