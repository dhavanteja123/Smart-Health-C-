#include "Search_dis.h"

Search_dis::Search_dis()
{
    count1=0 ;
    garbadge_size=0;
    out_size=0;
}
void Search_dis::set_inp_size(int Z)
{
        this->inp_size=Z;
}
Search_dis::Search_dis(vector <int> list,int inp_size)
{
    count1=0 ;
    this->inp_size=inp_size;
    garbadge_size=0;
    out_size=0;
    set_inp_list(list);

}
void Search_dis::set_inp_list(vector <int> list)
{
    inp_list=new int[inp_size];
    for(int i=0;i<inp_size;i++){
        inp_list[i]=list[i];
    }
    read_list();
}
void Search_dis::read_list()
{
    int count=0,x;
    ifstream inp;
    inp.open("Diseases.txt", ios::in);
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
                garbadge_list.push_back(x);
                garbadge_size++;}
            inp>>x;
            if(x==0){
                count++;
                break;}
}}
    inp.close();
    sort(garbadge_list.begin(), garbadge_list.end());
    select_out_list();
}
void Search_dis::select_out_list()
{
    for(int i=0;i<garbadge_size-1;i++){
        if(garbadge_list[i]==garbadge_list[i+1]){
            out_list.push_back(garbadge_list[i]);
            i++;
            out_size++;}
        while(garbadge_list[i]==garbadge_list[i+1])
            i++;}
        if (out_size==0){
            for(int i=0;i<garbadge_size;i++){
                out_list.push_back(garbadge_list[i]);
                }
            out_size=garbadge_size;
        }
        select_print_list() ;
    //print();
}
/*void Search_dis::print()
{
    for(int i=0;i<out_size;i++)
        cout<<translate_dis.get_translation(out_list[i])<<'\n';
}*/
Search_dis::Search_dis(Search_dis & s_dis )
{
    int i ;
    inp_size=s_dis.inp_size ;
    out_size=s_dis.out_size ;
    inp_list=new int [inp_size] ;
    for (i=0 ; i<inp_size ; i++)
    {
        inp_list[i]=s_dis.inp_list[i] ;
    }
    for (i=0 ; i<out_size ; i++)
    {
        out_list.push_back(s_dis.out_list[i]) ;
    }
}
Search_dis Search_dis::operator= (Search_dis s_dis)
{
    int i ;
    inp_size=s_dis.inp_size ;
    out_size=s_dis.out_size ;
    delete [] inp_list ;
    out_list.clear() ;
    inp_list = new int [inp_size] ;
    for (i=0 ; i<inp_size ; i++)
    {
        inp_list[i]=s_dis.inp_list[i] ;
    }
    for (i=0 ; i<out_size ; i++)
    {
        out_list.push_back(s_dis.out_list[i]) ;
    }
    return *this ;
}
int Search_dis::get_out_size()
{
    return out_size;
}
vector <int> Search_dis::get_out_list()
{
    return out_list;
}

void Search_dis::select_print_list()
{
    for (int i=0 ; i<out_size ; i++)
    {
        print_list.push_back("\nDisease:\n\t"+translate_dis.get_translation(out_list[i])+"\n\n") ;
    }
}
Search_dis::~Search_dis()
{
    out_list.clear();
    delete[]inp_list;
    garbadge_list.clear();
    print_list.clear();
}
