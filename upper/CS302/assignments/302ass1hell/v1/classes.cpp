#include "petRace.h"
using namespace std; // not working??






//class animals -------------------------------------------------------------//

animals::animals(std::string name): name
{
    srand(time(NULL));
    seed = rand() % int((pow(10,8)));
    
}

animals::~animals()
{
}

int animals::random_names(char *& name)
{
    vector<string> name_list = {
        "Aaron","Abigail","Adam","Adrian","Aiden","Alex","Alexander","Alexis","Alice","Alyssa",
        "Amanda","Amber","Amy","Andrea","Andrew","Angel","Anna","Anthony","Ashley","Aubrey",
        "Austin","Ava","Bailey","Benjamin","Bethany","Blake","Brandon","Brenda","Brian","Brianna",  
        "Brittany","Brooke","Caleb","Cameron","Caroline","Cassandra","Catherine","Charles","Charlotte",  
        "Chase","Chelsea","Chloe","Christian","Christina","Christopher","Claire","Cody","Cole","Colton",  
        "Connor","Courtney","Crystal","Daisy","Daniel","Danielle","David","Derek","Destiny","Devin",  
        "Diana","Dominic","Dylan","Elizabeth","Emily","Emma","Eric","Ethan","Eva","Evan","Gabriel",  
        "Gabrielle","Gavin","Grace","Haley","Hannah","Hayden","Heather","Isaac","Isabella","Isaiah",  
        "Jack","Jackson","Jacqueline","Jada","Jaden","Jasmine","Jason","Jayden","Jennifer","Jeremiah",  
        "Jessica","John","Jonathan","Jordan","Jose","Joshua","Julia","Justin","Kaitlyn","Katherine",  
        "Kathryn","Kayla","Kaylee","Kelsey","Kevin","Kyle","Lauren","Layla","Leah","Leo","Leonardo",  
        "Liam","Lillian","Lily","Logan","Lucas","Luke","Madeline","Madison","Maria","Mariah","Mason",  
        "Matthew","Megan","Melissa","Michael","Michelle","Morgan","Natalie","Nathan","Nathaniel",  
        "Nicholas","Nicole","Olivia","Owen","Paige","Patrick","Rachel","Rebecca","Robert","Ryan",  
        "Samantha","Sarah","Savannah","Sean","Sophia","Stephanie","Steven","Sydney","Taylor","Thomas",  
        "Tiffany","Timothy","Tristan","Tyler","Victoria","Zachary","Zoe"
    };

    int choice = seed % 100;
    int length = (name_list[choice]).length() + 1;
    name = new char[length];

    strcpy(name, name_list[choice].c_str());
    if (strcmp(name,name_list[choice].c_str()) != 0) exit(__LINE__);
    return choice;
}

//choose which animal name list to assign
int animals::random_animal(char *& name, int animal_list)
{
    if (animal) return *animal;

    if (animal_list == 1)

    if (animal_list == 2)

    if (animal_list == 3)

    animal = new int{rand() % 20};
    name = new char[Animal[*animal].length + 1];

    strcpy(name,Animal[*animal].c_str());
    if (strcmp(name,Animal[*animal]) != 0) exit(__LINE__);
    return *animal;



    return *animal;
}

int animals::seed_val()
{
    return seed;
}
//class tort ----------------------------------------------------------------//

tortoise::tortoise()
{
    attr = new int[3];

    char * fake = nullptr;
    attr[0] = seed_val(); //HIEARCHY DERIVED
    attr[1] = 1;
    attr[2] = random_animal(fake,1); //HIERARCHY DERIVE

    delete [] fake;
    fake = nullptr;

    attr[2] += random_name(fake); //HIEARCHY DERIVED
    name.assign(fake); //HIEARCHY DERIVED
    delete [] fake;

    on_back = false;


}
tortoise::~tortoise()
{

}
int tortoise::go()
{
    if (on_back) 
        on_back = rights_self();

    else 
    {
        on_back = fall_over();
        on_back = rights_self();
    }

    if (on_back)
        returns 0;

    return attr[1];

}
bool tortoise::fall_over()
{
    int fall {((rand() % 16) + attr[0]) % 11};
    if (fall == 7)
    {
        cout << "\nOh no! " << name << " fell over!" << endl;
        return true;
    }
    return false;
}
bool tortoise::rights_self()
{
    cout << "\n" << name << " attempts to right himself!" << endl;
    int fall {((rand() % 16) + attr[0]) % 11};

    if (fall < 5) 
    {
        cout << "\nAnd succeeds!" << endl;
        return false;
    }

    cout << "\nAnd fails!" << endl;
    return true;
}


//class hare ----------------------------------------------------------------//
hare::hare()
{
    attr = new int[3];

    char * fake = nullptr;
    attr[0] = seed_val(); //HIEARCHY DERIVED
    attr[1] = attr[0] % 5;
    attr[2] = random_animal(fake,2); //HIERARCHY DERIVE

    delete [] fake;
    fake = nullptr;

    attr[2] += random_name(fake); //HIEARCHY DERIVED
    name.assign(fake); //HIEARCHY DERIVED
    delete [] fake;
}
hare::~hare()
{

}
int hare::go()
{
    if ((rand() + attr[0]) % 2 == 0)
        return faster();
    return slower();
}
int hare::faster()
{
    attr[1] += ((rand() + attr[0]) % 2);

    if (attr[1] > 5)
    {
        attr[1] = 5;
        return 5;
    }

    return attr[1];

}
int hare::slower(int seed)
{
    attr[1] -= ((rand() + attr[0]) % 2) + 1;

    if (attr[1] < 0)
    {
        attr[1] = 0;
        return 0;
    }

    return attr[1];

}

//class pigeon --------------------------------------------------------------//
pigeon::pigeon()
{
    attr = new int[3];

    char * fake = nullptr;
    attr[0] = seed_val(); //HIEARCHY DERIVED
    attr[1] = ((rand() + attr[0]) % attr[0]) % 3;
    attr[2] = random_animal(fake,2); //HIERARCHY DERIVE

    delete [] fake;
    fake = nullptr;

    attr[2] += random_name(fake); //HIEARCHY DERIVED
    name.assign(fake); //HIEARCHY DERIVED
    delete [] fake;
}
pigeon::~pigeon()
{

}
int pigeon::go()
{
    if ((rand() + attr[0] % 101) < 70) return listens();

    if (attr[1] < 3)
        attr[1] = 3;
    else
        ++attr[1];
    return attr[1];

}
//minimum of -1, means skip round
int pigeon::distraction()
{

    attr[1] -= ((rand() + attr[0]) % attr[0]) % 3;

    if (attr[1] < -1)
    {
        cout << "\n" << name << " seems to be busy sleeping!" << endl;
        attr[1] = -1;
    }
    else
        cout << "\n" << name << " gets back on course!" << endl;

    return attr[1];
}
int pigeon::listens()
{
    cout << "\n" << name << " is considering their options..." << endl;
    if ((rand() + attr[0]) % 4 == 3)
    {
        cout << "\nAnd gets distracted!" << endl;
        return distraction();
    }

    cout << "\nAnd continues forward!" << endl;
    return attr[1];
}
