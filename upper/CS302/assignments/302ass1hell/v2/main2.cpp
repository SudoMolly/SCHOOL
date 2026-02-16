#include "overview.h"

int main()
{
    int choice {0};

    vector<land> L;
    vector<sea> S;
    vector<pigeon> P;

    cout << "Welcome to the pet racing program"
         << "\nYou will have your choice of animal type:"
         << "\n         -Land based"
         << "\n         -Water based"
         << "\n         -Random. "
         << "\nYou will be given the option for the "
         << "\nnumber of animals to have in a given animal"
         << "\ntype. Then you can name them, & what species they are.""
         << endl;
    do
    {
        choice = menu_display();
        switch(choice)
        {
            case(1): //make list
                if (!case1(L,S,P)) exit(__LINE__);
                break;
            case(2): //view all
                if (!display_all(t,p,h)) exit(__LINE__);
                break;
            case(3): //obstacle course
                break;
            case(4): //view who completed
                break;
            case(5): //leave
                cout << "Thank you and goodbye!" << endl;
                break;
            default:
            cout << "That's not a valid input!" 
                 << "\nPlease try again."
                 << endl;
        }
    } while (choice != 5);
    return 0;

}





/*
bool display_all(vector<vector<tortoise>> & t, vector<vector<hare>> & h,
                 vector<vector<pigeon>> & p);
{
    int outer_limitT {t.size()};
    int outer_limitH {h.size()};
    int outer_limitP {p.size()};

    int inner_limitT {0};
    int inner_limitH {0};
    int inner_limitP {0};

    cout << "\nLists of Slow Animals: " << endl;
    for (int i = 0; i < outer_limitT; ++i)
    {
        inner_limitT = t[i].size();
        cout << "List #" << i << ":" << endl;
        cout << "===========================";
        for (int i_i = 0; i_i < inner_limitT; ++i_i)
        {
            cout << "-----------------------" << endl;
            cout << "Animal #" << i_i << endl;
            if(!t[i][i_i].display()) exit(__LINE__);
        }
    }
    cout << "\nLists of Fast Animals: " << endl;
    for (int i = 0; i < outer_limitH; ++i)
    {
        inner_limitH = h[i].size();
        cout << "List #" << i << ":" << endl;
        cout << "===========================";
        for (int i_i = 0; i_i < inner_limitH; ++i_i)
        {
            cout << "-----------------------" << endl;
            cout << "Animal #" << i_i << endl;
            if(!h[i][i_i].display()) exit(__LINE__);
        }
    }

    cout << "\nLists of Random Animals: " << endl;
    for (int i = 0; i < outer_limitP; ++i)
    {
        inner_limitP = p[i].size();
        cout << "List #" << i << ":" << endl;
        cout << "===========================";
        for (int i_i = 0; i_i < inner_limitP; ++i_i)
        {
            cout << "-----------------------" << endl;
            cout << "Animal #" << i_i << endl;
            if(!p[i][i_i].display()) exit(__LINE__);
        }
    }

    return true;
}
*/
//main file 1






/*
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
*/

/*
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
*/
    

