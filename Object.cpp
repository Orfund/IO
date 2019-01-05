//
//  Object.cpp
//  IO Framework
//
//  Created by Дмитрий Маслюков on 04/01/2019.
//  Copyright © 2019 Дмитрий Маслюков. All rights reserved.
//
#include"types.h"
#include<memory.h>
#include<stdlib.h>
#include<stdio.h>
#define NUMTYPE double
#define foreach(name, coll) for(Iobj*name = coll.begin();name!=coll.end();++name)
#define var(name) Iobj name = Iobj()

class Iobj{
protected:
    size_t ptrsize;
    int len;
    int type;
    void*contents;
    
    void mkcoll(int nl){ //подходит тупо для всего
        type = IOCOLL;
        if(nl*sizeof(Iobj)>ptrsize)
            contents = realloc(contents, nl*sizeof(Iobj));
        ptrsize = nl*sizeof(Iobj);
        for(int i = len ; i< nl; i++){
            ((Iobj*)contents+i)->simpleini();
        }
        len = nl;
    }
    
    void simpleini(){
        ptrsize = sizeof(NUMTYPE);
        type = IONUM;
        len = 0;
        contents = malloc(sizeof(NUMTYPE));
    }
    
    
    
    
public:
    Iobj(){
        simpleini();
    }
    
    Iobj& operator[](size_t ind){
        if(type!=IOCOLL)
            throw NON_COLL_ERR;
        return *((Iobj*)contents + ind%len);
    }
    
    void operator=(Iobj& Other){
        //must be initialized
        type = Other.type;
        if(type == IONUM || type == IOCHAR){
            memcpy(contents, Other.contents, ptrsize);
        }
        else{
            mkcoll(Other.len);
            for(int i = 0; i<len;i++)
                *((Iobj*)contents+i) = Other[i];
        }
    }
    
    
    
    void operator=(double d){
        if(type == IOCOLL){
            free(contents);
            simpleini();
        }
        *((NUMTYPE*)contents) = d;
    }
    
    void append(Iobj&Other){
        var(getcp);
        if(type!=IOCOLL){
            getcp = (*this);
            mkcoll(1);
            *((Iobj*)contents) = getcp;
        }
        getcp = Other;
        mkcoll(len+1);
        *((Iobj*)contents+len-1) = getcp;
        
    }
    
    void print(FILE*f = stdout){
        if(type == IONUM)
            fprintf(f, "%lf",  (*((NUMTYPE*)contents)));
        if(type == IOCHAR)
            fputc((*((char*)contents)), f);
        if(type == IOCOLL){
            fputc('[', f);
            for(int i = 0; i<len-1 ; i++){
                ((Iobj*)contents+i)->print();
                fprintf(f, ", ");
            }
            ((Iobj*)contents+len-1)->print();
            fputc(']',f);
        }
    }
    
    
};


