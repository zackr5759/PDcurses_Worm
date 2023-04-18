
game.x:  main.o getChar.o freePool.o screen.o worm.o
	g++ -ggdb -o game.x main.o getChar.o freePool.o screen.o worm.o -lcurses -ltermcap

main.o: main.cpp
	g++ -c -ggdb main.cpp -o main.o

getChar.o: getChar.cpp 
	gcc -c -ggdb getChar.cpp -o getChar.o
	
freePool.o: freePool.cpp 
	gcc -c -ggdb freePool.cpp -o freePool.o
	
screen.o: screen.cpp 
	gcc -c -ggdb screen.cpp -o screen.o

worm.o: worm.cpp 
	gcc -c -ggdb worm.cpp -o worm.o
	
	

clean:
	/bin/rm -f game.x main.o getChar.o freePool.o screen.o worm.o *~
