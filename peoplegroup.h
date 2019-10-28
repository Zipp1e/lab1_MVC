#ifndef PEOPLEGROUP_H
#define PEOPLEGROUP_H

#include "visitor.h"

class PeopleGroup {
public:
    virtual void Accept(Visitor& v) = 0;
};

#endif // PEOPLEGROUP_H
