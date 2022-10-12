#ifndef STRUCT_H
#define STRUCT_H
#pragma once
#include <iostream>

struct string_str {
	int len;
	char* str;
};

struct Elem {
	int count = 0;
	string_str CurStr;
	Elem* next;
};

#endif