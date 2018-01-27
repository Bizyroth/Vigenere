CC=gcc
CFLAGS= -Wall -W

all: vigenere clean

vigenere: files.o Cesar.o Indice.o Vigenere.o main.o
	$(CC) -o $@ $^
		
main.o: files.h Vigenere.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)
		
clean: 
	rm -rf *.o *~
