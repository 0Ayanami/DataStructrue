//
// Created by muyou on 2022/9/22.
//
#include "stdio.h"
#include "stdlib.h"

#ifndef _Stack_h
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef PtrToNode LNode;
typedef int ElementType;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X,Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

#endif /*_Stack_h*/
//栈的链表实现
struct Node{
    ElementType element;
    LNode Next;
};
int IsEmpty(Stack S){
    return S->Next==NULL;
}
Stack CreateStack(void){
    Stack stack = (Stack) malloc(sizeof (struct Node));
    stack->Next = NULL;
    MakeEmpty(stack);
    return stack;
}
void MakeEmpty(Stack S){
    while(!IsEmpty(S))
        Pop(S);
}
void Push(ElementType X,Stack S){
    LNode Tmp;
    Tmp=(LNode) malloc(sizeof (struct Node));
    Tmp->Next = S->Next;
    S->Next = Tmp;
    Tmp->element = X;
}
ElementType Top(Stack S){
    if(!IsEmpty(S))
        return S->Next->element;
    else
        return 0;
}
void Pop(Stack S){
    LNode First;
    First = S->Next;
    S->Next = First ->Next;
    free(First);
}
void DisposeStack(Stack S){
    MakeEmpty(S);
    free(S);
}