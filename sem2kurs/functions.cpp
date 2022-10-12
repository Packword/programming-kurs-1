#pragma once
#include "struct.h";
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


extern int countL = 1;
extern int totalCount = 2;

extern L2Cup* head = NULL, * cur = NULL, * last = NULL;

void inputClosenopen(fstream& file) {
	file.close();
	file.open("input.txt", ios::in);
}


void operationsClosenopen(fstream& file) {
	file.close();
	file.open("operations.txt", ios::in);
}


bool inputErrorsCheck(fstream& file, fstream& fileOut) {
	char skip = '@', skipPrev;
	int count = 0, d = 0;
	file >> resetiosflags(ios::skipws);
	file >> skip;
	if (file.eof()) {
		fileOut << "Файл с данными пустой.\n";
		return 1;
	}
	inputClosenopen(file);
	file >> skip;
	if (skip == '\n') { fileOut << "Была встречена пустая строка\n"; return 1; }
	inputClosenopen(file);
	while (1) {
		skipPrev = skip;
		file >> skip;
		d++;
		if (skip == '-') { d--; }
		if (file.eof()) { count++; break; }
		if (skip == skipPrev && skip == '\n') { fileOut << "Была встречена пустая строка"; return 1; }
		if (d != 0 && skip == '-') { return 1; }
		if (d == 2 && skip == '0' && (skipPrev == '-' || skipPrev == '0')) { return 1; }
		if (skip != '-') {
			if ((skip != '\n' && skip != '0' && skip != '1' && skip != '2' && skip != '3' && skip != '4' && skip != '5' && skip != '6' && skip != '7' && skip != '8' && skip != '9')) {
				fileOut << "Встречен неподходящий символ";
				return 1;
			}
		}
		if (skip == '\n') { count++; d = 0; }
	}
	if (count < 2) { fileOut << "Недостаточно входных данных";  return 1; }
	return 0;
}


bool operationsErrorsCheck(fstream& file, fstream& fileOut) {
	char skip = '@', skipPrev;
	int max = 2, count, check;
	file >> resetiosflags(ios::skipws);
	file >> skip;
	if (file.eof()) { fileOut << "Файл с операциями пустой"; return 1; }
	operationsClosenopen(file);
	while (1) {
		count = 0;
		while (1) {
			skipPrev = skip;
			file >> skip;
			if (file.eof() || skip == '\n') { break; }
			if (skip == skipPrev && skip == ' ') { return 1; }
			if ((count == 0 || count == 1 || count == 3) && (skip != ' ' && skip != '0' && skip != '1' && skip != '2' && skip != '3' && skip != '4' && skip != '5' && skip != '6' && skip != '7' && skip != '8' && skip != '9')) { fileOut << "Некорректные данные"; return 1; }
			if ((count == 2) && (skip != ' ' && skip != '>' && skip != '<' && skip != '+' && skip != '-' && skip != '*' && skip != '/' && skip != '%' && skip != 'g' && skip != '^')) { fileOut << "Некорректные данные"; return 1; }
			if ((skipPrev == '>' || skipPrev == '<' || skipPrev == '+' || skipPrev == '-' || skipPrev == '*' || skipPrev == '/' || skipPrev == '%' || skipPrev == 'g' || skipPrev == '^') && (skip != ' ') && (count == 2)) { return 1; }
			if (skip == ' ') { count++; }
			if (count > 3) { return 1; }
		}
		if (count != 3) { return 1; }
		if (file.eof()) { break; }
	}
	operationsClosenopen(file);
	file >> setiosflags(ios::skipws);
	while (1) {
		for (int i = 0; i < 4; i++) {
			if (i == 0 || i == 1) {
				file >> check;
				if (check > max) { return 1; }
			}
			if (i == 3) {
				file >> check;
				if (check > (max + 1)) { return 1; }
				if (check == max + 1) { max++; }
			}
			if (i == 2) { file >> skip; }
		}
		if (file.eof()) { break; }
	}
	file >> resetiosflags(ios::skipws);
	return 0;
}


