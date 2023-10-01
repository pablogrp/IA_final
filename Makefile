p01_strings.out: arbol.o  main.o grafo.o nodo.o 
	g++ -g -o p01_strings.out arbol.o  main.o grafo.o nodo.o 

arbol.o: arbol.cc
	g++ -g -c arbol.cc

grafo.o: grafo.cc
	g++ -g -c grafo.cc

nodo.o: nodo.cc
	g++ -g -c nodo.cc

main.o: main.cc
	g++ -g -c main.cc

clean:
	rm -rf *.o *.out