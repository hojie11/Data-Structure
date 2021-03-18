#ifndef CIRCULARDOUBLELINKEDLIST_H
#define CIRCULARDOUBLELINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int Elementype;

typedef struct tagNode{
    int Data; // Data field
    struct tagNode* PrevNode; // Pointer that indicate previous node
    struct tagNode* NextNode; // Pointer that indicate next node
} Node;

/* Create Node */
Node* CDLL_CreateNode(Elementype NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = NewData;

    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;
}

/* Add Node */
void CDLL_AppendNode(Node** Head, Node* NewNode){
    if((*Head) == NULL){
        // if Head Node is NULL, New Node will be Head
        (*Head) = NewNode;
        (*Head)->NextNode = (*Head);
        (*Head)->PrevNode = (*Head);
    }
    else{
        // Insert New Node between Head and Tail
        Node* Tail = (*Head)->PrevNode;

        Tail->NextNode->PrevNode = NewNode;
        Tail->NextNode = NewNode;

        NewNode->NextNode = (*Head);
        NewNode->PrevNode = Tail; // PrveNode of new Tail indicate old Tail node
    }
}

/* Search Node */
Node* CDLL_GetNodeAt(Node* Head, int Location){
    Node* Current = Head;
    while(Current != NULL && (--Location) >= 0){
        Current = Current->NextNode;
    }

    return Current;
}

/* Remove Node */
void CDLL_RemoveNode(Node** Head, Node* Remove){
    if(*Head == Remove){
        (*Head)->PrevNode->NextNode = Remove->NextNode;
        (*Head)->NextNode->PrevNode = Remove->PrevNode;

        (*Head) = Remove->NextNode;

        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
    else{
        Node* Temp = Remove;

        Remove->PrevNode->NextNode = Temp->NextNode;
        Remove->NextNode->PrevNode = Temp->PrevNode;

        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
}

/* Insert Node */
void CDLL_InsertNode(Node* Current, Node* NewNode){
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    Current->NextNode->PrevNode = NewNode;
    Current->NextNode = NewNode;
}

/* Count Nodes */
int CDLL_GetNodeCount(Node* Head){
    unsigned int Count = 0;
    Node* Current = Head;

    while(Current != NULL){
        Current = Current->NextNode;
        Count++;

        if(Current == Head){
            break;
        }
    }

    return Count;
}

/* Destroy Node */
void CDLL_DestroyNode(Node* Node){
    free(Node);
}

/* Print Backway */
void PrintReverse(Node* Head){
    unsigned int Count = 0;
    Node* Current = NULL;

    Count = CDLL_GetNodeCount(Head);
    for(int i=Count-1; i>=0; i--){
        Current = CDLL_GetNodeAt(Head, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }
}

#endif