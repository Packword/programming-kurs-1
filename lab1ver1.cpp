/* Желнин Максим Юрьевич
формулировка: Посчитать полиндром
   */

#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	double x, p,p1,p2, p3, q, q1, q2, q3;
	cout << "Автор: Желнин Максим Юрьевич, группа 0302\n" << "Даты: Начало: 23.09; Конец: 23.09\n" << "Версия 1.0\n" << "Формулировка: посчитать полиномы и поделить один на другой\n" << "Введите х :=";
	cin >> x;
	p = 0.19 * x * x + 5.12;
	cout << "Шаг 1: P = " << setw(10) << setprecision(10) << p << "\n";
	p1 = x * p + 6.98;
	cout << "Шаг 2: P = " << setw(10) << setprecision(10) << p1 << "\n";
	p2 = x * x * x * x * x * p1;
	cout << "Для x = " << setw(5) << setprecision(10) << x << " P = " << setw(10) << setprecision(10) << p2 << "\n";
	q = 467 * x * x * x * x - 748392;
	cout << "Шаг 1: Q = " << setw(10) << setprecision(10) << q << "\n";
	q1 = x * x * x * x * x * x * x * x * x * q + 0.00006;
	cout << "Шаг 2: Q = " << setw(20) << setprecision(10) << q1 << "\n";
	q2 = x * x * x * x * x * q1;
	cout << "Для x = " << setw(5) << setprecision(10) << x << " Q = " << setw(20) << setprecision(100) << q2 << "\n";
	cout << "P/Q = " << setw(20) << setprecision(3) << p2 / q2;
	cin.get();
}
