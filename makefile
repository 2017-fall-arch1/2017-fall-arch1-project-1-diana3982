all: runBst

CFLAGS=-g -03

runBst: bst.o runBst.o
	cc -o $@ $^

bst.o: bst.c bst.h
	cc -c $(CFLAGS) bst.c

runBst.o: runBst.c bst.h
	cc -c $(CFLAGS) runBst.c

clean: rm -f *.o runBst

demo: runBst(./runBst)
