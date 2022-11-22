//
// Created by muyou on 2022/9/27.
//
#include "stdio.h"
#include "stdlib.h"

#ifndef _Queue_H_
struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef int ElementType;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElement);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType element, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q,ElementType *X);

#endif

#define MaxQueueSize (5)

struct QueueRecord {
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};
Queue CreateQueue(int MaxElement){
    Queue Q;
    Q = malloc(sizeof (struct QueueRecord));
    Q->Array = malloc(sizeof(ElementType)*MaxElement);
    Q->Capacity = MaxElement;
    MakeEmpty(Q);
}

int IsEmpty(Queue Q) {
    return Q->Size == 0;
}

int IsFull(Queue Q) {
    return Q->Size == Q->Capacity;
}

void MakeEmpty(Queue Q) {
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

static int Succ(int Value, Queue Q) {
    if (++Value == Q->Capacity)
        Value = 0;
    return Value;
}

void Enqueue(ElementType element, Queue Q) {
    if (IsFull(Q))
        printf("Error!");
    else {
        Q->Size++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = element;
    }
}

ElementType Front(Queue Q) {
    return Q->Array[Q->Front];
}

void Dequeue(Queue Q,ElementType *X) {
    if (!IsEmpty(Q)) {
        Q->Size--;
        *X = Q->Array[Q->Front];
        Q->Front = Succ(Q->Front, Q);
    }
    printf("Error!");
}

void DisposeQueue(Queue Q){
    if(Q != NULL){
        free(Q->Array);
        free(Q);
    }
}