//
//  numberimpl.cpp
//  iolang+
//
//  Created by Дмитрий Маслюков on 16/03/2019.
//  Copyright © 2019 Дмитрий Маслюков. All rights reserved.
//

#include "number.cpp"

object* ionum::alloc(){
    number*n = new number();
    n->val = 0;
    n->refcnt = 1;
    n->type = &numtype;
    return n;
}

object* ionum::plus(darg){
    number*n = (number*)ionum::alloc();
    n->val = ((number*)first)->val+((number*)second)->val;
    return n;
}
