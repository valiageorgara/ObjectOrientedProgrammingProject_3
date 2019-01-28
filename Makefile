make:
	g++ -o exe main.cpp header.h 
clean:
	rm -rf *.o
	rm -rf exe
