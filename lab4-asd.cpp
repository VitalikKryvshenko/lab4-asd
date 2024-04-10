#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int k = 1;

int sum_n(int n) {
    if (n == 0)
        return 0;
    return n % 10 + sum_n(n / 10);
}

void tail_r_arithmetic(int* mas, int n, int a, int d, int ind) {
    if (ind == n)
        return;
    mas[ind] = mas[ind - 1] + d;
    tail_r_arithmetic(mas, n, a, d, ind + 1);
}

void linear_r_arithmetic(int* mas, int n, int a, int d, int k) {
    if (k > 1) {
        k--;
        linear_r_arithmetic(mas, n, a, d, k);
    }
    mas[k] = a + (k - 1) * d;
}

void tail_r_geometric(int* mas, int n, int a, int r, int ind) {
    if (ind == n)
        return;
    mas[ind] = mas[ind - 1] * r;
    tail_r_geometric(mas, n, a, r, ind + 1);
}

void linear_r_geometric(int* mas, int n, int a, int r, int k) {
    if (k > 1) {
        k--;
        linear_r_geometric(mas, n, a, r, k);
    }
    mas[k] = a * pow(r, k - 1);
}

void print(int* mas, int n) {
    for (int i = 0; i < n; i++)
        cout << mas[i] << " ";
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Ukr");
    cout << "�������� 1: �������� ����������� �������i� �� ��������� ������i�" << endl;
    int b, n, ind = 1;
    int mas[100];

    cout << "����i�� ����i� ������: ";
    cin >> n;
    cout << "����i�� ������ ���� ������ (�i�� �����): ";
    cin >> mas[0];
    cout << "����i�� �i����� ����������� �������i�: ";
    cin >> b;
    tail_r_arithmetic(mas, n, mas[0], b, ind);
    cout << "����������� �������i� �� ��������� ������i��:" << endl;
    print(mas, n);

    for (int i = 1; i < n; i++)
        mas[i] = 0;
    k = n;
    linear_r_arithmetic(mas, n, mas[0], b, k);
    cout << "����������� �������i� �� �i�i���� ������i��:" << endl;
    print(mas, n);

    cout << endl;
    cout << "�������� 2: ������ ���� ���� �������� ������������ �����." << endl;
    int r;
    cout << "����i�� �����: ";
    cin >> r;
    cout << "���� ���� �����: " << sum_n(r) << endl;

    system("pause");
    return 0;
}