#include "grafo.h"

// Setter nodo inicio del grafo
void Grafo::set_nodoInicio(Nodo* nodo_inicio) { nodo_inicial_ = nodo_inicio; }

// Setter nodo final del grafo
void Grafo::set_nodoFin(Nodo* nodo_fin) { nodo_final_ = nodo_fin; }

// Resize vector nodos
void Grafo::vectorResize(int valor) { nodosGrafo_.resize(valor); }

Nodo* Grafo::get_nodo(int pos) { return nodosGrafo_.at(pos); }

bool Grafo::EsPadre(Nodo* primero, Nodo* segundo) {
  if (primero->get_padre() == nullptr) {
    return false;
  } else if (primero == segundo) {
    return true;
  } else {
    return false;
  }
}

Nodo* Grafo::CrearNodo(Nodo* segundo) {
  Nodo* nuevo = new Nodo;
  nuevo->set_padre(segundo);
  nuevo->set_identificador(segundo->get_identificador());
  return nuevo;
}

std::vector<Nodo*> Grafo::bfs(Nodo* inicial, Nodo* final, int total_nodos,
                              double coste_final) {
  int aristas = 0;  // Fórmula número máximo de aristas
  std::vector<int> visitados;
  std::vector<Nodo*> generados;
  std::vector<int> camino;

  // Mantener un mapa de padres para reconstruir el camino
  std::map<int, Nodo*> padres;

  inicial->set_padre(nullptr);

  std::queue<Nodo*> cola;
  cola.push(inicial);

  while (!cola.empty()) {
    int padre_actual = inicial->get_identificador();
    Nodo* actual = cola.front();
    cola.pop();

    if (actual->get_identificador() == final->get_identificador()) {
      std::cout << "Número de nodos = " << total_nodos << std::endl;
      std::cout << "Nodo inicial -> " << inicial->get_identificador()
                << std::endl;
      std::cout << "Nodo final -> " << final->get_identificador() << std::endl;
      std::cout << "Coste -> " << coste_final << std::endl;

      Nodo* nodo_actual = final;
      while (nodo_actual != nullptr) {
        camino.push_back(nodo_actual->get_identificador());
        nodo_actual = padres[nodo_actual->get_identificador()];
      }
      std::reverse(camino.begin(), camino.end());

      std::cout << "Generados: ";
      for (auto i : generados) {
        std::cout << i->get_identificador() << ", ";
      }
      std::cout << "Visitados: ";
      for (auto i : visitados) {
        std::cout << i << ", ";
        aristas++;
      }
      std::cout << std::endl;
      std::cout << "Camino: ";
      for (auto i : camino) {
        std::cout << i << " <- ";
      }
      std::cout << std::endl;
      std::cout << "Número aristas totales -> " << aristas << std::endl;
      std::cout << std::endl;
      return generados;
    }
    visitados.push_back(actual->get_identificador());

    for (auto i : actual->get_hijos()) {
      if (i->get_identificador() != padre_actual) {
        generados.push_back(i);
        int padre_actual = actual->get_identificador();
        bool encontrado = false;

        for (int j = 0; j < visitados.size(); ++j) {
          if (visitados[j] == i->get_identificador()) {
            encontrado = true;
            break;
          }
        }

        if (encontrado == false) {
          cola.push(i);
          // Registrar el padre de este nodo
          padres[i->get_identificador()] = actual;
        }
      }
    }
    std::queue<Nodo*> copia = cola;
    while (!copia.empty()) {
      copia.pop();
    }
  }
}

std::vector<Nodo*> Grafo::dfs(Nodo* inicial, Nodo* final, int nodos_totales,
                              double coste_final) {
  int numero_aristas = 0;  // Fórmula número máximo de aristas
  std::vector<int> visitados;
  std::vector<Nodo*> generados;
  std::vector<int> camino;

  inicial->set_padre(nullptr);

  std::stack<Nodo*> pila;
  pila.push(inicial);

  while (!pila.empty()) {
    Nodo* actual = pila.top();
    pila.pop();

    visitados.push_back(actual->get_identificador());

    if (actual->get_identificador() == final->get_identificador()) {
      std::cout << "Nodos totales: " << nodos_totales << std::endl;
      std::cout << "Nodo inicial -> " << inicial->get_identificador()
                << std::endl;
      std::cout << "Nodo final -> " << final->get_identificador() << std::endl;
      std::cout << "Coste -> " << coste_final << std::endl;

      std::cout << "Generados: ";
      for (auto i : generados) {
        std::cout << i->get_identificador() << ", ";
        numero_aristas++;
      }

      std::cout << "Vistiados: ";
      for (auto i : visitados) {
        std::cout << i << ", ";
      }

      std::cout << "Camino: ";
      for (auto i : camino) {
        std::cout << i << "<- ";
      }
      std::cout << std::endl;
      std::cout << "Total de aristas <- " << numero_aristas << std::endl;
      return generados;
    }

    bool encontrado = false;
    for (auto i : actual->get_hijos()) {
      if (!EsPadre(i, actual) &&
          std::find(visitados.begin(), visitados.end(),
                    i->get_identificador()) == visitados.end()) {
        generados.push_back(i);
        pila.push(i);
        encontrado = true;
        break;
      }
    }

    if (!encontrado) {
      camino.pop_back();
    }
    camino.push_back(actual->get_identificador());
  }

  // Si llegamos aquí y no encontramos el nodo final, significa que no hay
  // camino.
  return std::vector<Nodo*>();
}
