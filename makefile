HEADERS=Util.h	Vector.h	String.h	LinkedList.h	class.h	HashMap.h

default:	compile

compile.o:	Main.c	$(HEADERS)
	gcc -c	Main.c	-o	$@


string.o:	String.c	String.h
	gcc -c	String.c	-o	$@	-w


compile:	compile.o
	gcc compile.o	-o	out/compile

compile_clean:
	make clean && make compile

verbose:	compile.o
	gcc compile.o	-o	out/compile	-w

string:	string.o
	gcc string.o	-o	out/string_test

hashmap.o:	HashMap.c	HashMap.h
	gcc	-c	HashMap.c	-o	$@	-w

hashmap:	hashmap.o
	gcc	hashmap.o	-o	out/hashmap

test.o:
	gcc	-c	test.c	-o	$@

test: test.o
	gcc	test.o	-o	out/test

sha256.o:	sha256.c	sha256.h
	gcc	-c	sha256.c	-o	$@	-w

sha256_test.o:	sha256_test.c	sha256.c	sha256.h
	gcc	-c	sha256_test.c 	-o	$@	-w

sha256_test:	sha256_test.o
	gcc	sha256_test.o	-o	out/sha256_test



clean:
	-rm -f *.o
	-rm -f compile
	-rm -f string
	-rm -f test
	-rm -f sha256_test
	-rm -f hashmap
	-rm -rf out/*
