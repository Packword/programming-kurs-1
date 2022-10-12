#include <iostream>
#include <fstream>
#include <iomanip>
#include "struct.h";

using namespace std;

Elem* first = nullptr, * last = nullptr, * cur = nullptr;

bool inputErrorsCheck(fstream& file) {
	char skip = '\n', skipprev;
	if (file.eof()) { return 1; }
	while (!file.eof()) {
		skipprev = skip;
		file >> skip;
		if (skip == skipprev && skip == '\n') { return 1; }
	}
	return 0;
}


bool paramsErrorsCheck(fstream& file) {
	int d = 0;
	file >> resetiosflags(ios::skipws);
	if (file.eof() == 1) {
		return 1;
	}
	char check = '@';
	while (check == '/n') {
		d++;
		file >> check;
		if (d == 0 && (check == '0' || check == '\n')) { return 1; }
		if (check != '\n' && check != '0' && check != '1' && check != '2' && check != '3' && check != '4' && check != '5' && check != '6' && check != '7' && check != '8' && check != '9') {
			return 1;
		}
		if (file.eof() == 1) {
			return 1;
		}
	}
	file>>check;
	if (check == '\n' || file.eof() == 1) { return 1; }
	return 0;
}


int paramsLenRead(fstream& file) {
	file >> setiosflags(ios::skipws);
	int len, d = -1;
	char skip;
	file >> len;
	file >> skip;
	file >> resetiosflags(ios::skipws);
	while (!file.eof()) {
		file >> skip;
		d++;
		if (skip == '\n') {
			d--;
			break;
		}
	}
	return d + 2;
}


char* paramsRead(fstream& file, int len) {
	file >> setiosflags(ios::skipws);
	int skip;
	file >> skip;
	file >> resetiosflags(ios::skipws);
	char cur;
	file >> cur;
	char* params = new char(len + 1);
	for (int i = 0; i < len - 1; i++) {
		file >> params[i];
	}
	params[len - 1] = '\n';
	return params;
}


void paramsPrint(char* params, int len, fstream& file) {
	file << "Считавшаяся подстрока:\n";
	for (int i = 0; i < len; i++) {
		file << params[i];
	}
}


void setNext(Elem* a, Elem* b) {
	a->next = b;
}


Elem* getNext(Elem* a) {
	return a->next;
}


void setLen(int i) {
	cur->CurStr.len = i;
}


int getLen() {
	return cur->CurStr.len;
}


void setLastCount(int i) {
	last->count = i;
}


int getCount(Elem* a) {
	return a->count;
}


void setMemoryStr() {
	cur->CurStr.str = new char[cur->CurStr.len];
}


void delMemoryStr() {
	delete cur->CurStr.str;
}


void NextElemCreate() {
	Elem* NewElem = new Elem;
	setNext(cur, NewElem);
}


void ElemStep() {
	cur = getNext(cur);
}


bool notEmptyPointer(Elem* a) {
	if (getNext(a) == NULL) return 0;
	else return 1;
}


void goToFirst() {
	cur = first;
}


void delL() {
	Elem* p;
	goToFirst();
	while (getCount == 0) {
		p = cur;
		ElemStep();
		delete p;
	}
	delete cur;
}


void setChar(int i, char a) {
	cur->CurStr.str[i] = a;
}


void setStr(char* a) {
	cur->CurStr.str = a;
}


void ListCreate(fstream& file) {
	char skip;
	int d = 0;
	int count = 0;
	file >> resetiosflags(ios::skipws);
	cur = new Elem;
	first = cur;
	while (!file.eof()) {
		file >> skip;
		if (skip == '\n' && !file.eof()) {
			d++;
			setLen(count + 1);
			setMemoryStr();
			count = 0;
			NextElemCreate();
			ElemStep();
		}
		else {
			count++;
		}

	}
	d++;
	setLen(count - 1);
	setMemoryStr();
	last = cur;
	setLastCount(d);
}


void ListZapoln(fstream& file) {
	char a;
	for (int j = 0; j < getCount(last); j++) {
		for (int i = 0; i < getLen(); i++) {
			if (file.eof()) {
				break;
			}
			file >> a;
			setChar(i, a);
		}
		if (getCount(cur) == 0) {
			ElemStep();
		}
		else {
			file >> a;
		}
	}
}


void PrintSpisok(fstream& file) {
	goToFirst();
	for (int i = 0; i < getCount(last); i++) {
		for (int j = 0; j < getLen(); j++) {
			file << cur->CurStr.str[j];
		}
		ElemStep();
	}
}


void modifySpisok(int paramsLen, char* params, int paramsCount) {
	char* tmp;
	int tmpLen;
	goToFirst();
	for (int i = 0; i < getCount(last) - 1; i++) {
		ElemStep();
	}
	int tL = getCount(last) + paramsCount;
	setLastCount(0);
	for (int i = 0; i < paramsCount; i++) {
		NextElemCreate();
		ElemStep();
		setLen(paramsLen);
		setMemoryStr();
		setStr(params);
	}
	last = cur;
	setLastCount(tL);
}