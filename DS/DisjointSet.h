#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tagDisjoinSet{
    struct tagDisjoinSet* Parent;
    void* Data;
}DisjoinSet;

DisjoinSet* DS_FindSet(DisjoinSet* Set){
    while(Set->Parent != NULL){
        Set = Set->Parent;
    }

    return Set;
}

void DS_UnionSet(DisjoinSet* Set1, DisjoinSet* Set2){
    Set2 = DS_FindSet(Set2);
    Set2->Parent = Set1;
}

DisjoinSet* DS_MakeSet(void* NewData){
    DisjoinSet* NewNode = (DisjoinSet*)malloc(sizeof(DisjoinSet));
    NewNode->Data = NewData;
    NewNode->Parent = NULL;

    return NewNode;
}

void DS_DestroySet(DisjoinSet* Set){
    free(Set);
}


#endif