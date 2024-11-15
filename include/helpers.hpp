#ifndef HELPERS_H
#define HELPERS_H

#include "contact.hpp"
#include <cstdio>

namespace helpers {

void clearScreen();
bool fileExists();
void showContact(Contact contact);
void setContact(Contact *contact);
void sortContacts(Contact *contacts, int countContacts);

} // namespace helpers

#endif // HELPERS_H
