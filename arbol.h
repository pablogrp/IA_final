#include <iostream>
#include <vector>
#include "nodo.h"

#pragma once

class Arbol {
 public:
  Arbol() {} 
  Arbol(std::vector<Nodo*> nodos){}
  // Getters
  friend std::ostream& operator<< (std::ostream& os, const Arbol& arbol);
 private:
  std::vector<std::string> nodos_;
};

