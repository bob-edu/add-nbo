add-nbo: add-nbo.o
	g++ -o add-nbo add-nbo.o

add-nbo.o: main.cpp
	g++ -c -o add-nbo.o main.cpp

clean:
	rm -f *.o
	rm -f add-nbo