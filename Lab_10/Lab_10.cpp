
#include <iostream>
#include <ctime>
using namespace std;
//сортировка пузырьком
void bubble_sort(int mass[], int num) {
    int smena_znach;
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (mass[j] > mass[j + 1]) {
                smena_znach = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = smena_znach;
            }

        }
    }

}
int main()
{
    setlocale(LC_ALL, "RU");
    int num;
    cout << "Введите размер массива ( >> 1000 ): ";
    cin >> num;
    cout << endl;

    //выделение памяти
    int* mass = new int[num];

    srand(time(nullptr));

     
    //заполнение случайными числами от 0 до 17
    for (int i = 0; i < num; i++) {
        mass[i] = rand() % 18;
        cout << mass[i] << " ";
    }

    cout << endl;
    cout << endl;

    bubble_sort(mass, num);

    //вывод
    for (int i = 0; i < num; i++) {
        cout << mass[i] << " ";
    }
    cout << endl;
    delete[] mass;
    return 0;

}

