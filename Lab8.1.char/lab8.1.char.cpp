#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// ������� ��������� ������� �������� ������� "abc"
int Count(char* s) {
    int k = 0;
    int pos = 0; // ��������� ������� ������
    char* t;

    while ((t = strstr(s + pos, "abc")) != nullptr) { // ������ ������� "abc"
        k++;
        pos = t - s + 1; // ��������� ������� ������
    }

    return k;
}

// ������� ����� ������� "abc" �� "****"
char* Change(char* s) {
    char* t = new char[strlen(s) * 2 + 1]; // �������� ���'��� ��� ���� ������
    char* p;
    int pos1 = 0, pos2 = 0;
    *t = 0; // �������� � �������� ������

    while ((p = strstr(s + pos1, "abc")) != nullptr) { // ������ ������� "abc"
        pos2 = p - s; // ������� ������� "abc"
        strncat(t, s + pos1, pos2 - pos1); // ������� ������� ������ �� "abc"
        strcat(t, "****"); // �������� "abc" �� "****"
        pos1 = pos2 + 3; // ����������� �� ������� "abc"
    }

    strcat(t, s + pos1); // ������� ������� ������
    strcpy(s, t); // ������� ��������� ����� � ��������� ������
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

    delete[] dest; // ��������� ���'���
    return 0;
}
