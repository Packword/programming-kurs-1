/*
Максим желнин 0302 Определить, принадлежит ли точка функции, по заданным координатам и параметрам функции
*/

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	float a, x, y, xreal, xprom;
	cout << "Автор: Желнин Максим Юрьевич, группа 0302\n" << "Даты: Начало: 23.09; Конец: 23.09\n" << "Версия 1.0\n" << "Формулировка: Определить, принадлежит ли точка замкнутой области ограниченной функцией, по заданным координатам и параметрам функции \n";
	cout << "   a    -----               \n";
	cout << "   |  --     --              \n";
	cout << "   | |         |              \n";
	cout << "___0|_____a_____|_________________________ \n";
	cout << "                 -       -     \n";
	cout << "                  -     -     \n";
	cout << "                    ---      \n";
	cout << "Введите a:\n";
	cin >> a;
	cout << "Введите x:\n";
	cin >> x;
	cout << "Введите y:\n";
	cin >> y;
	if (a == 0 && (x != 0 || y != 0)) {
		cout << "Точка с координатами (" << setw(10) << setprecision(10) << x << ";" << setw(10) << setprecision(10) << y << ") не принадлежит данной функции.";
	}
	else {
		if (a == 0) {
			cout << "Точка с координатами (" << setw(10) << setprecision(10) << x << ";" << setw(10) << setprecision(10) << y << ") принадлежит данной функции.";
		}
		else {
			if (fabs(y) > fabs(a)) {
				cout << "Точка с координатами (" << setw(10) << setprecision(10) << x << ";" << setw(10) << setprecision(10) << y << ") не принадлежит данной функции.";
			}
			else {
				if ((a > 0 && x < 0) || (a < 0 && x > 0)) {
					cout << "Точка с координатами (" << setw(10) << setprecision(10) << x << ";" << setw(10) << setprecision(10) << y << ") не принадлежит данной функции.";
				}
				else{
					xprom = fabs(x) / (3 * fabs(a));
					xprom = truncf(xprom);
					xreal = fabs(x) - xprom * (3 * fabs(a));
					if (x < 0) {
						xreal = xreal * (-1);
					}
					if (((a < 0) && (((y >= ((-1) * sqrt(a * a - (xreal + fabs(a)) * (xreal + fabs(a))))) && (y <= 0) && (xreal >= 2*a)) || ((y <= sqrt((a / 2) * (a / 2) - (xreal + 2, 5 * fabs(a)) * (xreal + 2.5 * fabs(a)))) && (y >= 0) && (xreal <= 2*a)))) || ((a > 0) && (((y >= 0) && (xreal <= 2*a) && (y <= (sqrt(a * a - (xreal - fabs(a)) * (xreal - fabs(a)))))) || ((xreal >= 2*a) && (y <= 0) && (y >= (-1) * sqrt((a / 2) * (a / 2) - (xreal - 2, 5 * fabs(a)) * (xreal - 2.5 * fabs(a)))))))) {
						cout << "Точка с координатами (" << setw(10) << setprecision(10) << x << ";" << setw(10) << setprecision(10) << y << ") принадлежит данной функции.";
					}
					else {
						cout << "Точка с координатами (" << setw(10) << setprecision(10) << x << ";" << setw(10) << setprecision(10) << y << ") не принадлежит данной функции.";
					}
				}
			}
		}
	}
	cin.get();
}
