HEADERS=Util.h	Vector.h	String.h	LinkedList.h

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

test.o:
	gcc	-c	test.c	-o	$@

test: test.o
	gcc	test.o	-o	test

sha256.o:	sha256.c	sha256.h
	gcc	-c	sha256.c	-o	$@	-w

sha256_test.o:	sha256_test.c	sha256.h
	gcc	-c	sha256_test.c 	-o	$@	-w

sha256_test:	sha256_test.o	sha256.o
	gcc	sha256_test.o	sha256.o	-o	sha256_test



clean:
	-rm -f *.o
	-rm -f compile
	-rm -f string
	-rm -f test
	-rm -f sha256_test
