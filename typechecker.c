//-----BATCH 21------
//------KRISHNIKA AGARWAL 2011C6PS839P----
//------NAINCY SUMAN 2011C6PS692P----

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "typechecker.h"

char* getType(astLink ptr){

	//char *type_int,*type_real,*type_string,*type_matrix,*type_error;

	char type_int[20],type_real[20],type_string[20],type_matrix[20],type_error[20];
	char* returntype;
	strcpy(type_int,"INT");
	strcpy(type_real,"REAL");
	strcpy(type_string,"STRING");
	strcpy(type_matrix,"MATRIX");
	strcpy(type_error,"ERROR");

	if(strcmp(ptr->lexeme,"arithmeticExpression")==0){
		//printf("\n1");
		char* type1;
		char* type2;
		if(ptr->a_child->a_rightSib!=NULL){
			//printf("\n1aaa");
			//strcpy(type2,getType(ptr->a_child->a_rightSib));
			type1=getType(ptr->a_child);
			type2=getType(ptr->a_child->a_rightSib);
			//printf("\n1xyyxx");
			//printf("\n%s\n",getType(ptr->a_child));
			//strcpy(type1,getType(ptr->a_child));
			
			//printf("\n1xxx**");
			
			//printf("\n1bbb");
			if(strcmp(ptr->op,"PLUS")==0){
				if(strcmp(type1,"INT")==0 && strcmp(type2,"INT")==0){
					//strcpy(returntype,type_int);
						return "INT";
				}
				else if(strcmp(type1,"REAL")==0 && strcmp(type2,"REAL")==0){
					//strcpy(returntype,type_real);
						return "REAL";
				}
				else if(strcmp(type1,"STRING")==0 && strcmp(type2,"STRING")==0){
					//strcpy(returntype,type_string);
						return "STRING";
				}
				else if(strcmp(type1,"MATRIX")==0 && strcmp(type2,"MATRIX")==0){
					//strcpy(returntype,type_matrix);
						return "MATRIX";
				}
				else{
					error++;
					//error
					//errorTable=insertError(errorTable, 15, ptr->TI);
					//strcpy(returntype,type_error);
						return "ERROR";
				}
			}
			else if(strcmp(ptr->op,"MINUS")==0){
				if(strcmp(type1,"INT")==0 && strcmp(type2,"INT")==0){
					//strcpy(returntype,type_int);
						return "INT";
				}
				else if(strcmp(type1,"REAL")==0 && strcmp(type2,"REAL")==0){
					//strcpy(returntype,type_real);
						return "REAL";
				}
				else if(strcmp(type1,"MATRIX")==0 && strcmp(type2,"MATRIX")==0){
					//strcpy(returntype,type_matrix);
						return "MATRIX";
				}
				else if(strcmp(type1,"STRING")==0 && strcmp(type2,"STRING")==0){
					//strcpy(returntype,type_matrix);
						error++;
						errorTable=insertError(errorTable, 10, ptr->TI);
						return "STRING";
				}
				else{
					error++;
					//errorTable=insertError(errorTable, 15, ptr->TI);
					//strcpy(returntype,type_error);
						return "ERROR";
				}
			}
			else if(strcmp(ptr->op,"MUL")==0){
				if(strcmp(getType(ptr->a_child),"INT")==0 && strcmp(type2,"INT")==0){
					//strcpy(returntype,type_int);
						return "INT";
				}
				else if(strcmp(type1,"REAL")==0 && strcmp(type2,"REAL")==0){
					//strcpy(returntype,type_real);
						return "REAL";
				}
				else if(strcmp(type1,"STRING")==0 && strcmp(type2,"STRING")==0){
					//strcpy(returntype,type_matrix);
						error++;
						errorTable=insertError(errorTable, 10, ptr->TI);
						return "STRING";
				}
				else if(strcmp(type1,"MATRIX")==0 && strcmp(type2,"MATRIX")==0){
					//strcpy(returntype,type_matrix);
						error++;
						errorTable=insertError(errorTable, 9, ptr->TI);
						return "MATRIX";
				}
				
				else{
					error++;
					//errorTable=insertError(errorTable, 15, ptr->TI);
					//strcpy(returntype,type_error);
						return "ERROR";
				}
			}
			else if(strcmp(ptr->op,"DIV")==0){
				if(strcmp(type1,"INT")==0 || strcmp(type1,"REAL")==0){
					if(strcmp(type1,"INT")==0 || strcmp(type2,"REAL")==0){
						//strcpy(returntype,type_real);
						return "REAL";
					}
					else if(strcmp(type1,"STRING")==0 && strcmp(type2,"STRING")==0){
					//strcpy(returntype,type_matrix);
						error++;
						errorTable=insertError(errorTable, 10, ptr->TI);
						return "STRING";
					}
					else if(strcmp(type1,"MATRIX")==0 && strcmp(type2,"MATRIX")==0){
					//strcpy(returntype,type_matrix);
						error++;
						errorTable=insertError(errorTable, 9, ptr->TI);
						return "MATRIX";
					}
					else{
						error++;
						//errorTable=insertError(errorTable, 15, ptr->TI);
						//strcpy(returntype,type_error);
						return "ERROR";
					}
				}
				else{
					error++;
					//errorTable=insertError(errorTable, 15, ptr->TI);
					//strcpy(returntype,type_error);
						return "ERROR";
				}
			}

		}
		else{
			//printf("\n1222");
			//printf("\n%s\n",ptr->a_child->lexeme);
			//strcpy(type2,getType(ptr->a_child));
			//printf("\n===33=\n");
			//return type1;
			return getType(ptr->a_child);
		}

	}

	if(strcmp(ptr->lexeme,"arithmeticprime")==0){
		char* type1;
		char* type2;
		if(ptr->a_child->a_rightSib!=NULL){
			
			//strcpy(type1,getType(ptr->a_child));
			//strcpy(type2,getType(ptr->a_child->a_rightSib));
			type1=getType(ptr->a_child);
			type2=getType(ptr->a_child->a_rightSib);
			
			if(strcmp(ptr->op,"PLUS")==0){
				if(strcmp(type1,"INT")==0 && strcmp(type2,"INT")==0){
					//strcpy(returntype,type_int);
						return "INT";
				}
				else if(strcmp(type1,"REAL")==0 && strcmp(type2,"REAL")==0){
					//strcpy(returntype,type_real);
						return "REAL";
				}
				else if(strcmp(type1,"STRING")==0 && strcmp(type2,"STRING")==0){
					//strcpy(returntype,type_string);
						return "STRING";
				}
				else if(strcmp(type1,"MATRIX")==0 && strcmp(type2,"MATRIX")==0){
					//strcpy(returntype,type_matrix);
						return "MATRIX";
				}
				else{
					error++;
					//errorTable=insertError(errorTable, 15, ptr->TI);
					//strcpy(returntype,type_error);
						return "ERROR";
				}
			}
			else if(strcmp(ptr->op,"MINUS")==0){
				if(strcmp(type1,"INT")==0 && strcmp(type2,"INT")==0){
					//strcpy(returntype,type_int);
						return "INT";
				}
				else if(strcmp(type1,"REAL")==0 && strcmp(type2,"REAL")==0){
					//strcpy(returntype,type_real);
						return "REAL";
				}
				else if(strcmp(type1,"MATRIX")==0 && strcmp(type2,"MATRIX")==0){
					//strcpy(returntype,type_matrix);
						return "MATRIX";
				}
				else if(strcmp(type1,"STRING")==0 && strcmp(type2,"STRING")==0){
					//strcpy(returntype,type_matrix);
						error++;
						errorTable=insertError(errorTable, 10, ptr->TI);
						return "STRING";
				}
				else{
					error++;
					//errorTable=insertError(errorTable, 15, ptr->TI);
					//strcpy(returntype,type_error);
						return "ERROR";
				}
			}
			else if(strcmp(ptr->op,"MUL")==0){
				if(strcmp(type1,"INT")==0 && strcmp(type2,"INT")==0){
					//strcpy(returntype,type_int);
						return "INT";
				}
				else if(strcmp(type1,"REAL")==0 && strcmp(type2,"REAL")==0){
					//strcpy(returntype,type_real);
						return "REAL";
				}
				else if(strcmp(type1,"STRING")==0 && strcmp(type2,"STRING")==0){
					//strcpy(returntype,type_matrix);
						error++;
						errorTable=insertError(errorTable, 10, ptr->TI);
						return "STRING";
				}
				else if(strcmp(type1,"MATRIX")==0 && strcmp(type2,"MATRIX")==0){
					//strcpy(returntype,type_matrix);
						error++;
						errorTable=insertError(errorTable, 9, ptr->TI);
						return "MATRIX";
				}
				
				else{
					error++;
					//errorTable=insertError(errorTable, 15, ptr->TI);
					//strcpy(returntype,type_error);
						return "ERROR";
				}
			}
			else if(strcmp(ptr->op,"DIV")==0){
				if(strcmp(type1,"INT")==0 || strcmp(type1,"REAL")==0){
					if(strcmp(type2,"INT")==0 || strcmp(type2,"REAL")==0){
						//strcpy(returntype,type_real);
						return "REAL";
					}
					else if(strcmp(type1,"STRING")==0 && strcmp(type2,"STRING")==0){
					//strcpy(returntype,type_matrix);
						error++;
						errorTable=insertError(errorTable, 10, ptr->TI);
						return "STRING";
					}
					else if(strcmp(type1,"MATRIX")==0 && strcmp(type2,"MATRIX")==0){
					//strcpy(returntype,type_matrix);
						error++;
						errorTable=insertError(errorTable, 9, ptr->TI);
						return "MATRIX";
					}
					else{
						error++;
						//errorTable=insertError(errorTable, 15, ptr->TI);
						//strcpy(returntype,type_error);
						return "ERROR";
					}
				}
				else{
					error++;
					//errorTable=insertError(errorTable, 15, ptr->TI);
					//strcpy(returntype,type_error);
						return "ERROR";
				}
			}

		}
		else{
			//strcpy(type1,getType(ptr->a_child));
			return getType(ptr->a_child);
		}

	}

	if(strcmp(ptr->lexeme,"arithmeticTerm")==0){
		char* type1;
		char* type2;
		//printf("\n441");
		if(ptr->a_child->a_rightSib!=NULL){
			//printf("\n661");
			//strcpy(type1,getType(ptr->a_child));
			//strcpy(type2,getType(ptr->a_child->a_rightSib));
			type1=getType(ptr->a_child);
			type2=getType(ptr->a_child->a_rightSib);
			
			if(strcmp(ptr->op,"PLUS")==0){
				if(strcmp(type1,"INT")==0 && strcmp(type2,"INT")==0){
					//strcpy(returntype,type_int);
					return "INT";
				}
				else if(strcmp(type1,"REAL")==0 && strcmp(type2,"REAL")==0){
					//strcpy(returntype,type_real);
					return "REAL";
				}
				else if(strcmp(type1,"STRING")==0 && strcmp(type2,"STRING")==0){
					//strcpy(returntype,type_string);
					return "STRING";
				}
				else if(strcmp(type1,"MATRIX")==0 && strcmp(type2,"MATRIX")==0){
					//strcpy(returntype,type_matrix);
					return "MATRIX";
				}
				else{
					error++;
					//errorTable=insertError(errorTable, 15, ptr->TI);
					//strcpy(returntype,type_error);
					return "ERROR";
				}
			}
			else if(strcmp(ptr->op,"MINUS")==0){
				if(strcmp(type1,"INT")==0 && strcmp(type2,"INT")==0){
					//strcpy(returntype,type_int);
					return "INT";
				}
				else if(strcmp(type1,"REAL")==0 && strcmp(type2,"REAL")==0){
					//strcpy(returntype,type_real);
					return "REAL";
				}
				else if(strcmp(type1,"MATRIX")==0 && strcmp(type2,"MATRIX")==0){
					//strcpy(returntype,type_matrix);
					return "MATRIX";
				}
				else if(strcmp(type1,"STRING")==0 && strcmp(type2,"STRING")==0){
					//strcpy(returntype,type_matrix);
						error++;
						errorTable=insertError(errorTable, 10, ptr->TI);
						return "STRING";
				}
				else{
					error++;
					//errorTable=insertError(errorTable, 15, ptr->TI);
					//strcpy(returntype,type_error);
					return "ERROR";
				}
			}
			else if(strcmp(ptr->op,"MUL")==0){
				if(strcmp(type1,"INT")==0 && strcmp(type2,"INT")==0){
					//strcpy(returntype,type_int);
					return "INT";
				}
				else if(strcmp(type1,"REAL")==0 && strcmp(type2,"REAL")==0){
					//strcpy(returntype,type_real);
					return "REAL";
				}
				else if(strcmp(type1,"STRING")==0 && strcmp(type2,"STRING")==0){
					//strcpy(returntype,type_matrix);
						error++;
						errorTable=insertError(errorTable, 10, ptr->TI);
						return "STRING";
				}
				else if(strcmp(type1,"MATRIX")==0 && strcmp(type2,"MATRIX")==0){
					//strcpy(returntype,type_matrix);
						error++;
						errorTable=insertError(errorTable, 9, ptr->TI);
						return "MATRIX";
				}
				
				else{
					error++;
					//errorTable=insertError(errorTable, 15, ptr->TI);
					//strcpy(returntype,type_error);
					return "ERROR";
				}
			}
			else if(strcmp(ptr->op,"DIV")==0){
				if(strcmp(type1,"INT")==0 || strcmp(type1,"REAL")==0){
					if(strcmp(type2,"INT")==0 || strcmp(type2,"REAL")==0){
						//strcpy(returntype,type_real);
						return "REAL";
					}
					else if(strcmp(type1,"STRING")==0 && strcmp(type2,"STRING")==0){
					//strcpy(returntype,type_matrix);
						error++;
						errorTable=insertError(errorTable, 10, ptr->TI);
						return "STRING";
					}
					else if(strcmp(type1,"MATRIX")==0 && strcmp(type2,"MATRIX")==0){
					//strcpy(returntype,type_matrix);
						error++;
						errorTable=insertError(errorTable, 9, ptr->TI);
						return "MATRIX";
					}
					else{
						error++;
						//errorTable=insertError(errorTable, 15, ptr->TI);
						//strcpy(returntype,type_error);
						return "ERROR";
					}
				}
				else{
					error++;
					//errorTable=insertError(errorTable, 15, ptr->TI);
					//strcpy(returntype,type_error);
					return "ERROR";
				}
			}

		}
		else{
			//printf("\n8881\n");
			//printf("%s\n",ptr->a_child->lexeme);
			//printf("%s\n",ptr->a_child->a_child->lexeme);
			//printf("\n98881\n");
			//strcpy(type1,getType(ptr->a_child));
			//printf("\n==22==\n");
			return getType(ptr->a_child);
			//printf("\n==$2==\n");
			//return type1;
		}

	}

	if(strcmp(ptr->lexeme,"termPrime")==0){
		char* type1;
		char* type2;
		if(ptr->a_child->a_rightSib!=NULL){
			
			//strcpy(type1,getType(ptr->a_child));
			//strcpy(type2,getType(ptr->a_child->a_rightSib));
			type1=getType(ptr->a_child);
			type2=getType(ptr->a_child->a_rightSib);
			
			if(strcmp(ptr->op,"PLUS")==0){
				if(strcmp(type1,"INT")==0 && strcmp(type2,"INT")==0){
					//strcpy(returntype,type_int);
					return "INT";
				}
				else if(strcmp(type1,"REAL")==0 && strcmp(type2,"REAL")==0){
					//strcpy(returntype,type_real);
					return "REAL";
				}
				else if(strcmp(type1,"STRING")==0 && strcmp(type2,"STRING")==0){
					//strcpy(returntype,type_string);
					return "STRING";
				}
				else if(strcmp(type1,"MATRIX")==0 && strcmp(type2,"MATRIX")==0){
					//strcpy(returntype,type_matrix);
					return "MATRIX";
				}
				else{
					error++;
					//errorTable=insertError(errorTable, 15, ptr->TI);
					//strcpy(returntype,type_error);
					return "ERROR";
				}
			}
			else if(strcmp(ptr->op,"MINUS")==0){
				if(strcmp(type1,"INT")==0 && strcmp(type2,"INT")==0){
					//strcpy(returntype,type_int);
					return "INT";
				}
				else if(strcmp(type1,"REAL")==0 && strcmp(type2,"REAL")==0){
					//strcpy(returntype,type_real);
					return "REAL";
				}
				else if(strcmp(type1,"MATRIX")==0 && strcmp(type2,"MATRIX")==0){
					//strcpy(returntype,type_matrix);
					return "MATRIX";
				}
				else if(strcmp(type1,"STRING")==0 && strcmp(type2,"STRING")==0){
					//strcpy(returntype,type_matrix);
						error++;
						errorTable=insertError(errorTable, 10, ptr->TI);
						return "STRING";
				}
				else{
					error++;
					//errorTable=insertError(errorTable, 15, ptr->TI);
					//strcpy(returntype,type_error);
					return "ERROR";
				}
			}
			else if(strcmp(ptr->op,"MUL")==0){
				if(strcmp(type1,"INT")==0 && strcmp(type2,"INT")==0){
					//strcpy(returntype,type_int);
					return "INT";
				}
				else if(strcmp(type1,"REAL")==0 && strcmp(type2,"REAL")==0){
					//strcpy(returntype,type_real);
					return "REAL";
				}
				else if(strcmp(type1,"STRING")==0 && strcmp(type2,"STRING")==0){
					//strcpy(returntype,type_matrix);
						error++;
						errorTable=insertError(errorTable, 10, ptr->TI);
						return "STRING";
				}
				else if(strcmp(type1,"MATRIX")==0 && strcmp(type2,"MATRIX")==0){
					//strcpy(returntype,type_matrix);
						error++;
						errorTable=insertError(errorTable, 9, ptr->TI);
						return "MATRIX";
				}
				
				else{
					error++;
					//errorTable=insertError(errorTable, 15, ptr->TI);
					//strcpy(returntype,type_error);
					return "ERROR";
				}
			}
			else if(strcmp(ptr->op,"DIV")==0){
				if(strcmp(type1,"INT")==0 || strcmp(type1,"REAL")==0){
					if(strcmp(type2,"INT")==0 || strcmp(type2,"REAL")==0){
						//strcpy(returntype,type_real);
						return "REAL";
					}
					else if(strcmp(type1,"STRING")==0 && strcmp(type2,"STRING")==0){
					//strcpy(returntype,type_matrix);
						error++;
						errorTable=insertError(errorTable, 10, ptr->TI);
						return "STRING";
					}
					else if(strcmp(type1,"MATRIX")==0 && strcmp(type2,"MATRIX")==0){
					//strcpy(returntype,type_matrix);
						error++;
						errorTable=insertError(errorTable, 9, ptr->TI);
						return "MATRIX";
					}
					else{
						error++;
						//errorTable=insertError(errorTable, 15, ptr->TI);
						//strcpy(returntype,type_error);
						return "ERROR";
					}
				}
				else{
					error++;
					//errorTable=insertError(errorTable, 15, ptr->TI);
					//strcpy(returntype,type_error);
					return "ERROR";
				}
			}

		}
		else{
			//printf("%s\n",ptr->a_child->lexeme);
			//strcpy(type1,getType(ptr->a_child));
			return getType(ptr->a_child);
		}

	}


	if(strcmp(ptr->lexeme,"var")==0){
		
		//printf("\n%s",ptr->a_child->lexeme);
		//printf("\n====\n");
		if(strcmp(ptr->a_child->lexeme,"NUM")==0){
			//strcpy(returntype,type_int);
			//printf("\n||====\n");
			return "INT";
		}
		else if(strcmp(ptr->a_child->lexeme,"RNUM")==0){
			//strcpy(returntype,type_real);
			return "REAL";
		}
		else if(strcmp(ptr->a_child->lexeme,"STR")==0){
			//printf("\n==~~==\n");
			//strcpy(returntype,type_string);
			//printf("\n===11=\n");
			return "STRING";
		}
		else if(strcmp(ptr->a_child->lexeme,"matrix")==0){
			//strcpy(returntype,type_matrix);
			return "MATRIX";
		}
		else if(strcmp(ptr->a_child->lexeme,"ID")==0){
			if(ptr->a_child->a_child==NULL){
				return symboltable[ptr->a_child->table_index].Type;
			}
			else{
				//strcpy(returntype,type_int);
				return "INT";
			}
		}
	}

	if(strcmp(ptr->lexeme,"sizeOp")==0){
		if(strcmp(symboltable[ptr->a_child->table_index].Type,"STRING")==0){
			//strcpy(returntype,type_int);
				return "INT";
		}
		else if(strcmp(symboltable[ptr->a_child->table_index].Type,"MATRIX")==0){
			//strcpy(returntype,type_matrix);
				return "MATRIX";
		}
		else{
			error++;
			//errorTable=insertError(errorTable, 15, ptr->TI);
			//strcpy(returntype,type_error);
				return "ERROR";
			//error
		}
	}



}

