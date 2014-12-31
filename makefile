mycompiler:driver.o	typechecker.o createAbstractSyntaxTree.o	astOps.o	parser.o otherops.o lexer.o
	gcc -o mycompiler driver.o	typechecker.o createAbstractSyntaxTree.o	astOps.o	parser.o otherops.o lexer.o

driver.o: driver.c
	gcc -c driver.c

typechecker.o: typechecker.c
	gcc -c typechecker.c

createAbstractSyntaxTree.o: createAbstractSyntaxTree.c
	gcc -c createAbstractSyntaxTree.c

astOps.o: astOps.c
	gcc -c astOps.c

parser.o: parser.c
	gcc -c parser.c

otherops.o: otherops.c
	gcc -c otherops.c


lexer.o: lexer.c
	gcc -c -W lexer.c
clean:
	rm -rf *o mycompiler
