//-----BATCH 21------
//------KRISHNIKA AGARWAL 2011C6PS839P----
//------NAINCY SUMAN 2011C6PS692P----

#include "astOps.h"

void createast(char* lex, tokenInfo TI, int l)
{

ast_ptr =(astLink)malloc(sizeof(ast_Node));
strcpy(ast_ptr->TI.Tok_name,TI.Tok_name);
strcpy(ast_ptr->TI.lex_name,TI.lex_name);
ast_ptr->TI.attribute_int=TI.attribute_int;
ast_ptr->TI.line=TI.line;
ast_ptr->TI.attribute_float=TI.attribute_float;
strcpy(ast_ptr->lexeme,lex);
ast_ptr->table_index=-1;
//ast_ptr->TI = TI;
//ast_ptr->lexeme = lex;
ast_ptr->is_aleaf = l;
ast_ptr->a_child = NULL;
ast_ptr->a_parent = NULL;
ast_ptr->a_rightSib = NULL;
ast_ptr->a_leftSib = NULL;
//ast_ptr->scope_ptr=NULL;
//ast_ptr->lookup_ptr=NULL;
ast=ast_ptr;

}



// _______________________________________________________next______________________________________________________


void createChild(char* lex, tokenInfo TI, int l)
{
     astLink init;
     init=ast_ptr;
     if(ast_ptr->a_child==NULL)
     {
        ast_ptr->a_child =(astLink)malloc(sizeof(ast_Node));
       // ast_ptr->a_child->a_parent = ast_ptr;
	ast_ptr=ast_ptr->a_child;
	strcpy(ast_ptr->TI.Tok_name,TI.Tok_name);
	strcpy(ast_ptr->TI.lex_name,TI.lex_name);
	ast_ptr->TI.attribute_int=TI.attribute_int;
	ast_ptr->TI.line=TI.line;
	ast_ptr->TI.attribute_float=TI.attribute_float;
	strcpy(ast_ptr->lexeme,lex);
	ast_ptr->table_index=-1;
          //ast_ptr->TI = TI;
          //ast_ptr->lexeme = lex;
            ast_ptr->is_aleaf = l;
            ast_ptr->a_child = NULL;
            ast_ptr->a_parent = init;
            ast_ptr->a_rightSib = NULL;
            ast_ptr->a_leftSib = NULL;
		//ast_ptr->scope_ptr=NULL;
	//ast_ptr->lookup_ptr=NULL;
            //astLink = child;
     }


     else{
	ast_ptr=ast_ptr->a_child;
          while(ast_ptr-> a_rightSib != NULL)
          {
                ast_ptr = ast_ptr->a_rightSib;

                }

            ast_ptr->a_rightSib =(astLink)malloc(sizeof(ast_Node));
            ast_ptr->a_rightSib->a_leftSib = ast_ptr;
            ast_ptr = ast_ptr->a_rightSib;
        //astLink->a_child = ast_ptr;
         // ast_ptr->TI = TI;
          //ast_ptr->lexeme = lex;
	strcpy(ast_ptr->TI.Tok_name,TI.Tok_name);
	strcpy(ast_ptr->TI.lex_name,TI.lex_name);
	ast_ptr->TI.attribute_int=TI.attribute_int;
	ast_ptr->TI.line=TI.line;
	ast_ptr->table_index=-1;
	ast_ptr->TI.attribute_float=TI.attribute_float;
	strcpy(ast_ptr->lexeme,lex);
            ast_ptr->is_aleaf = l;
            ast_ptr->a_child = NULL;
            ast_ptr->a_parent = init;
            ast_ptr->a_rightSib = NULL;
	//ast_ptr->scope_ptr=NULL;
	//ast_ptr->lookup_ptr=NULL;

           // astLink = child;


          }

    // astLink = child;

	//printf("\n\n***%s\n",ast_ptr->a_parent->lexeme);
	//printf("!!!%s\n\n",ast_ptr->lexeme);


     }




     //---------------------------------------------next-----------------------------------------------------------


     void findParent(char* ch)
     {

		if(ast_ptr==NULL){
			//printf("\n888adddaa**bll\n");
			ast_ptr=ast_ptr->a_parent;
			//printf("\n888adddaabll\n");
			while(strcmp(ast_ptr->lexeme,ch)!=0){
				//printf("\n888aaabwwwll\n");
				ast_ptr=ast_ptr->a_parent;
				//printf("\n888xxxaaabll\n");
			}
		}
		//printf("\n888cccaabll\n");
		if((strcmp(ast_ptr->lexeme,ch)!=0)/* || (ast_ptr==NULL)*/){
			//printf("\n888adddaa**bll\n");
			//ast_ptr=ast_ptr->a_parent;
			//printf("\n888adddaabll\n");
			while(strcmp(ast_ptr->lexeme,ch)!=0){
				//printf("\n888aaabwwwll\n");
				ast_ptr=ast_ptr->a_parent;
				//printf("\n888xxxaaabll\n");
			}
		}
		//printf("\n888aaabll\n");
          /*astLink node;
           node = ast_ptr;
printf("\naa999bll\n");
           while(strcmp(node->lexeme, ch)!=0)
              {
		printf("\naaaa1000bll\n");
               node = node->a_parent;
		printf("\na111aabll\n");
              }
printf("\naaa6666abll\n");
              ast_ptr = node;*/



          }


