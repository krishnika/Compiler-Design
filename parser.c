// BATCH 21
// KRISHNIKA AGARWAL 2011C6PS839P
//NAINCY SUMAN 2011C6PS692P


#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include "parser.h"

void createParseTable(grammar G, table T)
{
    int i,j,k;
    
    //for nonterminal start
       T[0][0]=0;
       for (i=1;i<40;i++){
               T[0][i]=-1;}
               
               
               
       //for nonterminal mainFunction        
       
       T[1][0]=1;
       for(i=1;i<40;i++){
               T[1][i]=-1;
               }
     
     


      //for nonterminal stmtsAndFunctionDefs
       T[2][1]=2;
       T[2][5]=2;
       T[2][7]=2;
       T[2][8]=2;
       T[2][9]=2;
       T[2][10]=2;
       T[2][11]=2;
       T[2][14]=2;
       T[2][20]=2;
       T[2][21]=2;
       T[2][22]=2;
       T[2][0]=-1;
       T[2][2]=-1;
       T[2][3]=-1;
       T[2][4]=-1;
       T[2][6]=-1;
       T[2][12]=-1;
       T[2][13]=-1;
       T[2][15]=-1;
       T[2][16]=-1;
       T[2][17]=-1;
       T[2][18]=-1;
       T[2][19]=-1;
       for(i=23;i<40;i++)
       {
                  T[2][i] = -1;       
                         }
                         
       
       //for nonterminal RemainingStmts
      
      T[3][0]=-1;
      T[3][2]=-1;
      T[3][1]=3;
      T[3][3]=4;
      T[3][4]=-1;
      T[3][5]=3;
      T[3][6]=-1;
      T[3][7]=3;
      T[3][8]=3;
      T[3][9]=3;
      T[3][10]=3;
      T[3][11]=3;
      T[3][12]=-1;
      T[3][13]=-1;
      T[3][14]=3;
      T[3][15]=-1;
      T[3][16]=-1;
      T[3][17]=-1;
      T[3][18]=-1;
      T[3][19]=-1;
      T[3][20]=3;
      T[3][21]=3;
      T[3][22]=3;
      for(i=23;i<40;i++)
       {
                  T[3][i] = -1;       
                         }
                         
       
       // FOR NONTERMINAL stmtOrFunctionDef
      T[4][0]=-1;
      T[4][1]=5;
      T[4][2]=-1; 
      T[4][3]=-1;
      T[4][4]=-1;
      T[4][5]=6;
      T[4][6]=-1;
      T[4][7]=5;
      T[4][8]=5;
      T[4][9]=5;
      T[4][10]=5;
      T[4][11]=5;
      T[4][12]=-1;
      T[4][13]=-1;
      T[4][14]=5;
      T[4][15]=-1;
      T[4][16]=-1;
      T[4][17]=-1;
      T[4][18]=-1;
      T[4][19]=-1;
      T[4][20]=5;
      T[4][21]=5;
      T[4][22]=5;
      for(i=23;i<40;i++)
       {
                  T[4][i] = -1;       
                         }
                         
                         
       // FOR NON TERMINAL stmt
      T[5][0]=-1;
      T[5][1]=12;
      T[5][2]=-1; 
      T[5][3]=-1;
      T[5][4]=-1;
      T[5][5]=-1;
      T[5][6]=-1;
      T[5][7]=10;
      T[5][8]=7;
      T[5][9]=7;
      T[5][10]=7;
      T[5][11]=7;
      T[5][12]=-1;
      T[5][13]=-1;
      T[5][14]=11;
      T[5][15]=-1;
      T[5][16]=-1;
      T[5][17]=-1;
      T[5][18]=-1;
      T[5][19]=-1;
      T[5][20]=9;
      T[5][21]=9;
      T[5][22]=8;
      for(i=23;i<40;i++)
       {
                  T[5][i] = -1;       
                         }
                         
                         
                         
       // FOR NON TERMINAL functionDef
      T[6][0]=-1;
      T[6][1]=-1;
      T[6][2]=-1; 
      T[6][3]=-1;
      T[6][4]=-1;
      T[6][5]=13;
      for(i=6;i<40;i++)
       {
                  T[6][i] = -1;       
                         }
                         
                         
                         
                         
        // FOR NON TERMINAL parameters
      T[7][0]=-1;
      T[7][1]=-1;
      T[7][2]=15; 
      T[7][3]=-1;
      T[7][4]=-1;
      T[7][5]=-1;
      T[7][6]=-1;
      T[7][7]=-1;
      T[7][8]=14;
      T[7][9]=14;
      T[7][10]=14;
      T[7][11]=14;
      for(i=12;i<40;i++)
       {
                  T[7][i] = -1;       
                         }  
                         
                         
                         
      // FOR NON TERMINAL parameter_list
      T[8][0]=-1;
      T[8][1]=-1;
      T[8][2]=-1; 
      T[8][3]=-1;
      T[8][4]=-1;
      T[8][5]=-1;
      T[8][6]=-1;
      T[8][7]=-1;
      T[8][8]=16;
      T[8][9]=16;
      T[8][10]=16;
      T[8][11]=16;
      for(i=12;i<40;i++)
       {
                  T[8][i] = -1;       
                         }
                         
                         
     //epsilon included                    
       // FOR NON TERMINAL TYPE                 
      for(i=0;i<8;i++)
       {
                  T[9][i] = -1;       
                         } 
      T[9][8]=17;
      T[9][9]=18;
      T[9][10]=19;
      T[9][11]=20;
      for(i=12;i<40;i++)
       {
                  T[9][i] = -1;       
                         }
                         
                         
                         
        // FOR NON TERMINAL remainingList      
      T[10][0]=-1;
      T[10][1]=-1;
      T[10][2]=22; 
      T[10][3]=-1;
      T[10][4]=-1;
      T[10][5]=-1;
      T[10][6]=-1;
      T[10][7]=-1;
      T[10][8]=-1;
      T[10][9]=-1;
      T[10][10]=-1;
      T[10][11]=-1;
      T[10][12]=21;
      for(i=13;i<40;i++)
       {
                  T[10][i] = -1;       
                         }
                         
                         
                         
       // FOR NON TERMINAL declarationStmt                
      
       for(i=0;i<8;i++)
       {
                  T[11][i] = -1;       
                         } 
      T[11][8]=23;
      T[11][9]=23;
      T[11][10]=23;
      T[11][11]=23;
      for(i=12;i<40;i++)
       {
                  T[11][i] = -1;       
                         }
                         
                         
       
       // FOR NON TERMINAL var_list              
      
       for(i=0;i<14;i++)
       {
                  T[12][i] = -1;       
                         }                    
      T[12][14] = 24;
      for(i=15;i<40;i++)
       {
                  T[12][i] = -1;       
                         }
                         
                         
                         
       // FOR NON TERMINAL more_ids
      T[13][0]=-1;
      T[13][1]=-1;
      T[13][2]=26; 
      T[13][3]=-1;
      T[13][4]=-1;
      T[13][5]=-1;
      T[13][6]=-1;
      T[13][7]=-1;
      T[13][8]=-1;
      T[13][9]=-1;
      T[13][10]=-1;
      T[13][11]=-1;
      T[13][12]=25;
      T[13][13]=26;                   
      for(i=14;i<40;i++)
       {
                  T[13][i] = -1;       
                         }
                         
         
         
       //FOR NON TERMINAL assignmentStmt_type1  
       for(i=0;i<14;i++) 
     {
                  T[14][i] = -1;       
                         }
     T[14][14]=27;
     for(i=15;i<40;i++) 
     {
                  T[14][i] = -1;       
                         }
       
       
       //FOR NON TERMINAL assignmentStmt_type2                  
     T[15][0]=-1;
     T[15][1]=28;
     for(i=2;i<40;i++) 
     {
                  T[15][i] = -1;       
                         }   
           
           
     //FOR NON TERMINAL leftHandSide_singleVar  
       for(i=0;i<14;i++) 
     {
                  T[16][i] = -1;       
                         }
     T[16][14]=29;
     for(i=15;i<40;i++) 
     {
                  T[16][i] = -1;       
                         }
                         
                         
                         
     //FOR NON TERMINAL leftHandSide_listVar
     T[17][0]=-1;
     T[17][1]=30;
     for(i=2;i<40;i++) 
     {
                  T[17][i] = -1;       
                         }
                         
                         
                         
                         
     //FOR NON TERMINAL rightHandSide_type1
     T[18][0]=-1;
     T[18][1]=31;
     T[18][2]=-1;
     T[18][3]=-1;
     T[18][4]=-1;
     T[18][5]=-1;
     T[18][6]=-1;
     T[18][7]=33;
     T[18][8]=-1;
     T[18][9]=-1;
     T[18][10]=-1;
     T[18][11]=-1;
     T[18][12]=-1;
     T[18][14]=31;
     T[18][15]=31;
     T[18][16]=31;
     for(i=17;i<30;i++) 
     {
                  T[18][i] = -1;       
                         }
     T[18][30]=31;
     T[18][31]=31;
     for(i=32;i<38;i++) 
     {
                  T[18][i] = -1;       
                         }
     T[18][38]=32;
     T[18][39]=-1;
     
     
     
     //FOR NON TERMINAL rightHandSide_type2
     for(i=0;i<7;i++) 
     {
                  T[19][i] = -1;       
                         }
     T[19][7]=35;
     for(i=8;i<38;i++) 
     {
                  T[19][i] = -1;       
                         }
     T[19][38]=34;
     T[19][39]=-1;
                        
                         
                         
       //FOR NON TERMINAL conditionalStmt
      for(i=0;i<22;i++) 
     {
                  T[20][i] = -1;       
                         } 
      T[20][22]=36;
      for(i=23;i<40;i++) 
     {
                  T[20][i] = -1;       
                         }
                         
                         
                         
     //FOR NON TERMINAL elsepart
      for(i=0;i<18;i++) 
     {
                  T[21][i] = -1;       
                         } 
      T[21][18]=37;
      T[21][19]=38;
      for(i=20;i<40;i++) 
     {
                  T[21][i] = -1;       
                         }
                         
                         
                         
     // FOR NONTERMINAL otherStmts
      T[22][0]=-1;
      T[22][1]=39;
      T[22][2]=-1; 
      T[22][3]=-1;
      T[22][4]=-1;
      T[22][5]=-1;
      T[22][6]=-1;
      T[22][7]=39;
      T[22][8]=39;
      T[22][9]=39;
      T[22][10]=39;
      T[22][11]=39;
      T[22][12]=-1;
      T[22][13]=-1;
      T[22][14]=39;
      T[22][15]=-1;
      T[22][16]=-1;
      T[22][17]=-1;
      T[22][18]=40;
      T[22][19]=40;
      T[22][20]=39;
      T[22][21]=39;
      T[22][22]=39;
      for(i=23;i<40;i++)
       {
                  T[22][i] = -1;       
                         }
                         
                         
                         
       //FOR NON TERMINAL ioStmt
      for(i=0;i<20;i++) 
     {
                  T[23][i] = -1;       
                         } 
      T[23][20]=41;
      T[23][21]=42;
      for(i=22;i<40;i++) 
     {
                  T[23][i] = -1;       
                         }
                         
                         
                         
     //FOR NON TERMINAL arithemeticExpression
      
      T[24][0]=-1;
      T[24][1]=43;
      for(i=2;i<14;i++) 
     {
                  T[24][i] = -1;       
                         }
      T[24][14]=43;
      T[24][15]=43;                   
      T[24][16]=43;
      for(i=17;i<30;i++) 
     {
                  T[24][i] = -1;       
                         }
      T[24][30]=43;
      T[24][31]=43;
      T[24][32]=-1;
      T[24][33]=-1;
      T[24][34]=-1;
      T[24][35]=-1;
      T[24][36]=-1;
      T[24][37]=-1;
      T[24][38]=-1;
      T[24][39]=-1;
      
      
      
      
      //FOR NON TERMINAL arithmeticprime
      for(i=0;i<13;i++) 
     {
                  T[25][i] = -1;       
                         }
      T[25][13]=45;
      T[25][14]=-1;                   
      T[25][15]=-1;
      T[25][16]=-1;
      T[25][17]=45;                   
      T[25][18]=-1;
      T[25][19]=-1;
      T[25][20]=-1;                   
      T[25][21]=-1;
      T[25][22]=-1;
      T[25][23]=44;                   
      T[25][24]=44;
      for(i=25;i<40;i++) 
     {
                  T[25][i] = -1;       
                         }
                         
                         
                         
     //FOR NON TERMINAL arithmeticTerm
      
      T[26][0]=-1;
      T[26][1]=46;
      for(i=2;i<14;i++) 
     {
                  T[26][i] = -1;       
                         }
      T[26][14]=46;
      T[26][15]=46;
      T[26][16]=46;
      for(i=17;i<30;i++) 
     {
                  T[26][i] = -1;       
                         }
      T[26][30]=46;
      T[26][31]=46;
      T[26][32]=-1;
      T[26][33]=-1;
      T[26][34]=-1;
      T[26][35]=-1;
      T[26][36]=-1;
      T[26][37]=-1;
      T[26][38]=-1;
      T[26][39]=-1;
      
      
      
      
      //FOR NON TERMINAL termPrime
      for(i=0;i<13;i++) 
     {
                  T[27][i] = -1;       
                         }
      T[27][13]=48;
      T[27][14]=-1;                   
      T[27][15]=-1;
      T[27][16]=-1;
      T[27][17]=48;                   
      T[27][18]=-1;
      T[27][19]=-1;
      T[27][20]=-1;                   
      T[27][21]=-1;
      T[27][22]=-1;
      T[27][23]=48;                   
      T[27][24]=48;
      T[27][25]=47;                   
      T[27][26]=47;
      for(i=27;i<40;i++) 
     {
                  T[27][i] = -1;       
                         }
                         
                         
                         
     //FOR NON TERMINAL factor
      
      T[28][0]=-1;
      T[28][1]=50;
      for(i=2;i<14;i++) 
     {
                  T[28][i] = -1;       
                         }
      T[28][14]=50;
      T[28][15]=50;
      T[28][16]=49;  
      for(i=17;i<30;i++) 
     {
                  T[28][i] = -1;       
                         }             
      T[28][30]=50;
      T[28][31]=50;
      T[28][32]=-1;
      T[28][33]=-1;
      T[28][34]=-1;
      T[28][35]=-1;
      T[28][36]=-1;
      T[28][37]=-1;
      T[28][38]=-1;
      T[28][39]=-1;
      
      
      
      
      //FOR NON TERMINAL addSub
      for(i=0;i<23;i++) 
     {
                  T[29][i] = -1;       
                         }
      T[29][23]=51;
      T[29][24]=52;  
      for(i=25;i<40;i++) 
     {
                  T[29][i] = -1;       
                         }      
                         
                         
                         
     //FOR NON TERMINAL mulDiv
      for(i=0;i<25;i++) 
     {
                  T[30][i] = -1;       
                         }
      T[30][25]=53;
      T[30][26]=54;  
      for(i=27;i<40;i++) 
     {
                  T[30][i] = -1;       
                         }
                         
                         
                         
     //FOR NON TERMINAL boolExAll
      for(i=0;i<14;i++) 
     {
                  T[31][i] = -1;       
                         }
      T[31][14]=57;
      T[31][15]=-1;
      T[31][16]=55;  
      for(i=17;i<27;i++) 
     {
                  T[31][i] = -1;       
                         } 
      T[31][27]=56;
      T[31][28]=-1;
      T[31][29]=-1;
      T[31][30]=57;
      T[31][31]=57;
      for(i=32;i<40;i++) 
     {
                  T[31][i] = -1;       
                         }
                         
                         
                         
     //FOR NON TERMINAL logicEx
      for(i=0;i<16;i++) 
     {
                  T[32][i] = -1;       
                         }
      T[32][16]=58;  
      for(i=17;i<40;i++) 
     {
                  T[32][i] = -1;       
                         }
                         
                         
                         
     //FOR NON TERMINAL logicExPrime
      for(i=0;i<27;i++) 
     {
                  T[33][i] = -1;       
                         }
      T[33][27]=59;  
      for(i=28;i<40;i++) 
     {
                  T[33][i] = -1;       
                         }
                         
                         
                         
     //FOR NON TERMINAL boolEx
      for(i=0;i<14;i++) 
     {
                  T[34][i] = -1;       
                         }
      T[34][14]=60;  
      for(i=15;i<30;i++) 
     {
                  T[34][i] = -1;       
                         }
	T[34][30]=60;
	T[34][31]=60;
	for(i=32;i<40;i++) 
     {
                  T[34][i] = -1;       
                         }
                         
                         
                         
     //FOR NON TERMINAL logicOp_1
      for(i=0;i<28;i++) 
     {
                  T[35][i] = -1;       
                         }
      T[35][28]=61;  
      T[35][29]=62;
      for(i=30;i<40;i++) 
     {
                  T[35][i] = -1;       
                         }
                         
                         
                         
     //FOR NON TERMINAL var1                    
      for(i=0;i<14;i++) 
     {
                  T[36][i] = -1;       
                         }
      T[36][14]=63;
      for(i=15;i<30;i++) 
     {
                  T[36][i] = -1;       
                         }
      T[36][30]=64;
      T[36][31]=65;
      T[36][32]=-1;
      T[36][33]=-1;
      T[36][34]=-1;
      T[36][35]=-1;
      T[36][36]=-1;
      T[36][37]=-1;
      T[36][38]=-1;
      T[36][39]=-1;
      
      
      
      //FOR NON TERMINAL var                    
      
      T[37][0]=-1;
      T[37][1]=70;
      for(i=2;i<14;i++) 
     {
                  T[37][i] = -1;       
                         }
      T[37][14]=66;
      T[37][15]=67;
      for(i=16;i<30;i++) 
     {
                  T[37][i] = -1;       
                         }
      T[37][30]=68;
      T[37][31]=69;
      T[37][32]=-1;
      T[37][33]=-1;
      T[37][34]=-1;
      T[37][35]=-1;
      T[37][36]=-1;
      T[37][37]=-1;
      T[37][38]=-1;
      T[37][39]=-1;
      
      
      //FOR NON TERMINAL var_next                   
      
      T[38][0]=-1;
      T[38][1]=71;
      for(i=2;i<12;i++) 
     {
                  T[38][i] = -1;       
                         }
      T[38][12]=72;
      T[38][13]=72;
      T[38][14]=-1;
      T[38][15]=-1;
      T[38][16]=-1;
      T[38][17]=72;
      for(i=18;i<23;i++) 
     {
                  T[38][i] = -1;       
                         }
     T[38][23]=72;
     T[38][24]=72;
     T[38][25]=72;
     T[38][26]=72;
     for(i=27;i<40;i++) 
     {
                  T[38][i] = -1;       
                         }
      
      
      
      //FOR NON TERMINAL relationalOp
       for(i=0;i<32;i++) 
     {
                  T[39][i] = -1;       
                         }
      T[39][32]=73;
      T[39][33]=74;
      T[39][34]=75;
      T[39][35]=76;
      T[39][36]=77;
      T[39][37]=78;
      T[39][38]=-1;
      T[39][39]=-1;
      
      
      
      //FOR NON TERMINAL matrix
      T[40][0]=-1;
      T[40][1]=79;
      for(i=2;i<40;i++) 
     {
                  T[40][i] = -1;       
                         }
                         
                         
                         
     //FOR NON TERMINAL row
     for(i=0;i<30;i++) 
     {
                  T[41][i] = -1;       
                         }                   
     T[41][30]=80;
     for(i=31;i<40;i++) 
     {
                  T[41][i] = -1;       
                         }
                         
                         
                         
     //FOR NON TERMINAL moreRows
      T[42][0]=-1;
      T[42][1]=-1;
      T[42][2]=82;
      for(i=3;i<13;i++) 
     {
                  T[42][i] = -1;       
                         } 
      T[42][13]=81;
      for(i=14;i<40;i++) 
     {
                  T[42][i] = -1;       
                         }  
                         
                         
                         
     //FOR NON TERMINAL moreNum
      T[43][0]=-1;
      T[43][1]=-1;
      T[43][2]=84;
      for(i=3;i<12;i++) 
     {
                  T[43][i] = -1;       
                         } 
      T[43][12]=83;
      T[43][13]=84;
      for(i=14;i<40;i++) 
     {
                  T[43][i] = -1;       
                         }
                         
                         
      //FOR NON TERMINAL funCallStmt
       for(i=0;i<7;i++) 
     {
                  T[44][i] = -1;       
                         }   
      T[44][7]=85;              
      for(i=8;i<40;i++) 
     {
                  T[44][i] = -1;       
                         } 
                         
                         
      
      //FOR NON TERMINAL inputParameterList
      T[45][0]=-1;
      T[45][1]=86;
      for(i=2;i<14;i++) 
     {
                  T[45][i] = -1;       
                         }
     T[45][14]=86;
     T[45][15]=86;
     T[45][16]=-1;
     T[45][17]=87;
     for(i=18;i<30;i++) 
     {
                  T[45][i] = -1;       
                         }
     T[45][30]=86;
     T[45][31]=86;
     for(i=32;i<40;i++) 
     {
                  T[45][i] = -1;       
                         }
                         
                         
     //FOR NON TERMINAL listVar
     
     for(i=0;i<13;i++) 
     {
                  T[46][i] = -1;       
                         }
     T[46][12]=88;
     T[46][14]=-1;
     T[46][15]=-1;
     T[46][16]=-1;
     T[46][17]=89; 
     for(i=18;i<40;i++) 
     {
                  T[46][i] = -1;       
                         } 
                         
     //FOR NON TERMINAL sizeOp
       for(i=0;i<38;i++) 
     {
                  T[47][i] = -1;       
                         }   
      T[47][38]=90;                  
      T[47][39]=-1;                   
      
      
     /// to print the array                   
     /* for(j=0;j<48;j++)
      {
                       for(k=0;k<40;k++)
                       {
                                        printf("%d ",T[j][k]);
                                        }
                       printf("\n");
      
      }*/
      
     // getch();
 }



