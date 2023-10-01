#pragma once

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#include "arbol.h"
#include "nodo.h"

class Grafo {
 public:
  Grafo(){};

  void set_nodoInicio(Nodo*);
  void set_nodoFin(Nodo*);

  std::vector<Nodo*> bfs(Nodo* inicial, Nodo* final, int, double);
  std::vector<Nodo*> dfs (Nodo* iniicial, Nodo* final, int,double);
  Nodo* get_nodo(int);

  void vectorResize(int);
  std::vector<Nodo*> nodosGrafo_;

  bool EsPadre(Nodo*, Nodo*);
  Nodo* CrearNodo(Nodo*);

 private:
  Nodo* nodo_inicial_;
  Nodo* nodo_final_;
};

