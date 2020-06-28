#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <conio.h>

using namespace std;

void initialData(long *&Mas1, long *&Mas2, const long len) {

    //освобождаем память
    if (Mas1 != NULL) delete Mas1;
    if (Mas2 != NULL) delete Mas2;

    //задаём новыемассивы
    Mas1 = new long[len];
    Mas2 = new long[len];

    //заполняем массивы случайными значениями
    for (long i = 0;i < len;i++) {
        Mas1[i] = rand();
        Mas2[i] = Mas1[i];
    }
}

//Пузырьковая сортировка
void bubble(long *Mas, long len) {
    long time1 = clock();   //первоначальный замер времени

    //пузырьковая сортировка
    for (long i = 0;i < len - 1;i++) {
        bool transposition = false;
        for (long j = 0;j < len - i - 1;j++) {
            if (Mas[j] > Mas[j + 1]) {
                long tmp = Mas[j];
                Mas[j] = Mas[j + 1];
                Mas[j + 1] = tmp;
                transposition = true;
            }
        }
        if (!transposition) break;
    }

    long time2 = clock();   //конечный замер времени
    //выводим вычисленное время работы алгоритма
    cout << "Bubble runtime: " << (time2 - time1) / 1000.0 << "sec" << endl;
}

//сортировка Шелла
void Shell (long *Mas, long len) {
    long time1 = clock();   //первоначальный замер времени

    //сортировка методом Шелла
    for (long step = len / 2;step > 0;step /= 2) {
        for (long i = step;i < len;i++) {
            for (long j = i - step;j >= 0 && Mas[j] > Mas[j + step];j -= step) {
                long tmp = Mas[j + step];
                Mas[j + step]  = Mas[j];
                Mas[j] = tmp;
            }
        }
    }

    long time2 = clock();   //конечный замер времени
    //выводим вычисленное время работы алгоритма
    cout << "Shell runtime: " << (time2 - time1) / 1000.0 << "sec" << endl;
}

int main()
{
    long *Mas1 = NULL, *Mas2 = NULL;

    //10 тестов
    for (int i = 0;i < 4;i++) {

        //70000 - 100000
        cout << "Test (N=" << 70000 + 10000 * i << "):" << endl;
        initialData(Mas1, Mas2, 70000 + 10000 * i);   //инициализация начальных данных
        bubble(Mas1, 70000 + 10000 * i);              //алгоритм пузырьковой сортировки
        Shell(Mas2, 70000 + 10000 * i);               //алгоритм сортировки Шелла
        cout << endl;
    }

    cout << "Press any key to exit";
    getch();
    return 0;
}
