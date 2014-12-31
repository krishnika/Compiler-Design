// BATCH 21
// KRISHNIKA AGARWAL 2011C6PS839P
//NAINCY SUMAN 2011C6PS692P


#include "lexer.h"
#define NO_NONTERM 48
#define NO_TERM 40
#define LIM 91

//---parseTree----
struct p_list;
typedef struct p_list p_List;
typedef p_List* parseTree;

struct p_list{
	char data[45];
	int isLeaf;
	//int line;
	char parentNode[45];
	tokenInfo TI;
	parseTree p_next;
};

//---parseTree---
//---stack---

typedef struct node* Elem; 

struct node
{
	char data[45];
	int prodRule;
	Elem next;
};

typedef struct stack *Stack; 

struct stack
{
	Elem top;
	int size; 
};

typedef enum {FALSE=0, TRUE=1} Boolean; 

//---stack---
//---parseTable


typedef int table[NO_NONTERM][NO_TERM];

//--parseTable
//--grammar--

typedef struct production_rule{
	//int number;
	char nonTerm[LIM];
	Stack s;
}P_rule;
typedef P_rule* grammar;
//grammar G;

//--grammar---
//--enum---

typedef enum {
		 start,
                 mainFunction,
                 stmtsAndFunctionDefs,
                 RemainingStmts,
                 stmtOrFunctionDef,
                 stmt,
                 functionDef,
                 paramaters,
                 parameter_list,
                 type,
                 remainingList, 
                 declarationStmt,
                 var_list,
                 more_ids,
                 assignmentStmt_type1,
		 assignmentStmt_type2,
                 leftHandSide_singleVar,
		 leftHandSide_listVar,
                 rightHandSide_type1,
		 rightHandSide_type2,
                 conditionalStmt,
                 elsepart,
                 otherStmts,
                 ioStmt,
                 arithemeticExpression,
                 arithmeticprime,
                 arithmeticTerm,
                 termPrime,
                 factor,
                 addSub,
                 mulDiv,
                 boolExAll,
                 logicEx,
                 logicExPrime,
                 boolEx,
                 logicOp_1,
                 var1,
		 var,
		 var_next,
                 relationalOp,
                 matrix,
                 row,
                 moreRows,
                 moreNum,
                 funCallStmt,
		 inputParameterList,
		 listVar,
                 sizeOp 
                 }nonTerminals;      

		

typedef enum{
                MAIN=50,
                SQO=51,
                SQC=52,
                END=53,
                EPSILON=54,
                FUNCTION=55,
                ASSIGNOP=56,
                FUNID=57,
                INT=58,
                REAL=59,
                STRING=60,
                MATRIX=61,
                COMMA=62,
                SEMICOLON=63,
                ID=64,
                STR=65,
                OP=66,
                CL=67,
                ELSE=68,
                ENDIF=69,
                READ=70,
                PRINT=71,
                IF=72,
                PLUS=73,
                MINUS=74,
                MUL=75,
                DIV=76,
                NOT=77,
                AND=78,
                OR=79,
                NUM=80,
                RNUM=81,
                LT=82,
                LE=83,
                EQ=84,
                GT=85,
                GE=86,
                NE=87,
                SIZE=88,
                $=89
                }terminals;
