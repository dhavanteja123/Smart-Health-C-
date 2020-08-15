#ifndef SEARCH_DIS_H
#define SEARCH_DIS_H
#include "Search.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "Dictionary_dis.h"
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;


class Search_dis:public Search
{
    public:
        void select_print_list() ;
        Search_dis();
        Search_dis(Search_dis & s_dis);
        Search_dis operator=(Search_dis s_dis);
        ~Search_dis();
        Search_dis(vector <int> list,int inp_size);
        void set_inp_list(vector <int> list);
        void read_list();
        void select_out_list();
        void set_inp_size(int Z);
        int get_out_size();
        vector <int> get_out_list();
    private:
        vector <int> garbadge_list;
        int garbadge_size;
        Dictionary_dis translate_dis;
};

#endif
