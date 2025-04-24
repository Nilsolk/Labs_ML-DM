#include <iostream>
#include <locale.h>
using namespace std;

int** createArray(int N) {
	int** arr = new int* [N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[N];
	}
	return arr;
}

bool validation(int** arr, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] > 1 || arr[i][j] < 0) {
				cout << "Матрица содержит некорректные элементы, введите снова\n";
				return false;
			}
		}
	}

	return true;
}

void printArray(int** arr, int N) {
	cout << "Введенная матрица:\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

}

int getN() {
	cout << "Введите N (размер квадратной матрицы): ";
	int N;
	while (true) {
		cin >> N;
		if (N < 1 || N > 20) cout << "Размер должен быть больше 0 и меньше 20, повторите снова\n";
		else break;
	}
	return N;
}
void addData(int** arr, int N) {
	cout << "Введите значения матрицы (0 и 1):\n";
	do {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int value;
				cin >> value;
				arr[i][j] = value;
			}
		}
	} while (!validation(arr, N));
}


bool getReflection(int** arr, int N) {
	for (int i = 0; i < N; i++) {
		if (arr[i][i] != 1) return false;
	}
	return true;
}

bool getSymmetric(int** arr, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] != arr[j][i])
				return false;
		}
	}
	return true;
}

bool getCosoSymmetric(int** arr, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1 && arr[j][i] == 1 && i != j)
				return false;
		}
	}
	return true;
}

bool getTransitive(int** arr, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (arr[i][j] == 1 && arr[j][k] == 1 && arr[i][k] == 0) {
					return false;
				}
			}
		}
	}
	return true;
}

void checkConditions(int** arr, int N) {
	if (getSymmetric(arr, N)) cout << "Матрица симметрична" << endl;
	else cout << "Матрица несимметрична" << endl;

	if (getReflection(arr, N)) cout << "Матрица рефлективна" << endl;
	else cout << "Матрица нерефлективна" << endl;

	if (getCosoSymmetric(arr, N)) cout << "Матрица кососимметрична (антисимметрична)" << endl;
	else cout << "Матрица некососимметрична (антисимметрична)" << endl;

	if (getTransitive(arr, N)) cout << "Матрица транзитивна" << endl;
	else cout << "Матрица нетранзитивна" << endl;

}

int start_lab2()
{
	int N = getN();
	int** arr = createArray(N);
	addData(arr, N);
	printArray(arr, N);
	checkConditions(arr, N);
}
