//
//  bytenode.cpp
//  iolang+
//
//  Created by Дмитрий Маслюков on 15/03/2019.
//  Copyright © 2019 Дмитрий Маслюков. All rights reserved.
//
#ifndef IOBYTECODE
#define IOBYTECODE
#include <cstdlib>
#include "iobject.hpp"
class stack{
    struct node{
        object*val;
        node*next;
    };
    node*head;
public:
    stack(){
        head = nullptr;
    }
    stack(const stack& Other)=delete;
    stack(stack&&Other){
        head = Other.head;
        Other.head = nullptr;
    }
    object*& top(){
        return head->val;
    }
    void push(object*ob){
        node*nod = new node();
        nod->next = head;
        nod->val = ob;
        head = nod;
    }
    object* pop(){
        object*ob;
        node*nd = head->next;
        ob = head->val;
        delete head;
        head = nd;
        return ob;
    }
    ~stack(){
        node*buf;
        while(head!=nullptr){
            buf = head->next;
            delete head;
            head = buf;
        }
    }
};

struct action{
    void(*apifun)(stack&, int);
    int arg;
};
#endif
