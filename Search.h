#ifndef SEARCH
#define SEARCH
#include <vector>
#include <iostream>
using namespace std;

class Search
{
    public:
        template<class T>
        friend ostream& operator<< (ostream& os , T &obj)
        {
            os<<obj.get(obj.count1++)  ;
            return os ;
        }
        string get(int x)
        {
            return print_list[x] ;
        }
    protected:
        int * inp_list;
        vector<int> out_list;
        int inp_size;
        int out_size;
        vector<string>print_list ;
        int count1 ;
};

#endif // SEARCH
