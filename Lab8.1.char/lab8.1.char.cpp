#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// Функція підрахунку кількості входжень підрядка "abc"
int Count(char* s) {
    int k = 0;
    int pos = 0; // початкова позиція пошуку
    char* t;

    while ((t = strstr(s + pos, "abc")) != nullptr) { // Шукаємо підрядок "abc"
        k++;
        pos = t - s + 1; // Оновлюємо позицію пошуку
    }

    return k;
}

// Функція заміни підрядка "abc" на "****"
char* Change(char* s) {
    char* t = new char[strlen(s) * 2 + 1]; // Виділяємо пам'ять для нової строки
    char* p;
    int pos1 = 0, pos2 = 0;
    *t = 0; // Починаємо з порожньої строки

    while ((p = strstr(s + pos1, "abc")) != nullptr) { // Шукаємо підрядок "abc"
        pos2 = p - s; // позиція початку "abc"
        strncat(t, s + pos1, pos2 - pos1); // Копіюємо частину строки до "abc"
        strcat(t, "****"); // Замінюємо "abc" на "****"
        pos1 = pos2 + 3; // Просуваємося на довжину "abc"
    }

    strcat(t, s + pos1); // Копіюємо залишок строки
    strcpy(s, t); // Копіюємо результат назад в початкову строку
    return t;
}

int main() {
    char str[101];
    cout << "Enter:" << endl;
    cin.getline(str, 100);

    cout << "HAVE " << Count(str) << "  'abc'" << endl;

    char* dest = Change(str);

    cout << "first : " << str << endl;
    cout << "results: " << dest << endl;

    delete[] dest; // Звільняємо пам'ять
    return 0;
}
