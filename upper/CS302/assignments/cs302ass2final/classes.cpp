#include "ass2.h"
using namespace std;
using namespace H;

char * base::dyn_copy(char* b,const char* a)
{
    b = new char[strlen(a) + 1];
    strcpy(b,a);
    return b;
}

base::base() : name(nullptr), type(-1){}

base::base(const base& from) : name(dyn_copy(name = nullptr,from.name)), email(from.email),domain(from.domain),type(from.type)
{}

base::base(int ntype) : type(ntype) 
{}

base::base(const char * n, const string & e, const string & d, int ntype) : type(ntype)
{
    name = new char[strlen(n) + 1];
    strcpy(name,n);
    email.push_back(e);
    domain.push_back(d);
}

base::base(const char*n, int ntype) : name(dyn_copy(clear_char(name),n)), type(ntype)
{}

base& base::operator=(const base & src) 
{

    dyn_copy(clear_char(name),src.name);
    email = src.email;
    domain = src.domain;
    type = src.type;
    return *this;
}

/*ostream& base::display(ostream & o)
{

}*/

ostream& base::display_me(ostream & o)
{
    if (!name)
    {
        o << "No Registration Exists" << endl;
        return o;
    }
    o << "Name: " << name << endl;
    o << "-------" << endl;
    o << "Emails: " << endl;
    copy(email.begin(),email.end(),ostream_iterator<string>(o,"\n"));
    o << "-------" << endl;
    o << "Domains: " << endl;
    copy(domain.begin(),domain.end(),ostream_iterator<string>(o,"\n"));
    return o;
}
/*
ostream& base::operator<<(ostream & o)
{
    if (!name)
    {
        o << "No Registration Exists" << endl;
        return o;
    }
    o << "Name: " << name << endl;
    o << "-------" << endl;
    o << "Emails: " << endl;
    copy(email.begin(),email.end(),ostream_iterator<string>(o,"\n"));
    o << "-------" << endl;
    o << "Domains: " << endl;
    copy(domain.begin(),domain.end(),ostream_iterator<string>(o,"\n"));
    return o;
}
*/
/*
ostream& display_recur(ostream & o, list<string>::iterator ei, list<string>::iterator di)
{
    if (ei == 0 && di == 0) return o;
    else if (ei ==0 || di == 0)
    {
        if (ei == 0)
        {
            o = display_recur(o, ei,--di);
            return display_domain(o, di);
        }
        else
        {
            o = display_recur(o, --ei,di);
            return display_email(o, ei);
        }
    }
    o = display_recur(o, --ei,--di);
    o = display_domain(o, di);
    return display_email(o, ei);
}

ostream& display_email(ostream & o,list<string>::iterator i)
{
    o << "Email #" << static_cast<int>(i) << ": " << i << endl;
    return o;
}

ostream& display_domain(ostream &o, list<string>::iterator i)
{
    o << "Domain #" << static_cast<int>(i) << ": " << i << endl;
    return o;
}
*/
int base::add(const string *& item,int num, int numtype)
{
    if (num == 0) return num;

    if (numtype == 0)
    {
        int count = add(item,--num,numtype);
        email.push_back(*(item + count));
        return count + 1;
    }

    int count = add(item,--num,numtype);
    domain.push_back(*(item + count));
    return count + 1;

}


char * base::clear_char(char *& e)
{
    delete [] e;
    e = nullptr;
    return e;
}

int base::get_type()
{
    return type;
}

base::~base()
{
    name = clear_char(name);
    email.clear();
    domain.clear();
}

//-----------------------------------------------Personal---------------------------//

derivedP::derivedP() : base(0), relation(nullptr) {}
//derivedP::derivedP(derivedP& from) : base(from.name,from.email,from.domain, from.type), relation(dyn_copy(relation,from.relation))
//{}
derivedP::derivedP(const derivedP& from) : base(from), relation(dyn_copy(relation,from.relation))
{}
derivedP::derivedP(const string& n, const string & e,const string & d) : base(n.c_str(),e,d,0), relation(nullptr) {}
derivedP::derivedP(const string& r, const string& n, const string & e,const string & d) : base(n.c_str(),e,d,0), relation(dyn_copy(relation,r.c_str())) {}

derivedP& derivedP::operator=(const derivedP & src) 
{
    base::operator=(src);
    dyn_copy(clear_char(relation),src.relation);
    return *this;
}

int derivedP::change_relation(const string & new_rel)
{
    relation = dyn_copy(clear_char(relation),new_rel.c_str());
    return strcmp(new_rel.c_str(),relation) == 0 ? 1 : 0;
}

int derivedP::change_relation(char* new_rel)
{
    relation = dyn_copy(clear_char(relation),new_rel);
    return strcmp(new_rel,relation) == 0 ? 1 : 0;
}

derivedP::~derivedP()
{
    relation = clear_char(relation);
}

//---------------------------------------Business--------------------------------------//

derivedB::derivedB() : base(1)
{}

derivedB::derivedB(const derivedB & from) : base(from), emails(from.emails), subs(from.subs)
{}
//HElP
derivedB::derivedB(const string& n, const string & e, const string & d) : base(n.c_str(),e,d,1)
{
   forward_list<int> fl;
   fl.push_front(1);
   emails.push_back(fl);
}

//HELP
//implement for more than one (all 3 below)
int derivedB::add_forwards(const string *& mail, int num)
{
    if (num < 1) return 0;
    forward_list<int> new_list;
    emails.push_back(new_list);
    return add(mail,1,0);
}

