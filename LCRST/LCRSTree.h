#ifndef LEFTCHILDRIGHTSIBLINGTREE_H
#define LEFTCHILDRIGHTSIBLINGTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagLCRSNode{
    ElementType Data;

    struct tagLCRSNode* LeftChild;
    struct tagLCRSNode* RightSibling;
} LCRSNode;

LCRSNode* LCRS_CreateNode(ElementType NewData){
    LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));

    NewNode->LeftChild = NULL;
    NewNode->RightSibling = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

void LCRS_DestroyNode(LCRSNode* Node){
    free(Node);
}

void LCRS_DestroyTree(LCRSNode* Root){
    if(Root->RightSibling != NULL){
        LCRS_DestroyTree(Root->RightSibling);
    }

    if(Root->LeftChild != NULL){
        LCRS_DestroyTree(Root->LeftChild);
    }

    Root->LeftChild = NULL;
    Root->RightSibling = NULL;

    LCRS_DestroyNode(Root);
}

void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child){
    if(Parent->LeftChild == NULL){
        Parent->LeftChild = Child;
    }else{
        LCRSNode* TempNode = Parent->LeftChild;
        while(TempNode->RightSibling != NULL){
            TempNode = TempNode->RightSibling;
        }

        TempNode->RightSibling = Child;
    }
}

void LCRS_PrintTree(LCRSNode* Node, int Depth){
    int i = 0;

    /* Indentation as much as depth */
    for(i=0; i<Depth; i++){
        printf(" ");
    }

    /* Print the data in Node */
    printf("%c\n", Node->Data);

    if(Node->LeftChild != NULL){
        LCRS_PrintTree(Node->LeftChild, Depth+1);
    }

    if(Node->RightSibling != NULL){
        LCRS_PrintTree(Node->RightSibling, Depth);
    }
}

void LCRS_PrintNodesAtLevel(LCRSNode* Root, int Level){
    if(Level == 0){
        printf("%c", Root->Data);
    }else if(Level > 0){
        if(Root->LeftChild != NULL){
            LCRS_PrintNodesAtLevel(Root->LeftChild, Level-1);
        }
    }

    if(Root->RightSibling != NULL){
        LCRS_PrintNodesAtLevel(Root->RightSibling, Level);
    }
}

#endif