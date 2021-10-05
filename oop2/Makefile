ALL = main

all: $(ALL)

main: main.cpp Range.cpp range.o
	g++ -o $@ $^

range.o: range.c
	gcc -c $<

clean:
	rm -f *.o *~

