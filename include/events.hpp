#ifndef EVENTS_H
#define EVENTS_H

#include "contact.hpp"
#include <cstdio>

namespace events {

void create(FILE *&file, Contact contact);
void read(FILE *&file);
void init(FILE *&file);
void sortAndExportRecords(FILE *&file, FILE *&sortedFile);
void sortContacts(Contact *contacts, int countContacts);

} // namespace events

#endif // EVENTS_H
