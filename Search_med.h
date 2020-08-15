#ifndef SEARCH_MED
#define SEARCH_MED
#include "Dictionary_med.h"
#include "Search.h"
#include <fstream>

class Search_med : public Search
{
private :
   Dictionary_med translate_med  ;
public :
    void select_print_list() ;
    Search_med () ;
    Search_med (vector <int> list,int inp_size) ;
    void set_inp_list (vector <int> list) ;
    void read_list() ;
    Search_med operator= (Search_med s_med) ;
    void set_inp_size(int Z);
    Search_med (Search_med & ) ;
    ~Search_med() ;
    vector <int> get_out_list();



};


#endif // SEARCH_MED
