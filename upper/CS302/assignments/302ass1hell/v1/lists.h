
namespace LISTS
{
    class CLL
    {
        public:
            CLL();
            CLL(vector<tortoise> &t);
            CLL(vector<hare> &h);
            CLL(vector<pigeon> &p);

            ~CLL();
            class node
            {
                public:
                    node();
                    ~node();
                    bool next();

                private:
                    node * next;
                    int obstacle;
                    int node_num;
            };

            int build();
            int obstacle1(bool *&here);
            int obstacle2(bool *&here);
            int obstacle3(bool *&here);



        private:
            vector<auto> animals;
            array * list;
            node * rear;
    };

    class LLL
    {
        public:
            LLL(vector<tortoise> &t);
            ~LLL();
            class node
            {
                public:
                    int build(vector<tortoise> &t);
                    node();
                    ~node();
                private:
                    node * next;
                    string name;
                    string animal;
            };
        private:
            node * head;
    };
}






