g++ -g -c src/ListADT.cpp -o obj/ListADT.o
g++ -g -c src/ListApplication.cpp -o obj/ListApplication.o
g++ obj/ListADT.o obj/ListApplication.o -o bin/solution