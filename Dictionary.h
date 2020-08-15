#ifndef DIC
#define DIC
#include <iostream>
#include <map>

using namespace std;

class Dictionary
{
    protected:
        map<int,string> dictionary;
    public:
        string get_translation(int);
};

#endif // DIC
