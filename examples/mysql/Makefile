LIBS=-lcppdb -lcppdb_mysql


all: example1

example1: example1.cpp
	$(CXX) -O2 -Wall -g example1.cpp -o example1 ${LIBS}
	@rm -rf example1.dSYM

clean:
	rm -fr example1 example1.exe example1.dSYM
