#ifndef SEARCH_FIELD_H
#define SEARCH_FIELD_H
#include <vector>
#include "Search.h"
#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;
class Search_field: public Search
{
    public:
        Search_field();
        Search_field(Search_field & s_f );
        Search_field operator= (Search_field s_f);
        ~Search_field();
        Search_field(vector <int> list,int inp_size);
        void set_inp_list(vector <int> list);
        void read_list();
        void select_out_list();
        int get_out_size();
        vector <int> get_out_list();
        void Set_inp_size(int Z);
    private:
};

#endif // SEARCH_FIELD_H
