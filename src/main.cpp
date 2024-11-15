#include "../include/contact.hpp"
#include "../include/events.hpp"
#include "../include/helpers.hpp"
#include <cstddef>
#include <cstdio>
#include <iostream>

int main(int argc, char *argv[]) {
  char option;
  FILE *file = NULL;
  Contact contact;

  helpers::clearScreen();
  do {
    std::cout << "Menu de opciones" << std::endl;
    std::cout << "1. Crear archivo" << std::endl;
    std::cout << "2. Insertar mas registros" << std::endl;
    std::cout << "3. Mostrar registros" << std::endl;
    std::cout << "4. ordenar registros" << std::endl;
    std::cout << "5. mostrar registros ordenados" << std::endl;
    std::cout << "6. buscar registros" << std::endl;
    std::cout << "8. Salir" << std::endl;

    std::cout << "Opcion: ";
    std::cin >> option;

    switch (option) {
    case '1':
      events::init(file);
      break;
    case '2':
      helpers::clearScreen();
      std::cout << "Ingrese los datos del contacto" << std::endl;
      helpers::setContact(&contact);
      events::create(file, contact);
      break;
    case '3':
      events::read(file);
      break;
    case '8':
      helpers::clearScreen();
      break;
    };

  } while (option != '8');

  // close the file if it was opened
  if (file != NULL) {
    fclose(file);
  }

  return 0;
}
