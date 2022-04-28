//
// Created by Iluha on 28.04.2022.
//

#include <iostream>
#include "list.h"

list::list() {
    this->head = nullptr;
    this->tail = nullptr;
}

list::~list() {
    node* current = head->next;

    while (current != nullptr) {
        node* next = current->next;
        delete current;
        current = next;
    }
}

void list::push(int value) {
    node* newNode = new node;
    newNode->index = value;

    if (this->head == nullptr) {
        this->head = newNode;
        this->tail = newNode;
    } else {
        this->tail->next = newNode;
        this->tail = newNode;
    }

    this->tail->next = nullptr;
}

void list::print() {
    node* current = this->head;

    while (current != nullptr) {
        std::cout << current->index << " ";
        current = current->next;
    }
}

