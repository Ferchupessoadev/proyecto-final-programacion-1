#include "../include/events.hpp"
#include "../include/contact.hpp"
#include "../include/helpers.hpp"
#include <cstdio>
#include <iostream>
#include <ostream>

namespace events {

void init(FILE *&file) {
  file = fopen("data.bat", "wb");

  if (file == NULL) {
    std::cout << "Error abriendo el archivo" << std::endl;
    return;
  }
  helpers::clearScreen();
  std::cout << "Se ha creado el archivo" << std::endl;
}

void create(FILE *&file, Contact contact) {
  file = fopen("data.bat", "ab");

  if (file == NULL) {
    std::cout << "Error abriendo el archivo" << std::endl;
    return;
  }

  fwrite(&contact, sizeof(Contact), 1, file);

  fclose(file);
}

void read(FILE *&file) {
  helpers::clearScreen();
  file = fopen("data.bat", "rb");
  int countContacts = 0;

  if (file == NULL) {
    std::cout << "Error abriendo el archivo" << std::endl;
    return;
  }

  Contact contact;

  while (fread(&contact, sizeof(Contact), 1, file) == 1) {
    helpers::showContact(contact);
    countContacts++;
  }

  if (countContacts == 0) {
    std::cout << "No hay contactos" << std::endl;
    std::cout << std::endl;
    return;
  }

  std::cout << "Total de contactos: " << countContacts << std::endl;
  std::cout << std::endl;

  std::cout << "Presione enter para continuar... ";
  std::cin.ignore();
  std::cin.get();
  helpers::clearScreen();
}

} // namespace events
