CFLAGS = -Wno-implicit-function-declaration

all: final

final: main.o card.o
	echo "linking the two"
	gcc $(CFLAGS) main.o card.o -o final

main.o: Main.c
	echo "Compiling the main file"
	gcc $(CFLAGS) -c Main.c

card.o: Card.c
	echo "Compiling the card file"
	gcc $(CFLAGS) -c Card.c

clean: 
	echo "removing all but source file"
	rm main.o card.o final.o