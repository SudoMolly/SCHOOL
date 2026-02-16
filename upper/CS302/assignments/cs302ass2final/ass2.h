//Molly diaz , modiaz@pdx.edu , CS302 In-person assignment 2

/* Assignment 2, Templates & classes */
//Purpose: To use a template class to better use a class hierarchy

/* Header file */
//Purpose: To define and facilitate the class that interacts with the
//         main template of the assignment.
//


//NOTE: THIS IS IN A FAIRLY UNFINISHED STATE (despite my best efforts) and does
//only have BASIC functionality. It can create and display each class, but
//cannot do much else, there's also a lot of bizarre redefinitions throughout, 
//truth be told it just sucks, so please let me know any areas that stand out
//as exceptionally bad, I want to get better :/.
//-----------------------------Preprocessor-----------------------------------//

#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <stdexcept>

#include <cstddef>
#include <iterator>
#include <list>
#include <forward_list>
#include <array>
#include <algorithm>


//-------------------------------Classes--------------------------------------//

//To be implemented in template
namespace demail //demail
{
    using namespace std;

    template <class TYPE>
    class node;

    template <class TYPE>
    class RAiterator;

    template <class TYPE>
    class dll;

    //FRIENDS

    //NODE-----------------------------------------------------------------//

    //template <class TYPE>
    //ostream& display_all(ostream& o, node<TYPE>& curr);

    //template <class TYPE>
    //ostream& operator<<(ostream & o,node<TYPE> & copy_sent);

    template <class TYPE>
    bool operator==(const node<TYPE>&, const node<TYPE>&);

    template <class TYPE>
    bool operator!=(const node<TYPE>& A, const node<TYPE> & B);

    template <class TYPE>
    bool operator<(const node<TYPE>& A, const node<TYPE> & B);

    template <class TYPE>
    bool operator>(const node<TYPE>& A, const node<TYPE> & B);

    template <class TYPE>
    bool operator<=(const node<TYPE>& A, const node<TYPE> & B);

    template <class TYPE>
    bool operator>=(const node<TYPE>& A, const node<TYPE> & B);


    //ITERATOR-------------------------------------------------------------//
    template <class TYPE>
    bool operator==(const RAiterator<TYPE> & other1, const RAiterator<TYPE>  & other2);

    template <class TYPE>
    bool operator!=(const RAiterator<TYPE>  & other1, const RAiterator<TYPE>  & other2);

    template <class TYPE>
    bool operator<(const RAiterator<TYPE>  & other1, const RAiterator<TYPE>  & other2);

    template <class TYPE>
    bool operator>(const RAiterator<TYPE>  & other1, const RAiterator<TYPE>  & other2);

    template <class TYPE>
    bool operator<=(const RAiterator<TYPE>  & other1, const RAiterator<TYPE>  & other2);

    template <class TYPE>
    bool operator>=(const RAiterator<TYPE>  & other1, const RAiterator<TYPE>  & other2);


    //DLL--------------------------------------------------//
    template <class TYPE>
    dll<TYPE> operator+(const dll<TYPE>& , const TYPE&);

    template <class TYPE>
    dll<TYPE> operator+(const TYPE&, const dll<TYPE>&);

    template <class TYPE>
    dll<TYPE> operator+(const dll<TYPE>&, const dll<TYPE>&);

    /*
    namespace annoyances
    {
        template <class TYPE>
        ostream& operator<<(ostream & o, dll<TYPE> & from);
        
        template <class TYPE>
        ostream& display_one(ostream& o, dll<TYPE> & from, int n);
    };
    */

    template <class TYPE>
    class node
    {
        public:
            node();
            node(node*&);
            node(TYPE &);
            node(TYPE&,node*&);
            TYPE& give_priority();
            node*& get_next();
            node*& get_prev();
            node*& get_next(int n);
            node*& get_prev(int n);
            node*& set_next(TYPE&, node*& prev);
            //int set_prev();
            //void display_all(ostream& o, node<TYPE> *& curr);

