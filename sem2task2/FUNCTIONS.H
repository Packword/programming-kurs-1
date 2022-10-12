#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <fstream>
#include <iostream>
#include "struct.h";

using namespace std;
bool errorsCheck(fstream& file);
stringStr setStruct(fstream& file, int i, int j);
void outPutBlok(fstream& file, stringStr blok);
int procBlok(stringStr Block, int i, int j);

#endif FUNCTIONS_H