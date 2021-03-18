#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int Elementype;

typedef struct tagNode{
    int Data; // Data field
    struct tagNode* PrevNode; // Pointer that indicate previous node
    struct tagNode* NextNode; // Pointer that indicate next node
} Node;

/* Create Node */
Node* DLL_CreateNode(Elementype NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = NewData;

    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;
}

/* Add Node */
void DLL_AppendNode(Node** Head, Node* NewNode){
    if((*Head) == NULL){
        // if Head Node is NULL, New Node will be Head
        (*Head) = NewNode;
    }
    else{
        // Insert New Node between Head and Tail
        Node* Tail = (*Head);
        while(Tail->NextNode != NULL){
            Tail = Tail->NextNode;
        }

        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail; // PrveNode of new Tail indicate old Tail node
    }
}

/* Search Node */
Node* DLL_GetNodeAt(Node* Head, int Location){
    Node* Current = Head;
    while(Current != NULL && (--Location) >= 0){
        Current = Current->NextNode;
    }

    return Current;
}

/* Remove Node */
void DLL_RemoveNode(Node** Head, Node* Remove){
    if(*Head == Remove){
        *Head = Remove->NextNode;
        if((*Head) != NULL){
            (*Head)->PrevNode = NULL;
        }

        Remove->NextNode = NULL;
        Remove->PrevNode = NULL;
    }
    else{
        Node* Temp = Remove;

        Remove->PrevNode->NextNode = Temp->NextNode;
        if(Remove->NextNode != NULL){
            Remove->NextNode->PrevNode = Temp->PrevNode;
        }

        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
}

/* Insert Node */
void DLL_InsertNode(Node* Current, Node* NewNode){
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    if(Current->NextNode != NULL){
        Current->NextNode->PrevNode = NewNode;
    }

    Current->NextNode = NewNode;
}

/* Count Nodes */
int DLL_GetNodeCount(Node* Head){
    unsigned int Count = 0;
    Node* Current = Head;

    while(Current != NULL){
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}

/* Destroy Node */
void DLL_DestroyNode(Node* Node){
    free(Node);
}

/* Print Backway */
void PrintReverse(Node* Head){
    unsigned int Count = 0;
    Node* Current = NULL;

    Count = DLL_GetNodeCount(Head);
    for(int i=Count-1; i>=0; i--){
        Current = DLL_GetNodeAt(Head, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }
}

#endif