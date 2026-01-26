CFLAGS = -Wno-implicit-function-declaration

all: final.o

final.o: main.o card.o game.o
	echo "linking the three"
	gcc $(CFLAGS) main.o card.o game.o -o final.o
	
main.o: Main.c
	echo "Compiling the main file"
	gcc $(CFLAGS) -c Main.cpp

game.o: Game.cpp
	echo "Compiling the Game file"
	gcc $(CFLAGS) -c Game.cpp

card.o: Card.cpp
	echo "Compiling the card file"
	gcc $(CFLAGS) -c Card.cpp

clean: 
	echo "removing all but source file"
	rm main.o card.o game.o final.o