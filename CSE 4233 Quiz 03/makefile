all: newDatabase quiz3

quiz3: quiz3.o
	g++ quiz3.cpp -o quiz3.o -lsqlite3

newDatabase: buildDB.o
	g++ buildDB.cpp -o buildDB.o -lsqlite3
	./buildDB.o

clean:
	\rm *.o *.db
