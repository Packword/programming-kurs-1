#include <iostream>
#include <fstream>
#include <iomanip>

#include "functions.h";

using namespace std;
fstream file;

extern int progress[30];

void main() {
	setlocale(0, "");
	int total = 0;
	file.open("output.txt", ios::out);
	file << " Выполнил Желнин Максим 0302, Версия 1.0. \n Формулировка: Дан текстовый файл, содержайщий 30 строк, в каждой из которых по 66 символов. Необходимо посчитать количество строк, начинающихся с группы пробелов, за которыми следует знак  - \n";
	cout << " Выполнил Желнин Максим 0302, Версия 1.0. \n Формулировка: Дан текстовый файл, содержайщий 30 строк, в каждой из которых по 66 символов. Необходимо посчитать количество строк, начинающихся с группы пробелов, за которыми следует знак  - \n";
	file.close();
	file.open("input.txt", ios::in);
	if (file.bad() != 0) {
		file.close();
		file.open("output.txt", ios::app);
		cout << "Ошибка при открытии файла для ввода"; 
		file << "Ошибка при открытии файла для ввода"; 
		file.close();
	}
	else {
		file.close();
		file.open("input.txt", ios::in);
		if (errorsCheck(file) == 1) {
			file.close();
			file.open("output.txt", ios::app); 
			cout << "неверный формат данных"; 
			file << "неверный формат данных"; 
			file.close();
		}
		else {
			file.close();
			for (int i = 0; i < 30; i++) {
				progress[i] = 0;
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					file.open("input.txt", ios::in);
					stringStr blok = setStruct(file, i, j);
					file.close();
					file.open("output.txt", ios::app);
					cout << '\n' << "Блок с координатами: " << i + 1 << " " << j + 1<< '\n';
					file << '\n' << "Блок с координатами: " << i + 1 << " " << j + 1<< '\n';
					outPutBlok(file, blok);
					total += procBlok(blok, i, j);
					file.close();
				}
			}
			file.open("output.txt", ios::app);
			file << '\n' << "Количество подходящих строк: " << total;
			cout << '\n' << "Количество подходящих строк: " << total;
			file.close();
		}
	}
}
