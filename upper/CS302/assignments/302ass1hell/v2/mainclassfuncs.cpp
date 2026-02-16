#include "overview.h"

int make_sea(sea *& S,int max, int i)
{
    char * tempc;
    string temps;
    if(!case1_strings(tempc,temps)) exit(__LINE__);
    S[i].emplace(tempc,temps);
    ++i;
    ~strcpy2(tempc);
    if (i == max) return i;
    return (make_sea(S,max,i));
}

int make_land(land *& L, int max, int i)
{
    char * tempc;
    string temps;
    if(!case1_strings(tempc,temps)) exit(__LINE__);
    L.emplace(i,tempc,temps);
    ++i;
    ~strcpy2(tempc);
    if (i == max) return i;
    return (make_land(L,max,i));
}

int make_pigeon(vector<pigeon> *& P, int max, int i)
{
    char * tempc;
    string temps;
    if(!case1_strings(tempc,temps)) exit(__LINE__);
    P.emplace(i,tempc,temps);
    ++i;
    ~strcpy2(tempc);
    if (i == max) return i;
    return (make_pigeon(P,max,i));
}

bool case1(vector<land> & L, vector<sea> & S, vector<pigeon> & P) 
{

    int animal_type {0};
    int animal_num {0};

    cout << "Which animal type would you like to make?"
         << "       (1)        -Land Animal-"
         << "       (2)    -Water Based Animal-"
         << "       (3)     -Unreliable Animal-"
         << "------------------------------------------"
         << "\nInput: ";

    cin >> animal_type;
    cin.ignore(100,'\n');

    cout << "------------------------------------------"
         << "\nHow many would you like to add?"
         << "\nNum: ";
    cin >> animal_num;
    cin.ignore(100,'\n');
    

    switch(animal_type)
    {
        case(1):
            L.reserve(animal_num + L.size());
            animals_added = make_land(L.back(),animal_num,0);
            cout << "Number of animals added to land animals: "
                 << animals_added << endl;
            break;
        case(2):
            S.reserve(animal_num + S.size()); //LOOKUP
            animals_added = make_sea(S.back(),animal_num,0);
            cout << "Number of animals added to water animals: "
                 << animals_added << endl;
            break;
        case(3):
            P.reserve(animal_num + P.size()); //LOOKUP
            animals_added = make_pigeon(P.back(),animal_num,0);
            cout << "Number of animals added to random animals: "
                 << animals_added << endl;
            break;
    }
    return true;
}
