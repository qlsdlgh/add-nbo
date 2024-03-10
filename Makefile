all: add-nbo

add-nbo: main.o add-nbo.o
	g++ -o add-nbo main.o add-nbo.o

main.o: add-nbo.h main.cpp
	g++ -c -o main.o main.cpp

add-nbo.o: add-nbo.h add-nbo.cpp
	g++ -c -o add-nbo.o add-nbo.cpp

clean:
	rm -f add-nbo
	rm -f *.o