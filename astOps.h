//-----BATCH 21------
//------KRISHNIKA AGARWAL 2011C6PS839P----
//------NAINCY SUMAN 2011C6PS692P----

#include "astDef1.h"

extern void createast(char* lex, tokenInfo TI, int l);
extern void createChild(char* lex, tokenInfo TI, int l);
extern void findParent(char* ch);
extern void printast(astLink ptr, FILE* fp);
////
//extern t_link createST();
//extern t_link insertST(t_link head, char* symbol, tokenInfo TI, char* scope, int s_no);
//extern t_link insertST(t_link head, char* symbol, tokenInfo TI, char* scope, int s_no,t_link ptr1);
//
//extern int findST(t_link head, char* ch, t_link ptr);
//extern void printST();
extern scope_Stack newSStack();
extern Boolean s_push (scope_Stack st, char* scope,int scope_no,tokenInfo TI);
extern Boolean s_pop (scope_Stack st);
extern int s_size(scope_Stack st);


extern e_table createError();
extern e_table insertError(e_table head, int e_no, tokenInfo TI);
extern void printError(e_table head);


extern par_link createPar();
extern par_link insertpar(par_link head, char* type);
