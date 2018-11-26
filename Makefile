essai_fap: essai_fap.o fap.o
	gcc -o $@ $^

%.o: %.c fap.h
	gcc -c $<


