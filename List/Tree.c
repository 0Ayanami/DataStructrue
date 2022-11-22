//
// Created by muyou on 2022/9/30.
//
#include "stdio.h"
#include "stdlib.h"

#ifndef _Tree_H
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef int ElementType;
#define ERROR (0)
#define OK (1)

SearchTree MakeEmpty(SearchTree T);

Position Find(ElementType X, SearchTree T);

Position FindMin(SearchTree T);

Position FindMax(SearchTree T);

SearchTree Insert(ElementType X, SearchTree T);

SearchTree Delete(ElementType X, SearchTree T);


#endif
struct TreeNode {
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

SearchTree MakeEmpty(SearchTree T) {
    if (T != NULL) {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find(ElementType X, SearchTree T) {
    if (T == NULL)
        return NULL;
    if (X < T->Element)
        Find(X, T->Left);
    else if (X > T->Element)
        Find(X, T->Right);
    else
        return T;
}

Position FindMin(SearchTree T) {
    if (T == NULL)
        return NULL;
    else if (T->Left == NULL)
        return T;
    else
        return FindMin(T->Left);
}

Position FindMax(SearchTree T) {
    if (T == NULL)
        return NULL;
    else if (T->Right == NULL)
        return T;
    else
        return FindMax(T->Right);
}

SearchTree Insert(ElementType X, SearchTree T) {
    if (T == NULL) {
        T = malloc(sizeof(struct TreeNode));
        T->Element = X;
        T->Right = T->Left = NULL;
    } else if (X < T->Element)
        T->Left = Insert(X, T->Left);
    else if (X > T->Element)
        T->Right = Insert(X, T->Right);
    return T;
}

SearchTree Delete(ElementType X, SearchTree T) {
    Position TmpCell;

    if (T == NULL)
        printf("Error! Tree is Empty!");
    else if (X < T->Element)
        T->Left = Delete(X, T->Left);
    else if (X > T->Element)
        T->Right = Delete(X, T->Right);
    else if (T->Left && T->Right) {
        TmpCell = FindMin(T->Right);
        T->Element = TmpCell->Element;
        T->Right = Delete(T->Element, T->Right);
    } else {
        TmpCell = T;
        if (T->Right == NULL)
            T = T->Left;
        else if (T->Left == NULL)
            T = T->Right;
        free(TmpCell);
    }
    return T;
}

int PreOrderTraverse(SearchTree T) {
    if (T) {
        printf("%d ", T->Element);
        if (PreOrderTraverse(T->Left))
            if (PreOrderTraverse(T->Right))
                return OK;
        return ERROR;
    } else
        return OK;
}

void NodeCount(SearchTree T, int *count) {
    if (T) {
        if (T->Left != NULL && T->Right != NULL)
            (*count)++;
            NodeCount(T->Left,count);
            NodeCount(T->Right,count);
    }
}
void ChangePosition(SearchTree T){
        Position tmp;
        if(T) {
            if (T->Left != NULL && T->Right != NULL) {
                tmp = T->Left;
                T->Left = T->Right;
                T->Right = tmp;
                ChangePosition(T->Left);
                ChangePosition(T->Right);
            }
        }
}
int PostOrderTraverse(SearchTree T) {
    if (T) {
        if (PostOrderTraverse(T->Left))
            if (PostOrderTraverse(T->Right)) {
                printf("%d ", T->Element);
                return OK;
            }
        return ERROR;
    } else
        return OK;
}

int InOrderTraverse(SearchTree T) {
    if (T) {
        if (InOrderTraverse(T->Left)) {
            printf("%d ", T->Element);
            if (InOrderTraverse(T->Right))
                return OK;
        }
        return ERROR;
    } else
        return OK;
}

void InitialTree(SearchTree *T) {
    *T = (SearchTree *) malloc(sizeof(struct TreeNode));
    (*T)->Left = NULL;
    (*T)->Right = NULL;
}