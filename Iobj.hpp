//
//  Iobj.hpp
//  Io2.1
//
//  Created by Дмитрий Маслюков on 09/02/2019.
//  Copyright © 2019 Дмитрий Маслюков. All rights reserved.
//

#ifndef Iobj_hpp
#define Iobj_hpp

#include <stdio.h>
#include<cstdlib>
#include<cstring>
#include<string>

#define typescount 7


class Iobj{
public:
    class types{
    public:
        /*все структуры должны иметь статическими методами с аргументом object*self все апи-функции (описаны в iotype.h)*/
        struct object;
        struct number;
        struct string;
        struct list;
        struct dict;
        struct iobool;
        struct func;
        /*будет реализован позже*/
        struct slice;
        struct type;
    };
private:
    types::object*ptr;

};

#define IOHEAD int refcnt; const type* typeref;


/*Все объекты содержат IOHEAD для того, чтобы корректно разыменовываться как object,
 хотя, вообще говоря, они занимают больше места*/

struct Iobj::types::object{
    IOHEAD;
    void decref();
};


#endif /* Iobj_hpp */
