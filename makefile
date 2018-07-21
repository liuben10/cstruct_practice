HEADERS=Util.h	Vector.h String.h

default:	compile

compile.o:	Main.c	$(HEADERS)
	gcc -c	Main.c	-o	$@


string.o:	String.c	String.h
	gcc -c	String.c	-o	$@	-w


compile:	compile.o
	gcc compile.o	-o	compile

compile_clean:
	make clean && make compile

verbose:	compile.o
	gcc compile.o	-o	compile	-w

string:	string.o
	gcc string.o	-o	string_test




clean:
	-rm -f *.o
	-rm -f compile
	-rm -f string
