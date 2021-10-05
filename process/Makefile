DEFFLAGS = $(patsubst %, -D%, OPTION1 OPTION2 OPTION3)

CFLAGS = -O2 -g $(DEFFLAGS)
LDFLAGS = -lm -lpthread
GCC = gcc

ALL = main proc2

all: $(ALL)

main: proc.o
	$(GCC) -o $@  $^ $(LDFLAGS) 

proc2: proc2.o
	$(GCC) -o $@  $^ $(LDFLAGS) 

%.s: %.c
	$(GCC) $(CFLAGS) -S $<

clean:
	rm -f *.o *.s a.out

distclean: clean
	rm -r $(ALL)

