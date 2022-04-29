#include <iostream>
using namespace std;

int main()
{
    int size = 5;
    int** array = new int* [size]; //выделение памяти для указателей
    for (int i = 0; i < size; i++){
        array[i] = new int[size]; // выделение памяти для каждого элемента строки матрицы
    }

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            array[i][j] = 10 + rand() % 90; // заполнение числами от 10 до 99
            cout << array[i][j] << "  ";
        }
        cout << endl;
    }
    int max = 0;
    int buf = 0; // буфер для перестановки местами значений
    int x = 0; // номер строки с макс. значением
    int y = 0; // столбец с макс. значением

    for (int i = 0; i < size; i++){
        max = array[i][0];
        for (int j = 1; j < size; j++){
            if (array[i][j] > max){
                max = array[i][j];
                x = i;
                y = j;	// пузырек
            }
        }
        // замена максимума с первым элементом в строке
        if (array[i][0] < max){
            buf = array[i][0];
            array[i][0] = max;
            array[x][y] = buf;
        }
    }

    cout << "Matrix after permutation of the maximum values in the row: "<< endl;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout << array[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl << endl;

    // освобождение памяти
    for (int i = 0; i < size; i++){delete[] array[i];}
    delete[] array; // память под указатели на строки матрицы
    return 0;
}