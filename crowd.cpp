#include "crowd.h"

Crowd::Crowd() : people_({"a", "b", "c", "d"}) {}

void Crowd::Accept(Visitor &v) {
    v.VisitCrowd(this);
}

void Crowd::Remove() {
    people_.erase(people_.begin());
}
