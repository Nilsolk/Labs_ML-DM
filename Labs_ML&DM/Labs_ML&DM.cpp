#include <locale.h>
#include <cstdlib> 
#include <iostream>
#include "Lab_1.h"
#include "Lab_2.h"
#include "Lab_3.h"
#include "Lab_4.h"
#include "Lab_5.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Введите номер лабораторной, которую вы хотите открыть"<<
        "\n1 - Операции между множествами\n2 - Свойства отношения\n" <<
        "3 - Является ли отношение функцией\n4 - Кратчайший путь в графе\n"<<
        "5 - Матрица достижимости\n0 - Выход из программы\n"<< endl;
    char n;
    cout << "Введите цифру: ";
    cin >> n;
    switch (n) {
        case '1':
            start_lab1();
            break;
        case '2':
            start_lab2();
            break;
        case '3':
            start_lab3();
            break;
        case '4':
            start_lab4();
            break;
        case '5':
            start_lab5();
            break;
        case 0:
            exit(0);
        default:
            cout << "Неверный ввод, выход из программы\n";
            break;
    }
    return 0;
}