void InitInfo(L2Info* a) {
	a->next = nullptr;
	for (int i = 0; i < 15; i++) {
		a->number[i] = 0;
	}
	a->prev = nullptr;
}


void NewInfo(L2Info** a) {
	*a = new L2Info; InitInfo(*a);
}


void setNextInfo(L2Info* a, L2Info* b) {
	a->next = b;
}


void setPrevInfo(L2Info* a, L2Info* b) {
	a->prev = b;
}


L2Info* getNextInfo(L2Info* a) {
	return a->next;
}


L2Info* getPrevInfo(L2Info* a) {
	return a->prev;
}


void NextInfoCreate(L2Info* a) {
	L2Info* Info;
	NewInfo(&Info);
	setNextInfo(a, Info);
	setPrevInfo(Info, a);
}


void FrontStep(L2Info** a) {
	if (a != nullptr) { *a = getNextInfo(*a); };
}


void BackStep(L2Info** a) {
	if (a != nullptr) { *a = getPrevInfo(*a); };
}


void GoFirstInfo(L2Info** a) {
	while (getPrevInfo(*a) != nullptr) {
		BackStep(a);
	}
}


void GoLastInfo(L2Info** a) {
	while (getNextInfo(*a) != nullptr) {
		FrontStep(a);
	}
}


void GoToInfo(L2Cup* a, int j) {
	GoFirstInfo(&a->Info);
	for (int i = 0; i < j - 1; i++) {
		FrontStep(&a->Info);
	}
}


unsigned getNumberI(L2Cup* a, int i) {
	return a->Info->number[i];
}


void setNumberI(L2Info* a, unsigned num, int I) {
	a->number[I] = num;
}


void Init(L2Cup* a) {
	NewInfo(&a->Info);
	a->next = nullptr;
}


void GoFirst() {
	cur = head;
}


void GoLast() {
	cur = last;
}


void setNextElem(L2Cup* a, L2Cup* b) {
	a->next = b;
}


L2Cup* getNextElem(L2Cup* a) {
	return a->next;
}


void setLen(L2Cup* a, int len) {
	a->len = len;
}


int getLen(L2Cup* a) {
	return a->len;
}


void changeSign(L2Cup* a) {
	if (a->sign == '+') {
		a->sign = '-';
	}
	else {
		a->sign = '+';
	}
}


char getSign(L2Cup* a) {
	return a->sign;
}


L2Info* getInfo(L2Cup* a) {
	return a->Info;
}


int getInfoCount(L2Cup* a) {
	int count = 1;
	GoFirstInfo(&a->Info);
	while (getNextInfo(a->Info) != nullptr) {
		FrontStep(&a->Info);
		count++;
	}
	GoFirstInfo(&a->Info);
	return count;
}


int getRealLen(L2Cup* a) {
	int count = getInfoCount(a);
	int check = 0, tmp, d = 0, len;
	GoFirstInfo(&a->Info);
	for (int i = 0; i < count * 15; i++) {
		if (i % 15 == 0 && i != 0) {
			FrontStep(&a->Info);
		}
		tmp = getNumberI(a, i % 15);
		if (tmp != 0) {
			check = tmp;
			d = i;
		}
	}
	len = d * 4;
	if (check > 1000) {
		len += 4;
	}
	else {
		if (check > 100) {
			len += 3;
		}
		else {
			if (check > 10) {
				len += 2;
			}
			else {
				len++;
			}
		}
	}
	return len;
}


void NewElem(L2Cup** a) {
	*a = new L2Cup; Init(*a);
}


void InitFirstElem(L2Cup* a) {
	head = a;
	cur = a;
	last = a;
}


void OneElem() {
	NewElem(&head);
	InitFirstElem(head);
}


void NextElemCreate() {
	L2Cup* Elem;
	NewElem(&Elem);
	setNextElem(last, Elem);
	last = Elem;
	countL++;
}


