//
//  number.cpp
//  iolang+
//
//  Created by Дмитрий Маслюков on 16/03/2019.
//  Copyright © 2019 Дмитрий Маслюков. All rights reserved.
//

#include "iobject.hpp"
#include "bytenode.cpp"

void plus(stack&st, int n){
    object*first = st.pop();
    object*second = st.pop();
    object*res = first->type->arithmetics[0](first, second);
    st.push(res);
}
namespace ionum {
    object* alloc();
    void destroy(object*);
    object* plus(object*, object*);
    object* minus(object*, object*);
    object* mult(object*, object*);
    object* div(object*, object*);
};
const ob_type numtype{
    .allocator = &ionum::alloc,
    .destructor = &ionum::destroy,
    .arithmetics = {
        &ionum::plus,
        &ionum::minus,
        &ionum::mult,
        &ionum::div
    }
};

