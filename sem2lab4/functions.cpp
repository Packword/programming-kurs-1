#include <iostream>
#include <fstream>
#include <iomanip>
#include "struct.h";
using namespace std;

int count1 = 1, count2 = 1, count3 = 1;
L2Cup* head = NULL, * cur = NULL, * last = NULL, * head2 = NULL, * cur2 = NULL, * last2 = NULL, * head3 = NULL, * cur3 = NULL, * last3 = NULL;

void InitInfo(L2Info* a) {
	a->next = nullptr;
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


void charSet(int l2, char s, int i) {
	if (l2 == 1) {
		cur->Info->stroka[i] = s;
	}
	if (l2 == 2) {
		cur2->Info->stroka[i] = s;
	}
	if (l2 == 3) {
		cur3->Info->stroka[i] = s;
	}
}

char charGet(L2Info* a, int i) {
	return a->stroka[i];
}


void Init(L2Cup* a) {
	NewInfo(&a->Info);
	a->next = nullptr;
}


void GoFirst(int l2) {
	if (l2 == 1) {
		cur = head;
	}
	if (l2 == 2) {
		cur2 = head2;
	}
	if (l2 == 3) {
		cur3 = head3;
	}
}


void GoLast(int l2) {
	if (l2 == 1) {
		cur = last;
	}
	if (l2 == 2) {
		cur2 = last2;
	}
	if (l2 == 3) {
		cur3 = last3;
	}
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


L2Info* getInfo(L2Cup* a) {
	return a->Info;
}


void NewElem(L2Cup** a) {
	*a = new L2Cup; Init(*a);
}


void InitFirstElem(L2Cup* a, int l2) {
	if (l2 == 1) {
		head = a;
		cur = a;
		last = a;
	}
	if (l2 == 2) {
		head2 = a;
		cur2 = a;
		last2 = a;
	}
	if (l2 == 3) {
		head3 = a;
		cur3 = a;
		last3 = a;
	}
}


void OneElem(int l2) {
	if (l2 == 1) {
		NewElem(&head);
		InitFirstElem(head, l2);
	}
	if (l2 == 2) {
		NewElem(&head2);
		InitFirstElem(head2, l2);
	}
	if (l2 == 3) {
		NewElem(&head3);
		InitFirstElem(head3, l2);
	}
}


bool voidListCheck(int l2) {
	if (l2 == 1) {
		if (count1 == 0) { return 1; }
	}
	if (l2 == 2) {
		if (count2 == 0) { return 1; }
	}
	return 0;
}



void NextElemCreate(int l2) {
	L2Cup* Elem;
	NewElem(&Elem);
	if (l2 == 1) {
		setNextElem(last, Elem);
		last = Elem;
		count1++;
	}
	if (l2 == 2) {
		setNextElem(last2, Elem);
		last2 = Elem;
		count2++;
	}
	if (l2 == 3) {
		setNextElem(last3, Elem);
		last3 = Elem;
		count3++;
	}
}


void ElemStep(int l2) {
	if (l2 == 1) {
		if (cur != nullptr) cur = getNextElem(cur);
	}
	if (l2 == 2) {
		if (cur2 != nullptr) cur2 = getNextElem(cur2);
	}
	if (l2 == 3) {
		if (cur3 != nullptr) cur3 = getNextElem(cur3);
	}
}


void GoToI(int j, int l2) {
	GoFirst(l2);
	for (int i = -1; i < j - 1; i++) {
		ElemStep(l2);
	}
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


void delElemFirst(int l2) {
	L2Cup* tmp = nullptr;
	GoFirst(l2);
	ElemStep(l2);
	if (l2 == 1) {
		tmp = head;
		head = cur;
	}
	if (l2 == 2) {
		tmp = head2;
		head2 = cur2;
	}
	delElem(tmp);
}


void delElemI(int l2, int i) {
	L2Cup* tmpNext;
	L2Cup* tmp = nullptr;
	GoToI(i, l2);
	if (l2 == 1) {
		tmpNext = getNextElem(cur);
		tmp = cur;
		GoToI(i - 1, l2);
		setNextElem(cur, tmpNext);
	}
	if (l2 == 2) {
		tmpNext = getNextElem(cur2);
		tmp = cur2;
		GoToI(i - 1, l2);
		setNextElem(cur2, tmpNext);
	}
	if (l2 == 3) {
		tmpNext = getNextElem(cur3);
		tmp = cur3;
		GoToI(i - 1, l2);
		setNextElem(cur3, tmpNext);
	}
	delElem(tmp);
}


void delL2Cup(int l2) {
	if (voidListCheck(l2) == 0) {
		GoFirst(l2);
		L2Cup* tmp = nullptr;
		while (1) {
			if (l2 == 1) {
				if (getNextElem(cur) == nullptr) { break; }
				tmp = cur;
			}
			if (l2 == 2) {
				if (getNextElem(cur2) == nullptr) { break; }
				tmp = cur2;
			}
			if (l2 == 3) {
				if (getNextElem(cur3) == nullptr) { break; }
				tmp = cur3;
			}
			ElemStep(l2);
			delElem(tmp);
		}
	}
}


void listFromFile(int l2, fstream& file) {
	char skip;
	int len = 0;
	file >> resetiosflags(ios::skipws);
	while (1) {
		file >> skip;
		if (file.eof()) {
			if (l2 == 1) {
				setLen(cur, len);
			}
			if (l2 == 2) {
				setLen(cur2, len);
			}
			if (l2 == 3) {
				setLen(cur3, len);
			}
			break; 
		}
		if (skip == '\n') {
			NextElemCreate(l2);
			if (l2 == 1) {
				setLen(cur, len);
			}
			if (l2 == 2) {
				setLen(cur2, len);
			}
			if (l2 == 3) {
				setLen(cur3, len);
			}
			ElemStep(l2);
			len = 0;
		}
		else {
			len++;
			if ((len - 1) % 15 == 0 && len != 1) {
				if (l2 == 1) {
					NextInfoCreate(getInfo(cur));
					FrontStep(&cur->Info);
				}
				if (l2 == 2) {
					NextInfoCreate(getInfo(cur2));
					FrontStep(&cur2->Info);
				}
				if (l2 == 3) {
					NextInfoCreate(getInfo(cur3));
					FrontStep(&cur3->Info);
				}
			}
			charSet(l2, skip, (len - 1) % 15);
		}
	}
}


void PrintElem(int l2, fstream& fileOut) {
	if (voidListCheck(l2) == 1) {
		fileOut << "Множество пустое\n";
	}
	else {
		L2Cup* tmp = nullptr;
		GoFirst(l2);
		if (l2 == 1) {
			tmp = cur;
		}
		if (l2 == 2) {
			tmp = cur2;
		}
		if (l2 == 3) {
			tmp = cur3;
		}
		while (1) {
			GoFirstInfo(&tmp->Info);
			for (int i = 0; i < getLen(tmp); i++) {
				if (i % 15 == 0 && i != 0) {
					FrontStep(&tmp->Info);
				}
				fileOut << charGet(getInfo(tmp), i % 15);
			}
			fileOut << '\n';
			if (l2 == 1) {
				if (getNextElem(cur) != nullptr) {
					ElemStep(l2);
					tmp = cur;
				}
				else { break; }
			}
			if (l2 == 2) {
				if (getNextElem(cur2) != nullptr) {
					ElemStep(l2);
					tmp = cur2;
				}
				else { break; }
			}
			if (l2 == 3) {
				if (getNextElem(cur3) != nullptr) {
					ElemStep(l2);
					tmp = cur3;
				}
				else { break; }
			}
		}
	}
}


bool ElemEqCheck(L2Cup* a, L2Cup* b){
	if (getLen(a) != getLen(b)) { return 0; }
	else {
		int len = getLen(a);
		GoFirstInfo(&a->Info);
		GoFirstInfo(&b->Info);
		for (int i = 0; i < len; i++) {
			if (i % 15 == 0 && i != 0) {
				FrontStep(&a->Info);
				FrontStep(&b->Info);
			}
			if (charGet(a->Info, i % 15) != charGet(b->Info, i % 15)) { return 0; }
		}
		return 1;
	}
}


void simSub(fstream& fileOut){
	L2Cup* tmp1;
	L2Cup* tmp2;
	GoFirst(1);
	tmp1 = cur;
	GoFirst(2);
	tmp2 = cur2;
	for (int i = 0; i < count1; i++) {
		bool result = 0;
		int j = 0;
		GoToI(i, 1);
		tmp1 = cur;
		for ( j; j < count2; j++) {
			result = ElemEqCheck(tmp1, tmp2);
			if (result == 1) {
				count1--;
				count2--;
			}
			if (j != count2 - 1) {
				ElemStep(2); tmp2 = cur2;
			}
			if (result == 1) { break; }
		}
		if (result == 0) {
			GoFirst(2);
			tmp2 = cur2;
		}
		else {
			if (i == 0) {
				delElemFirst(1);
			}
			else { delElemI(1, i); }
			if (j == 0) {
				delElemFirst(2);
			}
			else { delElemI(2, j); }
			i--;
			GoFirst(2);
			tmp2 = cur2;
		}
	}
}


bool checkPrin() {
	bool check = 0;
	for (int i = 0; i < count3; i++) {
		GoToI(i, 3);
		for(int j1 = 0; j1 < count1; j1++){
			GoToI(j1, 1);
			check = ElemEqCheck(cur3, cur);
			if (check == 1) { break; }
		}
		if (check != 1) {
			for (int j2 = 0; j2 < count2; j2++) {
				GoToI(j2, 2); 
				check = ElemEqCheck(cur3, cur2);
				if (check == 1) { break; }
			}
		}
		if (check == 0) {
			return 0;
		}
	}
	return 1;
}

/*
void Init(L2Cup* a) {
	a->info = 0;
	a->next = nullptr;
}


void NewElem(L2Cup** a) {
	*a = new L2Cup; Init(*a);
}


void InitFirstElem(L2Cup* a) {
	head1 = a;
	cur1 = a;
	last1 = a;
}


void InitSecondElem(L2Cup* a) {
	head2 = a;
	cur2 = a;
	last2 = a;
}


void InitThirdElem(L2Cup* a) {
	head3 = a;
	cur3 = a;
	last3 = a;
}


void FirstElem() {
	NewElem(&head1);
	InitFirstElem(head1);
}


void SecondElem() {
	NewElem(&head2);
	InitSecondElem(head2);
}


void ThirdElem() {
	NewElem(&head3);
	InitThirdElem(head3);
}


void setNextElem(L2Cup* a, L2Cup* b) {
	a->next = b;
}


L2Cup* getNextElem(L2Cup* a) {
	return a->next;
}


void setLen(L2Cup* a, int i) {
	a->len = i;
}


int getLen(L2Cup* a) {
	return a->len;
}


void setInfo(L2Cup* a, int i) {
	a->info = i;
}


int getInfo(L2Cup* a) {
	return a->info;
}


void ElemStep(int l2) {
	if (l2 == 1) {
		if (cur1 != nullptr) cur1 = getNextElem(cur1);
	}
	if (l2 == 2) {
		if (cur2 != nullptr) cur2 = getNextElem(cur2);
	}
	if (l2 == 3) {
		if (cur3 != nullptr) cur3 = getNextElem(cur3);
	}
}


void NextElemCreate(int l2) {
	L2Cup* Elem;
	NewElem(&Elem);
	if (l2 == 1) {
		setNextElem(last1, Elem);
		last1 = Elem;
	}
	if (l2 == 2) {
		setNextElem(last2, Elem);
		last2 = Elem;
	}
	if (l2 == 3) {
		setNextElem(last3, Elem);
		last3 = Elem;
	}
}


void GoFirst(int i) {
	if (i == 1) {
		cur1 = head1;
	}
	if (i == 2) {
		cur2 = head2;
	}
	if (i == 3) {
		cur3 = head3;
	}
}


void GoToI(int j, int l2) {
	GoFirst(l2);
	for (int i = 0; i < j - 1; i++) {
		ElemStep(l2);
	}
}


void delL2Cup(int l2) {
	L2Cup* tmp = nullptr;
	GoFirst(l2);
	while (1) {
		if (l2 == 1) {
			if (cur1 == nullptr) { break; }
			tmp = cur1;
		}
		if (l2 == 2) {
			if (cur2 == nullptr) { break; }
			tmp = cur2;
		}
		if (l2 == 3) {
			if (cur3 == nullptr) { break; }
			tmp = cur3;
		}
		ElemStep(l2);
		delete tmp;
	}
}


void delIElem(int l2, int i) {
	L2Cup* a = nullptr;
	L2Cup* tmp;
	GoFirst(l2);
	GoToI(i - 1, l2);
	if (l2 == 1) { a = cur1; }
	if (l2 == 2) { a = cur2; }
	if (l2 == 3) { a = cur3; }
	tmp = getNextElem(a);
	setNextElem(a, getNextElem(getNextElem(a)));
	delete tmp;
}


void delFirst(int l2) {
	GoFirst(l2);
	L2Cup* a = nullptr;
	L2Cup* tmp;
	if (l2 == 1) { a = cur1; }
	if (l2 == 2) { a = cur2; }
	if (l2 == 3) { a = cur3; }
	tmp = a;
	ElemStep(l2);
	if (l2 == 1) { head1 = cur1; }
	if (l2 == 2) { head2 = cur2; }
	if (l2 == 3) { head2 = cur3; }
	delete tmp;
}


void ListsFromFile(fstream& file, int l2) {
	int num, d = 0;
	file >> setiosflags(ios::skipws);
	while (1) {
		file >> num;
		if (file.eof() == 1) {
			if (d != 0) {
				NextElemCreate(l2); ElemStep(l2);
			}
			if (l2 == 1) { setLen(head1, getLen(head1) + 1); setInfo(cur1, num); }
			if (l2 == 2) { setLen(head2, getLen(head2) + 1); setInfo(cur2, num); }
			if (l2 == 3) { setLen(head3, getLen(head3) + 1); setInfo(cur3, num); }
			break;
		}
		else {
			if (d != 0) { NextElemCreate(l2); ElemStep(l2); }
			d = 1;
			if (l2 == 1) { setLen(head1, getLen(head1) + 1); setInfo(cur1, num); }
			if (l2 == 2) { setLen(head2, getLen(head2) + 1); setInfo(cur2, num); }
			if (l2 == 3) { setLen(head3, getLen(head3) + 1); setInfo(cur3, num); }
		}
	}
}


void PrintL(int l2, fstream& fileOut) {
	GoFirst(l2);
	while (1) {
		if (l2 == 1) { fileOut << getInfo(cur1) << ' '; if (getNextElem(cur1) == nullptr) { break; } }
		if (l2 == 2) { fileOut << getInfo(cur2) << ' '; if (getNextElem(cur2) == nullptr) { break; } }
		if (l2 == 3) { fileOut << getInfo(cur3) << ' '; if (getNextElem(cur3) == nullptr) { break; } }
		ElemStep(l2);
	}
	fileOut << '\n';
}


void simSub() {
	int maxLen, dif = 0;
	GoFirst(1);
	GoFirst(2);
	int len1 = getLen(head1);
	int len2 = getLen(head2);
	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
			if (getInfo(cur1) == getInfo(cur2)) {
				if (len2 != 1) {
					if (j == 0) { delFirst(2); len2--; break; }
					else {
						delIElem(2, j + 1);
						len2--;
						break;
					}
				}
				else {
					setInfo(cur2, 0);
				}
			}
			if (j != len2 - 1) {
				ElemStep(2);
			}
		}
		GoFirst(2);
		if (i != len1 - 1) {
			ElemStep(1);
		}
	}
	setLen(head2, len2);
}


bool vlozhenostCheck() {
	bool check = 0;
	GoFirst(2);
	GoFirst(3);
	int len2 = getLen(head2);
	int len3 = getLen(head3);
	for (int i = 0; i < len3; i++) {
		for (int j = 0; j < len2; j++) {
			if (getInfo(cur2) == getInfo(cur3)) {
				check = 1;
			}
			if (j != len2 - 1) {
				ElemStep(2);
			}
		}
		if (check == 0) { return 0; }
		check = 0;
		if (i != len3 - 1) {
			ElemStep(3);
		}
		GoFirst(2);
	}
	return 1;
}
*/