void ElemStep() {
	if (cur != nullptr) cur = getNextElem(cur);
}


void GoToI(int j) {
	GoFirst();
	for (int i = 0; i < j - 1; i++) {
		ElemStep();
	}
}


void lensFromFile(fstream& file, fstream& fileP) {
	char skip;
	int i = 0;
	GoFirst();
	file >> resetiosflags(ios::skipws);
	while (1) {
		file >> skip;
		if (skip != '-') {
			if (skip == '\n') {
				fileP << i << " ";
				setLen(cur, i);
				i = 0;
				ElemStep();
			}
			if (file.eof() == 1) {
				fileP << i;
				setLen(cur, i);
				GoFirst();
				inputClosenopen(file);
				break;
			}
			if (skip != '\n' && !file.eof()) {
				i++;
			}
		}
	}
}


void delLastInfo(L2Cup* a) {
	L2Info* tmp;
	GoLastInfo(&a->Info);
	tmp = a->Info;
	BackStep(&a->Info);
	setNextInfo(a->Info, nullptr);
	delete tmp;
}


void updateL2Cup(L2Cup* a) {
	int count = getInfoCount(a);
	int curLen = count * 60;
	int len = getLen(a);
	int dif = len - curLen;
	if (dif > 0) {
		if (dif % 60 != 0) { dif = dif / 60 + 1; }
		else { dif /= 60; }
		GoLastInfo(&a->Info);
		for (int i = 0; i < dif; i++) {
			NextInfoCreate(a->Info);
			FrontStep(&a->Info);
		}
	}
	GoFirstInfo(&a->Info);
}


void ElemFromFile(L2Cup* Elem, fstream& file) {
	char skip;
	unsigned num = 0, total = 0, firstLen = getLen(Elem) % 4;
	file >> resetiosflags(ios::skipws);
	file >> skip;
	if (skip == '-') {
		changeSign(Elem);
		if (firstLen == 0) { firstLen = 4; }
	}
	else {
		num = skip - '0';
		if (firstLen == 0) { total += num * 1000; firstLen = 3; }
		else {
			if (firstLen == 1) { total += num; firstLen = 0; }
			else {
				if (firstLen == 2) { total += num * 10; firstLen = 1; }
				else {
					if (firstLen == 3) { total += num * 100; firstLen = 2; }
				}
			}
		}
	}
	if (firstLen == 4) {
		file >> skip;
		num = skip - '0';
		total += num * 1000;
		file >> skip;
		num = skip - '0';
		total += num * 100;
		file >> skip;
		num = skip - '0';
		total += num * 10;
		file >> skip;
		num = skip - '0';
		total += num;
	}
	if (firstLen == 3) {
		file >> skip;
		num = skip - '0';
		total += num * 100;
		file >> skip;
		num = skip - '0';
		total += num * 10;
		file >> skip;
		num = skip - '0';
		total += num;
		firstLen++;
	}
	if (firstLen == 2) {
		file >> skip;
		num = skip - '0';
		total += num * 10;
		file >> skip;
		num = skip - '0';
		total += num * 1;
		firstLen++;
	}
	if (firstLen == 1) {
		file >> skip;
		num = skip - '0';
		total += num;
		firstLen++;
	}
	if (firstLen == 0) {
		firstLen++;
	}
	int len = getLen(Elem) / 4;
	if (getLen(Elem) % 4 != 0) { len++; }
	GoLastInfo(&Elem->Info);
	setNumberI(Elem->Info, total, (len - 1) % 15);
	if (len % 15 == 1 && len != 1) { BackStep(&Elem->Info); }
	for (int i = 1; i < len; i++) {
		total = 0;
		file >> skip;
		num = skip - '0';
		total += num * 1000;
		file >> skip;
		num = skip - '0';
		total += num * 100;
		file >> skip;
		num = skip - '0';
		total += num * 10;
		file >> skip;
		num = skip - '0';
		total += num;
		setNumberI(Elem->Info, total, (len - i - 1) % 15);
		if ((len - i) % 15 == 1 && (len - i) != 1) { BackStep(&Elem->Info); }
	}
	file >> skip;
}


