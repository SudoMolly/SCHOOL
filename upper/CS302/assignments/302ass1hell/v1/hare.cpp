int make_sea(vector<hare> & h,int max, int i)
{
    char * tempc;
    string temps;
    if(!case1_strings(temps,tempc)) exit(__LINE__);
    h.emplace(i,temps,tempc);
    ++i;
    ~strcpy2(tempc);
    if (i == max) return i;
    return (make_hare(h,max,i));
}

int make_tortoise(&t, int max, int i)
{
    char * tempc;
    string temps;
    if(!case1_strings(temps,tempc)) exit(__LINE__);
    t.emplace(i,temps,tempc);
    ++i;
    ~strcpy2(tempc);
    if (i == max) return i;
    return (make_tortoise(t,max,i));
}

int make_pigeon(vector<pigeon> &p, int max, int i)
{
    char * tempc;
    string temps;
    if(!case1_strings(temps,tempc)) exit(__LINE__);
    p.emplace(i,temps,tempc);
    ++i;
    ~strcpy2(tempc);
    if (i == max) return i;
    return (make_pigeon(p,max,i));
}

