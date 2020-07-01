#ifndef READ_LINES
	#define READ_LINES
	#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
	char* read_line(FILE* fp);
	void read_lines(FILE* fp, char*** lines, int* num_lines);

    void push_back(char*** lines, const int* len, char** line);

    void push_back_C(char** array, const int* len, char val);

#endif
