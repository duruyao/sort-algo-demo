./bin/run: ./obj/test.o ./obj/sort_algo.o
	gcc ./obj/test.o ./obj/sort_algo.o -o ./bin/run -lm
	cp ./bin/run run

./obj/test.o: ./src/test.c
	gcc -c ./src/test.c -o ./obj/test.o -g

./obj/sort_algo.o: ./src/sort_algo.c
	gcc -c ./src/sort_algo.c -o ./obj/sort_algo.o -g

clear: 
	rm ./obj/*.o

