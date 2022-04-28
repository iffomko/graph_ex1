//
// Created by Iluha on 28.04.2022.
//

#pragma once
#ifndef INC_28_04_2022_EX1__CLASSWORK__LIST_H
#define INC_28_04_2022_EX1__CLASSWORK__LIST_H

struct node {
    node* next;
    int index;
};

class list {
    node* head = nullptr;
    node* tail = nullptr;
public:
    list();
    ~list();
    void push(int value);
    void print();

    bool check(const int &item);
};


#endif //INC_28_04_2022_EX1__CLASSWORK__LIST_H
