#include <iostream>
#include <iomanip>
#include <fstream>
#include "functions.h"

using namespace std;
fstream fileInput1;
fstream fileInput2;
fstream fileInput3;
fstream fileOut;


void main() {
	setlocale(0, "");
	fileInput1.open("input1.txt", ios::in);
	fileInput2.open("input2.txt", ios::in);
	fileInput3.open("input3.txt", ios::in);
	fileOut.open("output.txt", ios::out);
	if (fileInput1.bad() || fileInput2.bad() || fileInput3.bad()) { fileOut << "Проблемы при открытии файла."; }
	else {
		bool res;
		OneElem(1);
		OneElem(2);
		OneElem(3);
		listFromFile(1, fileInput1);
		listFromFile(2, fileInput2);
		listFromFile(3, fileInput3);
		fileOut << "Список 1\n";
		PrintElem(1, fileOut);
		fileOut << "Список 2\n";
		PrintElem(2, fileOut);
		fileOut << "Список 3\n";
		PrintElem(3, fileOut);
		simSub(fileOut);
		fileOut << "Симметрическая разность:\n";
		PrintElem(1, fileOut);
		PrintElem(2, fileOut);

		if (voidListCheck(1) != 1 || voidListCheck(2) != 1) {
			res = checkPrin();
			if (res == 0) {
				fileOut << "Не принадлежит";
			}
			else {
				fileOut << "Принадлежит";
			}
		}
		else {
			fileOut << "Не принадлежит";
		}

		delL2Cup(1);
		delL2Cup(2);
		delL2Cup(3);
	}
}