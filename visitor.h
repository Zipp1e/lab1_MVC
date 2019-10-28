#ifndef VISITOR_H
#define VISITOR_H

class StringStack;

class Crowd;

class Visitor {

public:
    virtual void VisitStack(StringStack* s) = 0;
    virtual void VisitCrowd(Crowd* c) = 0;
};

#endif // VISITOR_H