            ostream& display_node(ostream& o);
            //ostream& operator<<(ostream & o);
            friend bool operator== <>(const node<TYPE>&, const node<TYPE>&);
            friend bool operator!= <>(const node<TYPE>& A, const node<TYPE> & B);
            friend bool operator< <>(const node<TYPE>&,const node<TYPE>&);
            friend bool operator> <>(const node<TYPE>&,const node<TYPE>&);
            friend bool operator<= <>(const node<TYPE>&,const node<TYPE>&);
            friend bool operator>= <>(const node<TYPE>&,const node<TYPE>&);
            node*& append(node*& nxt);
            int insert(TYPE & DATA_PASSED);
        private:
            int num;
            node<TYPE> * next;
            node<TYPE> * prev;
            TYPE DATA;
    };


    template <class TYPE>
    class dll //doubly linked list
    {
        public:
            dll();
            dll(const dll &);

            friend dll<TYPE> operator+ <>(const dll<TYPE>& , const TYPE&);
            friend dll<TYPE> operator+ <>(const TYPE&, const dll<TYPE>&);
            friend dll<TYPE> operator+ <>(const dll<TYPE>&, const dll<TYPE>&);
            //friend ostream& annoyances::operator<< <>(ostream & o, dll<TYPE> & from);
            ostream& display_one(ostream&, int n);
            int display_all(ostream&,node<TYPE>*&);
            //friend ostream& display_all<>(ostream&, node<TYPE>&);
            dll& operator=(const dll<TYPE> &);
            dll& operator+=(const dll<TYPE> &);
            dll& operator+=(const TYPE &);
            //int sort();
            int insert(TYPE & DATA);
            node<TYPE>*& traverse(int n);
            node<TYPE>*& traverse();
            ~dll();
        protected:
            RAiterator<class node<TYPE>> it;
            //ostream_iterator<class node<TYPE>> oit;
            node<TYPE> * head;
            node<TYPE> * tail;
            int size;

    };

    template <class TYPE>
    class RAiterator
    {
        using iterator_category = random_access_iterator_tag;
        using difference_type = ptrdiff_t;
        using value_type = TYPE;
        using pointer = TYPE*;
        using reference = TYPE&;

        public:
            //Constructors
            RAiterator();
            RAiterator(pointer start);
            RAiterator(RAiterator & from);
            RAiterator(pointer fromC,pointer fromH,pointer fromT,pointer fromN,pointer fromP);

            //Assignment
            RAiterator& operator=(RAiterator & from);
            RAiterator& operator+=(int offset);
            RAiterator& operator-=(int offset);

            //Access
            pointer operator*() const;
            reference operator->();
            reference operator[](int offset);

            //Iterator
            RAiterator& operator++();
            RAiterator operator++(int);
            RAiterator& operator--();
            RAiterator operator--(int);

            //Arithmetic
            RAiterator operator+(int offset) const;
            RAiterator operator-(int offset) const;

            //Comparisons

            friend bool operator== <>(const RAiterator<TYPE> & other1, const RAiterator<TYPE> & other2);

            friend bool operator!= <>(const RAiterator<TYPE> & other1, const RAiterator<TYPE> & other2);

            friend bool operator< <>(const RAiterator<TYPE> & other1, const RAiterator<TYPE> & other2);

            friend bool operator> <>(const RAiterator<TYPE> & other1, const RAiterator<TYPE> & other2);

            friend bool operator<= <>(const RAiterator<TYPE> & other1, const RAiterator<TYPE> & other2);

            friend bool operator>= <>(const RAiterator<TYPE> & other1, const RAiterator<TYPE> & other2);

            RAiterator begin()
            {
                return ihead;
            }

            RAiterator end()
            {
                return itail->get_next();
            }



        private:
            pointer icurr;
            pointer ihead;
            pointer itail;
            pointer inext;
            pointer iprev;
    };


    /*
    template <class TYPE>
    class main : public dll<TYPE>
    {
        public:
            main();
            main(bool build);
            int Register_domain(string & name);
            int Add_node(string & type);
            int Generate_Example();
            int build(int size, int current_type, int i);
        private:
    };
    */
};

