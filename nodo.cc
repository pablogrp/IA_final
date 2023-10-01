#include "nodo.h"


// Constructor de la clase
Nodo::Nodo(int identificador) {
  identificador_ = identificador;
}


// Getter identificador nodo
int Nodo::get_identificador() {
  return identificador_;
}

// Setter identificador nodo
void Nodo::set_identificador(int identificador) {
  identificador_ = identificador;
}

// Getter padre del nodo
Nodo* Nodo::get_padre() {
  return padre_;
}

// Setter padre del nodo
void Nodo::set_padre(Nodo* padre) {
  padre_ = padre;
}

// Metodo que añade un nuevo nodo hijo del nodo actual
void Nodo::add_hijo(Nodo* hijo) {
  hijos_.push_back(hijo);
  hijo->set_padre(this);
}

// Getter de vector de hijos de un nodo
std::vector<Nodo*> Nodo::get_hijos() {
  return hijos_;
}

// Sobrecarga operador extraccion
std::ostream& operator<<(std::ostream& output, const Nodo& nodo) {
  output << "Nodo(" << nodo.identificador_ << ")";
  return output;
}