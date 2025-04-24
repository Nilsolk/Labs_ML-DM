#include <iostream>
using namespace std;

bool validation(int** arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] != 0 && arr[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}

int** init_arr(int n) {
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n]();
    }
    return arr;
}

int** get_arr(int n) {
    int** arr = init_arr(n);

    cout << "Введите матрицу смежности (размер " << n << "x" << n << "):" << endl;
    while (true) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        if (validation(arr, n)) {
            break;
        }
        else {
            cout << "Ошибка: матрица должна содержать только 0 и 1. Повторите ввод:" << endl;
        }
    }
    return arr;
}

int** multiple_arr(int** arr_1, int** arr_2, int n) {
    int** result = init_arr(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] = result[i][j] || (arr_1[i][k] && arr_2[k][j]);
            }
        }
    }
    return result;
}

int** get_sum_arr(int** arr_1, int** arr_2, int n) {
    int** result = init_arr(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = arr_1[i][j] || arr_2[i][j];
        }
    }
    return result;
}

int** get_identity_arr(int n) {
    int** arr = init_arr(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = (i == j) ? 1 : 0;
        }
    }
    return arr;
}

void print_arr(int** arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void free_matrix(int** arr, int n) {
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}


int** copy_arr(int** arr, int n) {
    int** copy_arr = init_arr(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            copy_arr[i][j] = arr[i][j];
        }
    }
    return copy_arr;
}

int** get_reachability_arr(int** adj_matrix, int n) {
    int** reachability = get_identity_arr(n);
    int** current_power = copy_arr(adj_matrix, n);

    for (int i = 1; i < n; i++) {
        int** new_reachability = get_sum_arr(reachability, current_power, n);
        free_matrix(reachability, n);
        reachability = new_reachability;

        if (i < n - 1) {
            int** next_power = multiple_arr(current_power, adj_matrix, n);
            free_matrix(current_power, n);
            current_power = next_power;
        }
    }
    free_matrix(current_power, n);

    return reachability;
}
void start_lab5() {
    int n;
    cout << "Введите количество вершин в графе: ";
    cin >> n;

    int** adj_matrix = get_arr(n);

    cout << "\nМатрица смежности:" << endl;
    print_arr(adj_matrix, n);

    int** reachability = get_reachability_arr(adj_matrix, n);

    cout << "\nМатрица достижимости:" << endl;
    print_arr(reachability, n);

    free_matrix(adj_matrix, n);
    free_matrix(reachability, n);
}
