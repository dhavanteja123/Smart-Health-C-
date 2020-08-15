#include "Search_field.h"
Search_field::Search_field()
{
    out_size=0;
}
void Search_field::Set_inp_size(int Z)
{
    this->inp_size=Z;
}
Search_field::~Search_field()
{

}
Search_field::Search_field(vector <int> list,int inp_size)
{
    this->inp_size=inp_size;
    out_size=0;
    set_inp_list(list);
}
void Search_field::set_inp_list(vector <int> list)
{
    inp_list=new int[inp_size];
    for(int i=0;i<inp_size;i++){
        inp_list[i]=list[i];
    }
    read_list();
}
void Search_field::read_list()
{
    int count=0,x;
    ifstream inp;
    inp.open("Fields.txt", ios::in);
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
                count++;
                break;}
}}
    inp.close();
}

Search_field::Search_field(Search_field & s_f )
{
    int i ;
    inp_size=s_f.inp_size ;
    out_size=s_f.out_size ;
    inp_list=new int [inp_size] ;
    for (i=0 ; i<inp_size ; i++)
    {
        inp_list[i]=s_f.inp_list[i] ;
    }
    for (i=0 ; i<out_size ; i++)
    {
        out_list.push_back(s_f.out_list[i]) ;
    }
}
Search_field Search_field::operator= (Search_field s_f)
{
    int i ;
    inp_size=s_f.inp_size ;
    out_size=s_f.out_size ;
    delete [] inp_list ;
    out_list.clear() ;
    inp_list = new int [inp_size] ;
    for (i=0 ; i<inp_size ; i++)
    {
        inp_list[i]=s_f.inp_list[i] ;
    }
    for (i=0 ; i<out_size ; i++)
    {
        out_list.push_back(s_f.out_list[i]) ;
    }
    return *this ;
}
int Search_field::get_out_size()
{
    return out_size;
}
vector <int> Search_field::get_out_list()
{
    return out_list;
}
