/* Желнин Максим Юрьевич
формулировка: Посчитать полиндром
   */

#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	float x;
	double p, q;
	printf("%s%s%s%s%s", "Автор: Желнин Максим Юрьевич, группа 0302\n", "Даты: Начало: 23.09; Конец: 23.09\n", "Версия 1.0\n", "Формулировка: посчитать полиномы и поделить один на другой\n", "Введите х :=");
	scanf_s("%f", &x);
	p = 0.19 * x * x + 5.12;
	printf("%s%10.10lf%s", "Шаг 1: P = ", p, "\n");
	p = x * p + 6.98;
	printf("%s%10.10lf%s", "Шаг 2: P = ", p, "\n");
	p = x * x * x * x * x * p;
	printf("%s%10.10lf%s%10.10f%s", "Для x = ", x, " P = ", p, "\n");
	q = 467 * x * x * x * x - 748392;
	printf("%s%10.20lf%s", "Шаг 1: Q = ", q, "\n");
	q = x * x * x * x * x * x * x * x * x * q + 0.00006;
	printf("%s%10.20lf%s", "Шаг 2: Q = ", q, "\n");
	q = x * x * x * x * x * q;
	printf("%s%10.20f%s%10.20lf%s", "Для x = ", x, " Q = ", q, "\n");
	printf("%s%10.20f", "P/Q = ", p / q);
	cin.get();
}