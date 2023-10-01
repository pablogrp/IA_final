//queue o el otro, no se como se llama
#include "arbol.h"

std::ostream& operator<< (std::ostream& os, const Arbol& arbol) {
  int contador_elemento = 0;
  int contador_pipe = 1;
  for (int i = 0; i < arbol.nodos_.size()-1; i++) {
    os << arbol.nodos_[i] << " ";
    if ((arbol.nodos_[i] == " | ") && (arbol.nodos_[i+1] == " | ")) {contador_elemento++; }
    if (arbol.nodos_[i] == " | ") {contador_pipe--;}
    //if ((arbol[i] && arbol[i-1]) == " | ") {contador_pipe--;}
    if (contador_pipe == 0) { os  << std::endl; contador_pipe = contador_elemento; contador_elemento = 0;}
    //os  << contador_pipe << " --- " << contador_elemento << std::endl;
    if (arbol.nodos_[i] != " | ") { contador_elemento++; }
  }
  os << std::endl;
  return os;
};