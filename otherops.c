// BATCH 21
// KRISHNIKA AGARWAL 2011C6PS839P
//NAINCY SUMAN 2011C6PS692P

#include "otherops.h"


void tokenize(char *filename){
	buffer B;
	line_no=1;
	printf("\nCheck1\n");
	int k=BUFFERSIZE;
	//b[1]=0;
	//b[0]=1;
	buf_ptr=0;
	forward=1;
	//char filename[30];
	//strcpy(filename,"input.txt");
	tokenInfo TI;
	FILE *fp;
	fp=fopen(filename,"r");
	TI=getNextToken(fp,B);
	while(strcmp(TI.lex_name,"$")!=0){
		
		printf("Token:%s\n%s\n\n",TI.lex_name,TI.Tok_name);
		TI=getNextToken(fp,B);
	}
	TI=getNextToken(fp,B);
	printf("Token:%s\n%s\n\n",TI.lex_name,TI.Tok_name);
	
	fclose(fp);
}







int getValueNonTerm(char* c){
	if(strcmp(c,"start")==0) {return 0;}
 	if(strcmp(c,"mainFunction")==0) {return 1;}
	if(strcmp(c,"stmtsAndFunctionDefs")==0) {return 2;}
	if(strcmp(c,"RemainingStmts")==0) {return 3;}
	if(strcmp(c,"stmtOrFunctionDef")==0) {return 4;}
	if(strcmp(c,"stmt")==0) {return 5;}
	if(strcmp(c,"functionDef")==0) {return 6;}
	if(strcmp(c,"parameters")==0) {return 7;}
	if(strcmp(c,"parameter_list")==0) {return 8;}
	if(strcmp(c,"type")==0) {return 9;}
	if(strcmp(c,"remainingList")==0) {return 10;}
	if(strcmp(c,"declarationStmt")==0) {return 11;}
	if(strcmp(c,"var_list")==0) {return 12;}
	if(strcmp(c,"more_ids")==0) {return 13;}
	if(strcmp(c,"assignmentStmt_type1")==0) {return 14;}
	if(strcmp(c,"assignmentStmt_type2")==0) {return 15;}
	if(strcmp(c,"leftHandSide_singleVar")==0) {return 16;}
	if(strcmp(c,"leftHandSide_listVar")==0) {return 17;}
	if(strcmp(c,"rightHandSide_type1")==0) {return 18;}
	if(strcmp(c,"rightHandSide_type2")==0) {return 19;}
	if(strcmp(c,"conditionalStmt")==0) {return 20;}
	if(strcmp(c,"elsepart")==0) {return 21;}
	if(strcmp(c,"otherStmts")==0) {return 22;}
	if(strcmp(c,"ioStmt")==0) {return 23;}
	if(strcmp(c,"arithmeticExpression")==0) {return 24;}
	if(strcmp(c,"arithmeticprime")==0) {return 25;}
	if(strcmp(c,"arithmeticTerm")==0) {return 26;}
	if(strcmp(c,"termPrime")==0) {return 27;}
	if(strcmp(c,"factor")==0) {return 28;}
	if(strcmp(c,"addSub")==0) {return 29;}
	if(strcmp(c,"mulDiv")==0) {return 30;}
	if(strcmp(c,"boolExAll")==0) {return 31;}
	if(strcmp(c,"logicEx")==0) {return 32;}
	if(strcmp(c,"logicExPrime")==0) {return 33;}
	if(strcmp(c,"boolEx")==0) {return 34;}
	if(strcmp(c,"logicOp_1")==0) {return 35;}
	if(strcmp(c,"var1")==0) {return 36;}
	if(strcmp(c,"var")==0) {return 37;}
	if(strcmp(c,"var_next")==0) {return 38;}
	if(strcmp(c,"relationalOp")==0) {return 39;}
	if(strcmp(c,"matrix")==0) {return 40;}
	if(strcmp(c,"row")==0) {return 41;}
	if(strcmp(c,"moreRows")==0) {return 42;}
	if(strcmp(c,"moreNum")==0) {return 43;}
	if(strcmp(c,"funCallStmt")==0) {return 44;}
	if(strcmp(c,"inputParameterList")==0) {return 45;}
	if(strcmp(c,"listVar")==0) {return 46;}
	if(strcmp(c,"sizeOp")==0) {return 47;}	
	
}