parseTree  parseInputSourceCode(char *testcaseFile, table T,grammar G){
	int line_global;
	FILE *fp,*fp2;
	int prodRuleNo=-1;
	parseTree PT;
	line_no=1;
	buf_ptr=0;
	forward=1;
	tokenInfo TI,T2;
	//strcpy(T2.lex_name,"----");
	//strcpy(T2.Tok_name,"--");
	T2.attribute_int=-1;
	T2.attribute_float=-1;
	//T2.line=-1;
	//printf("\n34533\n");	//
	int p;
	buffer B;
	Boolean bl;
	fp=fopen(testcaseFile,"r");
	Stack st,st2;
	char parentNode[LIM];
	char c[LIM];
	st=newStack();
	strcpy(c,"$");
	//printf("\n2233\n");	//
	bl=push(st,c,-2);
	//printf("\n4443\n");	//
	//printf("%s",G[0].nonTerm);
	bl=push(st,G[0].nonTerm,-1);
	//display(st);
	//printf("\n5553\n");	//
	//strcpy(parentNode,"rootNode");
	//printf("\n5555\n");	//
	PT=createList();
	//printf("\n666\n");	//
	TI=getNextToken(fp,B);
	line_global=TI.line;
	//display(st);
	while(size(st)!=0){
		//printf("\n2256\n");	//
		bl=top(st,&prodRuleNo);
//printf("\n2733\n");	//
		bl=pop(st,c);
//printf("\n2833\n");	//
		if(prodRuleNo==-1){
			//printf("\n78a33\n");	//
			strcpy(parentNode,"rootNode");
			//printf("\n7833\n");	//
		}
		else if(prodRuleNo==-2){
			strcpy(parentNode,"---");
			//printf("\n0833\n");	//
		}
		else{
			//printf("\n88bb33\n");	//
			//printf("%s\n",G[prodRuleNo].nonTerm);		//
			strcpy(parentNode,G[prodRuleNo].nonTerm);
			//printf("\n88833\n");	//
		}
		//printf("%s\n",c);
		//display(st);
		if((getValueNonTerm(c))>=0 && (getValueNonTerm(c))<=47){
			strcpy(T2.lex_name,"----");
			strcpy(T2.Tok_name,c);
			T2.line=line_global;
			//printf("\n2233\n");	//
			PT=insertelem(PT,c,0,parentNode,T2);
			//printf("\n2233\n");
			//strcpy(parentNode,c);
			p=T[getValueNonTerm(c)][getValueTerm(TI.Tok_name)];
			//printf("%d\n",p);
			if(p<=-1){ //value of empty slot
				printf("\nERROR_5: The token %s for %s does not match at line %d.\n",TI.Tok_name,TI.lex_name,TI.line);
				//printf("%s %s %s\n",c,TI.lex_name,TI.Tok_name);
				fclose(fp);
				return PT;
				break;
			}
			else{
				//st2=G[p].s;
				//display(st2);
				//FILE *fp2;
				fp2=fopen("productionRules.txt","r");
				G=create_gram(fp2);
				fclose(fp2);
				//display(G[24].s);
				//printf("%s\n",G[p].nonTerm);
				//display(G[p].s);
				//printf("\n%d\n",size(G[p].s));
				while(size(G[p].s)!=0){
					//printf("\n2233\n");
					bl=pop(G[p].s,c);
					//printf("\n1111\n");
					//bl=pop(G[p].s);
					bl=push(st,c,p);
				}	
			
			}
		}
		//if terminal
		else{
			if(strcmp(c,TI.Tok_name)==0){
				//printf("abc%s %s\n",c,TI.lex_name);
				PT=insertelem(PT,c,1,parentNode,TI);
				TI=getNextToken(fp,B);
				line_global=TI.line;
			}
			else{
				//printf("%s %s\n",c,TI.lex_name);
				printf("ERROR: The token %s for lexeme %s. The expected token here is %s\n",TI.Tok_name,TI.lex_name,c);
				fclose(fp);
				return PT;
				break;
			}
		}
	
	}
	printf("Compilation Complete");
	return PT;
	
}


