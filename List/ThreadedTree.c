//
// Created by muyou on 2022/10/22.
//
#include "stdio.h"
#include "stdlib.h"

#ifndef _Tree_H
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *ThreadedTree;
typedef int ElementType;
typedef enum {
    Link, Thread
} PointerTag;//Link = 0,指针;Thread = 1,线索;
#define ERROR (0)
#define OK (1)

ThreadedTree MakeEmpty(ThreadedTree T);

#endif
struct TreeNode {
    ElementType Element;
    ThreadedTree Left;
    ThreadedTree Right;
    PointerTag LTag;
    PointerTag RTag;
};

ThreadedTree MakeEmpty(ThreadedTree T) {
    if (T != NULL) {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

ThreadedTree NextNode(ThreadedTree T) {
    if (T->RTag)//若右子树为空
        return T->Right;//T->Right指向后继结点
    ThreadedTree next = T->Right;
    while (!next->LTag)
        next = next->Left;//找到右子树的最左结点
    return next;
}
ThreadedTree PriorTree(ThreadedTree T){
    if(T->LTag)//若左子树为空
        return T->Left;//T->Left指向前驱结点
    ThreadedTree pre = T->Left;
    while(!pre->RTag)
        pre = pre->Right;//找到左子树的最右结点
    return pre;
}
