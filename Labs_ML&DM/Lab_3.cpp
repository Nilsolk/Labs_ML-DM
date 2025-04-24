#include <iostream>
#include <set>
using namespace std;

void add_values(int size, set<char>* set) {
    cout << "Введите элемнты множества: ";
    for (int i = 0; i < size; i++) {
        char elem;
        cin >> elem;
        set->insert(elem);
    }
}
void output_set(set<char> set) {
    cout << "{ ";
    for (char elem : set) {
        cout << elem << " ";
    }
    cout << "}" << endl;
}
void output_relation_pairs(int size, char** rel_pairs) {
    for (int i = 0; i < size; i++) {
        int k = 0;
        cout << "(" << rel_pairs[i][k] << "," << rel_pairs[i][k + 1] << ")";
    }
    cout << endl;
}

char** enter_relation(int size) {
    char** arr = new char* [size];
    for (int i = 0; i < size; i++) {
        arr[i] = new char[2];
    }
    return arr;
    cout << endl;
}
void add_relation_pairs(int size, char** arr) {
    cout << "Введите пары элементов (элементы вводятся через пробел): ";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 2; j++) {
            char elem;
            cin >> elem;
            arr[i][j] = elem;
        }
    }
    cout << endl;
}

bool is_func(set<char> set_1, set<char> set_2, char** pairs, int size) {
    set<char> seen_elements;
    for (int i = 0; i < size; i++) {
        char first_pair_elem = pairs[i][0];
        char second_pair_elem = pairs[i][1];
        if (seen_elements.find(first_pair_elem) != seen_elements.end()) {
            return false;

        }
        else {
            if (set_1.find(first_pair_elem) == set_1.end() ||
                set_2.find(second_pair_elem) == set_2.end()
                ) return false;
            else seen_elements.insert(first_pair_elem);
        }
    }

    for (char elem : set_1) {
        if (seen_elements.find(elem) == seen_elements.end()) {
            return false;
        }
    }

    return true;
}


void start_lab3()
{
    set<char> first_set, second_set;
    int first_set_size, second_set_size, relation_size;

    cout << "Введите кол-во элементов в первом множестве: ";
    cin >> first_set_size;
    add_values(first_set_size, &first_set);

    cout << "Введите кол-во элементов во втором множестве: ";
    cin >> second_set_size;
    add_values(second_set_size, &second_set);


    cout << "Введите количестов пар элементов отношения: ";
    int size;
    cin >> size;
    char** pairs = enter_relation(size);
    add_relation_pairs(size, pairs);

    output_set(first_set);
    output_set(second_set);
    output_relation_pairs(size, pairs);

    if (is_func(first_set, second_set, pairs, size)) cout << endl << "Является функцией";
    else cout << "Не является функцией";
}

