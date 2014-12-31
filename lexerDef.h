// BATCH 21
// KRISHNIKA AGARWAL 2011C6PS839P
//NAINCY SUMAN 2011C6PS692P


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 30
#define BUFFERSIZE 20000

typedef char buffer[BUFFERSIZE];


struct token{
	int done;
	char Tok_name[MAX];
	char lex_name[MAX];
	int attribute_int;
	float attribute_float;
	int line;
	//int col;
};

typedef struct token tokenInfo;

int line_no;//=1;
//int col_no;//=1;
int buf_ptr;//=0;
int lexeme_start;//=0;
int forward;//=1;
