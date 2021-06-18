CC = g++
FLAGS = -g -Wall

a.out: main.o Hash.o HashTable.o
	$(CC) $(FLAGS) $^ -o $@
main.o: main.cpp
	$(CC) $(FLAGS) -c $<
Hash.o: Hash.cpp
	$(CC) $(FLAGS) -c $<
HashTable.o: HashTable.cpp
	$(CC) $(FLAGS) -c $<
clean:
	rm *.o a.out