void printElem(L2Cup* Elem, fstream& fileOut, fstream& fileP) {
	int len = 0, tmp;
	fileOut << getSign(Elem);
	fileP << getSign(Elem);
	GoLastInfo(&Elem->Info);
	len = getLen(Elem) / 4;
	if (getLen(Elem) % 4 != 0) { len++; }
	for (int i = len - 1; i >= 0; i--) {
		tmp = getNumberI(Elem, i % 15);
		if (i != len - 1) {
			if (tmp < 1000) { fileOut << 0; fileP << 0; }
			if (tmp < 100) { fileOut << 0; fileP << 0; }
			if (tmp < 10) { fileOut << 0; fileP << 0; }
		}
		fileOut << tmp;
		fileP << tmp;
		if (i % 15 == 0 && i != 0) { BackStep(&Elem->Info); }
	}
	fileOut << '\n';
	fileP << '\n';
}


void delElem(L2Cup* a) {
	L2Info* tmp;
	GoFirstInfo(&a->Info);
	while (getNextInfo(getInfo(a)) != nullptr) {
		tmp = getInfo(a);
		FrontStep(&a->Info);
		delete tmp;
	}
	delete a;
}


void delLast() {
	GoToI(countL - 1);
	setNextElem(cur, nullptr);
	delElem(last);
	last = cur;
	countL--;

}


void delL2Cup() {
	GoFirst();
	L2Cup* tmp;
	while (1) {
		if (getNextElem(cur) == nullptr) { break; }
		tmp = cur;
		ElemStep();
		delElem(tmp);
	}
}


void clearInfo(L2Cup* A) {
	GoLastInfo(&A->Info);
	while (getPrevInfo(getInfo(A)) != nullptr) {
		BackStep(&A->Info);
		delete getNextInfo(getInfo(A));
		setNextInfo(A->Info, nullptr);
	}
	for (int i = 0; i < 15; i++) {
		setNumberI(A->Info, 0, i);
	}
	setLen(A, 0);
}


void CopyToAny(L2Cup* A, L2Cup* B) {
	int len, tmp;
	clearInfo(B);
	setLen(B, getLen(A));
	updateL2Cup(B);
	if (getLen(A) % 4 != 0) { len = getLen(A) / 4 + 1; }
	else { len = getLen(A) / 4; }
	GoFirstInfo(&A->Info);
	GoFirstInfo(&B->Info);
	for (int i = 0; i < len; i++) {
		if (i % 15 == 0 && i != 0) {
			FrontStep(&A->Info);
			FrontStep(&B->Info);
		}
		tmp = getNumberI(A, i % 15);
		setNumberI(B->Info, tmp, i % 15);
	}
}


void CopyListToLast(L2Cup* A) {
	NextElemCreate();
	GoLast();
	setLen(last, getLen(A));
	updateL2Cup(last);
	int len;
	if (getLen(A) % 4 != 0) { len = getLen(A) / 4 + 1; }
	else { len = getLen(A) / 4; }
	GoFirstInfo(&last->Info);
	GoFirstInfo(&A->Info);
	for (int i = 0; i < len; i++) {
		if (i % 15 == 0 && i != 0) {
			FrontStep(&A->Info);
			FrontStep(&last->Info);
		}
		setNumberI(last->Info, getNumberI(A, i % 15), i % 15);
	}
}


