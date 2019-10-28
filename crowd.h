#pragma once
#ifndef CROWD_H
#define CROWD_H

#include "peoplegroup.h"
#include <vector>
#include <QString>

class Crowd : public PeopleGroup {
public:
    Crowd();
    void Accept(Visitor& v) override;
    void Remove();
    std::vector<QString> people_;
};

#endif // CROWD_H
