
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
//функция упаковки
void pack(const int* arr, size_t n, unsigned char** packed, size_t* packed_size) {
    uint64_t counts[18] = { 0 };
    for (size_t i = 0; i < n; ++i) {
        counts[arr[i]]++;
    }
    *packed_size = sizeof(counts);
    *packed = new unsigned char[*packed_size];
    memcpy(*packed, counts, *packed_size);
}
//функция расспаковки, восстановление исходного массива
void unpack(const unsigned char* packed, size_t packed_size, int** arr, size_t* n) {
    if (packed_size != 18 * sizeof(uint64_t)) {
        cerr << "Ошибка, неверный размер упакованных данных" << endl;
        return;
    }
    uint64_t counts[18];
    memcpy(counts, packed, packed_size);

    //создаем новый массив
    *n = 0;
    for (int i = 0; i < 18; ++i) {
        *n += counts[i];
    }

    *arr = new int[*n];
    size_t idx = 0;
    for (int val = 0; val < 18; ++val) {
        for (uint64_t cnt = 0; cnt < counts[val]; ++cnt) {
            (*arr)[idx++] = val;
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

    cout << endl << endl;

    bubble_sort(mass, num);

    //вывод
    for (int i = 0; i < num; i++) {
        cout << mass[i] << " ";
    }
    cout << endl;

    //упаковка
    unsigned char* packed_data;
    size_t packed_size;
    pack(mass, num, &packed_data, &packed_size);

    //распаковка
    int* restored;
    size_t restored_n;
    unpack(packed_data, packed_size, &restored, &restored_n);

    //проверка совпадения с исходным массивом
    bool ok = (restored_n == num);
    if (ok) {
        for (size_t i = 0; i < num - i; ++i) {
            if (restored[i] != mass[i]) {
                ok = false;
                break;
            }
        }
    }
    cout << "Восстановление прошло " << ( ok? "успешно" : "неудачно") << endl;

    delete[] mass;
    delete[] packed_data;
    delete[] restored;

    return 0;

}