void Sdvig(L2Cup* A) {
	int lenA, maxLen, tmpostprev = 0, tmpostcur = 0, tmp = 0;
	lenA = getLen(A) + 1;
	setLen(A, lenA);
	updateL2Cup(A);
	maxLen = lenA / 4;
	GoFirstInfo(&A->Info);
	if (lenA % 4 != 0) { maxLen++; }
	lenA = getLen(A);
	if (lenA % 4 == 0) { lenA /= 4; }
	else { lenA = lenA / 4 + 1; }
	for (int i = 0; i < maxLen; i++) {
		if (i % 15 == 0 && i != 0) {
			FrontStep(&A->Info);
		}
		if (i != maxLen - 1) {
			tmp = getNumberI(A, i % 15);
			tmpostcur = tmpostprev;
			tmpostprev = tmp / 1000;
			tmp %= 1000;
			tmp *= 10;
			tmp += tmpostcur;
		}
		else {
			if (i < lenA) {
				tmp = getNumberI(A, i % 15);
			}
			else {
				tmp = 0;
			}
			tmp *= 10;
			tmp += tmpostprev;
		}
		setNumberI(A->Info, tmp, i % 15);
	}
}


void SdvigNaN(L2Cup* A, int sp) {
	for (int i = 0; i < sp; i++) {
		Sdvig(A);
	}
}


int Sravnenie(int one, int two) {
	L2Cup* A;
	L2Cup* B;
	GoToI(one);
	A = cur;
	GoToI(two);
	B = cur;
	int len = 0;
	int bolshe = 1, menshe = 0;
	int Alen = getLen(A);
	int Blen = getLen(B);
	char Asign = getSign(A);
	char Bsign = getSign(B);
	GoFirstInfo(&A->Info);
	GoFirstInfo(&B->Info);
	if (Asign == '-' && Bsign == '+') { return menshe; }
	if (Asign == '+' && Bsign == '-') { return bolshe; }
	if (Asign == '-' && Bsign == '-') { bolshe = 0; menshe = 1; }
	if (Alen > Blen) { return bolshe; }
	if (Alen < Blen) { return menshe; }
	if (Alen == Blen) {
		if (Alen % 4 != 0) { len = (Alen / 4) + 1; }
		else { len = Alen / 4; }
		GoLastInfo(&A->Info);
		GoLastInfo(&B->Info);
		for (int i = len - 1; i >= 0; i--) {
			if (getNumberI(A, i % 15) > getNumberI(B, i % 15)) { return bolshe; }
			if (getNumberI(A, i % 15) < getNumberI(B, i % 15)) { return menshe; }
			if (i % 15 == 0 && i != 0) { BackStep(&A->Info); BackStep(&B->Info); }
		}
		return -1;
	}
}


int SravnenieSP(int one, int two, int sp) {
	L2Cup* A;
	L2Cup* B;
	int res;
	GoToI(one);
	A = cur;
	GoToI(two);
	B = cur;
	CopyListToLast(B);
	SdvigNaN(last, sp);
	res = Sravnenie(one, countL);
	delLast();
	return res;
}


void SravnenieRes(int i, fstream& fileOut, fstream& fileP) {
	if (i == 1) { fileOut << "A больше B\n"; fileP << "A больше B\n"; }
	if (i == 0) { fileOut << "A меньше B\n"; fileP << "A меньше B\n"; }
	if (i == -1) { fileOut << "A равно B\n"; fileP << "A равно B\n"; }
}