int derivedB::add_subdomains(const string *& nsubs,int num)
{
    if (num < 1) return 0;
    int count = add_subdomains(nsubs,--num);
    subs.push_back(*(nsubs + num));
    return count + 1;
}

int derivedB::add_emails(const string *& emails,int num)
{
    if (num < 1 || emails == nullptr) return 0;
    return add(emails,num,1);
}
//HELP-----------------------------------------------
/*
ostream& derivedB::display_forwards(ostream& o, const derivedB & output)
{

}

int derivedB::display_forwards_recur(ostream & o,list<forward_list<int>>::iterator ei, int forward_list<int>::iterator fi)
{
    if (fi <= 0) return 0;
    int recur_fi = display_forwards_recur(o,ei,--fi);
    if (fi == 0)
        o << "Forwards for email " << ei << ": " << endl;
    o << "Forward #" << fi << ":" << emails
ostream& derivedB::display_subs(ostream& o, const derivedB & output);

int derivedB::display_subs_recur();
*/

derivedB::~derivedB()
{
    emails.clear();
    subs.clear();
}

//--------------------------------------------Priority------------------------------//

derivedY::derivedY(const char*name) : base(name,2)
{}

derivedY::derivedY(const base& from) : base(from)
{}
derivedY::derivedY() : base(2)
{}

derivedY::derivedY(const derivedP & P) : base(P)
{
    Plist.push_back(P);
}

derivedY::derivedY(const derivedB & B) : base(B)
{
    Blist.push_back(B);
}

ostream& derivedY::display_me(ostream& o)
{

    cout << "\nPriority List!\n" << endl;
    list<derivedP>::iterator pi;
    pi = Plist.begin();
    o << "Personals list: " << endl;
    o << "----------------" << endl;
    display_p(o,pi,Plist,1);


    list<derivedB>::iterator bi;
    bi = Blist.begin();
    o << "Businesses list:" << endl;
    o << "----------------" << endl;
    display_b(o,bi,Blist,1);
    return o;
}

ostream& derivedY::display_p(ostream& o, list<derivedP>::iterator & pi, list<derivedP> & p, int i)
{
    if (pi == p.end())
        return o;

    o << "Personal entry #" << i << ":" << endl;
    pi->display_me(o);
    return display_p(o,++pi,p,++i);
}

ostream& derivedY::display_b(ostream& o, list<derivedB>::iterator & bi, list<derivedB> & b, int i)
{
    if (bi == b.end())
        return o;

    o << "Personal entry #" << i << ":" << endl;
    bi->display_me(o);
    return display_b(o,++bi,b,++i);
}
/*
ostream& operator<<(ostream& o,derivedY & output)
{
    for_each(output.Plist.begin(),output.Plist.end(),output.base::operator<<(o));
    for_each(output.Blist.begin(),output.Blist.end(),output.base::operator<<(o));
    return o;
}
*/

derivedY& derivedY::operator=(const derivedP & P)
{
    base::operator=(P);
    Plist.clear();
    Plist.push_back(P);
    return *this;
}

derivedY& derivedY::operator=(const derivedB & B)
{
    base::operator=(B);
    Blist.clear();
    Blist.push_back(B);
    return *this;
}

derivedY& derivedY::operator=(const derivedY & Y)
{
    if (this != &Y) {
        base::operator=(Y);
        Plist = Y.Plist;
        Blist = Y.Blist;
    }
    return *this;
}

derivedY operator+(const derivedY & Y, const derivedP & P)
{
    derivedY result(Y);
    result += P;
    return result;
}

derivedY operator+(const derivedY & Y, const derivedB & B)
{
    derivedY result(Y);
    result += B;
    return result;
}

derivedY operator+(const derivedY & Y1, const derivedY & Y2)
{
    derivedY result(Y1);
    result += Y2;
    return result;
}

derivedY& derivedY::operator+=(const derivedP & P)
{
    Plist.push_back(P);
    return *this;
}

derivedY& derivedY::operator+=(const derivedB & B)
{
    Blist.push_back(B);
    return *this;
}

derivedY& derivedY::operator+=(const derivedY & Y)
{
    Plist.insert(Plist.end(), Y.Plist.begin(), Y.Plist.end());
    Blist.insert(Blist.end(), Y.Blist.begin(), Y.Blist.end());
    return *this;
}
/*
int derivedY::copyP_in(list<derivedP>& src)
{
    Plist.insert(Plist.end(), src.begin(), src.end());
    return src.size();
}

int derivedY::copyB_in(list<derivedB>& src)
{
    Blist.insert(Blist.end(), src.begin(), src.end());
    return src.size();
}

//HELP
derivedY* derivedY::operator+(const derivedY & Y, const derivedY & Y2)
{
    derivedY new_copy(Y);
    int added {0};
    added = new_copy.copyB_in(Y2);
    added = new_copy.copyP_in(Y2) + added;
    return *new_copy;
}
derivedY& derivedY::operator+=(const derivedP & P)
{
    int added = P.copyP_in(this->Plist);
    return *this;
}
derivedY& derivedY::operator+=(const derivedB & B)
{
    int added = B.copyB_in(this->Blist);
    return *this;
}
//HELP

derivedY& derivedY::operator+=(const derivedY & Y)
{
    Y.copyP_in(this->Plist);
    Y.copyB_in(this->Blist);
    return *this;
}
*/
derivedY::~derivedY()
{
    Plist.clear();
    Blist.clear();
}
