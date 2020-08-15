#ifndef SEARCH_DOC
#define SEARCH_DOC
#include <iostream>
#include <fstream>
#include <vector>
#include "Search.h"
#include "Dictionary_doc.h"

using namespace std;

class Search_doc: public Search
{
    public:
        void select_print_list() ;
        Search_doc();
        Search_doc(Search_doc &);
        Search_doc(vector <int> list, int inp_size );
        Search_doc operator=(Search_doc);
        void set_inp_list (vector<int> list);
        void read_list();
        ~Search_doc();
        vector <int> get_out_list();
        void Set_inp_size(int Z);
    private:
        Dictionary_doc translate_doc;

};

#endif // SEARCH_DOC