void Plus(int one, int two, int three, fstream& fileP) {
	L2Cup* A;
	L2Cup* B;
	L2Cup* C;
	int lenA = 0, lenB = 0, lenMax = 0, i = 0;
	bool check = 0;
	unsigned tmp;
	GoToI(one);
	A = cur;
	lenA = getLen(A);
	GoFirstInfo(&A->Info);
	GoToI(two);
	B = cur;
	lenB = getLen(B);
	GoFirstInfo(&B->Info);
	GoToI(three);
	C = cur;
	GoFirstInfo(&C->Info);
	if (lenA >= lenB) {
		setLen(C, lenA + 1);
		lenMax = lenA;
	}
	else {
		setLen(C, lenB + 1);
		lenMax = lenB;
	}
	updateL2Cup(C);
	lenA /= 4;
	lenB /= 4;
	if (getLen(A) % 4 != 0) { lenA++; }
	if (getLen(B) % 4 != 0) { lenB++; }
	if (lenMax % 4 != 0) { lenMax = (lenMax / 4) + 1; }
	else { lenMax /= 4; }
	for (i; i < lenMax; i++) {
		tmp = 0;
		if (i % 15 == 0 && i != 0) {
			if (lenA >= i) {
				FrontStep(&A->Info);
			}
			if (lenB >= i) {
				FrontStep(&B->Info);
			}
			if (one != three) {
				FrontStep(&C->Info);
			}
		}
		if (lenA >= i) {
			tmp += getNumberI(A, i % 15);
		}
		if (lenB >= i) {
			tmp += getNumberI(B, i % 15);
		}
		tmp += check;
		if (tmp > 9999) { tmp = tmp % 10000; check = 1; }
		else { check = 0; }
		fileP << "Готовый разряд в результате сложения: " << tmp << " " << check << " переносим в следующий\n";
		setNumberI(C->Info, tmp, i % 15);
	}
	if (check == 1) {
		if (i % 15 == 0) {
			FrontStep(&C->Info);
		}
		fileP << "Добавляем единицу, так как увеличили число разрядов\n";
		setNumberI(C->Info, 1, i % 15);
	}
	else {
		setLen(C, getLen(C) - 1);
	}
}


void Minus(int One, int Two, int three, fstream& fileP) {
	L2Cup* A;
	L2Cup* B;
	L2Cup* C;
	int lenA = 0, lenB = 0, lenMax = 0;
	bool check = 0;
	int tmp;

	GoToI(One);
	A = cur;
	GoFirstInfo(&A->Info);
	GoToI(Two);
	B = cur;
	GoFirstInfo(&B->Info);
	GoToI(three);
	C = cur;
	lenA = getLen(A);
	lenB = getLen(B);
	lenMax = lenA;
	setLen(C, lenMax);
	if (lenA % 4 != 0) {
		lenA = lenA / 4 + 1;
	}
	else {
		lenA /= 4;
	}
	if (lenB % 4 != 0) {
		lenB = lenB / 4 + 1;
	}
	else {
		lenB /= 4;
	}
	lenMax = lenA;
	updateL2Cup(C);
	for (int i = 0; i < lenMax; i++) {
		tmp = 0;
		if (i % 15 == 0 && i != 0) {
			if (lenA > i) {
				FrontStep(&A->Info);
			}
			if (lenB > i) {
				FrontStep(&B->Info);
			}
			if (One != three && One != Two) {
				FrontStep(&C->Info);
			}
		}
		if (lenA >= i) {
			tmp += getNumberI(A, i % 15);
		}
		if (lenB >= i) {
			tmp -= getNumberI(B, i % 15);
		}
		tmp -= check;
		fileP << "Получившийся разряд: " << tmp;
		if (tmp < 0) {
			tmp += 10000;
			check = 1;
			fileP << ". Он получился отрицательным, поэтому прибавляем 10000 и занимаем 1 у следующего разряда: " << tmp;
		}
		else { check = 0; }
		fileP << ". Сохраняем число в новое.\n";
		setNumberI(C->Info, tmp, i % 15);
	}
	fileP << "Изменяем длину на новую: " << getLen(C) << " меняем на " << getRealLen(C) << '\n';
	if ((getLen(C) - 1) / 60 != (getRealLen(C) - 1) / 60) {
		delLastInfo(C);
	}
	setLen(C, getRealLen(C));
}


void MinusSP(int one, int Two, int three, int sp, fstream& fileP) {
	L2Cup* B;
	GoToI(Two);
	B = cur;
	CopyListToLast(B);
	SdvigNaN(last, sp);
	Minus(one, countL, three, fileP);
	delLast();
}


