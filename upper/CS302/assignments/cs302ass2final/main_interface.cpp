#include "ass2.h"
using namespace std;


mainmen::mainmen() : demail::dll<H::base>()
{
    cout << "Hello and welcome to the domain & email register." << endl;
    cout << "\n" << endl;
    cout << "Would you like to build an 'example' list? " << endl;
    cout << "choice(y/n): ";
    char chosen;
    cin >> chosen;
    cin.ignore(100,'\n');
    if (toupper(chosen) == 'Y')
        build();
    int runs = main_loop();
}

int mainmen::base_info(string& name, string& email, string& domain, int type)
{
    cout << "Name of Registree: " << endl;
    getline(cin,name);
    cout << "Contact email: " << endl;
    getline(cin,email);
    cout << "Domain name: " << endl;
    getline(cin,domain);
    return type;
}

int mainmen::sub_men(int option)
{
    int choice {0};
    switch (option)
    {
        case(1):
            {
                cout << "PERSONAL REGISTERS SUBMENU" << endl;
                cout << "--------------------------" << endl;
                cout << "1) Add Personal Register" << endl;
                cout << "2) Change Relation" << endl;
                cout << "3) Back to Main Menu" << endl;
                cout << "--------------------------" << endl;
                cout << "Input: ";
                cin >> choice;
                cin.ignore(100,'\n');
                if (choice > 3 || choice < 1)
                {
                    cout << "INVALID CHOICE, TRY AGAIN" << endl;
                    return sub_men(option);
                }
                break;
            }
        case(2):
            {
                cout << "BUSINESS REGISTERS SUBMENU" << endl;
                cout << "--------------------------" << endl;
                cout << "1) Add Business Register" << endl;
                cout << "2) Add Subdomain" << endl;
                cout << "3) Add forwarding email" << endl;
                cout << "4) Back to Main Menu" << endl;
                cout << "--------------------------" << endl;
                cin >> choice;
                cin.ignore(100,'\n');
                if (choice > 4 || choice < 1)
                {
                    cout << "INVALID CHOICE, TRY AGAIN" << endl;
                    return sub_men(option);
                }
                break;
            }
    }
    return choice;
}


int mainmen::main_loop()
{
    int choice = menu();
    int sub_choice {0};
    string name;
    string domain;
    string email;
    string relation;
    int type;

    switch(choice)
    {
        case(1||2):
            {
                sub_choice = sub_men(choice);
                if (choice == 1)
                {
                    switch (sub_choice)
                    {
                        case(1):
                            {       
                                type = base_info(name,domain,email,0);
                                cout << "Enter Personal Relationship with client: ";
                                getline(cin,relation);
                                H::derivedP personal(relation.c_str(),name.c_str(),domain,email);
                                insert(personal);
                                break;
                            }
                        case(2):
                            {
                                cout << "Enter Entry #" << "\n#: ";
                                cin >> type;
                                cin.ignore(100,'\n');
                                if (type > size) type = size - 1;
                                cout << "Enter New Relationship with client: "; 
                                getline(cin,relation);
                                //if ((traverse(type)->give_priority()).change_relation(relation) == 1)
                                 //   cout << "Relationship Successfully Changed" << endl;
                                //else
                                    cout << "Relationship Not Changed, Seek Assistance" << endl;
                            }
                    }
                }
                else
                {
                    switch(sub_choice)
                    {
                        case(1):
                            {
                                type = base_info(name,domain,email,1);
                                H::derivedB business(name.c_str(),domain,email);
                                insert(business);
                                break;
                            }
                        case(2):
                            {
                                cout << "Enter Entry #\n#: ";
                                cin >> type;
                                cin.ignore(100,'\n');
                                if (type > size) type = size - 1;
                                cout << "Enter new subdomain: ";
                                getline(cin,domain);
                                //if ((traverse(type)->give_priority()).add_subdomains(domain,1) == 1)
                                    //cout << "Subdomain added" << endl;
                                //else
                                    cout << "Subdomain not added :( " << endl;
                                break;
                            }
                        case(3):
                            {
                                cout << "Enter Entry #\n#: ";
                                cin >> type;
                                cin.ignore(100,'\n');
                                if (type > size) type = size - 1;
                                cout << "Enter new forwarding email: ";
                                getline(cin,email);
                                //if (traverse(type)->give_priority()).add_forwards(email,1) == 1)
                                 //   cout << "Forwarding email successfully added" << endl;
                                //else
                                    cout << "Forwarding email not added ;( " << endl;
                                break;
                            }
                    }
                }
                cout << "Exiting back to Main Menu" << endl;
                break;
            }
        case(3):{
                if (head == nullptr) 
                {
                    cout << "No registers found, cannot mark." << endl;
                    break;
                }
                cout << "Enter Name of Priority List: ";
                getline(cin,name);
                cout << "Enter Entry Number to be Marked Priority: ";
                cin >> type;
                H::derivedY priority((traverse(type)->give_priority()));
                insert(priority);
                break;
            }
        case(4):{
                cout << "Enter Entry Number to Display";
                cin >> type;
                display_one(cout,type);

                break;
            }
        case(5):{
                if (!head)
                    cout << "Nothing to display!" << endl;
                //copy(it.begin(), it.end(),oit(cout,"\n"));
                /*
                head->display_all(cout,(head)); //COULD NOT COMPILE ????? IDK! >:(
                */
                display_all(cout,head);
                break;
            }
        case(6):{
                return 0;
                break;
            }
    }
    return main_loop() + 1;
}

