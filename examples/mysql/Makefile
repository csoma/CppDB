LIBS=-lcppcms -lbooster -lcppdb -lcppdb_sqlite3


all: example1

example1: example1.cpp
	$(CXX) -O2 -Wall -g example1.cpp -o example1 ${LIBS}

clean:
	rm -fr example1 example1.exe example1.dSYM
