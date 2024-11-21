#include "../include/helpers.hpp"
#include "../include/contact.hpp"
#include <cstddef>
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
  std::cout << "Name: " << contact.name << std::endl
            << "phone: " << contact.phone << std::endl
            << "email: " << contact.email << std::endl
            << std::endl;
}

void setContact(Contact *contact) {
  do {
    std::cout << "Nombre: ";
    std::cin >> contact->name;
    std::cout << "Edad: ";
    std::cin >> contact->age;
    std::cout << "Telefono: ";
    std::cin >> contact->phone;
    std::cout << "Email: ";
    std::cin >> contact->email;
    helpers::clearScreen();
  } while (strlen(contact->name) == 0 || strlen(contact->phone) == 0 ||
           strlen(contact->email) == 0 || contact->age <= 0);
}

/*
 * Sorts an array. It uses the bubble sort algorithm
 */
void sortContacts(Contact *contacts, int countContacts) {
  for (int i = 0; i < countContacts - 1; i++) {
    for (int j = 0; j < countContacts - i - 1; j++) {
      if (strcmp(contacts[j].name, contacts[j + 1].name) > 0) {
        Contact temp = contacts[j];
        contacts[j] = contacts[j + 1];
        contacts[j + 1] = temp;
      }
    }
  }
}

} // namespace helpers
