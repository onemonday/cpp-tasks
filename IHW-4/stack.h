//
// Created by karak on 5/18/2022.
//

#ifndef CPP_TASKS_STACK_H
#define CPP_TASKS_STACK_H

struct node {
    unsigned int number;
    node* next;
};


class stack {
private:
    node* head;
public:
    stack();
    void push(unsigned int number);
    unsigned int pop();
    unsigned int peep();

    bool isEmpty();
};


#endif //CPP_TASKS_STACK_H
