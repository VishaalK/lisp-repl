CFLAGS = -std=c99 -Wall -Werror -pedantic

default:
	clang $(CFLAGS) prompt.c -ledit -o prompt 

#-o prompt.o

clean:
	rm -f *.out
	rm -f *.exe
	rm -f *.o
