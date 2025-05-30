#ifndef TEMPLATECLASS_H
#define TEMPLATECLASS_H

#include <string>

class TemplateClass {
public:
    TemplateClass();
    ~TemplateClass();

    void doSomething() const;

private:
    int data_;
};

#endif // TEMPLATECLASS_H