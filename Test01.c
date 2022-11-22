//
// Created by muyou on 2022/9/15.
//
// Created by muyou on 2022/9/15.
//
#include<stdio.h>
#include <malloc.h>

#ifndef _List_H
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode LinkList;
typedef PtrToNode Position;

void InitialList(LinkList *L);
void CreatList(LinkList L, int n);//��������
LinkList MergeList(LinkList LA, LinkList LB);//����ϲ���������
void PrintList(LinkList L);//��ӡ����
#endif

typedef int ElementType;

struct Node {
    ElementType element;
    Position next;
};

void InitialList(LinkList *L){
    *L = (LinkList *) malloc(sizeof(struct Node));
    (*L) ->next = NULL;
}

void CreatList(LinkList L, int n) {
    Position p = L;
    int data;
    while (n--) {
        Position tmp = (Position) malloc(sizeof(struct Node));
        p->next = tmp;
        scanf("%d", &data);
        tmp->element = data;
        p = tmp;
    }
    p->next = NULL;
}

LinkList MergeList(LinkList LA, LinkList LB) {
    Position pa, pb, tmp;
    pa = LA->next;
    pb = LB->next;
    while (pa && pb) {
        tmp = pb;
        pb = pb->next;
        tmp->next = pa->next;
        pa->next = tmp;
        pa = tmp->next;
    }
    tmp->next = pa ? pa : pb;
    free(LB);
    return LA;
}

void PrintList(LinkList L) {
    Position p = L->next;
    while (p) {
        printf("%d ", p->element);
        p = p->next;
    }
}

int main() {
    int LenA, LenB;
    printf("��ֱ�����A���B��ĳ��ȣ�");
    scanf("%d%d", &LenA, &LenB);
    LinkList LA, LB;
    InitialList(&LA);
    InitialList(&LB);
    CreatList(LA, LenA);
    CreatList(LB, LenB);
    printf("�ϲ���ı�C��");
    PrintList(MergeList(LA, LB));
    return 0;
}