void printast(astLink ptr, FILE* fp)
{
	//fprintf(fp,"

	if(ptr->a_parent==NULL){
		fprintf(fp,"ROOT	%-20s	%-10s	%-5d	%-20s	%-20s \n",ptr->lexeme,ptr->op,ptr->is_aleaf,ptr->TI.Tok_name,ptr->TI.lex_name);
		printf("ROOT	%-20s	%-10s	%-5d	%-20s	%-20s \n",ptr->lexeme,ptr->op,ptr->is_aleaf,ptr->TI.Tok_name,ptr->TI.lex_name);
ptr = ptr->a_child;
	}
     else{
     fprintf(fp,"%-20s	%-20s	%-10s	%-5d	%-20s	%-20s \n",ptr->a_parent->lexeme,ptr->lexeme,ptr->op,ptr->is_aleaf,ptr->TI.Tok_name,ptr->TI.lex_name);
	printf("%-20s	%-20s	%-10s	%-5d	%-20s	%-20s \n",ptr->a_parent->lexeme,ptr->lexeme,ptr->op,ptr->is_aleaf,ptr->TI.Tok_name,ptr->TI.lex_name);
ptr = ptr->a_child;}	
          
           while(ptr!=NULL){
//fprintf(fp,"%-20s	%-10s	%-5d	%-15s	%-15s \n",ptr->lexeme,ptr->op,ptr->is_aleaf,ptr->TI.Tok_name,ptr->TI.lex_name);
printast(ptr,fp);
ptr=ptr->a_rightSib;
     
     }
}

////




//-------------------------------------------------------------------------------------------------------

scope_Stack newSStack()
{
	scope_Stack st = (scope_Stack) malloc (sizeof (struct scope_stack)); 
	st->curr_scope=NULL;
	st->size=0; 
	
	return st; 
}

Boolean s_push (scope_Stack st, char* scope,int scope_no,tokenInfo TI)
{
	
	if (st==NULL)
		{
			printf("\n Error-Push: scope_Stack Non Existent");
			return FALSE;
		}
	
	scope_Elem el = (scope_Elem) malloc (sizeof (struct scope_node)); 
	el->next=NULL;
	//el->scope_record= scope_record;
	strcpy(el->scope,scope);
	el->scope_no=scope_no;
	strcpy(el->TI.lex_name,TI.lex_name);
	strcpy(el->TI.Tok_name,TI.Tok_name);
	el->TI.attribute_int = TI.attribute_int;
	el->TI.attribute_float = TI.attribute_float;
	el->TI.line = TI.line;
			
			if(st->curr_scope==NULL)
			{
				st->curr_scope=el;
				st->size=1;
			}
			else {
				el->next=st->curr_scope;
				st->curr_scope=el;
				st->size++;
			}
			return TRUE; 
	
	
}
Boolean s_pop (scope_Stack st)
{
	scope_Elem el=NULL;
	if (st==NULL)
		{
			printf("\n Error-Pop: scope_Stack Non Existent");
			return FALSE;
		}
	if (st->curr_scope==NULL)
		{
			printf("\n Error-Pop: Empty scope_Stack");
			return FALSE;
		}
	
	el=st->curr_scope;
	//*data=el->data;
	st->curr_scope=el->next;
	el->next=NULL;
	st->size--;
	//free(el);
	return TRUE; 	
}


/*Boolean curr_scope (scope_Stack st, int* data)
{
	scope_Elem el=NULL;
	if (st==NULL)
		{
			printf("\n Error-curr_scope: scope_Stack Non Existent");
			return FALSE;
		}
	if (st->curr_scope==NULL)
		{
			printf("\n Error-curr_scope: Empty scope_Stack");
			return FALSE;
		}
	
	el=st->curr_scope;
	*data=el->data;
	return TRUE; 	
}*/




int s_size(scope_Stack st)
{
if (st==NULL)
		{
			printf("\n Error-Pop: scope_Stack Non Existent");
			return -1;
		}
return st->size; 
}




