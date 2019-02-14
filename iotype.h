//
//  iotype.h
//  Io2.1
//
//  Created by Дмитрий Маслюков on 14/02/2019.
//  Copyright © 2019 Дмитрий Маслюков. All rights reserved.
//

#ifndef iotype_h
#define iotype_h
#include "Iobj.hpp"

#define double_arged object*, object*

struct Iobj::types::type{
    //константные объекты, которые не референсируются
    object*(*allocator)();
    void (*destructor)(object*);
    object* (*atindex)(object*, const size_t);
    // может, все-таки object*&?
    object* (*atstr)(object*, const char*);
    void (*append)(double_arged);
    void (*concat)(double_arged);
    void (*remove)(double_arged);
    void (*insert)(double_arged, const double);
    void (*pop)(object*, const double);
    object* (*copyfunc)(object*);
    
    
    /*следующие функции зависят от типа обоих аргументов, typescount - константа, отвечающая за число активных типов*/
    object* (*plusfunc[typescount])(double_arged);
    object* (*minusfunc[typescount])(double_arged);
    object* (*multfunc[typescount])(double_arged);
    object* (*divfunc[typescount])(double_arged);
    object* (*modulusfunc[typescount])(double_arged);
    object* (*andfunc[typescount])(double_arged);
    object* (*orfunc[typescount])(double_arged);
    object* (*xorfunc[typescount])(double_arged);
    /* ... */
    object*(*invertfunc)(object*);
    std::string (*serfunc)(object*);
    object* (*deserfunc)(const char*);
    object* (*keysfunc)(object*);
    object* (*executefunc)(double_arged);
    
    
};


#endif /* iotype_h */
