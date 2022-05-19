//
// Created by karak on 5/18/2022.
//

#include "stack.h"

stack::stack() {
    this->head->next = nullptr;
}

void stack::push(unsigned int number) {
    node* newNode = new node;
    newNode->number = number;

    newNode->next = this->head;
    this->head = newNode;
}

unsigned int stack::pop() {
    unsigned int result = this->head->number;
    node * shallBeDeleted = this->head;
    if (this->head->next == nullptr)
        this->head = nullptr;
    else
        this->head = this->head->next;

    delete shallBeDeleted;

    return result;
}

unsigned int stack::peep() {
    return this->head->number;
}
