.PHONY : build clean all

build: 
	bison -d analyser.y
	lex scanner.l
	gcc lex.yy.c analyser.tab.c grammar.c analyser.tab.h grammar.h -o Calculator
	./Calculator <config.in

clean:
	rm -f -d analyser.tab.*
	rm -f -d lex.yy.c
	rm -f -d Calculator

all: clean build