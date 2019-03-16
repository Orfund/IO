//
//  iobject.hpp
//  iolang+
//
//  Created by Дмитрий Маслюков on 10/03/2019.
//  Copyright © 2019 Дмитрий Маслюков. All rights reserved.
//

#ifndef iobject_hpp
#define iobject_hpp

#include <stdio.h>
#include <cstdlib>
#include <string>

struct ob_type;
#define IoHEAD int refcnt; const ob_type*type;
#define iosize unsigned int
struct object {
    IoHEAD
};
#define darg object*first, object*second
#define sarg object*self



#endif /* iobject_hpp */
