//CLASSES FILE
#include "overview.h"
using namespace std;

/*Attr description
 [0]def(random) = Animal's base speed stat
 [1]def(20%)    = Percentage for Bungle() to trigger
 [2]def(0)      = Rounds since Bungle() last triggered
 [3]def(10%)    = Percentage added per no Bungle() trigger
 [4]def(0)      = Boolean of is animal bungled?
 [5]def(1-3)    = int representing which animal type they are
*/
//base---------------------------------------------------------------------------------|
base::base()
{
    srand(time(NULL));
}
base::base(char *& toanimal, std::string & toname)
{
    strcpy2(animal,toanimal);
    name = toname;
}

base::~base()
{
    delete [] animal;
    animal = nullptr;
    name.clear();
}
int base::round_tick(std::vector<int> & attr)
{
    
}

int base::random()
{
    return (std::max(rand() % 101,1));
}

int base::type(int & type)
{
    return type;
}
int base::display()
{
    if (!animal) return 0;
    cout << "===============\n"
         << "Name: " << name
         << "\nAnimal: " << animal
         << endl;
    return 1;
}

//derived-----------------------------------------------------------------------------|

//land
land::land(char *& toanimal, std::string & toname) : public base(char*&toanimal,std::string & toname)
{
    attr.resize(6);
    attr[0] = max(random() % 5,1);
    attr[1] = 20;
    attr[2] = 0;
    attr[3] = 10;
    attr[4] = 0;
    attr[5] = 1;
}
land::land()
{
}
land::~land()
{
}
int land::bungle() //do they lay down?
{
    if (attr[4] == 1) return 0;
    attr[1] = 20;
    attr[2] = 0;
    attr[3] = 10;
    attr[4] = 1;

    cout << base.name << " is tired! They lay down." << endl;
    return 0;
    
}

int land::round() //per round calculations
{
    if (attr[4]) //if bungled
        if(!recover) return 0; //failure
    else
        if (random() <= (attr[1] + (attr[3] * attr[2])))
            return bungle();
    ++attr[2];
    return base.round_tick(attr)
}


bool land::recover() //if down, get up?
{
    cout << base.name << " attempts to get up!\nAnd they ";

    if (base.random() <= (attr[1] + (attr[3] * attr[2])))
    {
        attr[1] -= 5;
        attr[2] = 0;
        attr[3] -= 2;
        attr[4] = 0;
        cout << "Succeed!\n"
             << base.name << " is back on their feet!"
             << endl;
        return true;
    }
    cout << "Fail.\n"
         << base.name 
         << " is just too tired!"
         << endl;
    ++attr[2];
    return false;
}

bool land::display(vector<land> & list, max,i)
{
    if (list.empty()) return false;
    i += display();
    if (i == max) return true;
    return list[i].display(list,max,i);
}



//sea
sea::sea(char *& toanimal, std::string & toname) : public base(char*&toanimal,std::string & toname)
{
    attr.resize(6);
    attr[0] = max(random() % 3,1);
    attr[1] = 20;
    attr[2] = 0;
    attr[3] = 5;
    attr[4] = 0;
    attr[5] = 2;
    

}
sea::sea()
{
}
sea::~sea()
{
}
int sea::bungle() //Not actually bungle, do they speed up?
{
    if (attr[4]) return attr[0];

    ++attr[0];
    attr[1] = 20;
    attr[2] = 0;
    --attr[3];
    attr[4] = 1;
    cout << base.name << " speeds up!" << endl;
}
int sea::round() //Per round calculations
{
    if (attr[0] >= 7 || attr[4]) //got to max!
        if (recover()) return attr[0];

    if (base.random() <= attr[1] + (attr[3] * attr[2]) && attr[0] != 7)
        return bungle();
    ++attr[2];
    return base.round_tick(attr);
}
bool sea::recover() //Do they keep that speed? (bungle = loop, recover = cond)
{
}

bool sea::display(vector<sea> & list, max,i)
{
    if (list.empty()) return false;
    i += display();
    if (i == max) return true;
    return list[i].display(list,max,i);
}

//pigeon

pigeon::pigeon(char *& toanimal, std::string & toname) : public base(char*&toanimal,std::string & toname)
{
    attr.resize(6);
    attr[0] = random() % 6 - 2;
    attr[1] = random();
    attr[2] = 0;
    attr[3] = 10;
    attr[4] = 0;
    attr[5] = 3;
}
pigeon::pigeon()
{
}
pigeon::~pigeon()
{
}
bool pigeon::bungle() //Does the animal just do something else
{
}
int pigeon::round() //Per round calculations
{
}
bool pigeon::recover() //Does the animal get back on track
{
}

bool pigeon::display(vector<pigeon> & list, max,i)
{
    if (list.empty()) return false;
    i += display();
    if (i == max) return true;
    return list[i].display(list,max,i);
}