/*void display (scope_Stack st)
{

	if (st==NULL)
		{
			printf("\n Error-Display: scope_Stack Non Existent");
			
		}
	else{
		printf("\n scope_Stack-Display : ");
		scope_Elem curr=st->curr_scope;
	
		while(curr!=NULL)
		{
			printf("\n %d", curr->data);
			curr=curr->next;
		}
		
		printf("\n scope_Stack-Display ends \n");
	
	}
	
}*/
//----------------------------------------------------error table------------------------------------



// main function
e_table createError()
{
	e_table head;
	head = NULL;
	return head;
}



e_table insertError(e_table head, int e_no, tokenInfo TI)
{
	e_table ptr = head;
	
	if(head==NULL)
	{
		head = (e_table)malloc(sizeof(error_table));
		head->err_no = e_no;
		strcpy(head->TI.Tok_name,TI.Tok_name);
		strcpy(head->TI.lex_name,TI.lex_name);
		head->TI.attribute_int = TI.attribute_int;
		head->TI.attribute_float = TI.attribute_float;
		head->TI.line = TI.line;
		head->e_next = NULL;	
	}
	
	else
	{
		while(ptr->e_next!=NULL)
		{
			ptr = ptr->e_next;
		}
		
		ptr->e_next = (e_table)malloc(sizeof(error_table));
		ptr = ptr->e_next;
		ptr->err_no = e_no;
		strcpy(ptr->TI.Tok_name,TI.Tok_name);
		strcpy(ptr->TI.lex_name,TI.lex_name);
		ptr->TI.attribute_int = TI.attribute_int;
		ptr->TI.attribute_float = TI.attribute_float;
		ptr->TI.line = TI.line;
		ptr->e_next = NULL;
	
	}
	
	return head;
}


void printError(e_table head)
{
	e_table ptr;
	ptr=head;
	if(ptr==NULL){
		printf("\n Code compiles successfully..........\n");
	}
	else{
	while(ptr!=NULL)
		{
			if(ptr->err_no==1){
				printf("line %d: multiple declarations\n",ptr->TI.line);
			}
			else if(ptr->err_no==2){
				printf("line %d: variable not declared\n",ptr->TI.line);
			}
			else if(ptr->err_no==3){
				printf("line %d: types of actual and formal input parameters do not match\n",ptr->TI.line);
			}
			else if(ptr->err_no==4){
				printf("line %d: output parameters not assigned a value \n",ptr->TI.line);
			}
			else if(ptr->err_no==5){
				printf("line %d: FunCall not invoked appropriately \n",ptr->TI.line);
			}
			else if(ptr->err_no==6){
				printf("line %d: conditional expression not of type boolean \n",ptr->TI.line);
			}
			else if(ptr->err_no==7){
				printf("line %d: function overloading not allowed \n",ptr->TI.line);
			}
			else if(ptr->err_no==8){
				printf("line %d: recursive functin definations not allowed \n",ptr->TI.line);
			}
			else if(ptr->err_no==9){
				printf("line %d: matrices cannot be multiplied or divided \n",ptr->TI.line);
				
			}
			else if(ptr->err_no==10){
				printf("line %d: strings cannot be subtracted, multiplied or divided \n",ptr->TI.line);
			}
			else if(ptr->err_no==11){
				printf("line %d: matrices not of same size \n",ptr->TI.line);
			}
			else if(ptr->err_no==12){
				printf("line %d: Size of the string or matrix should be computed at compile time \n",ptr->TI.line);
			}
			else if(ptr->err_no==13){
				printf("line %d: Type mismatch \n",ptr->TI.line);
			}
			else if(ptr->err_no==14){
				printf("line %d: Function not Declared \n",ptr->TI.line);
			}
			else if(ptr->err_no==15){
				printf("line %d: Type Mismatch \n",ptr->TI.line);
			}
			else if(ptr->err_no==16){
				printf("line %d: number of actual and formal input parameters do not match \n",ptr->TI.line);
			}

			/*printf("%-3d	%-16s %-16s %-3d	%-3f	%-3d \n",ptr->err_no,ptr->TI.Tok_name,ptr->TI.lex_name,ptr->TI.attribute_int,ptr->TI.attribute_float,ptr->TI.line);*/
			ptr = ptr->e_next;
		}
	}

}

//-----------------------------------------------par list--------------------------------------------------------


par_link createPar()
{
	par_link head;
	head = NULL;
	return head;
}



par_link insertpar(par_link head, char* type)
{
	par_link ptr = head;
	
	if(ptr==NULL)
	{
		ptr = (par_link)malloc(sizeof(Par_list));
		strcpy(ptr->type,type);
		ptr->par_next = NULL;	
	}
	
	else
	{
		while(ptr->par_next!=NULL)
		{
			ptr = ptr->par_next;
		}
		
		ptr->par_next = (par_link)malloc(sizeof(Par_list));
		ptr = ptr->par_next;
		strcpy(ptr->type,type);
		ptr->par_next = NULL;
	
	}
	
	return ptr;
}

