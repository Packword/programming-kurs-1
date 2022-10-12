#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#pragma once
#include "struct.h";
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void inputClosenopen(fstream& file);
void operationsClosenopen(fstream& file);
bool inputErrorsCheck(fstream& file, fstream& fileOut);
bool operationsErrorsCheck(fstream& file, fstream& fileOut);
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
void GoToInfo(L2Cup* a, int j);
unsigned getNumberI(L2Cup* a, int i);
void setNumberI(L2Info* a, unsigned num, int I);
void Init(L2Cup* a);
void GoFirst();
void GoLast();
void setNextElem(L2Cup* a, L2Cup* b);
L2Cup* getNextElem(L2Cup* a);
void setLen(L2Cup* a, int len);
int getLen(L2Cup* a);
void changeSign(L2Cup* a);
char getSign(L2Cup* a);
L2Info* getInfo(L2Cup* a);
int getInfoCount(L2Cup* a);
int getRealLen(L2Cup* a);
void NewElem(L2Cup** a);
void InitFirstElem(L2Cup* a);
void OneElem();
void NextElemCreate();
void ElemStep();
void GoToI(int j);
void lensFromFile(fstream& file, fstream& fileP);
void updateL2Cup(L2Cup* a);
void ElemFromFile(L2Cup* Elem, fstream& file);
void printElem(L2Cup* Elem, fstream& fileOut, fstream& fileP);
void delElem(L2Cup* a);
void delLast();
void delL2Cup();
void clearInfo(L2Cup* A);
void CopyToAny(L2Cup* A, L2Cup* B);
void CopyListToLast(L2Cup* A);
void Sdvig(L2Cup* A);
void SdvigNaN(L2Cup* A, int sp);
int Sravnenie(int one, int two);
int SravnenieSP(int one, int two, int sp);
void SravnenieRes(int i, fstream& fileOut, fstream& fileP);
void Plus(int one, int two, int three, fstream& fileP);
void Minus(int One, int Two, int three, fstream& fileP);
void MinusSP(int one, int Two, int three, int sp, fstream& fileP);
void Proizv(int one, int two, int three, fstream& fileP);
void Stepen(int one, int two, int three, fstream& fileP, fstream& fileOut);
void makeDel(int one, int two, int three, bool modordiv, fstream& fileP, fstream& fileOut);
int LongDivMod(int one, int two, int three, bool modordiv, fstream& fileP, fstream& fileOut);
void NOD(int one, int two, int three, fstream& fileP, fstream& fileOut);


#endif FUNCTIONS_H