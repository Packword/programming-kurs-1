#ifndef STRUCT_H
#define STRUCT_H
#pragma once
#include <iostream>


struct L2Info {
	L2Info* prev;
	char stroka[15] = {};
	L2Info* next;
};


struct L2Cup {
	int len = 0;
	L2Info* Info;
	L2Cup* next;
};


#endif
