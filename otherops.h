// BATCH 21
// KRISHNIKA AGARWAL 2011C6PS839P
//NAINCY SUMAN 2011C6PS692P


#include "parserDef.h"


extern void tokenize(char *filename);
extern int getValueNonTerm(char* c);
extern int getValueTerm(char *c);

extern parseTree createList();

extern parseTree insertelem(parseTree head,char* data,int isLeaf,char* parentNode,tokenInfo TI);

extern Stack newStack(); 

extern Boolean push (Stack st, char* data, int prodRuleNo);

extern Boolean pop (Stack st, char* data);
extern Boolean top (Stack st, int* prodRuleNo );
extern int size(Stack st); 
extern void display (Stack); 

extern grammar create_gram(FILE *fp);
