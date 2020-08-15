#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include "Data.h"
#include "Search_dis.h"
#include "Search_field.h"
#include "Search_doc.h"
#include "Search_med.h"

using namespace std;

int main()
{
    vector<int> choices;
    Data dta;
    dta.record_personal_data();
    system("cls");
    dta.show_menu();
    dta.choose(choices);
    system("cls");
    dta.show_report();
    Search_dis a(choices,choices.size());
    Search_field b(a.get_out_list(),a.get_out_size());
    Search_doc c(b.get_out_list(),b.get_out_size());
    Search_med d(a.get_out_list(),a.get_out_size());
    for(int i=0;i<a.get_out_size();i++)
        cout<<a<<d<<c;
    system("color 03");
    dta.Show_warning();
    return 0;
}