int mainmen::menu()
{
    cout << "\nMAIN MENU" << endl;
    cout << "-----------" << endl;
    cout << "1) Personal Registers" << endl;
    cout << "2) Business Registers" << endl;
    cout << "3) Mark Existing Registers as priority" << endl;
    cout << "4) Display a register" << endl;
    cout << "5) Display all registers" << endl;
    cout << "6) Quit" << endl;
    cout << "-----------" << endl;
    cout << "Choice: ";
    int chosen;
    cin >> chosen;
    if (chosen < 1 || chosen > 6)
    {
        cout << "INVALID SELECTION, TRY AGAIN" << endl;
        return menu();
    }
    else if (chosen == 6)
        cout << "Thank you and Goodbye!" << endl;
    return chosen;
}

void mainmen::build()
{
    srand(time(NULL));
    //Number of nodes
    int total = rand() % 11 + 1;
    total -= total % 3;
    if (total == 0) total = 3;
    //Acceptable range = 3, 6, 9
    int delta = total/3;

    int built = generate(0,0,delta,total);
    cout << "\n" << built << " nodes built." << endl;
}

string mainmen::random(int type)
{
    int choice = rand() % 10;

    array<string,3> relations = {"Close","Ambigious","Far"};

    array<string,10> names= {"Matt","Chris","Chrissy","Sophia","Ethan",
                             "Liam","Ava","Noah","Sam","Mr. NotlongName"};
    array<string,10> emails = {"reynolds@gmail.com","CC@hotmail.com",
                               "notaburner@cox.net","TheBest@temp.mail",
                               "NigerianPrince@hotmail.com","me@you.net",
                               "mrGoogle@gmail.com","love@wrongplaces.com",
                               "tip@your.tongue","notLongEmail@LongUrlsNotAllowed.net.us.com"};
    array<string,10> domains = {"verix.net","truvox.gov","zenith.io","solaris.space", "ragnarok.org"
                                "heaven.earth","dallas.texas","google.com","yahoo.yahooooooo", "longWebsiteNamesAreBadForYouDontYouKnow.web"};


    if (type == 0)
        return relations[choice % 3];
    else if (type == 1)
        return names[choice];
    else if (type == 2)
        return emails[choice];
    return domains[choice];
}
    
    

int mainmen::generate(int curr_type,int i, int sent, int total)
{
    if (i == total)
        return total;

    string name = random(1);
    string email = random(2);
    string domain = random(3);

    switch (curr_type)
    {
        case(0):
            {
                string rels = random(0);
                H::derivedP personal(rels,name,domain,email);
                insert(personal);
                break;
            }
        case(1):
            {
                H::derivedB business(name,domain,email);
                insert(business);
                break;
            }
        case(2):
            {
                H::derivedY priority((traverse(total - i))->give_priority());
                insert(priority);
                break;
            }
    }
    if (i % sent == 0 && i != 0)
        ++curr_type;
    return generate(curr_type,++i,sent,total);
}



