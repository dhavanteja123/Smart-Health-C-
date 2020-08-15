#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

class Data
{
    public:
        Data();
        string get_name() const;
        int get_age() const;
        string get_gender() const;
        void record_personal_data();
        void choose(vector<int>&);
        bool valid_name();
        bool valid_age() const;
        bool valid_gender();
        bool valid_choice(double) const;
        void show_menu() const;
        void show_report() const;
        void Show_warning() const;
        ~Data();
    private:
        string name;
        double age;
        string gender;
};
#endif // DATA_H
