#pragma once

#include<iostream>
#include<vector>
#include<set>

class Nodo {
  public:
    // Constructor de la clase
    Nodo(int);
    Nodo() {} // Constructor por defecto

    int get_identificador(); // Getter identificador nodo
    void set_identificador(int); // Setter identificador nodo
    Nodo* get_padre(); // Getter padre del nodo
    void set_padre(Nodo*); // Setter padre del nodo
    void add_hijo(Nodo*); // Metodo para añadir un nuevo hijo a un nodo
    std::vector<Nodo*> get_hijos(); // Getter de vector de hijos de un nodo

    // Sobrecarga operador extraccion
    friend std::ostream& operator<<(std::ostream&, const Nodo&);
    int nodos_totales_;
  
  private:
    int identificador_;
    std::vector<Nodo*> hijos_;
    Nodo* padre_;
    double recorrido_;
};
