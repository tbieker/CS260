//Author: Tyler Bieker
//Class: CS 260
//Assignment: Lab 5
//Date: 05/23/2016
//Sources: None

#include "clist.h"

// Write your functions in this file.

//iterative functions
int count(node * head){
    int count = 1;
    node * curr = head;

    while(curr->next != head){
        count++;
        curr = curr->next;
    }
    return count;
}

int sum(node * head){
    int result = 0;
    node * curr = head;
    result = curr->data;

    while(curr->next != head){
        curr = curr->next;
        result = result + curr->data;
    }
    return result;
}

//recursive functions
int countR(node * head){
    node * curr;
    curr = head;
    return recursiveCount(head, curr);
}

int recursiveCount(node * head, node * curr){
    int count = 0;
    if(curr->next != head){
        count = 1 + recursiveCount(head, curr->next);
        return count;
    }else{
        return 1;
    }
}

int sumR(node * head){
    int result;
    node * curr = head;
    result = recursiveSum(head, curr);
    return result;
}

int recursiveSum(node * head, node * curr){
    int result;
    if(curr->next != head){
        result = curr->data + recursiveSum(head, curr->next);
        return result;
    }
    else{
        result = curr->data;
        return result;
    }
}