void Proizv(int one, int two, int three, fstream& fileP) {
	L2Cup* A;
	L2Cup* B;
	L2Cup* C;
	int lenA = 0, lenB = 0, lenMax = 0, d = 0, check = 0;
	unsigned long long tmp[1000] = {};
	char Asign, Bsign;
	GoToI(one);
	A = cur;
	Asign = getSign(A);
	lenA = getLen(A) / 4;
	if (getLen(A) % 4 != 0) { lenA++; }
	GoFirstInfo(&A->Info);
	GoToI(two);
	B = cur;
	Bsign = getSign(B);
	lenB = getLen(B) / 4;
	if (getLen(B) % 4 != 0) { lenB++; }
	GoFirstInfo(&B->Info);
	GoToI(three);
	C = cur;
	GoFirstInfo(&C->Info);
	if (Asign != Bsign) {
		changeSign(C);
	}
	for (int i = 0; i < lenA; i++) {
		if (i % 15 == 0 && i != 0) { FrontStep(&A->Info); }
		for (int j = 0; j < lenB; j++) {
			if (j % 15 == 0 && j != 0) { FrontStep(&B->Info); }
			tmp[i + j] += getNumberI(A, i % 15) * getNumberI(B, j % 15);
		}
		GoFirstInfo(&B->Info);
	}
	GoFirstInfo(&A->Info);
	GoFirstInfo(&B->Info);
	for (int i = 0; i < lenA + lenB - 1; i++) {
		tmp[i + 1] += tmp[i] / 10000;
		tmp[i] %= 10000;
		if (tmp[i + 1] != 0) {
			d = i + 1;
		}
	}
	lenMax += d * 4;
	check = tmp[lenA + lenB - 1];
	if (check < 10) { lenMax++; }
	else {
		if (check < 100) { lenMax += 2; }
		else {
			if (check < 1000) { lenMax += 3; }
			else { lenMax += 4; }
		}
	}
	fileP << "Обновляем длину списка: новая длина " << lenMax << '\n';
	setLen(C, lenMax);
	updateL2Cup(C);
	for (int i = 0; i < d + 1; i++) {
		if (i % 15 == 0 && i != 0) { FrontStep(&C->Info); }
		fileP << "Добавляем число: " << tmp[i] << '\n';
		setNumberI(C->Info, tmp[i], i % 15);
	}
}


void Stepen(int one, int two, int three, fstream& fileP, fstream& fileOut) {
	L2Cup* A;
	L2Cup* B;
	L2Cup* C;
	GoToI(one);
	A = cur;
	GoToI(two);
	B = cur;
	GoFirstInfo(&B->Info);
	GoToI(three);
	C = cur;
	if (getSign(B) == '-') {
		fileP << "Нельзя возводить в отрицательную степень\n";
		fileOut << "Нельзя возводить в отрицательную степень\n";
	}
	else {
		if (getLen(B) == 1 && B->Info->number[0] == 0) {
			clearInfo(C);
			setLen(C, 1);
			C->Info->number[0] = 1;
		}
		else {
			if (getLen(B) > 4) {
				fileOut << "Числа слишком большие\n";
				fileP << "Числа слишком большие\n";
			}
			else {
				NextElemCreate();
				fileP << "Промежуточные действия: \n";
				if (getLen(B) == 1 && B->Info->number[0] == 1) {
					delLast();
					Plus(three, one, three, fileP);
				}
				else {
					Plus(countL, one, countL, fileP);
					Proizv(one, countL, three, fileP);
					for (int i = 0; i < getNumberI(B, 0) - 2; i++) {
						fileP << "Возводим в степень " << i + 2 << '\n';
						Proizv(three, one, three, fileP);
					}
					delLast();
				}
			}
		}
	}
}


