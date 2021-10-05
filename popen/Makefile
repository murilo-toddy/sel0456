DEFFLAGS = $(patsubst %, -D%, OPTION1 OPTION2 OPTION3)

CFLAGS = -O2 -g $(DEFFLAGS)
LDFLAGS = -lm -lpthread
GCC = gcc

ALL = popen gnuplot popen-read stdout

all: $(ALL)

%: %.o
	$(GCC) -o $@  $^ $(LDFLAGS) 

%.s: %.c
	$(GCC) $(CFLAGS) -S $<

clean:
	rm -f *.o *.s a.out

distclean: clean
	rm -r $(ALL)

