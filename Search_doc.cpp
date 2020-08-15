#include "Search_doc.h"

Search_doc::Search_doc()
{
    //inp_size=0;
    count1=0 ;
    out_size=0;
}
void Search_doc::Set_inp_size(int Z)
{
        this->inp_size=Z;
}
Search_doc::Search_doc(vector <int> list,int inp_size)
{
    count1=0 ;
    this->inp_size=inp_size;
    out_size=0;
    set_inp_list(list);
}

void Search_doc::set_inp_list(vector<int> list)
{

    inp_list=new int[inp_size];
    for(int i=0;i<inp_size;i++){
        inp_list[i]=list[i];
    }
    read_list();
}
void Search_doc::read_list()
{
    int f=0,d=0;
    fstream infile("Doctors.txt",ios::in);
    for(int i=0;i<inp_size;i++)
    {
        while(f<=inp_list[i])
        {
            infile>>f>>d;
            if(inp_list[i]==f)
            {
                out_list.push_back(d);
            }
        }
        out_list.back()*=-1;
        infile.seekg(0,ios::beg);
        f=d=0;
    }
    infile.close();
    out_size=out_list.size();
    select_print_list() ;
}

Search_doc::Search_doc(Search_doc & s_doc)
{
    int i;
    inp_size=s_doc.inp_size;
    out_size=s_doc.out_size;
    inp_list=new int[inp_size];
    for(i=0;i<inp_size;i++)
    {
        inp_list[i]=s_doc.inp_list[i];
    }
    for(i=0;i<out_size;i++)
    {
        out_list.push_back(s_doc.out_list[i]);
    }
}
Search_doc Search_doc::operator=(Search_doc s_doc)
{
    int i;
    inp_size=s_doc.inp_size;
    out_size=s_doc.out_size;
    delete[] inp_list;
    out_list.clear();
    inp_list=new int[inp_size];
    for(i=0;i<inp_size;i++)
    {
        inp_list[i]=s_doc.inp_list[i];
    }
    for(i=0;i<out_size;i++)
    {
        out_list.push_back(s_doc.out_list[i]);
    }
    return *this;
}
Search_doc::~Search_doc()
{
    delete []inp_list;
    out_list.clear();
    print_list.clear();
}
vector <int> Search_doc::get_out_list()
{
    return out_list ;
}
void Search_doc::select_print_list()
{
    print_list.push_back("\nAvailable doctors:\n\t");
    for (int i=0 ; i<out_size ; i++)
    {
        if(out_list[i]>0)
            print_list.back()+=translate_doc.get_translation(out_list[i])+"\n\t";
        else
        {
            out_list[i]*=-1;
            print_list.back()+=translate_doc.get_translation(out_list[i])+"\n\t";
            print_list.push_back("\nAvailable doctors:\n\t");
        }
    }
}
