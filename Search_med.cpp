#include "Search_med.h"

Search_med::Search_med()
{
    count1=0 ;
    out_size=0;
}
void Search_med::set_inp_size(int Z)
{
    this->inp_size=Z;
}
Search_med::Search_med (vector <int> list,int inp_size)
    {
        count1=0 ;
        this->inp_size=inp_size;
        out_size=0;
        set_inp_list(list);
    }
void Search_med::set_inp_list (vector <int> list)
{
    inp_list=new int[inp_size];
    for(int i=0;i<inp_size;i++){
        inp_list[i]=list[i];
    }
    read_list();
}
void Search_med::read_list()
{
    int count=0,x;
    ifstream inp;
    inp.open("Medicines.txt", ios::in);
    for(int i=0;i<inp_size;i++){
        inp>>x;
        while(true){
            if(x==0)
                count++;
            if(count==inp_list[i]-1){
                break;}
            inp>>x;}
        while(true){
            if(x!=0){
                out_list.push_back(x);
                out_size++;}
            inp>>x;
            if(x==0){
                if(out_list.back()>0)
                    out_list.back()*=-1;
                count++;
                break;}
}}
    inp.close();
    select_print_list();
}

Search_med::Search_med(Search_med & s_med )
{
    int i ;
    inp_size=s_med.inp_size ;
    out_size=s_med.out_size ;
    inp_list=new int [inp_size] ;
    for (i=0 ; i<inp_size ; i++)
    {
        inp_list[i]=s_med.inp_list[i] ;
    }
    for (i=0 ; i<out_size ; i++)
    {
        out_list.push_back(s_med.out_list[i]) ;
    }
}
Search_med Search_med::operator= (Search_med s_med)
{
    int i ;
    inp_size=s_med.inp_size ;
    out_size=s_med.out_size ;
    delete [] inp_list ;
    out_list.clear() ;
    inp_list = new int [inp_size] ;
    for (i=0 ; i<inp_size ; i++)
    {
        inp_list[i]=s_med.inp_list[i] ;
    }
    for (i=0 ; i<out_size ; i++)
    {
        out_list.push_back(s_med.out_list[i]) ;
    }
    return *this ;
}
Search_med::~Search_med()
{
    delete[]inp_list ;
    out_list.clear() ;
    print_list.clear();
}
vector <int> Search_med::get_out_list()
{
    return out_list ;
}

void Search_med::select_print_list()
{
    print_list.push_back("\nSuggested medicines:\n\t");
    for (int i=0 ; i<out_size ; i++)
    {
        if(out_list[i]>0)
            print_list.back()+=translate_med.get_translation(out_list[i])+"\n\t";
        else
        {
            out_list[i]*=-1;
            print_list.back()+=translate_med.get_translation(out_list[i])+"\n\t";
            print_list.push_back("\nSuggested medicines:\n\t");
        }
    }
}
