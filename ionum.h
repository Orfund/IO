//
//  ionum.h
//  Io2.1
//
//  Created by Дмитрий Маслюков on 14/02/2019.
//  Copyright © 2019 Дмитрий Маслюков. All rights reserved.
//

#ifndef ionum_h
#define ionum_h

struct Iobj::types::number{
    IOHEAD;
    double val;
    static object* alloc();
    static void destroy(object*);
};

const Iobj::types::type numtype{
    .allocator = &Iobj::types::number::alloc
};


#endif /* ionum_h */
