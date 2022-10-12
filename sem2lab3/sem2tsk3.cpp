/* Выполнил Максим Желнин 0302, формулировка: дано 2 файла, с текстом и с параметрами. Необходимо вставить подстроку
											из файла с параметрами перед последним элементом каждой строки текста */

#include <iostream>
#include <fstream>
#include <iomanip>
#include "functions.h"


using namespace std;
fstream file;
fstream fileOut;


void main() {
	setlocale(0, "");
	fileOut.open("output.txt", ios::out);
	file.open("params.txt", ios::in);
	fileOut << "Выполнил: Желнин Максим\nГруппа 0302\nВерсия 2.0\nФормулировка: Вставить заданное число элементов перед последним элементом каждой строки\n";
	if (paramsErrorsCheck(file) == 1) {
		fileOut << "Ошибка в файле с параметрами";
	}
	else {
		file.close();
		file.open("params.txt", ios::in);
		int paramsLen = paramsLenRead(file);
		file.close();
		file.open("params.txt", ios::in);
		char* params = new char(paramsLen);
		params = paramsRead(file, paramsLen);
		paramsPrint(params, paramsLen, fileOut);
		file.close();
		file.open("params.txt", ios::in);
		file >> setiosflags(ios::skipws);
		int paramsCount;
		file >> paramsCount;
		file.close();
		file.open("input.txt", ios::in);
		if (inputErrorsCheck(file) == 1) {
			fileOut << "Ошибка во входном файле! Файл пуст или есть пустая строка.";
		}
		else {
			file.close();
			file.open("input.txt", ios::in);
			ListCreate(file);
			file.close();
			file.open("input.txt", ios::in);
			goToFirst();
			ListZapoln(file);
			fileOut << "Контрольный вывод текста:\n";
			PrintSpisok(fileOut);
			fileOut << '\n';
			modifySpisok(paramsLen, params, paramsCount);
			fileOut << "Изменённый текст:\n";
			PrintSpisok(fileOut);
			delL();
			delete params;
		}
	}
}
