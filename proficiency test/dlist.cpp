//Author: Tyler Bieker
//CS260 Programming proficiency test
//Date:06/09/2016

//dlist.cpp

#include "dlist.h"

int countEven(node * head){
    //recursively count even numbers in doubly
    //linked list
    int count = 0;
    if(head){
        int test;
        test = head->data % 2;
        if(test == 0){
            count = 1 + countEven(head->next);
        }else{
            count = countEven(head->next);
        }
    }
    return count;
}


int removeEven(node *& head){
    //recursively remove even numbers in doubly
    //linked list
    int count = 0;
    if(head){
        int test;
        test = head->data % 2;
        if(test == 0){
            count = 1 + removeEven(head->next);

            //if head is root of list
            if(head->previous == nullptr){
                node * temp = head;
                head = head->next;
                head->previous = nullptr;
                delete temp;
            }

            else{
                node * temp;
                temp = head;

                //tail of list
                if(head->next == nullptr){
                    head = head->previous;
                    head->next = nullptr;
                }

                else{
                    head->next->previous = head->previous;
                    head = head->next;
                }
                delete temp;
                temp = nullptr;
            }
        }else{
            count = removeEven(head->next);
        }
    }
    return count;

}
