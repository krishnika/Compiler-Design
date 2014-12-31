//-----BATCH 21------
//------KRISHNIKA AGARWAL 2011C6PS839P----
//------NAINCY SUMAN 2011C6PS692P----



#include "parser.h"


//-------------Function table------------------
struct parameter_list;
typedef struct parameter_list Par_list;
typedef Par_list* par_link;

struct parameter_list{
	char type[20];
	par_link par_next;
};

//


struct Fun_table{
	char symbol[45];
	char scope[45];
	tokenInfo TI;
	int scope_no;
	int in_par;
	int out_par;
	par_link in_parList;
	par_link out_parList;
};

typedef struct Fun_table *funTable;
funTable ftable;

//-------------------------------------------------


//-------------------Table Entry--------------------
//---------Linked list-------------------------
struct table_entry;
typedef struct table_entry entry;
typedef entry* t_link;

struct table_entry{
	int entry_present;
	char symbol[45];
	tokenInfo TI;
	//int value;
	char scope[45];
	int scope_no;
	char Type[30];
	int size;
	int offset;
	//int in_par;
	//int out_par;
	//t_link t_next;
	//f_link f_ptr; 
};

t_link symboltable;

//------------------------------------------------------

//----------------Scope_entry------------------
/*struct scope_entry;
typedef struct scope_entry s_entry;
typedef s_entry *s_link;
struct scope_entry{
	char scope[45];
	int scope_no;
	tokenInfo TI;
	t_link sLookup;
	//s_link snext;
};*/

typedef struct scope_node* scope_Elem; 

struct scope_node
{
	char scope[45];
	int scope_no;
	tokenInfo TI;
	//t_link sLookup;
	scope_Elem next;
};

typedef struct scope_stack *scope_Stack; 

struct scope_stack
{
	scope_Elem curr_scope;
	int size; 
};

scope_Stack SS;


//--------------------ast-----------------------------
struct astNode;
typedef struct astNode ast_Node;
typedef ast_Node* astLink;
astLink ast;
astLink ast_ptr;


struct astNode{
	tokenInfo TI;
	char lexeme[45];
	char op[10];
	int is_aleaf;
	int table_index;
	astLink a_child;
	astLink a_parent;
	astLink a_rightSib;
	astLink a_leftSib;
	//scope_Elem scope_ptr;
	//t_link lookup_ptr;
};

//-----------------------Error list-------------------
//-----------------------Dynamic Array-------------------
typedef struct ERROR_table error_table;
typedef error_table* e_table;
struct ERROR_table{
	int err_no;
	tokenInfo TI;
	e_table e_next;
};


e_table errorTable;
int error;

//---------------------Scope_stack-------------------------


//---------------------------------------------------------

char tag[LIM];
int scope_level;
int is_else;
int table_index;
int ftable_index;
int max_cap,max_cap1;




