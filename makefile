HEADERS=Util.h	Vector.h

default:	compile

compile.o:	Main.c	$(HEADERS)
	gcc -c	Main.c	-o	$@





compile:	compile.o
	gcc compile.o	-o	compile




clean:
	-rm -f compile.o
	-rm -f compile
