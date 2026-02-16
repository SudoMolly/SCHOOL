#include "petRace.h"
using namespace std;

int main()
{
    //pigeon * p;
    //tortoise * t;
    //hare * h;

    vector<vector<tortoise> t;
    vector<vector<hare>> h;
    vector<vector<pigeon>> p;
    cout << "Welcome to the pet racing program"
         << "\nYou will have your choice of animal type:"
         << "\n         -Slow, but steady"
         << "\n         -Fast, but unreliable"
         << "\n         -Random. "
         << "\nYou will be given the option for the "
         << "\nnumber of animals to have in a given animal"
         << "\ntype. Then you can name them, or have a"
         << "\nrandom name chosen for you."
         << endl;
    exit = menu(t,h,p);
    if (exit)

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


bool make_list (vector<vector<tortoise>> *&t, 
                vector<vector<hare>> *&h,
                vector<vector<pigeon>> *&p,
                int & tsize,int & hsize, int & psize)
{
    int animal_type {0};
    int animal_num {0};
    cout << "Which animal type would you like to make?"
            << "       (1)    -Slow, but steady-"
            << "       (2)-Fast, but inconsistent!-"
            << "       (3)        -Random-"
            << "------------------------------------------"
            << "\nInput: ";
    cin >> animal_type;
    cin.ignore(100,'\n');

    cout << "------------------------------------------"
            << "How many are in the list?"
            << "\nNum: ";
    cin >> animal_num;
    cin.ignore(100,'\n');

    switch(animal_type)
    {
        case(1):
            ++tsize;
            t.add(1);//LOOKUP 
            t[tsize].reserve(animal_num); //LOOKUP
            make_tortoise(t[tsize],animal_num,0);
            break;
        case(2):
            ++hsize;
            h.add(1); //LOOKUP
            h[hsize].reserve(animal_num); //LOOKUP
            break;
        case(3):
            ++psize;
            p.add(1); //LOOKUP
            p[psize].reserve(animal_num); //LOOKUP
            break;
    }
    return true;
}

bool view_list(int t,int h, int p)
{
    int choice {0};
    cout << "Which list would you like to view?" << endl;
    cout <<
    cout << "Input: ";
    cin >> choice;
    return true;
}

int menu(vector<vector<tortoise>> *&t, 
          vector<vector<hare>> *&h,
          vector<vector<pigeon>> *&p,
          int tsize,int hsize, int psize)
{
    choice = menu_display();

    switch(choice)
    {
        case(1):
            cout << "Which animal type would you like to make?"
                 << "       (1)    -Slow, but steady-"
                 << "       (2)-Fast, but inconsistent!-"
                 << "       (3)        -Random-"
                 << "------------------------------------------"
                 << "\nInput: ";
            cin >> animal_type;
            cin.ignore(100,'\n');

            cout << "------------------------------------------"
                 << "How many are in the list?"
                 << "\nNum: ";
            cin >> animal_num;
            cin.ignore(100,'\n');
            

            switch(animal_type)
            {
                case(1):
                    ++tsize;
                    t.add(1);//LOOKUP 
                    t[tsize].reserve(animal_num); //LOOKUP
                    make_tortoise(t[tsize],animal_num,0);
                    break;
                case(2):
                    ++hsize;
                    h.add(1); //LOOKUP
                    h[hsize].reserve(animal_num); //LOOKUP
                    break;
                case(3):
                    ++psize;
                    p.add(1); //LOOKUP
                    p[psize].reserve(animal_num); //LOOKUP
                    break;
            }
            if (!make_list(t,h,p,tsize,hsize,psize)) exit(__LINE__);
            break;
        case(2):
            

            break;
{
    if (animal == 1)
    {
        vector <string> Animal{
        "Sloth","Tortoise","Manatee","Starfish","Sea Horse","Banana Slug","Gila Monster","Koala",  
        "Loris","Giant Tortoise","Snail","Chameleon","Three-Toed Sloth","Aardvark","Pangolin","Opossum",  
        "Armadillo","Jellyfish","Nematode","Earthworm"
        };
    }
    else if (animal == 2)
    {
        vector <string> Animal{
        "Cheetah","Peregrine Falcon","Sailfish","Pronghorn Antelope","Spur-Winged Goose","Black Marlin",  
        "Lion","Quarter Horse","Blue Wildebeest","Brown Hare","Ostrich","Greyhound","Anna's Hummingbird",  
        "Frigatebird","Mako Shark","Killer Whale","Dolphin","Red Fox","Kangaroo","Swordfish"
        };
    };
    else
    {
        vector <string> Animal{
        "Ostrich","Turkey","Kakapo","Panda","Flamingo","Hippopotamus","Pufferfish","Peacock","Lemming",  
        "Dodo","Blobfish","Albatross","Goblin Shark","Narwhal","Platypus","Emu","Baboon","Possum",  
        "Peppered Moth","Mola Mola"
        };
    }

    int animal = display_vector(list,Animal.size(),Animal.size());
    if (animal < 0 || animal >= Animal.size()) return false; //LOOKUP
    Animal[animal].copy(ret); //LOOKUP
    return true;
}

int display_vector(vector<string>  & list, int i, int size)
{
    if (i == 0)
    {
        cout << "-----------------------------";
        cout << "\nInput: ";
        cin >> i;
        cin.ignore(100, '\n');
        if (i < 1 || i > size)
        {
            cout << "you can't be trusted" << endl;
            i = rand() % size;
            cout << list[i] << " chosen." << endl;
        }
        return i;
    }
    int current = size-i;
    cout << "Animal (" << current << ") : "
         << list[current] << endl;
    --i;
    return display_vector(list,i,size);
}

    

