// BATCH 21
// KRISHNIKA AGARWAL 2011C6PS839P
//NAINCY SUMAN 2011C6PS692P


//#include "parser.h"
//#include "createAbstractSyntaxTree.h"
#include "typechecker.h"
//#include "createSymbolTable.h"

void main(int argc, char *argv[]){
	int num;
	char filename[30];
	table T={0};
	int i,j;
	buffer B;
	error=0;
	scope_level=0;
	line_no=1;
	table_index=0;
	ftable_index=0;
	errorTable=createError();
	max_cap=100;
	max_cap1=50;
	int k=BUFFERSIZE;
	buf_ptr=0;
	forward=1;
	grammar G;
	printf("\n\nLEVEL 3: Symbol table/ AST/ Typechecker/ Semantic Rules modules work.\n\n");
	tokenInfo TI;
	parseTree PT,PT1;
	do{
		FILE *fp1,*fp2,*fp3,*fp4;
		printf(" \n\n-----Select your choice or press Ctrl^Z to exit!!-----\n\n1 :  For  printing the token list (on the console) generated by the lexer.Each token appears in a new line alongwith the corresponding lexeme.\n2 :  For parsing to verify the syntactic correctness of the input source code\n3 :  For printing Abstract Syntax Tree\n4	:  For printing Symbol Table\n5 : For producing assembly code\n");
		scanf("%d",&num);
		//printf("\ntesting1\n");
		switch(num){
			case 1:
				printf("\ntesting\n");
				tokenize(argv[1]);
				break;
			case 2:
				strcpy(filename,"ParseTree.txt");
				fp2=fopen("productionRules.txt","r");
				G=create_gram(fp2);
				fclose(fp2);
				createParseTable(G,T);
				//fp1=fopen(argv[0],"r");
				PT=parseInputSourceCode(argv[1],T,G);
				printParseTree(PT,filename);
				//fclose(fp1);
				break;
			case 3:
				//fp2=fopen("productionRules.txt","r");
				PT1=PT;
				ast=createAbstractSyntaxTree(PT, PT1);
				//printf("aaaab");
				fp4=fopen("astOut.txt","w");
				printast(ast,fp4);
				fclose(fp4);
				break;
			case 4:
				ast=createSymbolTable(ast);
				initializeSymbolTable();
				printf("\nIdentifier name     	Scope               	Type      	Offset\n");
				for(i=0;i<table_index;i++){
					printf("%-20s	%-20s	%-10s	%-6d\n",symboltable[i].symbol,symboltable[i].scope,symboltable[i].Type,symboltable[i].offset);
				}
				printf("\n\n");
				break;
			case 5:
				ast=typeChecker(ast);
				printError(errorTable);
				break;
			case 6:
				printf("\nMASM code not generated\n");
				
				break;
				
			default:
				printf("\nWrong choice!!!Enter Between 0 to 3");
		}
		//printf("\n\n-----Select other choice or press Ctrl^Z to exit!!-----\n");
	} while(1);
}
