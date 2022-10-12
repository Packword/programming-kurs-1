#include <iostream>
#include <iomanip>
#include <fstream>
#include "functions.h"


using namespace std;
fstream fileInput;
fstream fileOperations;
fstream fileOut;
fstream fileProtocol;

extern int countL;
extern int totalCount;

extern L2Cup* head, * cur, * last;


int main() 
{
	setlocale(0, "");
	fileInput.open("input.txt", ios::in);
	fileOperations.open("operations.txt", ios::in);
	fileOut.open("output.txt", ios::out);
	fileProtocol.open("protocol.txt", ios::out);
	fileOut << "Курсовая работа за второй семестр \nВыполнил Желнин Максим, группа 0302 \nФормулировка задания: реализовать при помощи списков арифметику длинных чисел для целочисленного типа, включая следующие операции: сравнение, сложение, вычетание, умножение, div, mod, НОД, возведение в степень \n";
	fileProtocol << "Курсовая работа за второй семестр \nВыполнил Желнин Максим, группа 0302 \nФормулировка задания: реализовать при помощи списков арифметику длинных чисел для целочисленного типа, включая следующие операции: сравнение, сложение, вычетание, умножение, div, mod, НОД, возведение в степень \n";
	if (fileInput.bad() || fileOperations.bad()) { fileOut << "Проблемы при открытии файла."; }
	else {
		if (inputErrorsCheck(fileInput, fileOut) == 1) { fileOut << "Проблема в файле для ввода."; }
		else {
			if (operationsErrorsCheck(fileOperations, fileOut) == 1) { fileOut << "Проблема в файле с операциями."; }
			else {
				inputClosenopen(fileInput);
				operationsClosenopen(fileOperations);
				fileOut << "Считавшиеся числа:\n";
				fileProtocol << "Считавшиеся числа:\n";
				OneElem();
				NextElemCreate();
				fileProtocol << "Длины считавшихся чисел: ";
				lensFromFile(fileInput, fileProtocol);
				updateL2Cup(cur);
				ElemFromFile(cur, fileInput);
				fileProtocol << "\nСчитавшиеся числа:\n";
				printElem(cur, fileOut, fileProtocol);
				ElemStep();
				updateL2Cup(cur);
				ElemFromFile(cur, fileInput);
				printElem(cur, fileOut, fileProtocol);
				fileOperations >> resetiosflags(ios::skipws);
				fileProtocol << "Начинаем операции над числами:\n";
				fileOut << "Начинаем операции над числами:\n";
				while (1) {
					int one, two, three, tmp;
					char operation, skip, Asign, Bsign;
					bool signOne = 0, signTwo = 0, changeCheck = 0;
					L2Cup* A;
					L2Cup* B;
					L2Cup* C;
					L2Cup* t;
					fileOperations >> one;
					fileOperations >> skip;
					fileOperations >> two;
					fileOperations >> skip;
					fileOperations >> operation;
					fileOperations >> skip;
					fileOperations >> three;
					fileOperations >> skip;
					fileProtocol << "Считавшаяся операция: " << one << " " << operation << " " << two << " и сохранить в " << three << '\n';
					fileOut << "Считавшаяся операция: " << one << " " << operation << " " << two << " и сохранить в " << three << '\n';
					fileProtocol << "Результат операции: \n";
					fileOut << "Результат операции: \n";
					if (operation == '>' || operation == '<') { SravnenieRes(Sravnenie(one, two), fileOut, fileProtocol); }
					else {
						if (three != totalCount + 1) { fileProtocol << "Ошибка! Можно сохранять только в новый элемент\n"; fileOut << "Ошибка! Можно сохранять только в новый элемент\n"; }
						else {
							totalCount++;
							NextElemCreate();
							GoToI(one);
							A = cur;
							GoToI(two);
							B = cur;
							GoToI(three);
							C = cur;
							if (getSign(A) == '-') { changeSign(A); signOne = 1; }
							if (getSign(B) == '-') { changeSign(B); signTwo = 1; }
							if (Sravnenie(one, two) == 0) { tmp = two; two = one; one = tmp; changeCheck = 1; t = B; B = A; A = t; }
							if (signOne == 1) {
								if (changeCheck == 1) { changeSign(B); }
								else { changeSign(A); }
							}
							if (signTwo == 1) {
								if (changeCheck == 1) { changeSign(A); }
								else { changeSign(B); }
							}
							if (changeCheck == 1) {
								Asign = getSign(B);
								Bsign = getSign(A);
							}
							else {
								Asign = getSign(A);
								Bsign = getSign(B);
							}
							if (operation == '+') {
								if (Asign == Bsign) {
									Plus(one, two, three, fileProtocol);
									if (Asign == '-') { changeSign(C); }
								}
								else {
									Minus(one, two, three, fileProtocol);
									if (Asign == '-' && changeCheck == 0) { changeSign(C); }
								}
							}
							if (operation == '-') {
								if (Asign == Bsign) {
									Minus(one, two, three, fileProtocol);
									if (Asign == '-' && changeCheck == 0) { changeSign(C); }
									if (Asign == '+' && changeCheck == 1) { changeSign(C); }
								}
								else {
									Plus(one, two, three, fileProtocol);
									if (Asign == '-') { changeSign(C); }
								}
							}
							if (operation == '*') { Proizv(one, two, three, fileProtocol); }
							if (operation == '^') {
								if (changeCheck == 1) { Stepen(two, one, three, fileProtocol, fileOut); }
								else { Stepen(one, two, three, fileProtocol, fileOut); }
							}
							if (operation == '/') {
								int resultdel;
								if (Asign != Bsign) { changeSign(C); }
								if (changeCheck == 1) { resultdel = LongDivMod(two, one, three, 1, fileProtocol, fileOut); if (resultdel == 0) { setLen(C, 1); } if (resultdel == 1) { setLen(C, 1); C->Info->number[0] = 1; } }
								else{ resultdel = LongDivMod(one, two, three, 1, fileProtocol, fileOut);  if (resultdel == 0) { setLen(C, 1); } if (resultdel == 1) { setLen(C, 1); C->Info->number[0] = 1; } }
							}
							if (operation == '%') {
								int resultdel;
								if(changeCheck == 1){ 
									resultdel = LongDivMod(two, one, three, 0, fileProtocol, fileOut);
									if (resultdel == 0) { CopyToAny(B, C); }
									if (resultdel == 1) { setLen(C, 1); }
									if (Bsign == '-') {
										Minus(one, three, three, fileProtocol);
									}
								}
								else {
									resultdel = LongDivMod(one, two, three, 0, fileProtocol, fileOut);
									if (resultdel == 0) { CopyToAny(A, C); }
									if (resultdel == 1) { setLen(C, 1); }
									if (Asign == '-') {
										Minus(two, three, three, fileProtocol);
									}
								}
							}
							if (operation == 'g') {
								if (Asign == '-') {
									changeSign(A);
									signOne = 1;
								}
								else { signOne = 0; }
								if (Bsign == '-') {
									changeSign(B);
									signTwo = 1;
								}
								else { signTwo = 0; }
								NOD(one, two, three, fileProtocol, fileOut);
								if (signOne == 1) { changeSign(A); }
								if (signTwo == 1) { changeSign(B); }
							}

							printElem(last, fileOut, fileProtocol);
						}
					}
					if (fileOperations.eof() == 1) { break; }
				}
				fileInput.close();
				fileOperations.close(); 
				fileOut.close();
				fileProtocol.close();
				delL2Cup();
			}
		}
	}
}
