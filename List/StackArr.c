//
// Created by muyou on 2022/9/22.
//
#include "stdio.h"
#include "stdlib.h"

#ifndef _Stack_H
struct StackRecord;
typedef struct StackRecord *Stack;
typedef int ElementType;
#define EmptyTos (-1)
#define MinStackSize (5)

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElement);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);

#endif /*_Stack_h*/



struct StackRecord {
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

Stack CreateStack(int MaxElement) {
    Stack S;
    if(MaxElement < MinStackSize)
        printf("Error! Stack Size Is Too Small!");

    S = malloc(sizeof(struct StackRecord));
    S->Array = malloc(sizeof(ElementType) * MaxElement);
    S->Capacity = MaxElement;
    MakeEmpty(S);
    return S;
}

int IsEmpty(Stack S) {
    return S->TopOfStack == EmptyTos;
}

void MakeEmpty(Stack S) {
    S->TopOfStack = EmptyTos;
}

void Push(ElementType X, Stack S) {
    if (!IsFull(S))
        S->Array[++S->TopOfStack] = X;
    else
        printf("Error! Stack is full!");
}

ElementType Top(Stack S) {
    if (!IsEmpty(S))
        return S->Array[S->TopOfStack];

    printf("Error! Stack is empty!");
    return 0;
}

void Pop(Stack S) {
    if (!IsEmpty(S))
        S->TopOfStack--;
    else
        printf("Error! Stack is empty!");
}

ElementType TopAndPop(Stack S) {
    if (!IsEmpty(S))
        return S->Array[S->TopOfStack--];
    printf("Error! Empty Stack!");
    return 0;
}

void DisposeStack(Stack S) {
    if (S != NULL) {
        free(S->Array);
        free(S);
    }
}

int IsFull(Stack S) {
    return S->TopOfStack == S->Capacity;
}

