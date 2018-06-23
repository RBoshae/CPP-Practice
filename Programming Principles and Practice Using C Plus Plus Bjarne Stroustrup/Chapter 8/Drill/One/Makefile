output: use.o my.o
		g++ use.o my.o -o output

main.o: use.cpp
		g++ -c use.cpp

my.o: my.cpp my.h
		g++ -c my.cpp

clean:
		rm *.o output
