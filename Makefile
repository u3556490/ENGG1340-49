CC=g++
CFLAGS1=-pedantic-errors -std=c++11 -g
CFLAGS2=-I.

addentry.o : addentry.cpp
	$(CC) $(CFLAGS1) -c $^ $(CFLAGS2)

rmentry.o : rmentry.cpp
	$(CC) $(CFLAGS1) -c $^ $(CFLAGS2)

search.o : search.cpp
	$(CC) $(CFLAGS1) -c $^ $(CFLAGS2)

sort.o : sort.cpp
	$(CC) $(CFLAGS1) -c $^ $(CFLAGS2)

filter.o : filter.cpp
	$(CC) $(CFLAGS1) -c $^ $(CFLAGS2)

imexport.o : imexport.cpp
	$(CC) $(CFLAGS1) -c $^ $(CFLAGS2)

stockalert.o : stockalert.cpp	
	$(CC) $(CFLAGS1) -c $^ $(CFLAGS2)

main.o : main.cpp
	$(CC) $(CFLAGS1) -c $^ $(CFLAGS2)

project : main.o addentry.o rmentry.o search.o sort.o filter.o
	$(CC) $(CFLAGS1) -o $@ $^ $(CFLAGS2)

.PHONY: clean
clean:
	rm -rf *.o *.gch *.exe
