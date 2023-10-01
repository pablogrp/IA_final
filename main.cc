#include "arbol.h"
#include "grafo.h"
#include "nodo.h"
#include "utilidad.cc"

int main(int argc, char* argv[]) {
  Usage(argc, argv);

  std::string nodo_inicio_string = argv[1];
  std::string nodo_final_string = argv[2];
  int total_nodos{0};

  int nodo_inicio = stoi(nodo_inicio_string);
  int nodo_final = stoi(nodo_final_string);

  std::ifstream archivo_entrada(argv[3]);  // Abrimos el fichero de entrada
  archivo_entrada >> total_nodos;  // Almacenamos el numero total de nodos

  Grafo graph;
  Nodo* nodoFinal;
  Nodo* nodoInicial;
  double coste_final{0};

  graph.vectorResize(total_nodos + 1);

  for (int i = 1; i <= total_nodos; i++) {
    for (int j = i + 1; j < total_nodos + 1; j++) {
      double coste;
      archivo_entrada >> coste;
      coste_final+= coste;
      if (coste != -1.00) {
        if (graph.nodosGrafo_[i] == NULL) graph.nodosGrafo_[i] = new Nodo(i);
        if (graph.nodosGrafo_[j] == NULL) graph.nodosGrafo_[j] = new Nodo(j);
        graph.nodosGrafo_[j]->add_hijo(graph.nodosGrafo_[i]);
        graph.nodosGrafo_[i]->add_hijo(graph.nodosGrafo_[j]);
      }
    }
  }

  nodoInicial = graph.nodosGrafo_.at(nodo_inicio);
  // std::cout << nodoInicial->get_identificador()+1;

  nodoFinal = graph.nodosGrafo_.at(nodo_final);
  // std::cout << nodoFinal->get_identificador()+1;
  std::string opcion_string = argv[4];
  int opcion = stoi(opcion_string);

  Arbol arbol;

  switch (opcion) {
    case 1:
      std::cout << "Este es el BFS: " << std::endl;
      arbol = Arbol(graph.bfs(nodoInicial, nodoFinal, total_nodos, coste_final));
      break;
    case 2:
      std::cout << "Este es el DFS: " << std::endl;
      arbol = Arbol(graph.dfs(nodoInicial, nodoFinal, total_nodos, coste_final));
      break;
    case 0:
      std::cout << "Saliendo del programa" << std::endl;
      return 0;
      break;
    default:
      std::cout << "Opción incorrecta" << std::endl;
      break;
  }
  return 0;
}
