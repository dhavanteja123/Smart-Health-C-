#ifndef VALIDATE_H
#define VALIDATE_H
#include <iostream>
#include <cctype>
#include <vector>

using namespace std;

class Validate
{
    public:
        Validate();
        bool name(string);
        bool age(double);
        bool gender(string&);
        bool choice(double);
        ~Validate();
};

#endif // VALIDATE_H