int getValueTerm(char *c) {
if(strcmp(c,"MAIN")==0) {return 0;}
if(strcmp(c,"SQO")==0) {return 1;}
if(strcmp(c,"SQC")==0) {return 2;}
if(strcmp(c,"END")==0) {return 3;}
if(strcmp(c,"EPSILON")==0) {return 4;}
if(strcmp(c,"FUNCTION")==0) {return 5;}
if(strcmp(c,"ASSIGNOP")==0) {return 6;}
if(strcmp(c,"FUNID")==0) {return 7;}
if(strcmp(c,"INT")==0) {return 8;}
if(strcmp(c,"REAL")==0) {return 9;}
if(strcmp(c,"STRING")==0) {return 10;}
if(strcmp(c,"MATRIX")==0) {return 11;}
if(strcmp(c,"COMMA")==0) {return 12;}
if(strcmp(c,"SEMICOLON")==0) {return 13;}
if(strcmp(c,"ID")==0) {return 14;}
if(strcmp(c,"STR")==0) {return 15;}
if(strcmp(c,"OP")==0) {return 16;}
if(strcmp(c,"CL")==0) {return 17;}
if(strcmp(c,"ELSE")==0) {return 18;}
if(strcmp(c,"ENDIF")==0) {return 19;}
if(strcmp(c,"READ")==0) {return 20;}
if(strcmp(c,"PRINT")==0) {return 21;}
if(strcmp(c,"IF")==0) {return 22;}
if(strcmp(c,"PLUS")==0) {return 23;}
if(strcmp(c,"MINUS")==0) {return 24;}
if(strcmp(c,"MUL")==0) {return 25;}
if(strcmp(c,"DIV")==0) {return 26;}
if(strcmp(c,"NOT")==0) {return 27;}
if(strcmp(c,"AND")==0) {return 28;}
if(strcmp(c,"OR")==0) {return 29;}
if(strcmp(c,"NUM")==0) {return 30;}
if(strcmp(c,"RNUM")==0) {return 31;}
if(strcmp(c,"LT")==0) {return 32;}
if(strcmp(c,"LE")==0) {return 33;}
if(strcmp(c,"EQ")==0) {return 34;}
if(strcmp(c,"GT")==0) {return 35;}
if(strcmp(c,"GE")==0) {return 36;}
if(strcmp(c,"NE")==0) {return 37;}
if(strcmp(c,"SIZE")==0) {return 38;}
if(strcmp(c,"$")==0) {return 39;}


}

parseTree createList(){
	parseTree head;
	//head=(parseTree)malloc(sizeof(p_List));
	//head->p_next=NULL;
	head=NULL;
	return head;
}

parseTree insertelem(parseTree head,char* data,int isLeaf,char* parentNode,tokenInfo TI){
	
	if(head==NULL){
		head=(parseTree)malloc(sizeof(p_List));
		strcpy(head->data,data);
		strcpy(head->parentNode,parentNode);
		head->isLeaf=isLeaf;
		//head->line=TI.line;
		strcpy(head->TI.Tok_name,TI.Tok_name);
		strcpy(head->TI.lex_name,TI.lex_name);
		head->TI.attribute_int=TI.attribute_int;
		head->TI.line=TI.line;
		head->TI.attribute_float=TI.attribute_float;
		head->p_next=NULL;
	}
	else{
		parseTree ptr=head;
		while(ptr->p_next!=NULL){
			ptr=ptr->p_next;
		}
		ptr->p_next=(parseTree)malloc(sizeof(p_List));
		strcpy(ptr->p_next->data,data);
		strcpy(ptr->p_next->parentNode,parentNode);
		ptr->p_next->isLeaf=isLeaf;
		//ptr->p_next->line=TI.line;
		strcpy(ptr->p_next->TI.Tok_name,TI.Tok_name);
		strcpy(ptr->p_next->TI.lex_name,TI.lex_name);
		ptr->p_next->TI.attribute_int=TI.attribute_int;
		ptr->p_next->TI.line=TI.line;
		ptr->p_next->TI.attribute_float=TI.attribute_float;
		ptr->p_next->p_next=NULL;
	}
	return head;
}

 int isNonTerm(char ch)
   {
                   if(ch >=start && ch<=sizeOp)
                   return 1;
                   else
                   return 0;
                   }