void printParseTree(parseTree  PT, char *outfile){
	parseTree ptr=PT;
	FILE *fout;
	fout=fopen(outfile,"w");

	fprintf(fout,"lexemeCurrentNode   	lineno	token     	valueIfNumber	parentNodeSymbol	isLeafNode	NodeSymbol\n");	
	
	while(ptr!=NULL){
		if(ptr->isLeaf==0){	//nonterminal
			fprintf(fout,"%-20s	-     	-         	-            	%-16s	0         	%s\n",ptr->TI.lex_name,ptr->parentNode,ptr->data);
			//printf("%d",ptr->elem);
			ptr=ptr->p_next;
		}
		else{
			if(ptr->TI.attribute_int!=-1){
				fprintf(fout,"%-20s	%-6d	%-10s	%-13d	%-16s	1         	%s\n",ptr->TI.lex_name,ptr->TI.line,ptr->TI.Tok_name,ptr->TI.attribute_int,ptr->parentNode,ptr->data);
				//printf("%d",ptr->elem);
				ptr=ptr->p_next;
			}
			else if(ptr->TI.attribute_float!=-1){
				fprintf(fout,"%-20s	%-6d	%-10s	%-13f	%-16s	1         	%s\n",ptr->TI.lex_name,ptr->TI.line,ptr->TI.Tok_name,ptr->TI.attribute_float,ptr->parentNode,ptr->data);
				ptr=ptr->p_next;
			}
			else{
				fprintf(fout,"%-20s	%-6d	%-10s	-            	%-16s	1         	%s\n",ptr->TI.lex_name,ptr->TI.line,ptr->TI.Tok_name,ptr->parentNode,ptr->data);
				ptr=ptr->p_next;
			}
		}
	}
	fclose(fout);
}

