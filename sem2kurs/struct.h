#ifndef STRUCT_H
#define STRUCT_H
#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


struct L2Info {
	L2Info* prev;
	unsigned number[15] = {};
	L2Info* next;
};


struct L2Cup {
	char sign = '+';
	int len = 0;
	L2Info* Info;
	L2Cup* next;
};


#endif