//-----BATCH 21------
//------KRISHNIKA AGARWAL 2011C6PS839P----
//------NAINCY SUMAN 2011C6PS692P----

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include "createAbstractSyntaxTree.h"

astLink createAbstractSyntaxTree(parseTree PT, parseTree p_head){
	FILE *fp4;
	//printf("\n((%s))\n",p_head->data);
	char c1[LIM];
	char c2[LIM];
	//char tag[LIM];
	//printf("aaaad");
	while(p_head!=NULL){
	//while(strcmp(p_head->data,"$")!=0 && p_head->p_next!=NULL){
	if(strcmp(p_head->data,"$")==0){
		//printf("\n\njjjjj\n");
		p_head=p_head->p_next;
		//return ast;
		//exit(0);
		goto labelxyz;
	}
	//printf("aaaac");
	if(strcmp(p_head->data,"start")==0 || strcmp(p_head->data,"stmtOrFunctionDef")==0 || strcmp(p_head->data,"stmt")==0 || strcmp(p_head->data,"leftHandSide_singleVar")==0 || strcmp(p_head->data,"leftHandSide_listVar")==0){
	
		p_head=p_head->p_next;
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}
	//printf("aaaae");

	if(strcmp(p_head->data,"mainFunction")==0){
		createast(p_head->data,p_head->TI,0);	//
		p_head=p_head->p_next;
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}
	//printf("aaaaf");

	if(strcmp(p_head->data,"stmtsAndFunctionDefs")==0){
		if(strcmp(p_head->data,ast_ptr->lexeme)==0){
			p_head=p_head->p_next;
			ast=createAbstractSyntaxTree(PT,p_head);
			goto labelxyz;
		}
		else{
			findParent(p_head->parentNode);		//
			createChild(p_head->data,p_head->TI,0);
			p_head=p_head->p_next;			
			ast=createAbstractSyntaxTree(PT,p_head);
			goto labelxyz;
		}
	}

//printf("aaaag");
	if(strcmp(p_head->data,"RemainingStmts")==0 || strcmp(p_head->data,"parameters")==0 || strcmp(p_head->data,"remainingList")==0|| strcmp(p_head->data,"rightHandSide_type1")==0 || strcmp(p_head->data,"rightHandSide_type2")==0 ||/* strcmp(p_head->data,"otherStmts")==0 || strcmp(p_head->data,"boolExAll")==0 ||*/ strcmp(p_head->data,"logicOp_1")==0 || strcmp(p_head->data,"relationalOp")==0 || strcmp(p_head->data,"factor")==0 || strcmp(p_head->data,"mulDiv")==0 || strcmp(p_head->data,"addSub")==0 || strcmp(p_head->data,"var1")==0 ||/* strcmp(p_head->data,"END")==0 ||*/ strcmp(p_head->data,"more_ids")==0){									////// || strcmp(p_head->data,"more_ids")==0 
		//printf("\nblab\n");
		//printf("\n%s\n",p_head->parentNode);
		findParent(p_head->parentNode);	//
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		//printf("\nblab\n");
		goto labelxyz;
	}
	
	if(strcmp(p_head->data,"END")==0){
		if(strcmp(p_head->parentNode,"mainFunction")==0){
			strcpy(c1,"stmtsAndFunctionDefs");
			findParent(c1);	//
			createChild(p_head->data,p_head->TI,1);
			p_head=p_head->p_next;			
			ast=createAbstractSyntaxTree(PT,p_head);
			//printf("\nblab\n");
			goto labelxyz;
		}
		else{
			//printf("\nblab\n");
			//printf("\n%s\n",p_head->parentNode);
			findParent(p_head->parentNode);	//
			p_head=p_head->p_next;			
			ast=createAbstractSyntaxTree(PT,p_head);
			//printf("\nblab\n");
			goto labelxyz;
		}
	}

	if(strcmp(p_head->data,"boolExAll")==0){
		if(strcmp(p_head->parentNode,"conditionalStmt")==0){
			strcpy(c1,"IF");
			findParent(c1);	//
			p_head=p_head->p_next;			
			ast=createAbstractSyntaxTree(PT,p_head);
			//printf("\nblab\n");
			goto labelxyz;
		}
		else{
			findParent(p_head->parentNode);	//
			p_head=p_head->p_next;			
			ast=createAbstractSyntaxTree(PT,p_head);
			//printf("\nblab\n");
			goto labelxyz;
		}
	}

	if(strcmp(p_head->data,"otherStmts")==0 ){
		//if(strcmp(p_head->parentNode,"otherStmts")==0){
			//printf("\n...%s....\n",tag);
			findParent(tag);	//
			p_head=p_head->p_next;			
			ast=createAbstractSyntaxTree(PT,p_head);
			//printf("\nblab\n");
			goto labelxyz;
		//}
	
	}
	
	/*if(strcmp(p_head->data,"more_ids")==0 ){
		findParent(p_head->parentNode);	//
		createChild(p_head->data,p_head->TI,0);
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
	}*/

	if(strcmp(p_head->data,"functionDef")==0){
		createChild(p_head->data,p_head->TI,0);
		strcpy(ast_ptr->op,"FUNCTION");	//
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}
	
	if(strcmp(p_head->data,"var_list")==0){
		//printf("\naaaabll\n");
		if(strcmp(p_head->data,ast_ptr->lexeme)==0){
			//printf("\nabbabll\n");
			p_head=p_head->p_next;
			ast=createAbstractSyntaxTree(PT,p_head);
			goto labelxyz;
		}
		else if(strcmp(ast_ptr->a_parent->lexeme,p_head->data)==0){	/////
				//printf("\naaccbll\n");
				ast_ptr=ast_ptr->a_parent;
				p_head=p_head->p_next;
				ast=createAbstractSyntaxTree(PT,p_head);
				goto labelxyz;
		}
		else{
			//printf("\naddabll\n");
			if(strcmp(p_head->parentNode,"leftHandSide_listVar")==0){
				strcpy(c1,"assignmentStmt_type2");
				findParent(c1);
			}
			else{
				findParent(p_head->parentNode);		/////
			}
			//printf("\naaaabll111\n");
			createChild(p_head->data,p_head->TI,0);
			//printf("\naaa22abll\n");
			p_head=p_head->p_next;	
			//printf("\na333aabll\n");		
			ast=createAbstractSyntaxTree(PT,p_head);
			//printf("\naa444bll\n");
			goto labelxyz;
		}
	}

	if(strcmp(p_head->data,"parameter_list")==0){
		if(strcmp(p_head->data,ast_ptr->lexeme)==0){
			//printf("\nabbabll\n");
			p_head=p_head->p_next;
			ast=createAbstractSyntaxTree(PT,p_head);
			goto labelxyz;
		}
		else{
			createChild(p_head->data,p_head->TI,0);
			//printf("\naaa22abll\n");
			p_head=p_head->p_next;	
			//printf("\na333aabll\n");		
			ast=createAbstractSyntaxTree(PT,p_head);
			//printf("\naa444bll\n");
			goto labelxyz;
		}
	}

	if(strcmp(p_head->data,"ioStmt")==0){
		createChild(p_head->data,p_head->TI,0);
		
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}
	
	if(strcmp(p_head->data,"type")==0 || strcmp(p_head->data,"declarationStmt")==0){
		createChild(p_head->data,p_head->TI,0);
		
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}
	
	if(strcmp(p_head->data,"INT")==0 || strcmp(p_head->data,"REAL")==0 || strcmp(p_head->data,"STRING")==0 || strcmp(p_head->data,"MATRIX")==0){
		createChild(p_head->data,p_head->TI,1);
		
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}
	
	if(strcmp(p_head->data,"assignmentStmt_type1")==0 || strcmp(p_head->data,"assignmentStmt_type2")==0){
		createChild(p_head->data,p_head->TI,0);
		strcpy(ast_ptr->op,"ASSIGNOP");	//
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}

	if(strcmp(p_head->data,"conditionalStmt")==0){
		createChild(p_head->data,p_head->TI,0);
		//strcpy(tag,"conditionalStmt");
		//strcpy(ast_ptr->op,"IF");	//
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}
	
	if(strcmp(p_head->data,"IF")==0){
		//findParent(p_head->parentNode);	//
		createChild(p_head->data,p_head->TI,0);
		strcpy(tag,p_head->data);
		strcpy(ast_ptr->op,"IF");	//
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}

	

	if(strcmp(p_head->data,"elsepart")==0){
		if(strcmp(p_head->p_next->data,"ELSE")==0){
			findParent(p_head->parentNode);	//
			createChild(p_head->data,p_head->TI,0);
			strcpy(tag,"elsepart");
			strcpy(ast_ptr->op,"ELSE");	//
			p_head=p_head->p_next;			
			ast=createAbstractSyntaxTree(PT,p_head);
			goto labelxyz;
		}
		else{
			findParent(p_head->parentNode);	//
			p_head=p_head->p_next;			
			ast=createAbstractSyntaxTree(PT,p_head);
			goto labelxyz;
		}
	}

	if(strcmp(p_head->data,"READ")==0 || strcmp(p_head->data,"PRINT")==0){
		findParent(p_head->parentNode);
		strcpy(ast_ptr->op,p_head->data);	//
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}

	/*if(strcmp(p_head->data,"PRINT")==0){
		createChild(p_head->data,p_head->TI,0);
		strcpy(ast_ptr->op,"PRINT");	//
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
	}*/
	
	if(strcmp(p_head->data,"logicEx")==0|| strcmp(p_head->data,"boolEx")==0){
		createChild(p_head->data,p_head->TI,0);
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}
	
	if(strcmp(p_head->data,"logicExPrime")==0){
		createChild(p_head->data,p_head->TI,0);
		strcpy(ast_ptr->op,"NOT");	//
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}

	if(strcmp(p_head->data,"LT")==0 || strcmp(p_head->data,"LE")==0 || strcmp(p_head->data,"EQ")==0 || strcmp(p_head->data,"GT")==0 || strcmp(p_head->data,"GE")==0 || strcmp(p_head->data,"NE")==0 || strcmp(p_head->data,"AND")==0 || strcmp(p_head->data,"OR")==0){
		strcpy(ast_ptr->op,p_head->data);
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}

	if(strcmp(p_head->data,"arithmeticExpression")==0){
		createChild(p_head->data,p_head->TI,0);
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}

	if(strcmp(p_head->data,"arithmeticTerm")==0/* || strcmp(p_head->data,"arithmeticprime")==0 || strcmp(p_head->data,"termPrime")==0*/){
		findParent(p_head->parentNode);	//
		createChild(p_head->data,p_head->TI,0);
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}

	if(strcmp(p_head->data,"arithmeticprime")==0){
		findParent(p_head->parentNode);
		if(strcmp(p_head->p_next->data,"addSub")==0){
			createChild(p_head->data,p_head->TI,0);
			p_head=p_head->p_next;			
			ast=createAbstractSyntaxTree(PT,p_head);
			goto labelxyz;
		}
		else{
			p_head=p_head->p_next;			
			ast=createAbstractSyntaxTree(PT,p_head);
			goto labelxyz;
		}
	}

	if(strcmp(p_head->data,"termPrime")==0){
		findParent(p_head->parentNode);
		if(strcmp(p_head->p_next->data,"mulDiv")==0){
			createChild(p_head->data,p_head->TI,0);
			p_head=p_head->p_next;			
			ast=createAbstractSyntaxTree(PT,p_head);
			goto labelxyz;
		}
		else{
			p_head=p_head->p_next;			
			ast=createAbstractSyntaxTree(PT,p_head);
			goto labelxyz;
		}
	}
	
	if(strcmp(p_head->data,"PLUS")==0 || strcmp(p_head->data,"MINUS")==0 || strcmp(p_head->data,"MUL")==0 || strcmp(p_head->data,"DIV")==0){
		strcpy(ast_ptr->a_parent->op,p_head->data);	//
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}

	if(strcmp(p_head->data,"ENDIF")==0){
		strcpy(c1,"conditionalStmt");
		findParent(c1);	//
		//ast_ptr=ast_ptr->a_parent;
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}

	if(strcmp(p_head->data,"ID")==0 || strcmp(p_head->data,"STR")==0 || strcmp(p_head->data,"NUM")==0 || strcmp(p_head->data,"RNUM")==0 || strcmp(p_head->data,"FUNID")==0){

		if(strcmp(p_head->parentNode,"var1")==0){
			strcpy(c1,"boolEx");
			findParent(c1);	//
			createChild(p_head->data,p_head->TI,1);
			p_head=p_head->p_next;			
			ast=createAbstractSyntaxTree(PT,p_head);
			goto labelxyz;
		}

		else if(strcmp(p_head->parentNode,"leftHandSide_singleVar")==0 || strcmp(p_head->parentNode,"leftHandSide_listVar")==0 || strcmp(p_head->parentNode,"moreNum")==0){
			createChild(p_head->data,p_head->TI,1);
			p_head=p_head->p_next;			
			ast=createAbstractSyntaxTree(PT,p_head);
			goto labelxyz;
		}
		else{
		findParent(p_head->parentNode);	//
		createChild(p_head->data,p_head->TI,1);
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
		}
	}
	
	if(strcmp(p_head->data,"sizeOp")==0){
		createChild(p_head->data,p_head->TI,0);
		strcpy(ast_ptr->op,"SIZE");	//
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}

	if(strcmp(p_head->data,"var")==0){
		createChild(p_head->data,p_head->TI,0);
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}
	
	if(strcmp(p_head->data,"var_next")==0){
		if(strcmp(p_head->p_next->data,"SQO")==0){
			findParent(p_head->parentNode);	/////
			createChild(p_head->data,p_head->TI,0);
			strcpy(ast_ptr->op,"matrix_element");	//
			
			p_head=p_head->p_next->p_next;
			createChild(p_head->data,p_head->TI,1);
			p_head=p_head->p_next->p_next;

			findParent(p_head->parentNode);	/////
			createChild(p_head->data,p_head->TI,1);
			p_head=p_head->p_next;

			ast=createAbstractSyntaxTree(PT,p_head);
			goto labelxyz;
		}
		else{
			p_head=p_head->p_next;			
			ast=createAbstractSyntaxTree(PT,p_head);
			goto labelxyz;
		}
	}

	if(strcmp(p_head->data,"matrix")==0){
		findParent(p_head->parentNode);	//
		createChild(p_head->data,p_head->TI,0);
		//strcpy(ast_ptr->op,"matrix");	//
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}

	if(strcmp(p_head->data,"row")==0){
		createChild(p_head->data,p_head->TI,0);
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}

	if(strcmp(p_head->data,"moreRows")==0){
		strcpy(c2,"matrix");
		findParent(c2);
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}

	if(strcmp(p_head->data,"funCallStmt")==0){
		createChild(p_head->data,p_head->TI,0);
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}

	if(strcmp(p_head->data,"inputParameterList")==0){
		if(strcmp(p_head->data,ast_ptr->lexeme)==0){
			p_head=p_head->p_next;
			ast=createAbstractSyntaxTree(PT,p_head);
			goto labelxyz;
		}
		else{
			findParent(p_head->parentNode);		/////
			createChild(p_head->data,p_head->TI,0);
			p_head=p_head->p_next;			
			ast=createAbstractSyntaxTree(PT,p_head);
			goto labelxyz;
		}
	}

	if(strcmp(p_head->data,"listVar")==0){
		findParent(p_head->parentNode);
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}

	if(strcmp(p_head->data,"COMMA")==0 || strcmp(p_head->data,"OP")==0 || strcmp(p_head->data,"SQO")==0 || strcmp(p_head->data,"SEMICOLON")==0){
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}

	if(strcmp(p_head->data,"CL")==0){
		if(strcmp(p_head->parentNode,"factor")==0){
			p_head=p_head->p_next;			
			ast=createAbstractSyntaxTree(PT,p_head);
			goto labelxyz;
		}
		else if(strcmp(p_head->parentNode,"conditionalStmt")==0){
			strcpy(c1,"IF");
			findParent(c1);
			p_head=p_head->p_next;			
			ast=createAbstractSyntaxTree(PT,p_head);
			goto labelxyz;
		}
		else{
			findParent(p_head->parentNode);	//
			p_head=p_head->p_next;			
			ast=createAbstractSyntaxTree(PT,p_head);
			goto labelxyz;
		}
	}

	if(strcmp(p_head->data,"moreNum")==0){
		strcpy(c1,"row");
		findParent(c1);
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
		goto labelxyz;
	}

	//write for moreNum
	/*if(strcmp(p_head->data,"MAIN")==0 || strcmp(p_head->data,"SQC")==0 || strcmp(p_head->data,"FUNCTION")==0 || strcmp(p_head->data,"IF")==0 || strcmp(p_head->data,"CL")==0 || strcmp(p_head->data,"ELSE")==0 || strcmp(p_head->data,"SIZE")==0){
		printf("\n\n\nllll\n");
		printf("\n%s\n",p_head->data);
		findParent(p_head->parentNode);	//
		p_head=p_head->p_next;			
		ast=createAbstractSyntaxTree(PT,p_head);
	}*/
	/*if(strcmp(p_head->data,"$")==0){
		printf("\n\njjjjj\n");
		//p_head=p_head->p_next;
		//return ast;
		fp4=fopen("astOut.txt","w");
				printast(ast,fp4);
				fclose(fp4);
		exit(0);
		break;
	}*/

	else{	
		if(strcmp(p_head->data,"$")==0){
		//printf("\n\njjjjj\n");
			p_head=p_head->p_next;
		//return ast;
		//exit(0);
			goto labelxyz;
		}
		else{

			//printf("\n\n\nllll\n");
			//printf("\n%s\n",p_head->data);
			if(strcmp(p_head->parentNode,"conditionalStmt")==0){
				strcpy(c1,"IF");
				findParent(c1);
			}
			if(strcmp(p_head->parentNode,"leftHandSide_listVar")==0){
				strcpy(c1,"assignmentStmt_type2");
				findParent(c1);
			}
			else{
				findParent(p_head->parentNode);	//
			}
			p_head=p_head->p_next;			
			ast=createAbstractSyntaxTree(PT,p_head);
			goto labelxyz;
		}
	}
	}
	labelxyz:
		return ast;
		//break;
}

