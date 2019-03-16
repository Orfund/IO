//
//  iobject.cpp
//  iolang+
//
//  Created by Дмитрий Маслюков on 10/03/2019.
//  Copyright © 2019 Дмитрий Маслюков. All rights reserved.
//

#include "iobject.hpp"
#include "bytenode.cpp"
#include "ioast.cpp"
struct ob_type{
    const char*name;
    object*(*allocator)();
    void(*destructor)(object*);
    object*(*arithmetics[4])(object*, object*);
    object*(*assign)(object*, object*); //returns always nullptr
    object*(*len)(object*);
    object*(*atindex)(object*, object*); //object*& ?
    object*(*atname)(object*, object*);
    object*(*executefunc)(object*, object*);//???
    object*(*logics[4])(object*, object*); //and or xor not
    object*(*append)(object*, object*);
    std::string (*tostr)(object*);
};

struct number:public object{
    double val;
};

struct string:public object{
    bool isshort;
    union str{
        char shortstr[20];
        const char* longstr;
    };
};

struct list:public object{
    object**elems;
    iosize itemc;
    iosize cap;
};

struct boolean:public object{
    bool val;
};

struct tuple:public object{
    iosize itemc;
    object**elems;
};

struct instance:public object{
    iosize itemc;
    iosize cap;
    struct member{
        char name[20];
        object*val;
    };
    member*members;
};

struct iofunc:public object{
    iosize varc;
    iosize paramc;
    iosize constc;
    iosize actionc;
    object**constants;
    
    
    action*actions;
};
