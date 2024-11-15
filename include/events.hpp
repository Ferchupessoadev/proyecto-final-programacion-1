#ifndef EVENTS_H
#define EVENTS_H

#include "contact.hpp"
#include <cstdio>

namespace events {

void create(FILE *&file, Contact contact);
void read(FILE *&file);
void init(FILE *&file);

} // namespace events

#endif // EVENTS_H
