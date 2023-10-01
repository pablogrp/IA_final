#include "utilidad.h"

void Usage(int argc, char* argv[]) {
  std::string cadena = "--help";
  if (argc > 1) {
    std::string ayuda = argv[1];
    if (ayuda == cadena) {
      std::cout << "A parte de los ejecutable y los archivios, las opciones "
                   "pueden ser:\n 1 Longitud\n 2 Inversa\n 3 "
                   "Prefijos\n 4 Sufijos\n 5 Subcadenas "
                << std::endl;
      std::exit(1);
    }
  }
  if (argc != 5) {
    std::cout
        << "El programa necesita 5 argumentos. El ejecutable, el nodo inicio y "
           "final, el nombre del fihcero a leer y la opción que se quiere tomar"
        << std::endl;
    std::exit(1);
  }
}