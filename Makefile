CC=g++
CFLAGS1=-pedantic-errors -std=c++11 -g
CFLAGS2=-I.

main.o : main.cpp
	$(CC) $(CFLAGS1) -c $^ $(CFLAGS2)

project : main.o
	$(CC) $(CFLAGS1) -o $@ $^ $(CFLAGS2)

.PHONY: clean
clean:
	rm -rf *.o
