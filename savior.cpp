#include "savior.h"

void Savior::VisitStack(StringStack* s) {
    s->Pop();
}

void Savior::VisitCrowd(Crowd* c) {
    c->Remove();
}