////-----------------------------------------------------------------------------------------------------------------




extern astLink createSymbolTable(astLink ptr){
	//error=0
	//initialie this ast_ptr=ast
	//create new stack
	//initialize scope level
	//printf("\naammm\n");
	if(table_index==max_cap-1){
		//realloc
		max_cap=max_cap*2;
		symboltable=(t_link)realloc(symboltable,sizeof(entry)*max_cap);
	}
	if(ftable_index==max_cap1-1){
		//realloc
		max_cap1=max_cap1*2;
		ftable=(funTable)realloc(ftable,(sizeof(struct Fun_table))*100);
	}
	//printf("\n??%s\n",ptr->lexeme);
	Boolean b1,b2;
	char ch[45];
	int found,i;
	char var[45];
	
	if(strcmp(ptr->lexeme,"mainFunction")==0){
		//printf("\naammkkm\n");
		SS=newSStack();////////
		symboltable=(t_link)malloc((sizeof(entry))*100);
		ftable=(funTable)malloc((sizeof(struct Fun_table))*100);
		for(i=0;i<100;i++){
			symboltable[i].entry_present=0;
		}
		//printf("\naarrrmmm\n");
		b1=s_push(SS,ptr->lexeme,scope_level,ptr->TI);
		
		scope_level++;

		ptr=ast->a_child;
		ast=createSymbolTable(ptr);

		b2=s_pop(SS);//////
		goto label2;
		
	}

	if(strcmp(ptr->lexeme,"stmtsAndFunctionDefs")==0){
		//printf("\n$$$%s$$\n",ptr->lexeme);
		ptr=ptr->a_child;
		while(ptr->a_rightSib!=NULL){
			//printf("\naaa$$$%s$$\n",ptr->lexeme);
			ast=createSymbolTable(ptr);
			//printf("__---__\n");
			//printf("\n$$##$%s$$\n",ptr->lexeme);
			ptr=ptr->a_rightSib;
			//printf("\n$$$%s$##$\n",ptr->lexeme);
		}
		if(ptr->a_rightSib==NULL){
		if(strcmp(ptr->lexeme,"END")!=0){
		ast=createSymbolTable(ptr);
		}
		}
		goto label2;
	}


	if(strcmp(ptr->lexeme,"declarationStmt")==0){
		char type[45];
		strcpy(type,ptr->a_child->a_child->lexeme);
		ptr=ptr->a_child->a_rightSib;
		ptr=ptr->a_child;
		while(ptr!=NULL){
			found=0;
			//printf("||%s\n",ptr->lexeme);
			//printf("||||%s\n",ptr->TI.lex_name);
			//printf("\nscope %d\n",scope_level);
			strcpy(var,ptr->TI.lex_name);
			if(table_index==0){
				//insert entry
				strcpy(symboltable[table_index].symbol,var);
				strcpy(symboltable[table_index].Type,type);
				strcpy(symboltable[table_index].scope,SS->curr_scope->scope);
				symboltable[table_index].scope_no=SS->curr_scope->scope_no;
				//printf("\nscope %d	%d\n",SS->curr_scope->scope_no,symboltable[table_index].scope_no);
				symboltable[table_index].size=-1;
				symboltable[table_index].offset=-1;
				symboltable[table_index].entry_present=1;
				
				strcpy(symboltable[table_index].TI.lex_name,ptr->TI.lex_name);
				strcpy(symboltable[table_index].TI.Tok_name,ptr->TI.Tok_name);
				symboltable[table_index].TI.attribute_int = ptr->TI.attribute_int;
				symboltable[table_index].TI.attribute_float = ptr->TI.attribute_float;
				symboltable[table_index].TI.line = ptr->TI.line;

				ptr->table_index=table_index;
				table_index++;
				//printf("\ntable_index	%d\n",table_index);
			}
			else{
				for(i=0;i<=table_index;i++){
					//printf("\n~%s-%s	~%s-%s	~%d-%d\n",symboltable[i].symbol,var,symboltable[i].scope,SS->curr_scope->scope,symboltable[i].scope_no,SS->curr_scope->scope_no);
					if(strcmp(symboltable[i].symbol,var)==0 && strcmp(symboltable[i].scope,SS->curr_scope->scope)==0 /*&& symboltable[i].scope_no==SS->curr_scope->scope_no*/){
						found=1;
						//printf("\nfound	%d\n",found);
						break;
					}
				}
				//printf("\nfound	%d\n",found);
				if(found==0){
					//insert entry
					strcpy(symboltable[table_index].symbol,var);
					strcpy(symboltable[table_index].Type,type);
					strcpy(symboltable[table_index].scope,SS->curr_scope->scope);
					symboltable[table_index].scope_no=SS->curr_scope->scope_no;
					//printf("\nscope %d	%d\n",SS->curr_scope->scope_no,symboltable[table_index].scope_no);
					symboltable[table_index].size=-1;
					symboltable[table_index].offset=-1;
					symboltable[table_index].entry_present=1;
				
					strcpy(symboltable[table_index].TI.lex_name,ptr->TI.lex_name);
					strcpy(symboltable[table_index].TI.Tok_name,ptr->TI.Tok_name);
					symboltable[table_index].TI.attribute_int = ptr->TI.attribute_int;
					symboltable[table_index].TI.attribute_float = ptr->TI.attribute_float;
					symboltable[table_index].TI.line = ptr->TI.line;
					ptr->table_index=table_index;
					table_index++;
					//printf("\ntable_index	%d\n",table_index);
				}
				else{
					//error
						error++;
						errorTable=insertError(errorTable, 1, ptr->TI);
				}
			}
		ptr=ptr->a_rightSib;
		}
		goto label2;
	}


	if(strcmp(ptr->lexeme,"conditionalStmt")==0){
		ptr=ptr->a_child;
		ast=createSymbolTable(ptr);
		if(ptr->a_rightSib!=NULL){
			ptr=ptr->a_rightSib;
			ast=createSymbolTable(ptr);
		}
		goto label2;
	}


	if(strcmp(ptr->lexeme,"IF")==0){
		
		b1=s_push(SS,ptr->lexeme,scope_level,ptr->TI);
		//SS->curr_scope->sLookup=createST();
		//ptr->scope_ptr=SS->curr_scope;
		scope_level++;

		ptr=ptr->a_child;
		while(ptr->a_rightSib!=NULL){
			ast=createSymbolTable(ptr);
			ptr=ptr->a_rightSib;
		}
		ast=createSymbolTable(ptr);
		//ptr->lookup_ptr=SS->curr_scope->sLookup;
		b2=s_pop(SS);/////
		goto label2;
		
	}

	if(strcmp(ptr->lexeme,"elsepart")==0){
		
		b1=s_push(SS,ptr->lexeme,scope_level,ptr->TI);
		//SS->curr_scope->sLookup=createST();
		//ptr->scope_ptr=SS->curr_scope;
		scope_level++;

		ptr=ptr->a_child;
		while(ptr->a_rightSib!=NULL){
			ast=createSymbolTable(ptr);
			ptr=ptr->a_rightSib;
		}
		ast=createSymbolTable(ptr);
		//ptr->lookup_ptr=SS->curr_scope->sLookup;
		b2=s_pop(SS);/////
		goto label2;
		
	}

	if(strcmp(ptr->lexeme,"logicExPrime")==0){
		ptr=ptr->a_child;
		ast=createSymbolTable(ptr);
		goto label2;
	}

	if(strcmp(ptr->lexeme,"logicEx")==0){
		ptr=ptr->a_child;
		ast=createSymbolTable(ptr);
		ptr=ptr->a_rightSib;
		ast=createSymbolTable(ptr);
		goto label2;
	}

	if(strcmp(ptr->lexeme,"boolEx")==0){
		ptr=ptr->a_child;
		if(strcmp(ptr->lexeme,"ID")==0){
			found=0;
			strcpy(var,ptr->TI.lex_name);
			scope_Elem pres_scope;
			pres_scope=SS->curr_scope->next;
			//printf("\n%s	%s	%s\n",pres_scope->scope,pres_scope->next->scope,pres_scope->next->sLookup->symbol);
			while(found!=1 ){
				//printf("\n:;yy;;;\n");
				for(i=0;i<=table_index;i++){
					//printf("\n~%s-%s	~%s-%s	~%d-%d\n",symboltable[i].symbol,var,symboltable[i].scope,pres_scope->scope,symboltable[i].scope_no,pres_scope->scope_no);
					if(strcmp(symboltable[i].symbol,var)==0 && strcmp(symboltable[i].scope,pres_scope->scope)==0 /*&& symboltable[i].scope_no==pres_scope->scope_no*/){
						found=1;
						ptr->table_index=i;
						//printf("\nfound	%d	%d\n",found,i);
						break;
					}
				}
				//printf("\n<<<%s	%d>>>\n",var,found);
				//printf("\n:;;;;ss\n");
				pres_scope=pres_scope->next;
				if(pres_scope==NULL){
					//printf("\nNULL\n");
					break;
				}
				//printf("\n:;;aaa;;\n");
			}
			//printf("\n:;;aa====\n");
			if(found==0){
				//printf("\n:;;aa((a;;\n");
				error++;
				///error var undeclared
				errorTable=insertError(errorTable, 2, ptr->TI);
			}
			
		}
		ptr=ptr->a_rightSib;
		if(strcmp(ptr->lexeme,"ID")==0){
			found=0;
			strcpy(var,ptr->TI.lex_name);
			scope_Elem pres_scope;
			pres_scope=SS->curr_scope->next;
			//printf("\n%s	%s	%s\n",pres_scope->scope,pres_scope->next->scope,pres_scope->next->sLookup->symbol);
			while(found!=1 ){
				//printf("\n:;yy;;;\n");
				for(i=0;i<=table_index;i++){
					//printf("\n~%s-%s	~%s-%s	~%d-%d\n",symboltable[i].symbol,var,symboltable[i].scope,pres_scope->scope,symboltable[i].scope_no,pres_scope->scope_no);
					if(strcmp(symboltable[i].symbol,var)==0 && strcmp(symboltable[i].scope,pres_scope->scope)==0 /* && symboltable[i].scope_no==pres_scope->scope_no*/){
						found=1;
						ptr->table_index=i;
						//printf("\nfound	%d	%d\n",found,i);
						break;
					}
				}
				//printf("\n<<<%s	%d>>>\n",var,found);
				//printf("\n:;;;;ss\n");
				pres_scope=pres_scope->next;
				if(pres_scope==NULL){
					//printf("\nNULL\n");
					break;
				}
				//printf("\n:;;aaa;;\n");
			}
			//printf("\n:;;aa====\n");
			if(found==0){
				//printf("\n:;;aa((a;;\n");
				error++;
				///error var undeclared
				errorTable=insertError(errorTable, 2, ptr->TI);
			}
			
		}
		goto label2;
	}

	
		if(strcmp(ptr->lexeme,"ioStmt")==0){
			ptr=ptr->a_child;
			if(strcmp(ptr->lexeme,"ID")==0){
			found=0;
			strcpy(var,ptr->TI.lex_name);
			scope_Elem pres_scope;
			pres_scope=SS->curr_scope;
			//printf("\n%s	%s	%s\n",pres_scope->scope,pres_scope->next->scope,pres_scope->next->sLookup->symbol);
			while(found!=1 ){
				//printf("\n:;yy;;;\n");
				for(i=0;i<=table_index;i++){
					//printf("\n~%s-%s	~%s-%s	~%d-%d\n",symboltable[i].symbol,var,symboltable[i].scope,pres_scope->scope,symboltable[i].scope_no,pres_scope->scope_no);
					if(strcmp(symboltable[i].symbol,var)==0 && strcmp(symboltable[i].scope,pres_scope->scope)==0 /*&& symboltable[i].scope_no==pres_scope->scope_no*/){
						found=1;
						ptr->table_index=i;
						//printf("\nfound	%d	%d\n",found,i);
						break;
					}
				}
				//printf("\n<<<%s	%d>>>\n",var,found);
				//printf("\n:;;;;ss\n");
				pres_scope=pres_scope->next;
				if(pres_scope==NULL){
					//printf("\nNULL\n");
					break;
				}
				//printf("\n:;;aaa;;\n");
			}
			//printf("\n:;;aa====\n");
			if(found==0){
				//printf("\n:;;aa((a;;\n");
				error++;
				///error var undeclared
				errorTable=insertError(errorTable, 2, ptr->TI);
			}
			
		}
		goto label2;
		}


	if(strcmp(ptr->lexeme,"assignmentStmt_type1")==0){
		ptr=ptr->a_child;
		if(strcmp(ptr->lexeme,"ID")==0){
			found=0;
			strcpy(var,ptr->TI.lex_name);
			scope_Elem pres_scope;
			pres_scope=SS->curr_scope;
			//printf("\n%s	%s	%s\n",pres_scope->scope,pres_scope->next->scope,pres_scope->next->sLookup->symbol);
			while(found!=1 ){
				//printf("\n:;yy;;;\n");
				for(i=0;i<=table_index;i++){
					//printf("\n~%s-%s	~%s-%s	~%d-%d\n",symboltable[i].symbol,var,symboltable[i].scope,pres_scope->scope,symboltable[i].scope_no,pres_scope->scope_no);
					if(strcmp(symboltable[i].symbol,var)==0 && strcmp(symboltable[i].scope,pres_scope->scope)==0 /*&& symboltable[i].scope_no==pres_scope->scope_no*/){
						found=1;
						ptr->table_index=i;
						//printf("\nfound	%d	%d\n",found,i);
						break;
					}
				}
				//printf("\n<<<%s	%d>>>\n",var,found);
				//printf("\n:;;;;ss\n");
				pres_scope=pres_scope->next;
				if(pres_scope==NULL){
					//printf("\nNULL\n");
					break;
				}
				//printf("\n:;;aaa;;\n");
			}
			//printf("\n:;;aa====\n");
			if(found==0){
				//printf("\n:;;aa((a;;\n");
				error++;
				///error var undeclared
				errorTable=insertError(errorTable, 2, ptr->TI);
			}
			
		}

		ptr=ptr->a_rightSib;
		ast=createSymbolTable(ptr);
		goto label2;
	}

	if(strcmp(ptr->lexeme,"sizeOp")==0){
		ptr=ptr->a_child;
		if(strcmp(ptr->lexeme,"ID")==0){
			found=0;
			strcpy(var,ptr->TI.lex_name);
			scope_Elem pres_scope;
			pres_scope=SS->curr_scope;
			//printf("\n%s	%s	%s\n",pres_scope->scope,pres_scope->next->scope,pres_scope->next->sLookup->symbol);
			while(found!=1 ){
				//printf("\n:;yy;;;\n");
				for(i=0;i<=table_index;i++){
					//printf("\n~%s-%s	~%s-%s	~%d-%d\n",symboltable[i].symbol,var,symboltable[i].scope,pres_scope->scope,symboltable[i].scope_no,pres_scope->scope_no);
					if(strcmp(symboltable[i].symbol,var)==0 && strcmp(symboltable[i].scope,pres_scope->scope)==0 /* && symboltable[i].scope_no==pres_scope->scope_no*/){
						found=1;
						ptr->table_index=i;
						//printf("\nfound	%d	%d\n",found,i);
						break;
					}
				}
				//printf("\n<<<%s	%d>>>\n",var,found);
				//printf("\n:;;;;ss\n");
				pres_scope=pres_scope->next;
				if(pres_scope==NULL){
					//printf("\nNULL\n");
					break;
				}
				//printf("\n:;;aaa;;\n");
			}
			//printf("\n:;;aa====\n");
			if(found==0){
				//printf("\n:;;aa((a;;\n");
				error++;
				///error var undeclared
				errorTable=insertError(errorTable, 2, ptr->TI);
			}
			
		}
		goto label2;
	}
	
	if(strcmp(ptr->lexeme,"arithmeticExpression")==0){
		ptr=ptr->a_child;
		while(ptr!=NULL){
			ast=createSymbolTable(ptr);
			ptr=ptr->a_rightSib;
		}
		//ast=createSymbolTable(ptr);
		goto label2;
	}

	if(strcmp(ptr->lexeme,"arithmeticprime")==0){
		ptr=ptr->a_child;
		while(ptr!=NULL){
			ast=createSymbolTable(ptr);
			ptr=ptr->a_rightSib;
		}
		//ast=createSymbolTable(ptr);
		goto label2;
	}

	if(strcmp(ptr->lexeme,"arithmeticTerm")==0){
		ptr=ptr->a_child;
		while(ptr!=NULL){
			ast=createSymbolTable(ptr);
			ptr=ptr->a_rightSib;
		}
		//ast=createSymbolTable(ptr);
		goto label2;
	}


	if(strcmp(ptr->lexeme,"termPrime")==0){
		ptr=ptr->a_child;
		while(ptr!=NULL){
			ast=createSymbolTable(ptr);
			ptr=ptr->a_rightSib;
		}
		//ast=createSymbolTable(ptr);
		goto label2;
	}
	

	if(strcmp(ptr->lexeme,"var")==0){
		ptr=ptr->a_child;
		if(strcmp(ptr->lexeme,"ID")==0){
			found=0;
			strcpy(var,ptr->TI.lex_name);
			scope_Elem pres_scope;
			pres_scope=SS->curr_scope;
			//printf("\n%s	%s	%s\n",pres_scope->scope,pres_scope->next->scope,pres_scope->next->sLookup->symbol);
			while(found!=1 ){
				//printf("\n:;yy;;;\n");
				for(i=0;i<=table_index;i++){
					//printf("\n~%s-%s	~%s-%s	~%d-%d\n",symboltable[i].symbol,var,symboltable[i].scope,pres_scope->scope,symboltable[i].scope_no,pres_scope->scope_no);
					if(strcmp(symboltable[i].symbol,var)==0 && strcmp(symboltable[i].scope,pres_scope->scope)==0 /*&& symboltable[i].scope_no==pres_scope->scope_no*/){
						found=1;
						ptr->table_index=i;
						//printf("\nfound	%d	%d\n",found,i);
						break;
					}
				}
				//printf("\n<<<%s	%d>>>\n",var,found);
				//printf("\n:;;;;ss\n");
				pres_scope=pres_scope->next;
				if(pres_scope==NULL){
					//printf("\nNULL\n");
					break;
				}
				//printf("\n:;;aaa;;\n");
			}
			//printf("\n:;;aa====\n");
			if(found==0){
				//printf("\n:;;aa((a;;\n");
				error++;
				///error var undeclared
				errorTable=insertError(errorTable, 2, ptr->TI);
			}
			
		}
		goto label2;
	}


	if(strcmp(ptr->lexeme,"assignmentStmt_type2")==0){
		ptr=ptr->a_child;
		ast=createSymbolTable(ptr);
		ptr=ptr->a_rightSib;
		ast=createSymbolTable(ptr);
		goto label2;
	}

	if(strcmp(ptr->lexeme,"var_list")==0){
		ptr=ptr->a_child;
		while(ptr!=NULL){
			if(strcmp(ptr->lexeme,"ID")==0){
			found=0;
			strcpy(var,ptr->TI.lex_name);
			scope_Elem pres_scope;
			pres_scope=SS->curr_scope;
			//printf("\n%s	%s	%s\n",pres_scope->scope,pres_scope->next->scope,pres_scope->next->sLookup->symbol);
			while(found!=1 ){
				//printf("\n:;yy;;;\n");
				for(i=0;i<=table_index;i++){
					//printf("\n~%s-%s	~%s-%s	~%d-%d\n",symboltable[i].symbol,var,symboltable[i].scope,pres_scope->scope,symboltable[i].scope_no,pres_scope->scope_no);
					if(strcmp(symboltable[i].symbol,var)==0 && strcmp(symboltable[i].scope,pres_scope->scope)==0 /*&& symboltable[i].scope_no==pres_scope->scope_no*/){
						found=1;
						ptr->table_index=i;
						//printf("\nfound	%d	%d\n",found,i);
						break;
					}
				}
				//printf("\n<<<%s	%d>>>\n",var,found);
				//printf("\n:;;;;ss\n");
				pres_scope=pres_scope->next;
				if(pres_scope==NULL){
					//printf("\nNULL\n");
					break;
				}
				//printf("\n:;;aaa;;\n");
			}
			//printf("\n:;;aa====\n");
			if(found==0){
				//printf("\n:;;aa((a;;\n");
				error++;
				///error var undeclared
				errorTable=insertError(errorTable, 2, ptr->TI);
			}
			
		}
		ptr=ptr->a_rightSib;
		}
		goto label2;
	}

	if(strcmp(ptr->lexeme,"functionDef")==0){
		int out_par, fun_index;
		char type[45],var[45];
		out_par=0;
		astLink ptr1;
		astLink par_left,fun_ptr,par_right,ptr_next;

		if(strcmp(ptr->a_child->lexeme,"parameter_list")==0){
			par_left=ptr->a_child;
			fun_ptr=ptr->a_child->a_rightSib;
			
			if(strcmp(fun_ptr->a_rightSib->lexeme,"parameter_list")==0){
				par_right=fun_ptr->a_rightSib;
				ptr_next=par_right->a_rightSib;
			}
			else{
				par_right=NULL;
				ptr_next=fun_ptr->a_rightSib;
			}
		}
		else{
			par_left=NULL;
			fun_ptr=ptr->a_child;

			if(strcmp(fun_ptr->a_rightSib->lexeme,"parameter_list")==0){
				par_right=fun_ptr->a_rightSib;
				ptr_next=par_right->a_rightSib;
			}
			else{
				par_right=NULL;
				ptr_next=fun_ptr->a_rightSib;
			}
		}

		//for funid
		strcpy(var,fun_ptr->TI.lex_name);
		if(ftable_index==0){
			strcpy(ftable[ftable_index].symbol,var);
				
				strcpy(ftable[ftable_index].scope,SS->curr_scope->scope);
				ftable[ftable_index].scope_no=SS->curr_scope->scope_no;
				//printf("\nscope %d	%d\n",SS->curr_scope->scope_no,ftable[ftable_index].scope_no);
				ftable[ftable_index].in_par=0;
				ftable[ftable_index].out_par=0;
				
				strcpy(ftable[ftable_index].TI.lex_name,fun_ptr->TI.lex_name);
				strcpy(ftable[ftable_index].TI.Tok_name,fun_ptr->TI.Tok_name);
				ftable[ftable_index].TI.attribute_int = fun_ptr->TI.attribute_int;
				ftable[ftable_index].TI.attribute_float = fun_ptr->TI.attribute_float;
				ftable[ftable_index].TI.line = fun_ptr->TI.line;
				ftable[ftable_index].in_parList=createPar();
				ftable[ftable_index].out_parList=createPar();

				fun_ptr->table_index=ftable_index;
				fun_index=ftable_index;
				ftable_index++;
				//printf("\ntable_index	%d\n",ftable_index);
		}
		else{
			scope_Elem pres_scope;
			pres_scope=SS->curr_scope;

			while(pres_scope!=NULL){
				for(i=0;i<=ftable_index;i++){
					//printf("\n~%s-%s	~%s-%s	~%d-%d\n",ftable[i].symbol,var,ftable[i].scope,pres_scope->scope,ftable[i].scope_no,pres_scope->scope_no);
					if(strcmp(ftable[i].symbol,var)==0 && strcmp(ftable[i].scope,pres_scope->scope)==0 /*&& ftable[i].scope_no==pres_scope->scope_no*/){
						found=1;
						//ptr->table_index=i;
						//printf("\nfound	%d	%d\n",found,i);
						//break;
					}
				}
				pres_scope=pres_scope->next;
			}
			if(found==1){
				error++;
				errorTable=insertError(errorTable, 7, ptr->TI);
			}
			else{
				strcpy(ftable[ftable_index].symbol,var);
				
				strcpy(ftable[ftable_index].scope,SS->curr_scope->scope);
				ftable[ftable_index].scope_no=SS->curr_scope->scope_no;
				//printf("\nscope %d	%d\n",SS->curr_scope->scope_no,ftable[ftable_index].scope_no);
				ftable[ftable_index].in_par=0;
				ftable[ftable_index].out_par=0;
				
				strcpy(ftable[ftable_index].TI.lex_name,fun_ptr->TI.lex_name);
				strcpy(ftable[ftable_index].TI.Tok_name,fun_ptr->TI.Tok_name);
				ftable[ftable_index].TI.attribute_int = fun_ptr->TI.attribute_int;
				ftable[ftable_index].TI.attribute_float = fun_ptr->TI.attribute_float;
				ftable[ftable_index].TI.line = fun_ptr->TI.line;
				ftable[ftable_index].in_parList=createPar();
				ftable[ftable_index].out_parList=createPar();
				fun_ptr->table_index=ftable_index;
				fun_index=ftable_index;
				ftable_index++;
				//printf("\ntable_index	%d\n",ftable_index);
			}
		}

	
		b1=s_push(SS,fun_ptr->TI.lex_name,scope_level,ptr->TI);

		scope_level++;

		if(par_left==NULL){
			ftable[fun_index].out_par=0;
		}
		else{
			ptr1=par_left->a_child;
			while(ptr1!=NULL){
				strcpy(type,ptr1->a_child->lexeme);
				ftable[fun_index].out_parList=insertpar(ftable[fun_index].out_parList,type);
			
				ptr1=ptr1->a_rightSib;
				if(strcmp(ptr1->lexeme,"ID")==0){
					found=0;
					out_par++;
					strcpy(var,ptr1->TI.lex_name);
					//insert
					scope_Elem pres_scope;
					pres_scope=SS->curr_scope->next;
			//printf("\n%s	%s	%s\n",pres_scope->scope,pres_scope->next->scope,pres_scope->next->sLookup->symbol);
					while(found!=1 ){
						//printf("\n:;yy;;;\n");
						for(i=0;i<=table_index;i++){
							//printf("\n~%s-%s	~%s-%s	~%d-%d\n",symboltable[i].symbol,var,symboltable[i].scope,pres_scope->scope,symboltable[i].scope_no,pres_scope->scope_no);
							if(strcmp(symboltable[i].symbol,var)==0 && strcmp(symboltable[i].scope,pres_scope->scope)==0 /*&& symboltable[i].scope_no==pres_scope->scope_no*/){
								error++;
								errorTable=insertError(errorTable, 1, ptr1->TI);
								found=1;
								ptr1->table_index=i;
								//printf("\nfound	%d	%d\n",found,i);
								//error++;
								//errorTable=insertError(errorTable, 1, ptr1->TI);
								break;
							}
						}
						if(found==1){
							break;
						}
						//printf("\n<<<%s	%d>>>\n",var,found);
						//printf("\n:;;;;ss\n");
						pres_scope=pres_scope->next;
						if(pres_scope==NULL){
							found=0;
						//	printf("\nNULL\n");
							break;
						}
						//printf("\n:;;aaa;;\n");
					}
					/*if(found==0){
					//insert entry
					strcpy(symboltable[table_index].symbol,var);
					strcpy(symboltable[table_index].Type,type);
					strcpy(symboltable[table_index].scope,SS->curr_scope->scope);
					symboltable[table_index].scope_no=SS->curr_scope->scope_no;
					printf("\nscope %d	%d\n",SS->curr_scope->scope_no,symboltable[table_index].scope_no);
					symboltable[table_index].size=-1;
					symboltable[table_index].offset=-1;
					symboltable[table_index].entry_present=1;
				
					strcpy(symboltable[table_index].TI.lex_name,ptr1->TI.lex_name);
					strcpy(symboltable[table_index].TI.Tok_name,ptr1->TI.Tok_name);
					symboltable[table_index].TI.attribute_int = ptr1->TI.attribute_int;
					symboltable[table_index].TI.attribute_float = ptr1->TI.attribute_float;
					symboltable[table_index].TI.line = ptr1->TI.line;
					ptr1->table_index=table_index;
					table_index++;
					printf("\ntable_index	%d\n",table_index);
				}*/
				/*if(found==1){
					//error
						error++;
						errorTable=insertError(errorTable, 1, ptr->TI);
				}*/
				if(found==0){
					//insert entry
					strcpy(symboltable[table_index].symbol,var);
					strcpy(symboltable[table_index].Type,type);
					strcpy(symboltable[table_index].scope,SS->curr_scope->scope);
					symboltable[table_index].scope_no=SS->curr_scope->scope_no;
					//printf("\nscope %d	%d\n",SS->curr_scope->scope_no,symboltable[table_index].scope_no);
					symboltable[table_index].size=-1;
					symboltable[table_index].offset=-1;
					symboltable[table_index].entry_present=1;
				
					strcpy(symboltable[table_index].TI.lex_name,ptr1->TI.lex_name);
					strcpy(symboltable[table_index].TI.Tok_name,ptr1->TI.Tok_name);
					symboltable[table_index].TI.attribute_int = ptr1->TI.attribute_int;
					symboltable[table_index].TI.attribute_float = ptr1->TI.attribute_float;
					symboltable[table_index].TI.line = ptr1->TI.line;
					ptr1->table_index=table_index;
					table_index++;
					//printf("\ntable_index	%d\n",table_index);
				}

				}
				ptr1=ptr1->a_rightSib;
			}
		}
		
		ftable[fun_index].out_par=out_par;
		//symboltable[fun_index].in_par=out_par;
		out_par=0;

		if(par_right==NULL){
			ftable[fun_index].in_par=0;
		}
		else{
			ptr1=par_right->a_child;
			while(ptr1!=NULL){
				strcpy(type,ptr1->a_child->lexeme);
				ftable[fun_index].in_parList=insertpar(ftable[fun_index].in_parList,type);
			
				ptr1=ptr1->a_rightSib;
				if(strcmp(ptr1->lexeme,"ID")==0){
					found=0;
					out_par++;
					strcpy(var,ptr1->TI.lex_name);
					scope_Elem pres_scope;
					pres_scope=SS->curr_scope->next;
			//printf("\n%s	%s	%s\n",pres_scope->scope,pres_scope->next->scope,pres_scope->next->sLookup->symbol);
					while(found!=1 ){
						//printf("\n:;yy;;;\n");
						for(i=0;i<=table_index;i++){
							//printf("\n~%s-%s	~%s-%s	~%d-%d\n",symboltable[i].symbol,var,symboltable[i].scope,pres_scope->scope,symboltable[i].scope_no,pres_scope->scope_no);
							if(strcmp(symboltable[i].symbol,var)==0 && strcmp(symboltable[i].scope,pres_scope->scope)==0 /*&& symboltable[i].scope_no==pres_scope->scope_no*/){
								error++;
								errorTable=insertError(errorTable, 2, ptr1->TI);
								found=1;
								ptr1->table_index=i;
								//printf("\nfound	%d	%d\n",found,i);
								
								break;
							}
						}
						if(found==1){
							break;
						}
						//printf("\n<<<%s	%d>>>\n",var,found);
						//printf("\n:;;;;ss\n");
						pres_scope=pres_scope->next;
						if(pres_scope==NULL){
							//printf("\nNULL\n");
							found=0;
							break;
						}
						//printf("\n:;;aaa;;\n");
					}
					//insert
					
					/*if(found==0){
					//insert entry
					strcpy(symboltable[table_index].symbol,var);
					strcpy(symboltable[table_index].Type,type);
					strcpy(symboltable[table_index].scope,SS->curr_scope->scope);
					symboltable[table_index].scope_no=SS->curr_scope->scope_no;
					printf("\nscope %d	%d\n",SS->curr_scope->scope_no,symboltable[table_index].scope_no);
					symboltable[table_index].size=-1;
					symboltable[table_index].offset=-1;
					symboltable[table_index].entry_present=1;
				
					strcpy(symboltable[table_index].TI.lex_name,ptr1->TI.lex_name);
					strcpy(symboltable[table_index].TI.Tok_name,ptr1->TI.Tok_name);
					symboltable[table_index].TI.attribute_int = ptr1->TI.attribute_int;
					symboltable[table_index].TI.attribute_float = ptr1->TI.attribute_float;
					symboltable[table_index].TI.line = ptr1->TI.line;
					ptr1->table_index=table_index;
					table_index++;
					printf("\ntable_index	%d\n",table_index);
				}*/
				/*if(found==1){
					//error
						error++;
						errorTable=insertError(errorTable, 2, ptr->TI);
				}*/
				if(found==0){
					//insert entry
					strcpy(symboltable[table_index].symbol,var);
					strcpy(symboltable[table_index].Type,type);
					strcpy(symboltable[table_index].scope,SS->curr_scope->scope);
					symboltable[table_index].scope_no=SS->curr_scope->scope_no;
					//printf("\nscope %d	%d\n",SS->curr_scope->scope_no,symboltable[table_index].scope_no);
					symboltable[table_index].size=-1;
					symboltable[table_index].offset=-1;
					symboltable[table_index].entry_present=1;
				
					strcpy(symboltable[table_index].TI.lex_name,ptr1->TI.lex_name);
					strcpy(symboltable[table_index].TI.Tok_name,ptr1->TI.Tok_name);
					symboltable[table_index].TI.attribute_int = ptr1->TI.attribute_int;
					symboltable[table_index].TI.attribute_float = ptr1->TI.attribute_float;
					symboltable[table_index].TI.line = ptr1->TI.line;
					ptr1->table_index=table_index;
					table_index++;
					//printf("\ntable_index	%d\n",table_index);
				}

				}
				ptr1=ptr1->a_rightSib;
			}
		}
		ftable[fun_index].in_par=out_par;
		
		ast=createSymbolTable(ptr_next);


		b2=s_pop(SS);/////
		goto label2;
	}
	
	if(strcmp(ptr->lexeme,"funCallStmt")==0){
		ptr=ptr->a_child;
		if(strcmp(ptr->lexeme,"FUNID")==0){
			found=0;
			strcpy(var,ptr->TI.lex_name);
			//printf("\n$$%s	%s$$\n",var,SS->curr_scope->scope);
			if(strcmp(var,SS->curr_scope->scope)==0){
				error++;
				errorTable=insertError(errorTable, 8, ptr->TI);
			}
			scope_Elem pres_scope;
			pres_scope=SS->curr_scope;
			//printf("\n%s	%s	%s\n",pres_scope->scope,pres_scope->next->scope,pres_scope->next->sLookup->symbol);
			while(found!=1 ){
				//printf("\n:;yy;;;\n");
				for(i=0;i<=ftable_index;i++){
					//printf("\n~%s-%s	~%s-%s	~%d-%d\n",ftable[i].symbol,var,ftable[i].scope,pres_scope->scope,ftable[i].scope_no,pres_scope->scope_no);
					if(strcmp(ftable[i].symbol,var)==0 && strcmp(ftable[i].scope,pres_scope->scope)==0 /*&& ftable[i].scope_no==pres_scope->scope_no*/){
						found=1;
						ptr->table_index=i;
						//printf("\nfound	%d	%d\n",found,i);
						break;
					}
				}
				//printf("\n<<<%s	%d>>>\n",var,found);
				//printf("\n:;;;;ss\n");
				pres_scope=pres_scope->next;
				if(pres_scope==NULL){
					//printf("\nNULL\n");
					break;
				}
				//printf("\n:;;aaa;;\n");
			}
			//printf("\n:;;aa====\n");
			if(found==0){
				//printf("\n:;;aa((a;;\n");
				error++;
				errorTable=insertError(errorTable, 14, ptr->TI);
				///error var undeclared
				//errorTable=insertError(errorTable, 2, ptr->TI);
			}
			
		}

		ptr=ptr->a_rightSib;
		ast=createSymbolTable(ptr);



		goto label2;
	}

	if(strcmp(ptr->lexeme,"inputParameterList")==0){
		astLink ptr1;
		ptr=ptr->a_child;
		while(ptr!=NULL){
			ptr1=ptr->a_child;
			if(strcmp(ptr1->lexeme,"ID")==0){
			found=0;
			strcpy(var,ptr1->TI.lex_name);
			scope_Elem pres_scope;
			pres_scope=SS->curr_scope;
			//printf("\n%s	%s	%s\n",pres_scope->scope,pres_scope->next->scope,pres_scope->next->sLookup->symbol);
			while(found!=1 ){
				//printf("\n:;yy;;;\n");
				for(i=0;i<=table_index;i++){
					//printf("\n~%s-%s	~%s-%s	~%d-%d\n",symboltable[i].symbol,var,symboltable[i].scope,pres_scope->scope,symboltable[i].scope_no,pres_scope->scope_no);
					if(strcmp(symboltable[i].symbol,var)==0 && strcmp(symboltable[i].scope,pres_scope->scope)==0 /*&& symboltable[i].scope_no==pres_scope->scope_no*/){
						found=1;
						ptr1->table_index=i;
						//printf("\nfound	%d	%d\n",found,i);
						break;
					}
				}
				//printf("\n<<<%s	%d>>>\n",var,found);
				//printf("\n:;;;;ss\n");
				pres_scope=pres_scope->next;
				if(pres_scope==NULL){
					//printf("\nNULL\n");
					break;
				}
				//printf("\n:;;aaa;;\n");
			}
			//printf("\n:;;aa====\n");
			if(found==0){
				//printf("\n:;;aa((a;;\n");
				error++;
				errorTable=insertError(errorTable, 2, ptr1->TI);
				//printError(errorTable);
				///error var undeclared
			}
			
		}
		ptr=ptr->a_rightSib;
		}

		goto label2;
	}
	


	label2:
		//printf("^^^^^^^^\n");
		return ast;
}


void initializeSymbolTable(){
	int i,int_flag,real_flag,str_flag,mat_flag;
	int_flag=0;
	real_flag=0;
	str_flag=0;
	mat_flag=0;

	for(i=0;i<table_index;i++){
		if(strcmp(symboltable[i].Type,"INT")==0){
			symboltable[i].offset=int_flag;
			int_flag=int_flag+2;
		}
		else if(strcmp(symboltable[i].Type,"REAL")==0){
			symboltable[i].offset=real_flag;
			real_flag=real_flag+4;
		}
		else if(strcmp(symboltable[i].Type,"STRING")==0){
			symboltable[i].offset=str_flag;
			str_flag=str_flag+20;
		}
		else if(strcmp(symboltable[i].Type,"MATRIX")==0){
			symboltable[i].offset=mat_flag;
			mat_flag=mat_flag+18;
		}
	}
}