namespace H //Hierarchy
{
    using namespace std;

    class base;
    class derivedP;
    class derivedB;
    class derivedY;
    //ostream& operator<<(ostream & o,const base & output);

    ostream& display_forwards(ostream& o, const derivedB & output);
    ostream& display_subs(ostream& o, const derivedB & output);

    //ostream& operator<<(ostream& o, derivedY output);
    //derivedY operator+(const derivedY & Y, const derivedP & P);
    //derivedY operator+(const derivedY & Y, const derivedB & B);
    //derivedY operator+(const derivedY & Y, const derivedY & Y2);
    class base
	{
    public: 
        base();
        base(const base&);
        base(int type);
        base(const char*,const string & e,const string & d, int ntype);
        base(const char*, int ntype);
        base& operator=(const base &);
        ostream& display_me(ostream & o);
        //ostream& operator<<(ostream & o);
        //friend ostream& display_recur(ostream & o, list<string>::iterator ei, list<string>::iterator di);
        //friend ostream& display_email(ostream & o,list<string>::iterator  ei);
        //friend ostream& display_domain(ostream & o, list<string>::iterator di);
        int add(const string *& item, int num, int type);
        char* dyn_copy(char*,const char*);
        char* clear_char(char*&);
        int get_type();
        ~base();
    protected:
        char * name;
        list<string> email;
        list<string> domain;
        int type; //0-P,1-B,2-Y
	};

    class derivedP : public base
    {
        public:
            derivedP();
            derivedP(const derivedP&);
            derivedP(const string& n, const string& e, const string& d);// : base(n,e,d), relation(nullptr);
            derivedP(const string& r, const string& n, const string& e, const string& d);// : base(n,e,d), relation(r);
            derivedP& operator=(const derivedP &);
            int change_relation(const string &);
            int change_relation(char*);
            ~derivedP();
        private:
            char * relation;
    };

    class derivedB : public base
    {
        public:
            derivedB();
            derivedB(const derivedB&);
            derivedB(const string& n, const string & e, const string & d);// : base(n,e,d);
            int add_forwards(const string *& emails, int num);
            int add_subdomains(const string *& subs_add, int num);
            int add_emails(const string*& emails, int num);
            friend ostream& display_forwards(ostream& o, const derivedB & output);
            friend ostream& display_subs(ostream& o, const derivedB & output);
            ~derivedB();
        private:
            list<forward_list<int>> emails;
            list<string> subs;
    };
        

    class derivedY : public base
    {
        public:
            derivedY(const char * name);// : base(name);
            derivedY();
            derivedY(const base& E);
            derivedY(const derivedP & P);
            derivedY(const derivedB & B);
            derivedY& operator=(const derivedP & P);
            derivedY& operator=(const derivedB & B);
            derivedY& operator=(const derivedY & Y);
            ostream& display_me(ostream&o);
            ostream& display_p(ostream& o, list<derivedP>::iterator & pi, list<derivedP> & p, int i);
            ostream& display_b(ostream& o, list<derivedB>::iterator & bi, list<derivedB> & b, int i);
            //friend ostream& operator<<(ostream& o, derivedY& output);
            friend derivedY operator+(const derivedY & Y, const derivedP & P);
            friend derivedY operator+(const derivedY & Y, const derivedB & B);
            friend derivedY operator+(const derivedY & Y, const derivedY & Y2);
            derivedY& operator+=(const derivedP & P);
            derivedY& operator+=(const derivedB & B);
            derivedY& operator+=(const derivedY & Y2);
            ~derivedY();
        private:
            list<derivedP> Plist;
            list<derivedB> Blist;
    };

};

class mainmen : public demail::dll<H::base>
{
    public:
        mainmen();
        int base_info(std::string& name, std::string& email, std::string& domain, int type);
        int main_loop();
        int menu();
        void build();
        std::string random(int);
        int generate(int curr_type,int i, int sent, int total);
        int sub_men(int option);
};



#include "demail.tpp"

