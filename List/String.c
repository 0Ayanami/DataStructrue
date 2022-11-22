//
// Created by muyou on 2022/10/7.
//
#include<stdio.h>
#include "stdlib.h"

#ifndef _String_H_

struct HString;
typedef struct HString *String;

void StringAssign(String T, char *chars);

int StrLength(String S);

int StrCompare(String S, String T);

void ClearString(String S);

void Concat(String T, String S1, String S2);

void SubString(String Sub, String S, int pos, int len);

#endif
struct HString {
    char *ch;
    int length;
};

void StringAssign(String T, char *chars) {
    if (T->ch)
        free(T->ch);
    char *c;
    int i;
    for (i = 0, c = chars; c != NULL; c++, i++);
    if (!i) {
        T->ch = NULL;
        T->length = 0;
    } else {
        T->ch = (char *) malloc(i * sizeof(char));
        T->length = i;
        for (i = 0; i < T->length; i++)
            T->ch[i] = chars[i];
    }
}

int StrLength(String S) {
    return S->length;
}

int StrCompare(String S, String T) {
    for (int i = 0; i < S->length && i < T->length; i++) {
        if (S->ch[i] != T->ch[i])
            return S->ch[i] - T->ch[i];
    }
    return S->length - T->length;
}

void ClearString(String S) {
    if (S->ch) {
        free(S->ch);
        S->ch = NULL;
    }
    S->length = 0;
}

void Concat(String T, String S1, String S2) {
    if (T->ch) {
        free(T->ch);
        T->ch = NULL;
    }
    T->ch = (char *) malloc((S1->length + S2->length) * sizeof(char));
    T->length = S1->length + S2->length;
    for (int i = 0; i < S1->length; i++)
        T->ch[i] = S1->ch[i];
    for (int i = S1->length; i < T->length; i++)
        T->ch[i] = S2->ch[i];
}

void SubString(String Sub, String S, int pos, int len) {
    if (Sub)
        free(Sub->ch);
    if (!len) {
        Sub->ch = NULL;
        Sub->length = 0;
    } else {
        Sub->ch = (char *) malloc(len * sizeof(char));
        for (int i = 0; i < len; i++)
            Sub->ch[i] = S->ch[pos - 1 + i];
        Sub->length = len;
    }
}