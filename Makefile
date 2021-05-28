CC = g++
CFLAGS = -Wall -g

main: main.o color.o
	$(CC) $(CFLAGS) -o ch_red main.o color.o

main.o: main.cpp color.h
	$(CC) $(CFLAGS) -c main.cpp

color.o: color.h

clean:
	rm ch_red color.o main.o