void makeDel(int one, int two, int three, bool modordiv, fstream& fileP, fstream& fileOut) { // если modordiv == 0, то сохраняем mod, в ином случае - div.
	int sp, lenA, lenB, res1, res2, chislo;
	bool check = 0;
	L2Cup* A;
	L2Cup* B;
	L2Cup* C;
	L2Cup* Acur;
	L2Cup* tmp;
	GoToI(one);
	A = cur;
	lenA = getLen(A);
	GoToI(two);
	B = cur;
	lenB = getLen(B);
	GoToI(three);
	C = cur;
	clearInfo(C);
	GoFirstInfo(&B->Info);
	if (lenB == 1 && B->Info->number[0] == 0) {
		fileP << "На 0 делить нельзя\n";
		fileOut << "На 0 делить нельзя\n";
	}
	else {
		sp = lenA - lenB;
		if (SravnenieSP(one, two, sp) == 0) { sp--; }
		fileP << "Вычисляем при помощи сравнения со сдвигом точную разность в количестве разрядов у чисел: " << sp << '\n';
		CopyListToLast(A);
		Acur = last;
		for (int i = sp; i >= 0; i--) {
			check = 0;
			chislo = 0;
			res1 = SravnenieSP(countL, two, i);
			if (res1 != 0) {
				while (check == 0) {
					chislo++;
					fileP << "Выполняем вычитание со сдвигом на " << i << '\n';
					MinusSP(countL, two, countL, i, fileP);
					tmp = last;
					res2 = SravnenieSP(countL, two, i);
					if (res2 == 0) { check = 1; }
				}
			}
			if (modordiv == 1) {
				Sdvig(C);
				GoFirstInfo(&C->Info);
				fileP << "Находим разряд частного: " << chislo << '\n';
				C->Info->number[0] += chislo;
			}
		}
		if (modordiv == 0) {
			fileP << "Остаток получаем как то, что осталось от деления, точно как и при счёте <<в столбик>>\n";
			CopyToAny(last, C);
		}
		delLast();
	}
}


int LongDivMod(int one, int two, int three, bool modordiv, fstream& fileP, fstream& fileOut) {
	int res;
	L2Cup* A;
	L2Cup* B;
	GoToI(one);
	A = cur;
	GoToI(two);
	B = cur;
	bool cA = 0, cB = 0;
	if (getSign(A) == '-') { cA = 1; changeSign(A); }
	if (getSign(B) == '-') { cB = 1; changeSign(B); }
	res = Sravnenie(one, two);
	if (cA == 1) { changeSign(A); }
	if (cB == 1) { changeSign(B); }
	if (res == 0) { return 0; }
	if (res == -1) { return 1; }
	if (res == 1) { makeDel(one, two, three, modordiv, fileP, fileOut); return 2; }
}


void NOD(int one, int two, int three, fstream& fileP, fstream& fileOut) {
	L2Cup* A;
	L2Cup* B;
	L2Cup* C;
	L2Cup* altA;
	L2Cup* altB;
	int numA, numB, numC, res;
	GoToI(one);
	A = cur;
	GoToI(two);
	B = cur;
	GoToI(three);
	C = cur;
	clearInfo(C);
	if (getLen(B) == 1 && B->Info->number[0] == 0) {
		fileP << "На 0 делить нельзя\n";
		fileOut<< "На 0 делить нельзя\n";
	}
	else {
		CopyListToLast(A);
		altA = last;
		CopyListToLast(B);
		altB = last;
		NextElemCreate();
		numA = countL - 2;
		numB = countL - 1;
		numC = countL;
		while (1) {
			fileP << "Находим остаток от деления\n";
			res = LongDivMod(numA, numB, numC, 0, fileP, fileOut);
			if (res == 0) { fileP << "Ошибка в нод!\n"; fileOut << "Ошибка в нод!\n"; break; }
			if (res == 1) { setLen(C, 1);  C->Info->number[0] = 1; break; }
			if (getLen(last) == 1 && last->Info->number[0] == 0) { CopyToAny(altB, C); break; }
			CopyToAny(altB, altA);
			CopyToAny(last, altB);
		}
		delLast();
		delLast();
		delLast();
	}
}
