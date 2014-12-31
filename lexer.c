// BATCH 21
// KRISHNIKA AGARWAL 2011C6PS839P
//NAINCY SUMAN 2011C6PS692P


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include "lexerDef.h"
#include "lexer.h"
//#include"ops.h"

FILE *getStream(FILE *fp, buffer B, int k)
{
     int i = buf_ptr;int j;
	//printf("**%d\n",buf_ptr);
	 char c;
	while(!feof(fp) && i<k){
		c=getc(fp);
		B[i]=c;
		//printf("\n%c",c);
	  	//printf("%c",B[i]);
		i++;
	}

	if(feof(fp)){
	//printf("\n\n...\n\n");
           B[i-2]= '$'; 
	//printf("\n\n...\n\n");
	}
	
	/*for(j=0;j<=i;j++){
		printf("%c",B[j]);
	}*/
           return fp;
     
 }


tokenInfo  getNextToken( FILE *fp,buffer B){
	int k=BUFFERSIZE;
	tokenInfo TI;
	TI.done=0;
	TI.attribute_int=-1;
	TI.attribute_float=-1.00;
	char lex[MAX]={NULL};
	int l=0;
	//forward=buf_ptr+1;
	//printf("\nabc4\n");
	if(B[0]==NULL){
	//	printf("\nabc4.4\n");
		fp=getStream(fp,B,k);
	}
	//printf("%d\n",buf_ptr);

	//while(B[buf_ptr]!='$'){
	//	printf("\nabc5\n");
		while(forward!=k || TI.done!=0){		//while2

			while(B[buf_ptr]==' ' || B[buf_ptr]=='\t' || B[buf_ptr]=='\n' || B[buf_ptr]=='#'){
				if(B[buf_ptr]==' '){
					buf_ptr++;
					//lexeme_start++;
					forward++;
					//col_no++;
				}
				if(B[buf_ptr]=='\t'){
					//int j=4-(col_no%4)+1;
					//col_no=col_no+j;
					buf_ptr++;
					//lexeme_start++;
					forward++;
				}
				if(B[buf_ptr]=='\n'){
					buf_ptr++;
					//lexeme_start++;
					forward++;
					line_no++;
					//col_no=1;
				}
				if(B[buf_ptr]=='#'){
				while(B[buf_ptr]!='\n'){
					buf_ptr++;
					//lexeme_start++;
					//forward++;
					//col_no++;
				}
				line_no++;
				buf_ptr++;

				//lexeme_start=buf_ptr;

				forward=buf_ptr+1;

				//col_no=1;

			}
			
			}

			/*if(B[buf_ptr]=='#'){
				while(B[buf_ptr]!='\n'){
					buf_ptr++;
					//lexeme_start++;
					//forward++;
					//col_no++;
				}
				line_no++;
				buf_ptr++;
				//lexeme_start=buf_ptr;
				forward=buf_ptr+1;
				//col_no=1;
			}
*/
			
			if(B[buf_ptr]=='='){
				//lexeme_start=buf_ptr;
				forward=buf_ptr+1;
				lex[l]=B[buf_ptr];
					
				if(B[forward]=='/' && B[forward+1]=='='){
					lex[l+1]=B[forward];
					lex[l+2]=B[forward+1];
					strcpy(TI.Tok_name,"NE");
					strcpy(TI.lex_name,lex);
					TI.line=line_no;
					TI.done=1;
					//TI.col=col_no;
					//col_no=col_no+3;
					buf_ptr=forward+2;
					//lexeme_start=buf_ptr;
					forward=buf_ptr+1;
					return TI;
					break;
				}
						
				else if(B[forward]=='='){
					lex[l+1]=B[forward];
					strcpy(TI.Tok_name,"EQ");
					strcpy(TI.lex_name,lex);
					TI.line=line_no;
					TI.done=1;					
					//TI.col=col_no;
					//col_no=col_no+2;
					buf_ptr=forward+1;
					//lexeme_start=buf_ptr;
					forward=buf_ptr+1;
					return TI;
					break;
				}
						
				else{
					strcpy(TI.Tok_name,"ASSIGNOP");
					strcpy(TI.lex_name,lex);
					TI.line=line_no;
					TI.done=1;
					//TI.col=col_no;
					//col_no++;
					buf_ptr=forward;
					//lexeme_start=forward;
					forward++;
					return TI;
					break;
				}
				}

			if(B[buf_ptr]=='['){
				lex[l]=B[buf_ptr];
				strcpy(TI.Tok_name,"SQO");
				strcpy(TI.lex_name,lex);
				TI.line=line_no;
				TI.done=1;
				//TI.co=col_no;
				//col_no++;
				buf_ptr=forward;
				//lexeme_start=forward;
				forward++;
				return TI;
				break;
			}
					
			if(B[buf_ptr]==']'){
				lex[l]=B[buf_ptr];
				strcpy(TI.Tok_name,"SQC");
				strcpy(TI.lex_name,lex);
				TI.line=line_no;
				TI.done=1;
				//col_no++;
				buf_ptr=forward;
				//lexeme_start=forward;
				forward++;
				return TI;
				break;
			}
					
			if(B[buf_ptr]=='('){
				lex[l]=B[buf_ptr];
				strcpy(TI.Tok_name,"OP");
				strcpy(TI.lex_name,lex);
				TI.line=line_no;
				TI.done=1;
				//col_no++;
				buf_ptr=forward;
				//lexeme_start=forward;
				forward++;
				return TI;
				break;
			}
					
			if(B[buf_ptr]==')'){
				lex[l]=B[buf_ptr];
				strcpy(TI.Tok_name,"CL");
				strcpy(TI.lex_name,lex);
				TI.line=line_no;
				TI.done=1;
				//col_no++;
				buf_ptr=forward;
				//lexeme_start=forward;
				forward++;
				return TI;
				break;
			}

			if(B[buf_ptr]==','){
				lex[l]=B[buf_ptr];
				strcpy(TI.Tok_name,"COMMA");
				strcpy(TI.lex_name,lex);
				TI.line=line_no;
				TI.done=1;
				//col_no++;
				buf_ptr=forward;
				//lexeme_start=forward;
				forward++;
				return TI;
				break;
			}
				
			if(B[buf_ptr]=='+'){
				lex[l]=B[buf_ptr];
				strcpy(TI.Tok_name,"PLUS");
				strcpy(TI.lex_name,lex);
				TI.line=line_no;
				TI.done=1;
				//col_no++;
				buf_ptr=forward;
				//lexeme_start=forward;
				forward++;
				return TI;
				break;
			}
					
			if(B[buf_ptr]=='-'){
				lex[l]=B[buf_ptr];
				strcpy(TI.Tok_name,"MINUS");
				strcpy(TI.lex_name,lex);
				TI.line=line_no;
				TI.done=1;
				//col_no++;
				buf_ptr=forward;
				//lexeme_start=forward;
				forward++;
				return TI;
				break;
			}
				
			if(B[buf_ptr]=='*'){
				lex[l]=B[buf_ptr];
				strcpy(TI.Tok_name,"MUL");
				strcpy(TI.lex_name,lex);
				TI.line=line_no;
				TI.done=1;
				//col_no++;
				buf_ptr=forward;
				//lexeme_start=forward;
				forward++;
				return TI;
				break;
			}
					
			if(B[buf_ptr]=='/'){
				lex[l]=B[buf_ptr];
				strcpy(TI.Tok_name,"DIV");
				strcpy(TI.lex_name,lex);
				TI.line=line_no;
				TI.done=1;
				//col_no++;
				buf_ptr=forward;
				//lexeme_start=forward;
				forward++;
				return TI;
				break;
			}
					
			if(B[buf_ptr]=='@'){
				lex[l]=B[buf_ptr];
				strcpy(TI.Tok_name,"SIZE");
				strcpy(TI.lex_name,lex);
				TI.line=line_no;
				TI.done=1;
				//col_no++;
				buf_ptr=forward;
				//lexeme_start=forward;
				forward++;
				return TI;
				break;
			}
				
			if(B[buf_ptr]=='<'){
				lex[l]=B[buf_ptr];
				if(B[forward]=='='){
					lex[l+1]=B[forward];
					strcpy(TI.lex_name,lex);
					strcpy(TI.Tok_name,"LE");
					TI.line=line_no;
					TI.done=1;
					//col_no=co_no+2;
					buf_ptr=forward+1;
					//lexeme_start=buf_ptr;
					forward=buf_ptr+1;
					return TI;
					break;
				}
				else{
					strcpy(TI.Tok_name,"LT");
					strcpy(TI.lex_name,lex);
					TI.line=line_no;
					TI.done=1;
					//col_no++;
					buf_ptr=forward;
					//lexeme_start=forward;
					forward++;
					return TI;
					break;
				}
			}
					
			if(B[buf_ptr]=='>'){
				lex[l]=B[buf_ptr];
				if(B[forward]=='='){
					lex[l+1]=B[forward];
					strcpy(TI.lex_name,lex);
					strcpy(TI.Tok_name,"GE");
					TI.line=line_no;
					TI.done=1;
					//col_no=co_no+2;
					buf_ptr=forward+1;
					//lexeme_start=buf_ptr;
					forward=buf_ptr+1;
					return TI;
					break;
				}
				else{
					strcpy(TI.Tok_name,"GT");
					strcpy(TI.lex_name,lex);
					TI.line=line_no;
					TI.done=1;
					//col_no++;
					buf_ptr=forward;
					//lexeme_start=forward;
					forward++;
					return TI;
					break;
				}
			}

			if(B[buf_ptr]=='.'){
				lex[l]=B[buf_ptr];
				l++;
				switch(B[forward]){
					case 'a':
						lex[l]=B[forward];
						l++;
						forward++;
						switch(B[forward]){
							case 'n':
								lex[l]=B[forward];
								l++;
								forward++;
								switch(B[forward]){
									case 'd':
										lex[l]=B[forward];
										l++;
										forward++;
										switch(B[forward]){
											case '.':
												lex[l]=B[forward];
												forward++;
												strcpy(TI.Tok_name,"AND");
												strcpy(TI.lex_name,lex);
												TI.line=line_no;
												TI.done=1;
												buf_ptr=forward;
												forward=buf_ptr+1;
												return TI;
												break;
											default:
												printf("Error1:Line=%d ",line_no);
												strcpy(TI.Tok_name,"ERROR");
												strcpy(TI.lex_name,lex);
												TI.line=line_no;
												TI.done=1;
												//col_no=col_no+count; //or col_no=col_no++
												buf_ptr=forward;
												//lexeme_start=forward;
												forward=buf_ptr+1;
												return TI;
												break;
										}
									default:
										printf("ERROR:  Unknown pattern %s\n ",lex);
										strcpy(TI.Tok_name,"ERROR");
										strcpy(TI.lex_name,lex);
										TI.line=line_no;
										TI.done=1;
										//col_no=col_no+count; //or col_no=col_no++
										buf_ptr=forward;
										//lexeme_start=forward;
										forward=buf_ptr+1;
										return TI;
										break;
								}
							default:
								printf("ERROR:  Unknown pattern %s\n ",lex);
								strcpy(TI.Tok_name,"ERROR");
								strcpy(TI.lex_name,lex);
								TI.line=line_no;
								TI.done=1;
								//col_no=col_no+count; //or col_no=col_no++
								buf_ptr=forward;
								//lexeme_start=forward;
								forward=buf_ptr+1;
								return TI;
								break;
						}
					case 'o':
						lex[l]=B[forward];
						l++;
						forward++;
						switch(B[forward]){
							case 'r':
								lex[l]=B[forward];
								l++;
								forward++;
								switch(B[forward]){
									case '.':
										lex[l]=B[forward];
										forward++;
										strcpy(TI.Tok_name,"OR");
										strcpy(TI.lex_name,lex);
										TI.line=line_no;
										TI.done=1;
										buf_ptr=forward;
										forward=buf_ptr+1;
										return TI;
										break;
									default:
										printf("ERROR:  Unknown pattern %s\n ",lex);
										strcpy(TI.Tok_name,"ERROR");
										strcpy(TI.lex_name,lex);
										TI.line=line_no;
										TI.done=1;
										//col_no=col_no+count; //or col_no=col_no++
										buf_ptr=forward;
										//lexeme_start=forward;
										forward=buf_ptr+1;
										return TI;
										break;
								}
							default:
								printf("ERROR:  Unknown pattern %s\n ",lex);
								strcpy(TI.Tok_name,"ERROR");
								strcpy(TI.lex_name,lex);
								TI.line=line_no;
								TI.done=1;
								//col_no=col_no+count; //or col_no=col_no++
								buf_ptr=forward;
								//lexeme_start=forward;
								forward=buf_ptr+1;
								return TI;
								break;
						}
					case 'n':
						lex[l]=B[forward];
						l++;
						forward++;
						switch(B[forward]){
							case 'o':
								lex[l]=B[forward];
								l++;
								forward++;
								switch(B[forward]){
									case 't':
										lex[l]=B[forward];
										l++;
										forward++;
										switch(B[forward]){
											case '.':
												lex[l]=B[forward];
												forward++;
												strcpy(TI.Tok_name,"NOT");
												strcpy(TI.lex_name,lex);
												TI.line=line_no;
												TI.done=1;
												buf_ptr=forward;
												forward=buf_ptr+1;
												return TI;
												break;
											default:
												printf("ERROR:  Unknown pattern %s\n ",lex);
												strcpy(TI.Tok_name,"ERROR");
												strcpy(TI.lex_name,lex);
												TI.line=line_no;
												TI.done=1;
												//col_no=col_no+count; //or col_no=col_no++
												buf_ptr=forward;
												//lexeme_start=forward;
												forward=buf_ptr+1;
												return TI;
												break;
										}
									default:
										printf("ERROR:  Unknown pattern %s\n ",lex);
										strcpy(TI.Tok_name,"ERROR");
										strcpy(TI.lex_name,lex);
										TI.line=line_no;
										TI.done=1;
										//col_no=col_no+count; //or col_no=col_no++
										buf_ptr=forward;
										//lexeme_start=forward;
										forward=buf_ptr+1;
										return TI;
										break;
								}
							default:
								printf("ERROR:  Unknown pattern %s\n ",lex);
								strcpy(TI.Tok_name,"ERROR");
								strcpy(TI.lex_name,lex);
								TI.line=line_no;
								TI.done=1;
								//col_no=col_no+count; //or col_no=col_no++
								buf_ptr=forward;
								//lexeme_start=forward;
								forward=buf_ptr+1;
								return TI;
								break;
						}
					default:
						printf("ERROR:  Unknown pattern %s\n ",lex);
						strcpy(TI.Tok_name,"ERROR");
						strcpy(TI.lex_name,lex);
						TI.line=line_no;
						TI.done=1;
						//col_no=col_no+count; //or col_no=col_no++
						buf_ptr=forward;
						//lexeme_start=forward;
						forward=buf_ptr+1;
						return TI;
						break;
				}			
			}
			
			if(B[buf_ptr]=='_'){
				lex[l]=B[buf_ptr];
				l++;
				if(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
					switch(B[forward]){
						case 'm':
							lex[l]=B[forward];
							l++;
							forward++;
							switch(B[forward]){
								case 'a':
									lex[l]=B[forward];
									l++;
									forward++;
									switch(B[forward]){
										case 'i':
											lex[l]=B[forward];
											l++;
											forward++;
											switch(B[forward]){
												case 'n':
													lex[l]=B[forward];
													l++;
													forward++;
													if(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z' || B[forward]>='0' && B[forward]<='9'){
														while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z' || B[forward]>='0' && B[forward]<='9'){
															lex[l]=B[forward];
															forward++;
															l++;
														}
														strcpy(TI.Tok_name,"FUNID");
														strcpy(TI.lex_name,lex);
														TI.line=line_no;
														TI.done=1;
														buf_ptr=forward;
														//lexeme_start=forward;
														forward=buf_ptr+1;
														return TI;
														break;
													}
													else{
														strcpy(TI.Tok_name,"MAIN");
														strcpy(TI.lex_name,lex);
														TI.line=line_no;
														TI.done=1;
														buf_ptr=forward;
														//lexeme_start=forward;
														forward=buf_ptr+1;
														return TI;
														break;
													}
												default:
													if(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z' || B[forward]>='0' && B[forward]<='9'){
														while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z' || B[forward]>='0' && B[forward]<='9'){
															lex[l]=B[forward];
															forward++;
															l++;
														}
														strcpy(TI.Tok_name,"FUNID");
														strcpy(TI.lex_name,lex);
														TI.line=line_no;
														TI.done=1;
														buf_ptr=forward;
														//lexeme_start=forward;
														forward=buf_ptr+1;
														return TI;
														break;
													}
													else{
														strcpy(TI.Tok_name,"FUNID");
														strcpy(TI.lex_name,lex);
														TI.line=line_no;
														TI.done=1;
														buf_ptr=forward;
														//lexeme_start=forward;
														forward=buf_ptr+1;
														return TI;
														break;
													}
											}
										default:
											if(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z' || B[forward]>='0' && B[forward]<='9'){
												while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z' || B[forward]>='0' && B[forward]<='9'){
													lex[l]=B[forward];
													forward++;
													l++;
												}
												strcpy(TI.Tok_name,"FUNID");
												strcpy(TI.lex_name,lex);
												TI.line=line_no;
												TI.done=1;
												buf_ptr=forward;
												//lexeme_start=forward;
												forward=buf_ptr+1;
												return TI;
												break;
											}
											else{
												strcpy(TI.Tok_name,"FUNID");
												strcpy(TI.lex_name,lex);
												TI.line=line_no;
												TI.done=1;
												buf_ptr=forward;
												//lexeme_start=forward;
												forward=buf_ptr+1;
												return TI;
												break;
											}
									}
								default:
									if(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z' || B[forward]>='0' && B[forward]<='9'){
										while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z' || B[forward]>='0' && B[forward]<='9'){
											lex[l]=B[forward];
											forward++;
											l++;
										}
										strcpy(TI.Tok_name,"FUNID");
										strcpy(TI.lex_name,lex);
										TI.line=line_no;
										TI.done=1;
										buf_ptr=forward;
										//lexeme_start=forward;
										forward=buf_ptr+1;
										return TI;
										break;
									}
									else{
										strcpy(TI.Tok_name,"FUNID");
										strcpy(TI.lex_name,lex);
										TI.line=line_no;
										TI.done=1;
										buf_ptr=forward;
										//lexeme_start=forward;
										forward=buf_ptr+1;
										return TI;
										break;
									}
							}
						default:
							while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z' || B[forward]>='0' && B[forward]<='9'){
								lex[l]=B[forward];
								forward++;
								l++;
							}
							strcpy(TI.Tok_name,"FUNID");
							strcpy(TI.lex_name,lex);
							TI.line=line_no;
							TI.done=1;
							buf_ptr=forward;
							//lexeme_start=forward;
							forward=buf_ptr+1;
							return TI;
							break;
					}
				}
				/*else{
					printf("ERROR:  Unknown symbol %s at line %d\n ",lex,line_no);
					strcpy(TI.Tok_name,"ERROR");
					strcpy(TI.lex_name,lex);
					TI.line=line_no;
					TI.done=1;
					buf_ptr=forward;
					//lexeme_start=forward;
					forward=buf_ptr+1;
					return TI;
					break;
				}*/
			}

			if(B[buf_ptr]>='a' && B[buf_ptr]<='z' || B[buf_ptr]>='A' && B[buf_ptr]<='Z'){
				switch(B[buf_ptr]){
					case 'e':
						lex[l]=B[buf_ptr];
						l++;
						switch(B[forward]){
							case 'n':
								lex[l]=B[forward];
								l++;
								forward++;
								switch(B[forward]){
									case 'd':
										lex[l]=B[forward];
										l++;
										forward++;
										switch(B[forward]){
											case 'i':
												lex[l]=B[forward];
												l++;
												forward++;
												switch(B[forward]){
													case 'f':
														lex[l]=B[forward];
														l++;
														forward++;
														if(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z' || B[forward]>='0' && B[forward]<='9'){
															while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
																lex[l]=B[forward];
																l++;
																forward++;
															}
															if(B[forward]>='0' && B[forward]<='9'){									/////
																if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
																else{
																lex[l]=B[forward];
																l++;
																forward++;
																}
															}
															if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no);strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1;return TI; break;}
															else{
															strcpy(TI.Tok_name,"ID");
															strcpy(TI.lex_name,lex);
															TI.line=line_no;
															TI.done=1;
															buf_ptr=forward;
															//lexeme_start=forward;
															forward=buf_ptr+1;
															return TI;
															break;}
														}
														else{
															strcpy(TI.Tok_name,"ENDIF");
															strcpy(TI.lex_name,lex);
															TI.line=line_no;
															TI.done=1;
															buf_ptr=forward;
															//lexeme_start=forward;
															forward=buf_ptr+1;
															return TI;
															break;
														}
													default:
														while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
															lex[l]=B[forward];
															l++;
															forward++;
														}
														if(B[forward]>='0' && B[forward]<='9'){
															if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
															else{
															lex[l]=B[forward];
															l++;
															forward++;
															}
														}
														if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no);strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1; return TI;break;}
														else{
														strcpy(TI.Tok_name,"ID");
														strcpy(TI.lex_name,lex);
														TI.line=line_no;
														TI.done=1;
														buf_ptr=forward;
														//lexeme_start=forward;
														forward=buf_ptr+1;
														return TI;
														break;}
												}
											default:
												if(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z' || B[forward]>='0' && B[forward]<='9'){
													while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
														lex[l]=B[forward];
														l++;
														forward++;
													}
													if(B[forward]>='0' && B[forward]<='9'){
														if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
														else{
														lex[l]=B[forward];
														l++;
														forward++;
														}
													}
													if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no);strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1;return TI; break;}
													else{
													strcpy(TI.Tok_name,"ID");
													strcpy(TI.lex_name,lex);
													TI.line=line_no;
													TI.done=1;
													buf_ptr=forward;
													//lexeme_start=forward;
													forward=buf_ptr+1;
													return TI;
													break;}
												}
												else{
													strcpy(TI.Tok_name,"END");
													strcpy(TI.lex_name,lex);
													TI.line=line_no;
													TI.done=1;
													buf_ptr=forward;
													//lexeme_start=forward;
													forward=buf_ptr+1;
													return TI;
													break;
												}
										}
									default:
										while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
										lex[l]=B[forward];
										l++;
										forward++;
										}
										if(B[forward]>='0' && B[forward]<='9'){
											if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
											else{
											lex[l]=B[forward];
											l++;
											forward++;
											}
										}
										if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no);strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1;return TI; break;}
										else{
										strcpy(TI.Tok_name,"ID");
										strcpy(TI.lex_name,lex);
										TI.line=line_no;
										TI.done=1;
										buf_ptr=forward;
										//lexeme_start=forward;
										forward=buf_ptr+1;
										return TI;
										break;}
								}
							case 'l':
								lex[l]=B[forward];
								l++;
								forward++;
								switch(B[forward]){
									case 's':
										lex[l]=B[forward];
										l++;
										forward++;
										switch(B[forward]){
											case 'e':
												lex[l]=B[forward];
												l++;
												forward++;
												if(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z' || B[forward]>='0' && B[forward]<='9'){
													while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
														lex[l]=B[forward];
														l++;
														forward++;
													}
													if(B[forward]>='0' && B[forward]<='9'){
														if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
														else{
														lex[l]=B[forward];
														l++;
														forward++;
														}
													}
													if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no);strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1; return TI;break;}
													else{
													strcpy(TI.Tok_name,"ID");
													strcpy(TI.lex_name,lex);
													TI.line=line_no;
													TI.done=1;
													buf_ptr=forward;
													//lexeme_start=forward;
													forward=buf_ptr+1;
													return TI;
													break;}
												}
												else{
													strcpy(TI.Tok_name,"ELSE");
													strcpy(TI.lex_name,lex);
													TI.line=line_no;
													TI.done=1;
													buf_ptr=forward;
													//lexeme_start=forward;
													forward=buf_ptr+1;
													return TI;
													break;
												}
											default:
												while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
													lex[l]=B[forward];
													l++;
													forward++;
												}
												if(B[forward]>='0' && B[forward]<='9'){
													if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
													else{
													lex[l]=B[forward];
													l++;
													forward++;
													}
												}
												if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no);strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1;return TI; break;}
												else{
												strcpy(TI.Tok_name,"ID");
												strcpy(TI.lex_name,lex);
												TI.line=line_no;
												TI.done=1;
												buf_ptr=forward;
												//lexeme_start=forward;
												forward=buf_ptr+1;
												return TI;
												break;}
										}
									default:
										while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
											lex[l]=B[forward];
											l++;
											forward++;
										}
										if(B[forward]>='0' && B[forward]<='9'){
											if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
											else{
											lex[l]=B[forward];
											l++;
											forward++;
											}
										}
										if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no);strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1; return TI;break;}
															else{
										strcpy(TI.Tok_name,"ID");
										strcpy(TI.lex_name,lex);
										TI.line=line_no;
										TI.done=1;
										buf_ptr=forward;
										//lexeme_start=forward;
										forward=buf_ptr+1;
										return TI;
										break;}
								}
							default:
								while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
								lex[l]=B[forward];
								l++;
								forward++;
								}
								if(B[forward]>='0' && B[forward]<='9'){
									if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
									else{
									lex[l]=B[forward];
									l++;
									forward++;
									}
								}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no);strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1; return TI;break;}
															else{
								strcpy(TI.Tok_name,"ID");
								strcpy(TI.lex_name,lex);
								TI.line=line_no;
								TI.done=1;
								buf_ptr=forward;
								//lexeme_start=forward;
								forward=buf_ptr+1;
								return TI;
								break;}
						}
					case 'i':
						lex[l]=B[buf_ptr];
						l++;
						switch(B[forward]){
							case 'n':
								lex[l]=B[forward];
								l++;
								forward++;
								switch(B[forward]){
									case 't':
										lex[l]=B[forward];
										l++;
										forward++;
										if(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z' || B[forward]>='0' && B[forward]<='9'){
											while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
												lex[l]=B[forward];
												l++;
												forward++;
											}
											if(B[forward]>='0' && B[forward]<='9'){
												if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
												else{
												lex[l]=B[forward];
												l++;
												forward++;
												}
											}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no);strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1; return TI;break;}
															else{
											strcpy(TI.Tok_name,"ID");
											strcpy(TI.lex_name,lex);
											TI.line=line_no;
											TI.done=1;
											buf_ptr=forward;
											//lexeme_start=forward;
											forward=buf_ptr+1;
											return TI;
											break;}
										}
										else{
											strcpy(TI.Tok_name,"INT");
											strcpy(TI.lex_name,lex);
											TI.line=line_no;
											TI.done=1;
											buf_ptr=forward;
											//lexeme_start=forward;
											forward=buf_ptr+1;
											return TI;
											break;
										}
									default:
										while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
											lex[l]=B[forward];
											l++;
											forward++;
										}
										if(B[forward]>='0' && B[forward]<='9'){
											if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
											else{
											lex[l]=B[forward];
											l++;
											forward++;
										}
										}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no);strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1; return TI;break;}
															else{
										strcpy(TI.Tok_name,"ID");
										strcpy(TI.lex_name,lex);
										TI.line=line_no;
										TI.done=1;
										buf_ptr=forward;
										//lexeme_start=forward;
										forward=buf_ptr+1;
										return TI;
										break;}
								}
							case 'f':
								lex[l]=B[forward];
								l++;
								forward++;
								if(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z' || B[forward]>='0' && B[forward]<='9'){
									while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
										lex[l]=B[forward];
										l++;
										forward++;
									}
									if(B[forward]>='0' && B[forward]<='9'){
										if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
										else{
										lex[l]=B[forward];
										l++;
										forward++;
										}
									}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no);strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1; return TI;break;}
															else{
									strcpy(TI.Tok_name,"ID");
									strcpy(TI.lex_name,lex);
									TI.line=line_no;
									TI.done=1;
									buf_ptr=forward;
									//lexeme_start=forward;
									forward=buf_ptr+1;
									return TI;
									break;}
								}
								else{
									strcpy(TI.Tok_name,"IF");
									strcpy(TI.lex_name,lex);
									TI.line=line_no;
									TI.done=1;
									buf_ptr=forward;
									//lexeme_start=forward;
									forward=buf_ptr+1;
									return TI;
									break;
								}
							default:
								while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
									lex[l]=B[forward];
									l++;
									forward++;
								}
								if(B[forward]>='0' && B[forward]<='9'){
									if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
									else{
									lex[l]=B[forward];
									l++;
									forward++;
									}
								}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no);strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1;return TI; break;}
															else{
								strcpy(TI.Tok_name,"ID");
								strcpy(TI.lex_name,lex);
								TI.line=line_no;
								TI.done=1;
								buf_ptr=forward;
								//lexeme_start=forward;
								forward=buf_ptr+1;
								return TI;
								break;}
						}
					case 'r':
						lex[l]=B[buf_ptr];
						l++;
						switch(B[forward]){
							case 'e':
								lex[l]=B[forward];
								l++;
								forward++;
								switch(B[forward]){
									case 'a':
										lex[l]=B[forward];
										l++;
										forward++;
										switch(B[forward]){
											case 'd':
												lex[l]=B[forward];
												l++;
												forward++;
												if(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z' || B[forward]>='0' && B[forward]<='9'){
													while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
														lex[l]=B[forward];
														l++;
														forward++;
													}
													if(B[forward]>='0' && B[forward]<='9'){
														if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
														else{
														lex[l]=B[forward];
														l++;
														forward++;
														}
													}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no);strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1;return TI; break;}
															else{
													strcpy(TI.Tok_name,"ID");
													strcpy(TI.lex_name,lex);
													TI.line=line_no;
													TI.done=1;
													buf_ptr=forward;
													//lexeme_start=forward;
													forward=buf_ptr+1;
													return TI;
													break;}
												}
												else{
													strcpy(TI.Tok_name,"READ");
													strcpy(TI.lex_name,lex);
													TI.line=line_no;
													TI.done=1;
													buf_ptr=forward;
													//lexeme_start=forward;
													forward=buf_ptr+1;
													return TI;
													break;
												}
											case 'l':
												lex[l]=B[forward];
												l++;
												forward++;
												if(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z' || B[forward]>='0' && B[forward]<='9'){
													while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
														lex[l]=B[forward];
														l++;
														forward++;
													}
													if(B[forward]>='0' && B[forward]<='9'){
														if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
														else{
														lex[l]=B[forward];
														l++;
														forward++;
														}
													}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no);strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1; return TI;break;}
															else{
													strcpy(TI.Tok_name,"ID");
													strcpy(TI.lex_name,lex);
													TI.line=line_no;
													TI.done=1;
													buf_ptr=forward;
													//lexeme_start=forward;
													forward=buf_ptr+1;
													return TI;
													break;}
												}
												else{
													strcpy(TI.Tok_name,"REAL");
													strcpy(TI.lex_name,lex);
													TI.line=line_no;
													TI.done=1;
													buf_ptr=forward;
													//lexeme_start=forward;
													forward=buf_ptr+1;
													return TI;
													break;
												}
											default:
												while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
													lex[l]=B[forward];
													l++;
													forward++;
												}
												if(B[forward]>='0' && B[forward]<='9'){
													if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
													else{
													lex[l]=B[forward];
													l++;
													forward++;
													}
												}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no);strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1;return TI; break;}
															else{
												strcpy(TI.Tok_name,"ID");
												strcpy(TI.lex_name,lex);
												TI.line=line_no;
												TI.done=1;
												buf_ptr=forward;
												//lexeme_start=forward;
												forward=buf_ptr+1;
												return TI;
												break;}
										}
									default:
										while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
											lex[l]=B[forward];
											l++;
											forward++;
										}
										if(B[forward]>='0' && B[forward]<='9'){
											if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
											else{
											lex[l]=B[forward];
											l++;
											forward++;
											}
										}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1;return TI; break;}
															else{
										strcpy(TI.Tok_name,"ID");
										strcpy(TI.lex_name,lex);
										TI.line=line_no;
										TI.done=1;
										buf_ptr=forward;
										//lexeme_start=forward;
										forward=buf_ptr+1;
										return TI;
										break;}
								}
							default:
								while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
									lex[l]=B[forward];
									l++;
									forward++;
								}
								if(B[forward]>='0' && B[forward]<='9'){
									if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
									else{
									lex[l]=B[forward];
									l++;
									forward++;
								}
								}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1;return TI; break;}
															else{
								strcpy(TI.Tok_name,"ID");
								strcpy(TI.lex_name,lex);
								TI.line=line_no;
								TI.done=1;
								buf_ptr=forward;
								//lexeme_start=forward;
								forward=buf_ptr+1;
								return TI;
								break;}
						}
					case 'p':
						lex[l]=B[buf_ptr];
						l++;
						switch(B[forward]){
							case 'r':
									lex[l]=B[forward];
									l++;
									forward++;
									switch(B[forward]){
										case 'i':
											lex[l]=B[forward];
											l++;
											forward++;
											switch(B[forward]){
												case 'n':
													lex[l]=B[forward];
													l++;
													forward++;
													switch(B[forward]){
														case 't':
															lex[l]=B[forward];
				 											l++;
															forward++;
															if(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z' || B[forward]>='0' && B[forward]<='9'){
																while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
																	lex[l]=B[forward];
																	l++;
																	forward++;
																}
																if(B[forward]>='0' && B[forward]<='9'){
																	if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
															else{
																	lex[l]=B[forward];
																	l++;
																	forward++;
																	}
																}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1; return TI;break;}
															else{
																strcpy(TI.Tok_name,"ID");
																strcpy(TI.lex_name,lex);
																TI.line=line_no;
																TI.done=1;
																buf_ptr=forward;
																//lexeme_start=forward;
																forward=buf_ptr+1;
																return TI;
																break;}
															}
															else{
																strcpy(TI.Tok_name,"PRINT");
																strcpy(TI.lex_name,lex);
																TI.line=line_no;
																TI.done=1;
																buf_ptr=forward;
																//lexeme_start=forward;
																forward=buf_ptr+1;
																return TI;
																break;
															}
														default:
															while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
																lex[l]=B[forward];
																l++;
																forward++;
															}
															if(B[forward]>='0' && B[forward]<='9'){
																if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
																else{
																lex[l]=B[forward];
																l++;
																forward++;
																}
															}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1; return TI;break;}
															else{
															strcpy(TI.Tok_name,"ID");
															strcpy(TI.lex_name,lex);
															TI.line=line_no;
															TI.done=1;
															buf_ptr=forward;
															//lexeme_start=forward;
															forward=buf_ptr+1;
															return TI;
															break;}
													}
												default:
													while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
														lex[l]=B[forward];
														l++;
														forward++;
													}
													if(B[forward]>='0' && B[forward]<='9'){
														if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
														else{
														lex[l]=B[forward];
														l++;
														forward++;
														}
													}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1;return TI; break;}
															else{
													strcpy(TI.Tok_name,"ID");
													strcpy(TI.lex_name,lex);
													TI.line=line_no;
													TI.done=1;
													buf_ptr=forward;
													//lexeme_start=forward;
													forward=buf_ptr+1;
													return TI;
													break;}
											}
										default:
											while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
												lex[l]=B[forward];
												l++;
												forward++;
											}
											if(B[forward]>='0' && B[forward]<='9'){
												if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
												else{
												lex[l]=B[forward];
												l++;
												forward++;
												}
											}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1;return TI; break;}
															else{
											strcpy(TI.Tok_name,"ID");
											strcpy(TI.lex_name,lex);
											TI.line=line_no;
											TI.done=1;
											buf_ptr=forward;
											//lexeme_start=forward;
											forward=buf_ptr+1;
											return TI;
											break;}
									}
							default:
								while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
									lex[l]=B[forward];
									l++;
									forward++;
								}
								if(B[forward]>='0' && B[forward]<='9'){
									if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
									else{
									lex[l]=B[forward];
									l++;
									forward++;
									}
								}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1;return TI; break;}
															else{
								strcpy(TI.Tok_name,"ID");
								strcpy(TI.lex_name,lex);
								TI.line=line_no;
								TI.done=1;
								buf_ptr=forward;
								//lexeme_start=forward;
								forward=buf_ptr+1;
								return TI;
								break;}
						}
					case 's':
						lex[l]=B[buf_ptr];
						l++;
						switch(B[forward]){
							case 't':
								lex[l]=B[forward];
								l++;
								forward++;
								
								switch(B[forward]){
									case 'r':
									lex[l]=B[forward];
									l++;
									forward++;
									switch(B[forward]){
										case 'i':
											lex[l]=B[forward];
											l++;
											forward++;
											switch(B[forward]){
												case 'n':
													lex[l]=B[forward];
													l++;
													forward++;
													switch(B[forward]){
														case 'g':
															lex[l]=B[forward];
				 											l++;
															forward++;
															if(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z' || B[forward]>='0' && B[forward]<='9'){
																while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
																	lex[l]=B[forward];
																	l++;
																	forward++;
																}
																if(B[forward]>='0' && B[forward]<='9'){
																	if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
																	else{
																	lex[l]=B[forward];
																	l++;
																	forward++;
																}
																}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1;return TI; break;}
															else{
																strcpy(TI.Tok_name,"ID");
																strcpy(TI.lex_name,lex);
																TI.line=line_no;
																TI.done=1;
																buf_ptr=forward;
																//lexeme_start=forward;
																forward=buf_ptr+1;
																return TI;
																break;}
															}
															else{
																strcpy(TI.Tok_name,"STRING");
																strcpy(TI.lex_name,lex);
																TI.line=line_no;
																TI.done=1;
																buf_ptr=forward;
																//lexeme_start=forward;
																forward=buf_ptr+1;
																return TI;
																break;
															}
														default:
															while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
																lex[l]=B[forward];
																l++;
																forward++;
															}
															if(B[forward]>='0' && B[forward]<='9'){
																if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
																else{
																lex[l]=B[forward];
																l++;
																forward++;
																}
															}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1; return TI;break;}
															else{
															strcpy(TI.Tok_name,"ID");
															strcpy(TI.lex_name,lex);
															TI.line=line_no;
															TI.done=1;
															buf_ptr=forward;
															//lexeme_start=forward;
															forward=buf_ptr+1;
															return TI;
															break;}
													}
												default:
													while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
														lex[l]=B[forward];
														l++;
														forward++;
													}
													if(B[forward]>='0' && B[forward]<='9'){
														if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
														else{
														lex[l]=B[forward];
														l++;
														forward++;
														}
													}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1; return TI;break;}
															else{
													strcpy(TI.Tok_name,"ID");
													strcpy(TI.lex_name,lex);
													TI.line=line_no;
													TI.done=1;
													buf_ptr=forward;
													//lexeme_start=forward;
													forward=buf_ptr+1;
													return TI;
													break;}
											}
										default:
											while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
												lex[l]=B[forward];
												l++;
												forward++;
											}
											if(B[forward]>='0' && B[forward]<='9'){
												if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
												else{
												lex[l]=B[forward];
												l++;
												forward++;
												}
											}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1;return TI; break;}
															else{
											strcpy(TI.Tok_name,"ID");
											strcpy(TI.lex_name,lex);
											TI.line=line_no;
											TI.done=1;
											buf_ptr=forward;
											//lexeme_start=forward;
											forward=buf_ptr+1;
											return TI;
											break;}
									}
							default:
								while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
									lex[l]=B[forward];
									l++;
									forward++;
								}
								if(B[forward]>='0' && B[forward]<='9'){
									if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
									else{
									lex[l]=B[forward];
									l++;
									forward++;
									}
								}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1;return TI; break;}
															else{
								strcpy(TI.Tok_name,"ID");
								strcpy(TI.lex_name,lex);
								TI.line=line_no;
								TI.done=1;
								buf_ptr=forward;
								//lexeme_start=forward;
								forward=buf_ptr+1;
								return TI;
								break;}
								}
							default:
								while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
									lex[l]=B[forward];
									l++;
									forward++;
								}
								if(B[forward]>='0' && B[forward]<='9'){
									if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
									else{
									lex[l]=B[forward];
									l++;
									forward++;
								}
								}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1; return TI;break;}
															else{
								strcpy(TI.Tok_name,"ID");
								strcpy(TI.lex_name,lex);
								TI.line=line_no;
								TI.done=1;
								buf_ptr=forward;
								//lexeme_start=forward;
								forward=buf_ptr+1;
								return TI;
								break;}
						}
					//case 'm':
					case 'm':
						lex[l]=B[buf_ptr];
						l++;
						switch(B[forward]){
							case 'a':
								lex[l]=B[forward];
								l++;
								forward++;
								
								switch(B[forward]){
									case 't':
									lex[l]=B[forward];
									l++;
									forward++;
									switch(B[forward]){
										case 'r':
											lex[l]=B[forward];
											l++;
											forward++;
											switch(B[forward]){
												case 'i':
													lex[l]=B[forward];
													l++;
													forward++;
													switch(B[forward]){
														case 'x':
															lex[l]=B[forward];
				 											l++;
															forward++;
															if(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z' || B[forward]>='0' && B[forward]<='9'){
																while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
																	lex[l]=B[forward];
																	l++;
																	forward++;
																}
																if(B[forward]>='0' && B[forward]<='9'){
																	if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
																else{
																	lex[l]=B[forward];
																	l++;
																	forward++;
																	}
																}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1;return TI; break;}
															else{
																strcpy(TI.Tok_name,"ID");
																strcpy(TI.lex_name,lex);
																TI.line=line_no;
																TI.done=1;
																buf_ptr=forward;
																//lexeme_start=forward;
																forward=buf_ptr+1;
																return TI;
																break;}
															}
															else if(B[forward]==' '){
																strcpy(TI.Tok_name,"MATRIX");
																strcpy(TI.lex_name,lex);
																TI.line=line_no;
																TI.done=1;
																buf_ptr=forward;

																//lexeme_start=forward;
																forward=buf_ptr+1;
																return TI;
																break;
															}
														default:
															while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
																lex[l]=B[forward];
																l++;
																forward++;
															}
															if(B[forward]>='0' && B[forward]<='9'){
																if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
															else{
																lex[l]=B[forward];
																l++;
																forward++;
																}
															}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1;return TI; break;}
															else{
															strcpy(TI.Tok_name,"ID");
															strcpy(TI.lex_name,lex);
															TI.line=line_no;
															TI.done=1;
															buf_ptr=forward;

															//lexeme_start=forward;
															forward=buf_ptr+1;
															return TI;

															break;}
													}
												default:
													while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
														lex[l]=B[forward];
														l++;
														forward++;
													}
													if(B[forward]>='0' && B[forward]<='9'){
														if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
														else{
														lex[l]=B[forward];
														l++;
														forward++;
														}
													}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1; return TI;break;}
															else{
													strcpy(TI.Tok_name,"ID");
													strcpy(TI.lex_name,lex);
													TI.line=line_no;
													TI.done=1;
													buf_ptr=forward;

													//lexeme_start=forward;
													forward=buf_ptr+1;
													return TI;

													break;}
											}
										default:
											while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
												lex[l]=B[forward];
												l++;
												forward++;
											}
											if(B[forward]>='0' && B[forward]<='9'){
												if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
												else{
												lex[l]=B[forward];
												l++;
												forward++;
												}
											}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1;return TI; break;}
															else{
											strcpy(TI.Tok_name,"ID");
											strcpy(TI.lex_name,lex);
											TI.line=line_no;
											TI.done=1;
											buf_ptr=forward;
											//lexeme_start=forward;
											forward=buf_ptr+1;
											return TI;
											break;}
									}
							default:
								while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
									lex[l]=B[forward];
									l++;
									forward++;
								}
								if(B[forward]>='0' && B[forward]<='9'){
									if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
									else{
									lex[l]=B[forward];
									l++;
									forward++;
									}
								}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1; return TI;break;}
															else{
								strcpy(TI.Tok_name,"ID");
								strcpy(TI.lex_name,lex);
								TI.line=line_no;
								TI.done=1;
								buf_ptr=forward;
								//lexeme_start=forward;
								forward=buf_ptr+1;
								return TI;
								break;}
								}
							default:
								while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
									lex[l]=B[forward];
									l++;
									forward++;
								}
								if(B[forward]>='0' && B[forward]<='9'){
									if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
									else{
									lex[l]=B[forward];
									l++;
									forward++;
									}
								}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1; return TI;break;}
															else{
								strcpy(TI.Tok_name,"ID");
								strcpy(TI.lex_name,lex);
								TI.line=line_no;
								TI.done=1;
								buf_ptr=forward;
								//lexeme_start=forward;
								forward=buf_ptr+1;
								return TI;
								break;}
						}
					//case f
					case 'f':
						lex[l]=B[buf_ptr];
						l++;
						switch(B[forward]){
							case 'u':
								lex[l]=B[forward];
								l++;
								forward++;
								
								switch(B[forward]){
									case 'n':
									lex[l]=B[forward];
									l++;
									forward++;
									switch(B[forward]){
										case 'c':
											lex[l]=B[forward];
											l++;
											forward++;
											switch(B[forward]){
												case 't':
													lex[l]=B[forward];
													l++;
													forward++;
													switch(B[forward]){
													case 'i':
													lex[l]=B[forward];
													l++;
													forward++;
													switch(B[forward]){
													case 'o':
													lex[l]=B[forward];
													l++;
													forward++;
													switch(B[forward]){
														case 'n':
															lex[l]=B[forward];
				 											l++;
															forward++;
															if(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z' || B[forward]>='0' && B[forward]<='9'){
																while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
																	lex[l]=B[forward];
																	l++;
																	forward++;
																}
																if(B[forward]>='0' && B[forward]<='9'){
																	if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
																else{
																	lex[l]=B[forward];
																	l++;
																	forward++;
																	}
																}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1;return TI; break;}
															else{
																strcpy(TI.Tok_name,"ID");
																strcpy(TI.lex_name,lex);
																TI.line=line_no;
																TI.done=1;
																buf_ptr=forward;
																//lexeme_start=forward;
																forward=buf_ptr+1;
																return TI;
																break;}
															}
															else if(B[forward]==' '){
																strcpy(TI.Tok_name,"FUNCTION");
																strcpy(TI.lex_name,lex);
																TI.line=line_no;
																TI.done=1;
																buf_ptr=forward;

																//lexeme_start=forward;
																forward=buf_ptr+1;
																return TI;
																break;
															}
														default:
															while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
																lex[l]=B[forward];
																l++;
																forward++;
															}
															if(B[forward]>='0' && B[forward]<='9'){
																if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
															else{
																lex[l]=B[forward];
																l++;
																forward++;
																}
															}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1;return TI; break;}
															else{
															strcpy(TI.Tok_name,"ID");
															strcpy(TI.lex_name,lex);
															TI.line=line_no;
															TI.done=1;
															buf_ptr=forward;

															//lexeme_start=forward;
															forward=buf_ptr+1;
															return TI;

															break;}
													}
												default:
													while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
														lex[l]=B[forward];
														l++;
														forward++;
													}
													if(B[forward]>='0' && B[forward]<='9'){
														if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
														else{
														lex[l]=B[forward];
														l++;
														forward++;
														}
													}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1; return TI;break;}
															else{
													strcpy(TI.Tok_name,"ID");
													strcpy(TI.lex_name,lex);
													TI.line=line_no;
													TI.done=1;
													buf_ptr=forward;

													//lexeme_start=forward;
													forward=buf_ptr+1;
													return TI;

													break;}
											}
										default:
											while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
												lex[l]=B[forward];
												l++;
												forward++;
											}
											if(B[forward]>='0' && B[forward]<='9'){
												if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
												else{
												lex[l]=B[forward];
												l++;
												forward++;
												}
											}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1;return TI; break;}
															else{
											strcpy(TI.Tok_name,"ID");
											strcpy(TI.lex_name,lex);
											TI.line=line_no;
											TI.done=1;
											buf_ptr=forward;
											//lexeme_start=forward;
											forward=buf_ptr+1;
											return TI;
											break;}
									}
							default:
											while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
												lex[l]=B[forward];
												l++;
												forward++;
											}
											if(B[forward]>='0' && B[forward]<='9'){
												if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
												else{
												lex[l]=B[forward];
												l++;
												forward++;
												}
											}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1;return TI; break;}
															else{
											strcpy(TI.Tok_name,"ID");
											strcpy(TI.lex_name,lex);
											TI.line=line_no;
											TI.done=1;
											buf_ptr=forward;
											//lexeme_start=forward;
											forward=buf_ptr+1;
											return TI;
											break;}
									}
									default:
											while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
												lex[l]=B[forward];
												l++;
												forward++;
											}
											if(B[forward]>='0' && B[forward]<='9'){
												if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
												else{
												lex[l]=B[forward];
												l++;
												forward++;
												}
											}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1;return TI; break;}
															else{
											strcpy(TI.Tok_name,"ID");
											strcpy(TI.lex_name,lex);
											TI.line=line_no;
											TI.done=1;
											buf_ptr=forward;
											//lexeme_start=forward;
											forward=buf_ptr+1;
											return TI;
											break;}
									}
							default:
								while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
									lex[l]=B[forward];
									l++;
									forward++;
								}
								if(B[forward]>='0' && B[forward]<='9'){
									if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
									else{
									lex[l]=B[forward];
									l++;
									forward++;
									}
								}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1; return TI;break;}
															else{
								strcpy(TI.Tok_name,"ID");
								strcpy(TI.lex_name,lex);
								TI.line=line_no;
								TI.done=1;
								buf_ptr=forward;
								//lexeme_start=forward;
								forward=buf_ptr+1;
								return TI;
								break;}
								}
							default:
								while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
									lex[l]=B[forward];
									l++;
									forward++;
								}
								if(B[forward]>='0' && B[forward]<='9'){
									if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
									else{
									lex[l]=B[forward];
									l++;
									forward++;
									}
								}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1; return TI;break;}
															else{
								strcpy(TI.Tok_name,"ID");
								strcpy(TI.lex_name,lex);
								TI.line=line_no;
								TI.done=1;
								buf_ptr=forward;
								//lexeme_start=forward;
								forward=buf_ptr+1;
								return TI;
								break;}
						}
					default:
						lex[l]=B[buf_ptr];
						l++;
						while(B[forward]>='a' && B[forward]<='z' || B[forward]>='A' && B[forward]<='Z'){
							lex[l]=B[forward];
							l++;
							forward++;
						}
						if(B[forward]>='0' && B[forward]<='9'){
							if( B[forward+1]>='0' && B[forward+1]<='9'){				///////
																	lex[l]=B[forward];l++;lex[l]=B[forward+1];
																	printf("ERROR:  Unknown pattern %s",lex);
																	strcpy(TI.Tok_name,"ERROR");
																	strcpy(TI.lex_name,lex);
																	TI.done=1;
																	buf_ptr=forward+2;
																	forward=buf_ptr+1;
																	return TI;
																	break;
																}
							else{
							lex[l]=B[forward];
							l++;
							forward++;
							}
						}
								if(l>20){printf("ERROR : Identifier at line %d is longer than the prescribed length of 20 characters",line_no); strcpy(TI.Tok_name,"ERROR");strcpy(TI.lex_name,lex);TI.done=1; buf_ptr=forward; forward=buf_ptr+1;return TI; break;}
															else{
						strcpy(TI.Tok_name,"ID");
						strcpy(TI.lex_name,lex);
						TI.line=line_no;
						TI.done=1;
						buf_ptr=forward;
						//lexeme_start=forward;
						forward=buf_ptr+1;
						return TI;
						break;}
				}
			}
			
			if(B[buf_ptr]>='0' && B[buf_ptr]<='9'){
				lex[l]=B[buf_ptr];
				l++;
				while(B[forward]>='0' && B[forward]<='9'){
					lex[l]=B[forward];
					l++;
					forward++;
				}
				switch(B[forward]){
					case '.':
						if(B[forward+1]>='0' && B[forward+1]<='9' && B[forward+2]>='0' && B[forward+2]<='9'){
							lex[l]=B[forward];
							lex[l+1]=B[forward+1];
							lex[l+2]=B[forward+2];
							strcpy(TI.Tok_name,"RNUM");
							strcpy(TI.lex_name,lex);
							TI.attribute_float=atof(lex);
							TI.line=line_no;
							TI.done=1;
							buf_ptr=forward+3;
							forward=buf_ptr+1;
							return TI;
							break;
						}
						else{
							strcpy(TI.Tok_name,"NUM");
							strcpy(TI.lex_name,lex);
							TI.line=line_no;
							TI.attribute_int=atoi(lex);
							TI.done=1;
							buf_ptr=forward;
							//lexeme_start=forward;
							forward=buf_ptr+1;
							return TI;
							break;
						}
					default:
						strcpy(TI.Tok_name,"NUM");
						strcpy(TI.lex_name,lex);
						TI.line=line_no;
						TI.attribute_int=atoi(lex);
						TI.done=1;
						buf_ptr=forward;
						//lexeme_start=forward;
						forward=buf_ptr+1;
						return TI;
						break;
				}
			}
		
			if(B[buf_ptr]=='"'){
				lex[l]=B[buf_ptr];
				l++;
				if(B[forward]>='a' && B[forward]<='z' || B[forward]==' '){
					while(B[forward]>='a' && B[forward]<='z' || B[forward]==' '){
						lex[l]=B[forward];
						l++;
						forward++;
					}
					if(B[forward]=='"'){
						lex[l]=B[forward];
						forward++;
						strcpy(TI.Tok_name,"STR");
						strcpy(TI.lex_name,lex);
						TI.line=line_no;
						TI.done=1;
						buf_ptr=forward;
						forward=buf_ptr+1;
						return TI;
						break;
					}
					else{
						printf("ERROR:  Unknown pattern %s\n",lex);
						strcpy(TI.Tok_name,"ERROR");
						strcpy(TI.lex_name,lex);
						TI.line=line_no;
						TI.done=1;
						buf_ptr=forward;
						forward=buf_ptr+1;
						return TI;
						break;
					}
				}
				else{
					printf("ERROR: Unknown Symbol %s at line %d\n",lex,line_no);
					strcpy(TI.Tok_name,"ERROR");
					strcpy(TI.lex_name,lex);
					TI.line=line_no;
					TI.done=1;
					buf_ptr=forward;
					forward=buf_ptr+1;
					return TI;
					break;
				}
			}
		
			if(B[buf_ptr]==';'){
				//printf("\nabc8\n");
				lex[l]=B[buf_ptr];
				strcpy(TI.Tok_name,"SEMICOLON");
				strcpy(TI.lex_name,lex);
				TI.line=line_no;
				TI.done=1;
				buf_ptr=forward;
				forward=buf_ptr+1;
				//printf("\nabc9\n");
				return TI;
				break;	
			}
			if(B[buf_ptr]=='$'){
			lex[l]=B[buf_ptr];
			strcpy(TI.Tok_name,lex);
			strcpy(TI.lex_name,lex);
			TI.line=line_no;
			TI.done=1;
			return TI;
			}
			else{
				printf("ERROR: Unknown Symbol %c at line %d\n",B[buf_ptr],line_no);
				lex[l]=B[buf_ptr];
				strcpy(TI.Tok_name,"ERROR");
				strcpy(TI.lex_name,lex);
				TI.done=1;
				buf_ptr=forward;
				forward=buf_ptr+1;
				return TI;
				break;
			}
			
		}//end while2
		if(TI.done==0){
			int i;
			//printf("%c %c\n",B[buf_ptr+1],B[buf_ptr]);
			for(i=0;i<k-buf_ptr;i++){
				B[i]=B[buf_ptr+i];
				//printf("[]%c\n",B[i]);
			}
			buf_ptr=k-buf_ptr;
			fp=getStream(fp,B,k);
			buf_ptr=0;
			forward=1;	
		}
		
	//} 
/*	if(B[buf_ptr]=='$'){
		lex[l]=B[buf_ptr];
		strcpy(TI.Tok_name,"FINISH");
		strcpy(TI.lex_name,lex);
		TI.done=1;
		return TI;
	}*/
	//return TI;

}


