//
//  ioast.hpp
//  iolang+
//
//  Created by Дмитрий Маслюков on 15/03/2019.
//  Copyright © 2019 Дмитрий Маслюков. All rights reserved.
//

#ifndef ioast_hpp
#define ioast_hpp

#include <cstdlib>
#include "iobject.hpp"
struct astnode;
enum nodetype {
    IOLOCAL,
    IOCONSTANT,
    IOPARAM,
    IOBIN,
    IOUN,
    IOP,
    IOIF,
    IOCOMP
};
struct ioif{
    astnode*condition;
    astnode*then;
    astnode*ioelse;
};
struct iocomp {
    int number;
    astnode*exprs;
};
struct astbinfunc{
    astnode*first;
    astnode*second;
    object*(*binaryfunc)(object*, object*);
};

struct astunfunc{
    astnode*arg;
    object*(*unaryfunc)(object*);
};
struct astop{
    astnode*fisrt;
    astnode*second;
    object*(*ioperator)(object*, object*);
};
struct astnode {
    nodetype type;
    union elem{
        int loc;
        int con;
        int par;
        astbinfunc*astbinfunction;
        astunfunc*astunaryfunction;
        astop*astoperator;
        ioif*ifcondition;
        iocomp*iocompound;
    };
};

#endif /* ioast_hpp */
