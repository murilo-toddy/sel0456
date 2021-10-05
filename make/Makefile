DEFFLAGS = $(patsubst %, -D%, OPTION1 OPTION2 OPTION3)

CFLAGS = -O2 -g $(DEFFLAGS) -Wall
LDFLAGS = -lm -lpthread
GCC = gcc

ALL = main

all: $(ALL)

main: main.o sqr.o mult_acc.o
	$(GCC) -o $@  $^ $(LDFLAGS) 

%.s: %.c
	$(GCC) $(CFLAGS) -S $<

clean:
	rm -f *.o *.s a.out

distclean: clean
	rm -r $(ALL)

