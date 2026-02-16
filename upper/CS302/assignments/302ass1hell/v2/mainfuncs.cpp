#include "overview.h"

void strcpy2(char *& from, char *& to)
{
    to = new char[strlen(from)];
    strcpy(to,from);
}

void ~strcpy2(char *& copy)
{
    delete [] copy;
    copy = nullptr;
}

bool case1_strings(char *& animal, string & name)
{
    cout << "\n------------------------------------------" << endl;
    cout << "\nWhat animal would you like this one to be?" 
         << "\n------" << "\nInput: ";
     
    string temp_string;
    cin.get(temp_string,100);
    cin.ignore(100,'\n');

    strcpy2(temp_string.c_str(), animal);


    cout << "\n-------------"
         << "\nAnd its name?"
         << "\nInput: ";
    cin.get(name, 100);
    cin.ignore('\n',100);

    return true;
}

int view_list(int t,int h, int p)
{
    int choice {0};
    cout << "Which list would you like to view?" << endl;
    cout << "----------------------------------\n";
    cout << "Input: ";
    cin >> choice;
    cin.ignore(100,'\n');
    return choice;
}

int menu_display()
{
    int choice {0};
    cout << "Please choose from the options below:"
         << "\nChoice 1) Make list of animals"
         << "\nChoice 2) View list of current animals"
         << "\nChoice 3) Add another animal"
         << "\nChoice 4) Do some obstacle courses!
         << "\nChoice 5) Look at all times"
         << "\nChoice 6) Exit"
         << "\n---------------------------------------"
         << "\nInput: ";
    cin >> choice;
    cin.ignore(100, '\n');

    if (choice > 6 || choice < 1)
    {
        cout << "\nInvalid Input.\nTry again" << endl;
        return menu_display();
    }

    return choice;
}