Stack newStack()
{
	Stack st = (Stack) malloc (sizeof (struct stack)); 
	st->top=NULL;
	st->size=0; 
	
	return st; 
}

Boolean push (Stack st, char* data, int prodRuleNo)
{
	
	if (st==NULL)
		{
			printf("\n Error-Push: Stack Non Existent");
			return FALSE;
		}
	
	Elem el = (Elem) malloc (sizeof (struct node)); 
	el->next=NULL;
	strcpy(el->data,data);
	el->prodRule=prodRuleNo;
			
			if(st->top==NULL)
			{
				st->top=el;
				st->size=1;
			}
			else {
				el->next=st->top;
				st->top=el;
				st->size++;
			}
			return TRUE; 
	
	
}
Boolean pop (Stack st, char* data)
{
	Elem el=NULL;
	if (st==NULL)
		{
			printf("\n Error-Pop: Stack Non Existent");
			return FALSE;
		}
	if (st->top==NULL)
		{
			printf("\n Error-Pop: Empty Stack");
			return FALSE;
		}
	
	el=st->top;
	strcpy(data,el->data);
	//*data=el->data;
	st->top=el->next;
	st->size=st->size-1;
	free(el);
	return TRUE; 	
}


Boolean top (Stack st, int* prodRuleNo)
{
	Elem el=NULL;
	if (st==NULL)
		{
			printf("\n Error-Top: Stack Non Existent");
			return FALSE;
		}
	if (st->top==NULL)
		{
			printf("\n Error-Top: Empty Stack");
			return FALSE;
		}
	
	el=st->top;
	
	//strcpy(data,el->data);
	//st->size=st->size-1;
	*prodRuleNo=el->prodRule;
	return TRUE; 	
}




int size(Stack st)
{
if (st==NULL)
		{
			printf("\n Error-Pop: Stack Non Existent");
			return -1;
		}
return st->size; 
}




void display (Stack st)
{

	if (st==NULL)
		{
			printf("\n Error-Display: Stack Non Existent");
			
		}
	else{
		printf("\n Stack-Display : ");
		Elem curr=st->top;
	
		while(curr!=NULL)
		{
			printf("\n %s", curr->data);
			curr=curr->next;
		}
		
		printf("\n Stack-Display ends \n");
	
	}
	
}


grammar create_gram(FILE *fp)
{
	grammar G;
        int i=0, j=0; //i==line no j==for cha c
        char c[LIM],d[LIM];
        Stack st;
	Boolean bl;


        G = (grammar)malloc(LIM*(sizeof(P_rule)));
        while (fscanf(fp,"%s",d)!= EOF)
        {
		strcpy(G[i].nonTerm,d);
		//printf("2%s\n",d);
		G[i].s=newStack();
		fscanf(fp,"%s",c);
              while (strcmp(c,"~")!=0 && !feof(fp))
              {

		bl=push(G[i].s,c,i);
		//printf("3%s\n",c);
		j++;
		fscanf(fp,"%s",c);
              
		}
		/*printf("\n4");
		display(G[i].s);
		printf("5\n");*/
		i++;

         }
	//display(G[24].s);

	return G;
}

