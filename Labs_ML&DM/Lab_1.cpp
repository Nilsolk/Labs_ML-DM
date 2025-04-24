#include <iostream>
#include <stdio.h>
#include <vector>
#include <ctype.h>
using namespace std;
struct Element {
    int i_1;
    int j;
    char b;
    int i_2;
};

bool validation(char i_1, char j, char b, char i_2) {
    bool first_elem = isdigit(i_1) && (int)i_1 % 2 == 0;
    bool second_elem = isdigit(j) && (int)j % 2 == 1;
    bool third_elem = isalpha(b);
    bool fourth_elem = isdigit(i_2) && (int)i_2 % 2 == 0;
    return first_elem and second_elem and third_elem and fourth_elem;
}
bool isDublicate(vector<Element> set, int i_1, int j, char b, int i_2) {
    for (Element elem : set) {
        if (elem.i_1 == i_1 && elem.j == j && elem.b == b && elem.i_2 == i_2) {
            return false;
        }
    }
    return true;
}

vector<Element> removeDublicates(vector<Element>& set) {
    vector<Element> uniqueSet;
    for (const auto& elem : set) {
        bool found = false;
        for (const auto& uniqueElem : uniqueSet) {
            if (uniqueElem.i_1 == elem.i_1 &&
                uniqueElem.j == elem.j &&
                uniqueElem.b == elem.b &&
                uniqueElem.i_2 == elem.i_2) {
                found = true;
                break;
            }
        }
        if (!found) {
            uniqueSet.push_back(elem);
        }
    }
    return uniqueSet;
}

void inputElements(vector<Element>& set) {
    int count;
    cout << "Введите кол-во элемнтов множества\n";
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        char i_1 = '0';
        char j = '0';
        char b = '0';
        char i_2 = '0';
        do {
            cout << "Введите четная цифра ";
            cin >> i_1;
            cout << "Введите нечетная цифра ";
            cin >> j;
            cout << "Введите букву ";
            cin >> b;
            cout << "Введите четная цифра ";
            cin >> i_2;
            if (!validation(i_1, j, b, i_2)) cout << "Ошибка ввода какого-либо элемента, повторите снова\n";
            if (!isDublicate(set, i_1 - '0', j - '0', b, i_2 - '0')) cout << "Элемент уже существет, повторите снова\n";

        } while (!validation(i_1, j, b, i_2) ||
            !isDublicate(set, i_1 - '0', j - '0', b, i_2 - '0'));
        Element newElem = Element();
        newElem.i_1 = i_1 - '0';
        newElem.j = j - '0';
        newElem.b = b;
        newElem.i_2 = i_2 - '0';
        set.push_back(newElem);
        cout << "Элемент загружен\n\n_____________\n";
    }

}
void get_vectorValues(vector<Element> set) {
    cout << "{";
    for (Element elem : set) {
        cout << elem.i_1 << elem.j << elem.b << elem.i_2 << " ";
    }
    cout << "}";
    cout << endl;
}

void getUnion(vector<Element> set_1, vector<Element> set_2) {
    cout << "Объединение: ";
    set_1.insert(set_1.end(), set_2.begin(), set_2.end());

    set_1 = removeDublicates(set_1);
    get_vectorValues(set_1);
}

void getIntersection(vector<Element> set_1, vector<Element> set_2) {
    cout << "Персечение: ";
    vector <Element> tmpVector;
    for (Element elem1 : set_1) {
        for (Element elem2 : set_2) {
            if (elem1.i_1 == elem2.i_1 &&
                elem1.i_2 == elem2.i_2 &&
                elem1.j == elem2.j &&
                elem1.b == elem2.b)
            {
                tmpVector.push_back(elem1);
            }
        }
    }
    tmpVector = removeDublicates(tmpVector);
    get_vectorValues(tmpVector);
}
vector <Element> additionAB(vector<Element> set_1, vector<Element> set_2) {
    vector<Element> tmpVector;
    for (Element elem1 : set_1) {
        bool found = false;
        for (Element elem2 : set_2) {
            if (elem1.i_1 == elem2.i_1 &&
                elem1.i_2 == elem2.i_2 &&
                elem1.j == elem2.j &&
                elem1.b == elem2.b)
            {
                found = true;
                break;
            }
        }
        if (!found) {
            tmpVector.push_back(elem1);
        }
    }
    tmpVector = removeDublicates(tmpVector);
    return tmpVector;
}

vector <Element> additionBA(vector<Element> set_1, vector<Element> set_2) {
    vector<Element> tmpVector;
    for (Element elem2 : set_2) {
        bool found = false;
        for (Element elem1 : set_1) {
            if (elem1.i_1 == elem2.i_1 &&
                elem1.i_2 == elem2.i_2 &&
                elem1.j == elem2.j &&
                elem1.b == elem2.b)
            {
                found = true;
                break;
            }
        }
        if (!found) {
            tmpVector.push_back(elem2);
        }
    }
    tmpVector = removeDublicates(tmpVector);
    return tmpVector;
}

void symmDiff(vector<Element> set_1, vector<Element> set_2) {
    cout << "Симметрическая разность: ";
    vector<Element> abVector = additionAB(set_1, set_2);
    vector<Element> baVector = additionBA(set_1, set_2);
    abVector.insert(abVector.end(), baVector.begin(), baVector.end());
    get_vectorValues(abVector);
}

void start_lab1()
{
    vector <Element> first_set;
    vector <Element> second_set;
    inputElements(first_set);
    inputElements(second_set);
    getUnion(first_set, second_set);
    getIntersection(first_set, second_set);
    cout << "Дополнение A/B: ";
    get_vectorValues(additionAB(first_set, second_set));
    cout << "Дополнение B/A: ";
    get_vectorValues(additionBA(first_set, second_set));
    symmDiff(first_set, second_set);
}
