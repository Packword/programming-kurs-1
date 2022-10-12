#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <fstream>
#include <iostream>
#include "struct.h";

using namespace std;

bool inputErrorsCheck(fstream& file);
bool paramsErrorsCheck(fstream& file);
int paramsLenRead(fstream& file);
char* paramsRead(fstream& file, int len);
void paramsPrint(char* params, int len, fstream& file);
void setNext(Elem* a, Elem* b);
Elem* getNext(Elem* a);
void setLen(int i);
int getLen();
void setLastCount(int i);
int getCount(Elem* a);
void setMemoryStr();
void delMemoryStr();
void NextElemCreate();
void ElemStep();
bool notEmptyPointer(Elem* a);
void goToFirst();
void delL();
void setChar(int i, char a);
void ListCreate(fstream& file);
void ListZapoln(fstream& file);
void PrintSpisok(fstream& file);
void modifySpisok(int paramsLen, char* params, int paramsCount);

#endif FUNCTIONS_H
