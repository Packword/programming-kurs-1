#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <fstream>
#include <iostream>
#include "struct.h";
using namespace std;

void InitInfo(L2Info* a);
void NewInfo(L2Info** a);
void setNextInfo(L2Info* a, L2Info* b);
void setPrevInfo(L2Info* a, L2Info* b);
L2Info* getNextInfo(L2Info* a);
L2Info* getPrevInfo(L2Info* a);
void NextInfoCreate(L2Info* a);
void FrontStep(L2Info** a);
void BackStep(L2Info** a);
void GoFirstInfo(L2Info** a);
void GoLastInfo(L2Info** a);
void charSet(int l2, char s, int i);
char charGet(L2Info* a, int i);
void Init(L2Cup* a);
void GoFirst(int l2);
void GoLast(int l2);
void setNextElem(L2Cup* a, L2Cup* b);
L2Cup* getNextElem(L2Cup* a);
void setLen(L2Cup* a, int len);
int getLen(L2Cup* a);
L2Info* getInfo(L2Cup* a);
void NewElem(L2Cup** a);
void InitFirstElem(L2Cup* a, int l2);
void OneElem(int l2);
bool voidListCheck(int l2);
void NextElemCreate(int l2);
void ElemStep(int l2);
void GoToI(int j, int l2);
void delElem(L2Cup* a);
void delElemFirst(int l2);
void delElemI(int l2, int i);
void delL2Cup(int l2);
void listFromFile(int l2, fstream& file);
void PrintElem(int l2,fstream& fileOut);
bool ElemEqCheck(L2Cup* a, L2Cup* b);
void simSub(fstream& fileOut);
bool checkPrin();
#endif FUNCTIONS_H
