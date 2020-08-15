#include "Data.h"

Data::Data()
{
    //ctor
}
string Data::get_name() const
{
    return name;
}

int Data::get_age() const
{
    return age;
}

string Data::get_gender() const
{
    return gender;
}

void Data::record_personal_data()
{
    cout<<"Enter your name: ";
    while(true)
    {
        try{
        getline(cin,name);
        if(!valid_name())
            throw "Invalid name!!\nPlease re-enter your name: ";
        else break;
        }
        catch(const char* error_msg){cerr<<error_msg;}
    }
    cout<<"Enter your age (in years): ";
    while(true)
    {
        try{
        cin>>age;
        if(!valid_age())
            throw "Invalid age!!\nPlease re-enter your age (in years): ";
        else break;
        }
        catch(const char* error_msg){cerr<<error_msg;}
    }
    cin.ignore();
    cout<<"Enter your gender: ";
    while(true)
    {
        try{
        getline(cin,gender);
        if(!valid_gender())
            throw "Invalid gender!!\nPlease re-enter your gender: ";
        else break;
        }
        catch(const char* error_msg){cerr<<error_msg;}
    }
}

void Data::choose(vector<int>& choices)
{
    double choice;
    while(true)
    {
        try{
        cin>>choice;
        if(choice==0) break;
        if(!valid_choice(choice))
            throw "There's invalid choices!!\nPlease enter your choices again:\n";
        else
            choices.push_back(choice);
        }
        catch(const char* error_msg)
        {
            cerr<<error_msg;
            choices.clear();
        }
    }
    sort(choices.begin(),choices.end());
    for(unsigned int i=1;i<choices.size();i++)
        if(choices[i]==choices[i-1])
        {
            choices.erase(choices.begin()+i);
            i--;
        }
}

bool Data::valid_name()
{
    for(unsigned int i=0;i<name.length();i++)
        if(!isalpha(name[i]) && name[i]!=' ')
            return 0;
    return 1;
}

bool Data::valid_age() const
{
    if(age<=0)
        return 0;
    return 1;
}

bool Data::valid_gender()
{
    for(unsigned int i=0;i<gender.length();i++)
        gender[i]=tolower(gender[i]);
    if(gender!="f" && gender!="m" && gender!="male" && gender!="female")
        return 0;
    return 1;
}

bool Data::valid_choice(double choice) const
{
    if(choice<1 || choice>57 || choice!=int(choice))
        return 0;
    return 1;
}

void Data::show_menu() const
{
    cout<<"Please tell us how do you feel (choose from the menu and when you are finished enter 0)\n\n"
        <<"\n\t\tAches and pain in different body parts\n\n"
        <<"1- Body aches\t\t2- Foot/ankle/knee/hand pain\t3- Chest pain\n"
        <<"4- Back pain\t\t5- Neck/throat pain\t\t6- Mouth pain\n"
        <<"7- Arm pain\t\t8- Abdominal pain\n"
        <<"\n\t\t\tMouth, nose and joints\n\n"
        <<"9- Runny nose\t\t10- Cough\t\t\t11- Dry cough\n"
        <<"12- Coughing up blood\t13- Fever\t\t\t14- Sneezing\n"
        <<"15- Difficult chewing\t16- Difficult swallowing\t17- Difficult breathing\n"
        <<"18- Sore throat\t\t19- Voice hoarseness\t\t20- Low motion mobility\n"
        <<"21- Joint inflammation\t22- Easy bone fracture\t\t23- Height loss\n"
        <<"\n\t\t\t\tSkin\n\n"
        <<"24- Red pupules\t\t25- Nodules\t\t\t26- Cysts\n"
        <<"27- Skin pigment loss\t28- Focal skin pattern\t\t29- Segment skin pattern\n"
        <<"30- Skin red spots\t31- Reddish-brown skin\n"
        <<"\n\t\t\tEye disorders\n\n"
        <<"32- Double vision\t33- Drooped eyelids\t\t34- Eye irritation\n"
        <<"35- Squinting\t\t36- Eye strain\t\t\t37- Red eyes\n"
        <<"38- Water eyes\t\t39- Burning eyes\t\t40- Itchy eyelids\n"
        <<"41- Inflamed eyelids\t42- Oily eyelids\n"
        <<"\n\t\t\tother symptoms\n\n"
        <<"43- Weight loss\t\t44- Pressure\t\t\t45- Heaviness\n"
        <<"46- Headache\t\t47- Dizziness\t\t\t48- High blood glucose\n"
        <<"49- Diarrhea\t\t50- Bloody stool\t\t51- Bloody urine\n"
        <<"52- Low urine output\t53- Frequent thirst\t\t54- Drooling\n"
        <<"55- Bloating\t\t56- Nansea\t\t\t57- Congestion\n";
}

void Data::show_report() const
{
    cout<<"\t\t\t\tDiagnosis Report\n\nPersonal Data:\n\nName: "<<name<<"\nAge: "<<age<<" years\nGender: "<<gender
        <<"\n\nDiseases that you may have:\n";
}

void Data::Show_warning() const
{
    cout<<"\nWarning: Please don't take any medicine unless you are supervised by your \n\t doctor.\n\n";
}

Data::~Data()
{
    //dtor
}
