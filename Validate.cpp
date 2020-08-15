#include "Validate.h"

Validate::Validate()
{
    //ctor
}

bool Validate::name(string name)
{
    for(unsigned int i=0;i<name.length();i++)
        if(!isalpha(name[i]) && name[i]!=' ')
            return 0;
    return 1;
}

bool Validate::age(double age)
{
    if(age<=0)
        return 0;
    return 1;
}

bool Validate::gender(string& gender)
{
    for(unsigned int i=0;i<gender.length();i++)
        gender[i]=tolower(gender[i]);
    if(gender!="f" && gender!="m" && gender!="male" && gender!="female")
        return 0;
    return 1;
}

bool Validate::choice(double choice)
{
    if(choice<1 || choice>57 || choice!=int(choice))
        return 0;
    return 1;
}

Validate::~Validate()
{
    //dtor
}