//-------------------------------------typechecker--------------------------------------------------

astLink typeChecker(astLink ptr)
{
	astLink ptr1, ptr2, ptr3;
	int a;
	
	if(strcmp(ptr->lexeme,"mainFunction")==0)
	{
		//printf("\n2");
		ptr  = ptr->a_child;
		ast = typeChecker(ptr);
		goto label;	
	}
	
	
	
	
	if(strcmp(ptr->lexeme,"stmtsAndFunctionDefs")==0){
		//printf("\n$$$%s$$\n",ptr->lexeme);
		ptr=ptr->a_child;
		while(ptr->a_rightSib!=NULL){
			//printf("\naaa$$$%s$$\n",ptr->lexeme);
			ast=typeChecker(ptr);
			//printf("__---__\n");
			//printf("\n$$##$%s$$\n",ptr->lexeme);
			ptr=ptr->a_rightSib;
			//printf("\n$$$%s$##$\n",ptr->lexeme);
		}
		if(ptr->a_rightSib==NULL){
		if(strcmp(ptr->lexeme,"END")!=0){
		ast=typeChecker(ptr);
		}
		}
		goto label;
	}
	
	
	
	if(strcmp(ptr->lexeme,"declarationStmt")==0 || strcmp(ptr->lexeme,"ioStmt")==0 /*|| strcmp(ptr->lexeme,"funCallStmt")==0*/)
	{
		goto label;
	}
	
	
	
	if(strcmp(ptr->lexeme,"conditionalStmt")==0)
	{
		ptr  = ptr->a_child;
		ptr1 = ptr; // ptr to IF
		//printf("\n4");
		if(ptr!=NULL)
		{
			ptr = ptr->a_child;
			ptr2 = ptr ;   // ptr to boolean
			//ptr = ptr->a_rightSib
			
			while(ptr!=NULL)
			{
				if(strcmp(ptr->TI.Tok_name,"ID")==0)
				{
					if(strcmp(symboltable[ptr->table_index].Type,"INT")==0 || strcmp(symboltable[ptr->table_index].Type,"REAL")==0)
					{
						goto label;
					}
					
					else
					{
						error++ ;
						errorTable=insertError(errorTable, 15, ptr->TI); // error = type does not match
					}
				}
				
				else
					ptr = ptr->a_child;
					
					
			}
			
			ptr = ptr2;
			ptr = ptr->a_rightSib;
			
			while(ptr!=NULL)
			{
				ast = typeChecker(ptr);
				ptr = ptr->a_rightSib;
			}
		
		}
		
		ptr = ptr1;
		ptr = ptr->a_rightSib;
		
		if(ptr==NULL)
		{
			goto label;
		}
		
		else
		{
			ptr = ptr->a_child;
			while(ptr!=NULL)
			{
				ast = typeChecker(ptr);
				ptr = ptr->a_rightSib;
			}
		}
	}	
		
	if(strcmp(ptr->lexeme,"assignmentStmt_type1")==0){
		char left_type[20],right_type[20];
		//printf("\n5");
		if(strcmp(ptr->a_child->a_rightSib->lexeme,"funCallStmt")!=0){
			
			strcpy(left_type,symboltable[ptr->a_child->table_index].Type);
			//printf("\n%s",ptr->a_child->TI.lex_name);
			//printf("\n'''\n");
			strcpy(right_type,getType(ptr->a_child->a_rightSib));
			//printf("\n''aa'\n");
			//printf("\n%s	%s\n",left_type,right_type);
			if(strcmp(right_type,"ERROR")==0){
				errorTable=insertError(errorTable, 15, ptr->TI);
				goto label;
			}
			else if(strcmp(right_type,left_type)==0){
				goto label;
			}
		
			else if(strcmp(right_type,left_type)!=0){
				error++;
				errorTable=insertError(errorTable, 15, ptr->TI);
				goto label;
			}
		}

		else{
			//funcallstmt
			int inputPar,count;
			count=0;
			astLink ptr1;
			ptr1=ptr->a_child->a_rightSib;
			par_link inList,outList;
			inList=ftable[ptr1->a_child->table_index].in_parList;
			outList=ftable[ptr1->a_child->table_index].out_parList;
			if(ftable[ptr1->a_child->table_index].out_par!=1){
				error++;
				errorTable=insertError(errorTable, 16, ptr->TI);
				goto label;
			}
			else{
				strcpy(left_type,symboltable[ptr->a_child->table_index].Type);
				if(strcmp(left_type,outList->type)!=0){
					error++;
					errorTable=insertError(errorTable, 3, ptr->TI);
				goto label;
				}
			}
			astLink ptr2,ptr3,ptr4;
			ptr2=ptr1->a_child;	//funid
			ptr3=ptr2->a_rightSib;	//inputparlist
			ptr4=ptr3->a_child;
			inputPar=ftable[ptr2->table_index].in_par;
			while(ptr4!=NULL){
				count++;
				ptr4=ptr4->a_rightSib;
			}
			//printf("\n..%d %d ..\n",inputPar,count);
			if(inputPar!=count){
				error++;
				errorTable=insertError(errorTable, 16, ptr->TI);
				goto label;
			}
			else{
			ptr4=ptr3->a_child;
			while(ptr4!=NULL){
				char* typet;
				typet=getType(ptr4);
				//printf("\nType check: %s %s\n",inList->type,symboltable[ptr4->a_child->table_index].Type);
				if(inList==NULL){
					break;
				}
				if(strcmp(inList->type,typet)!=0){
					error++;
					errorTable=insertError(errorTable, 3, ptr->TI);
					goto label;
				}
				else{
					ptr4=ptr4->a_rightSib;
					inList=inList->par_next;
				}
				
			}
			}
			
		}
		//printf("\npppp\n");
		goto label;

	}
	
	if(strcmp(ptr->lexeme,"assignmentStmt_type2")==0){
		char left_type[20],right_type[20];
		int count,check;
		char *types;
		count=0;
		check=1;
		//printf("\npppp1\n");
		if(strcmp(ptr->a_child->a_rightSib->lexeme,"sizeOp")==0){
			//printf("\npppp2\n");
			//printf("\n%s	%s\n",ptr->a_child->a_rightSib->a_child->lexeme,symboltable[ptr->a_child->a_rightSib->a_child->table_index].Type);
			types=symboltable[ptr->a_child->a_rightSib->a_child->table_index].Type;
			if(strcmp(types,"MATRIX")!=0){
			//	printf("\npppp3\n");
				error++;
				errorTable=insertError(errorTable, 15, ptr->TI);
				goto label;
			}
			else if(strcmp(types,"MATRIX")==0){
				//printf("\npppp33\n");
				astLink ptr1;
				ptr1=ptr->a_child->a_child;
				//printf("\npppp343\n");
				while(ptr1!=NULL){
					//printf("\npppp353\n");
					count++;
					ptr1=ptr1->a_rightSib;
				}
				if(count!=2){
					//printf("\npppp3753\n");
					error++;
					errorTable=insertError(errorTable, 15, ptr->TI);
					goto label;
				}
				else{
					//printf("\npppp99\n");
					ptr1=ptr->a_child->a_child;
					while(ptr1!=NULL){
			
						if(strcmp(symboltable[ptr1->table_index].Type,"INT")!=0){
							error++;
						errorTable=insertError(errorTable, 15, ptr->TI);
						goto label;
						}
						ptr1=ptr1->a_rightSib;
					}
				}
			}
		}
		else{
			//funcallstmt
			//printf("\npppp\n");
			int inputPar,count,outputPar,count1;
			count1=0;
			count=0;
			astLink ptr1,ptrx,ptry;
			ptr1=ptr->a_child->a_rightSib;
			par_link inList,outList;
			inList=ftable[ptr1->a_child->table_index].in_parList;
			outList=ftable[ptr1->a_child->table_index].out_parList;
			outputPar=ftable[ptr1->a_child->table_index].out_par;
			ptrx=ptr->a_child->a_child;
			while(ptrx!=NULL){
				count1++;
				ptrx=ptrx->a_rightSib;
			}
			if(outputPar!=count1){
				error++;
				errorTable=insertError(errorTable, 16, ptr->TI);
				goto label;
			}
			else{
			ptry=ptr->a_child->a_child;
			while(ptry!=NULL){
				if(strcmp(inList->type,symboltable[ptry->table_index].Type)!=0){
					error++;
				errorTable=insertError(errorTable, 3, ptr->TI);
				goto label;
				}
				else{
					ptry=ptry->a_rightSib;
					inList=inList->par_next;
				}
			}
			}
			


			astLink ptr2,ptr3,ptr4;
			ptr2=ptr1->a_child;	//funid
			ptr3=ptr2->a_rightSib;	//inputparlist
			ptr4=ptr3->a_child;
			inputPar=ftable[ptr2->table_index].in_par;
			while(ptr4!=NULL){
				count++;
				ptr4=ptr4->a_rightSib;
			}
			if(inputPar!=count){
				error++;
				errorTable=insertError(errorTable, 16, ptr->TI);
				goto label;
			}
			else{
			ptr4=ptr3->a_child;
			while(ptr4!=NULL){
				char* typet;
				typet=getType(ptr4);
				//printf("\nType check: %s %s\n",inList->type,symboltable[ptr4->a_child->table_index].Type);
				if(inList==NULL){
					break;
				}
				if(strcmp(inList->type,typet)!=0){
					error++;
					errorTable=insertError(errorTable, 3, ptr->TI);
					goto label;
				}
				else{
					ptr4=ptr4->a_rightSib;
					inList=inList->par_next;
				}
				
			}
			}
			
		}
		goto label;
		
	}

	if(strcmp(ptr->lexeme,"funCallStmt")==0){

		//funcallstmt
			//printf("\nentered funcall\n");
			int inputPar,count;
			count=0;
			astLink ptr1;
			ptr1=ptr->a_child;
			par_link inList,outList;
			inList=ftable[ptr1->table_index].in_parList;
			outList=ftable[ptr1->table_index].out_parList;
			if(outList!=NULL){
				//printf("\n1funcall\n");
				error++;
				errorTable=insertError(errorTable, 16, ptr->TI);
				goto label;
			}
			//printf("\n2funcall\n");
			astLink ptr2,ptr3,ptr4;
			//ptr2=ptr1->a_child;	//funid
			ptr3=ptr1->a_rightSib;	//inputparlist
			ptr4=ptr3->a_child;
			inputPar=ftable[ptr1->table_index].in_par;
			while(ptr4!=NULL){
				//printf("\n3funcall\n");
				count++;
				ptr4=ptr4->a_rightSib;
			}
			if(inputPar!=count){
				//printf("\n4funcall\n");
				error++;
				errorTable=insertError(errorTable, 16, ptr->TI);
				goto label;
			}
			else{
			ptr4=ptr3->a_child;
			//printf("\n4funcall\n");
			while(ptr4!=NULL){
				char* typet;
				typet=getType(ptr4);
				//printf("\nType check: %s %s\n",inList->type,symboltable[ptr4->a_child->table_index].Type);
				if(inList==NULL){
					break;
				}
				if(strcmp(inList->type,typet)!=0){
					error++;
					errorTable=insertError(errorTable, 3, ptr->TI);
					goto label;
				}
				else{
					ptr4=ptr4->a_rightSib;
					inList=inList->par_next;
				}
				
			}
			}
			//printf("\n6funcall\n");
		goto label;
	}
	
	if(strcmp(ptr->lexeme,"functionDef")==0){
		astLink ptr1;
		ptr1=ptr->a_child;
		while(ptr1->a_rightSib!=NULL){
			ptr1=ptr1->a_rightSib;
		}
		if(strcmp(ptr1->lexeme,"stmtsAndFunctionDefs")==0){
			ast = typeChecker(ptr1);
		}
		goto label;
	}




	label:
		//printf("\nlabel\n");
		return ast;
	
}		





