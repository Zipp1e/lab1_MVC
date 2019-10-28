#pragma once
#ifndef SAVIOR_H
#define SAVIOR_H

#include "stack.h"
#include "crowd.h"

class Savior : public Visitor {
public:
    void VisitStack(StringStack* s) override;
    void VisitCrowd(Crowd* c) override;
};

#endif // SAVIOR_H
