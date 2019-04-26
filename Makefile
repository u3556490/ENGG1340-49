CC=g++
CFLAGS1=-pedantic-errors -std=c++11 -g
CFLAGS2=-I.

inpututil.o : inpututil.cpp
	$(CC) $(CFLAGS1) -c $^ $(CFLAGS2)

addentry.o : addentry.cpp main.h
	$(CC) $(CFLAGS1) -c $^ $(CFLAGS2)

rmentry.o : rmentry.cpp main.h
	$(CC) $(CFLAGS1) -c $^ $(CFLAGS2)

search.o : search.cpp main.h inpututil.h
	$(CC) $(CFLAGS1) -c $^ $(CFLAGS2)

sort.o : sort.cpp main.h inpututil.h
	$(CC) $(CFLAGS1) -c $^ $(CFLAGS2)

filter.o : filter.cpp main.h search.h
	$(CC) $(CFLAGS1) -c $^ $(CFLAGS2)

imexport.o : imexport.cpp main.h
	$(CC) $(CFLAGS1) -c $^ $(CFLAGS2)

stockalert.o : stockalert.cpp main.h search.h
	$(CC) $(CFLAGS1) -c $^ $(CFLAGS2)

update.o : update.cpp main.h
	$(CC) $(CFLAGS1) -c $^ $(CFLAGS2)

printinv.o : printinv.cpp main.h
	$(CC) $(CFLAGS1) -c $^ $(CFLAGS2)

main.o : main.cpp main.h
	$(CC) $(CFLAGS1) -c $^ $(CFLAGS2)

project : main.o addentry.o rmentry.o search.o sort.o filter.o imexport.o stockalert.o update.o printinv.o inpututil.o
	$(CC) $(CFLAGS1) -o $@ $^ $(CFLAGS2)

.PHONY: clean
clean:
	rm -rf *.o *.gch *.exe *.stackdump
