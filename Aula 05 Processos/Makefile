# Definição de variáveis
DFLAGS = $(patsubst %, -D%, OPTION1 OPTION2 OPTION3)

# -Ox --> Flags de otimização
CFLAGS = -O2 $(DFLAGS) -g

# -lm --> Linker para math.h  //  -lpthread --> Linker para pthread.h
LDFLAGS = -lm -lpthread

ALL = main

# $^ --> Todas as dependências
# $@ --> Nome do método

all: $(ALL)

main: *.c
	gcc $(CFLAGS) $^ $(LDFLAGS) -o $@

run:
	./main

%.s: %.c
	gcc -S $<

clean:
	rm -f *.o *.s a.out $(ALL)

distclean: clean
	rm -r $(ALL)