#include "../include/helpers.hpp"
#include "../include/contact.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>

namespace helpers {

/*
 * Clears the console independently of the OS
 */
void clearScreen() {
#ifdef _WIN32
  // Windows
  std::system("cls");
#elif defined(__unix__) || defined(__APPLE__) || defined(__MACH__)
  // Unix/Linux/macOS
  std::system("clear");
#else
  std::cout << "No se puede determinar el sistema operativo." << std::endl;
#endif
}

/*
 * Checks if a file exists. This feature is just in case
 */
bool fileExists(const char *filename) {
  FILE *file = fopen(filename, "r");

  if (file != NULL) {
    fclose(file);
    return true;
  }

  return false;
}

/*
 * Show a contact struct
 */
void showContact(Contact contact) {
  std::cout << "| " << contact.name << " | " << contact.phone << " | "
            << contact.email << " |" << std::endl;
}

void setContact(Contact *contact) {
  do {
    std::cout << "Nombre: ";
    std::cin >> contact->name;
    std::cout << "Telefono: ";
    std::cin >> contact->phone;
    std::cout << "Email: ";
    std::cin >> contact->email;
    helpers::clearScreen();
  } while (strlen(contact->name) == 0 || strlen(contact->phone) == 0 ||
           strlen(contact->email) == 0);
}

} // namespace helpers
