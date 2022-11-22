//
// Created by muyou on 2022/9/27.
//
#include "stdio.h"
#include "stdlib.h"

#ifndef _Queue_H_
struct Node;
struct QueueRecord;
typedef struct Node *PtrToNode;
typedef PtrToNode LNode;
typedef int ElementType;
typedef struct QueueRecord *Queue;

int IsEmpty(Queue Q);

void CreateQueue(Queue Q);

void DisposeQueue(Queue Q);

void MakeEmpty(Queue Q);

void Enqueue(ElementType element, Queue Q);

ElementType Front(Queue Q);

void Dequeue(Queue Q);

void FrontAndDequeue(Queue Q, ElementType *element);

#endif
struct QueueRecord{
    LNode Front;
    LNode Rear;
};
struct Node {
    ElementType element;
    LNode next;
};

int IsEmpty(Queue Q) {
    return Q->Front == Q->Rear;
}

void CreateQueue(Queue Q) {
    Q->Front = malloc(sizeof(struct Node));
    Q->Rear = Q->Front;
    Q->Front->next = NULL;
    MakeEmpty(Q);
}

void MakeEmpty(Queue Q) {
    while (!IsEmpty(Q))
        Dequeue(Q);
}

void Enqueue(ElementType element, Queue Q) {
    LNode Tmp = malloc(sizeof(struct Node));
    Tmp->next = NULL;
    Tmp->element = element;
    Q->Rear->next = Tmp;
    Q->Rear = Tmp;
}

void Dequeue(Queue Q) {
    if (IsEmpty(Q))
        printf("Error!");
    else {
        LNode q = Q->Front->next;
        Q->Front->next = q->next;
        if (Q->Rear == q)
            Q->Rear = Q->Front;
        free(q);
    }
}

void FrontAndDequeue(Queue Q, ElementType *element) {
    if (IsEmpty(Q))
        printf("Error!");
    else {
        LNode q = Q->Front->next;
        *element = q->element;
        Q->Front->next = q->next;
        if (Q->Rear == q)
            Q->Rear = Q->Front;
        free(q);
    }
}

void DisposeQueue(Queue Q) {
    while (Q->Front) {
        Q->Rear = Q->Front->next;
        free(Q->Front);
        Q->Front = Q->Rear;
    }
}

ElementType Front(Queue Q) {
    return Q->Front->next->element;
}