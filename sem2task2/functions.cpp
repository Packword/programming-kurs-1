#include <iostream>
#include <fstream>
#include <iomanip>
#include "struct.h";

using namespace std;

int const high = 30, width = 66;


int progress[30];

bool errorsCheck(fstream& file) {
	setlocale(0, "");
	file << resetiosflags(ios::skipws);
	char skip;
	int strokC = 0, charsC = 0;
	if (file.eof() == 1) { return 1; }
	while (1) {
		if (file.eof() == 1) { break; }
		file >> skip;
		if ((skip == '@') || (skip == '\n')) {
			strokC++;
			if (charsC != 66) { return 1; }
			charsC = -1;
			file >> skip;
		}
		charsC++;
	}
	if (strokC != 30) {
		return 1;
	}

	return 0;
}

stringStr setStruct(fstream& file, int i, int j) {
	char skip = '0';
	stringStr curBlok;
	file << resetiosflags(ios::skipws);
	for (int s = 0; s < i * 10; s++) {
		while (skip != curBlok.Mark)
		{
			file >> skip;
		}
		file >> skip;
	}
	for (int curS = 0; curS < 10; curS++) {
		for (int skipC = 0; skipC < j * 22; skipC++) {
			file >> skip;
		}
		for (int curC = 0; curC < 22; curC++) {
			file >> curBlok.Str[curS].Str[curC];
		}
		if (j == 2) {
			file >> skip;
			file >> skip;
		}
		else {
			for (int skipC = 0; skipC < (2 - j) * 22 + 2; skipC++) {
				file >> skip;
			}
		}
	}
	return curBlok;
}

void outPutBlok(fstream& file, stringStr blok) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 22; j++) {
			cout << blok.Str[i].Str[j];
			file << blok.Str[i].Str[j];
		}
		cout << '\n';
		file << '\n';
	}
	cout << '\n';
	file << '\n';
}

int procBlok(stringStr Block, int i, int j) {
	int d, total = 0;
	if (j == 0) {
		for (int curS = 0; curS < 10; curS++) {
			d = 1;
			for (int curC = 0; curC < 22; curC++){
				if (Block.Str[curS].Str[curC] != ' ' && d == 1) {
					if (Block.Str[curS].Str[curC] != '-') {
						d = 0;
					}
					else {
						if (curC == 0) { d = 0; }
						else{
							d = 0;
							total++;
						}
					}
				}
			}
			if (d == 1) {
				progress[curS + i * 10] = 1;
			}
		}
	}
	if (j != 0) {
		for (int curS = 0; curS < 10; curS++) {
			d = 1;
			if (progress[i * 10 + curS] != 0) {
				for (int curC = 0; curC < 22; curC++) {
					if (Block.Str[curS].Str[curC] != ' ' && d == 1) {
						if (Block.Str[curS].Str[curC] != '-') {
							d = 0;
							progress[i * 10 + curS] = 0;
						}
						if (Block.Str[curS].Str[curC] == '-') {
							d = 0;
							progress[i * 10 + curS] = 0;
							total++;
						}
					}
				}
				if (d == 1) {
					progress[curS + i * 10]++;
				}
			}
			
		}
	}
	return total;
}