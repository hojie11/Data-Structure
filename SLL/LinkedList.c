#include "LinkedList.h"

/* Create Node */
Node* SLL_CreateNode(ElementType NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData; // Save Data
    NewNode->NextNode = NULL; // Initialize next node pointer to null

    return NewNode;
}

/* Add Node */
void SLL_AppendNode(Node** Head, Node* NewNode){
    // if Head Node is null, New Ndoe will be Head
    if ((*Head) == NULL){
        *Head = NewNode;
    }
    else{
        // find tail and connect to new node
        Node* Tail = (*Head);
        while(Tail->NextNode != NULL){
            Tail = Tail->NextNode;
        }

        Tail->NextNode = NewNode;
    }
}

/* Search Node */
Node* SLL_GetNodeAt(Node* Head, int Location){
    Node* Current = Head;

    while(Current != NULL && (--Location) >= 0){
        Current = Current->NextNode;
    }

    return Current;
}

/* Remove Node */
void SLL_RemoveNode (Node** Head, Node* Remove){
    if (*Head == Remove){
        *Head = Remove->NextNode;
    }
    else{
        Node* Current = *Head;
        while(Current != NULL && Current->NextNode != Remove){
            Current = Current->NextNode;
        }

        if (Current != NULL){
            Current->NextNode = Remove->NextNode;
        }
    }
}

/* Insert Node */
void SLL_InsertAfter(Node* Current, Node* NewNode){
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}

void SLL_InsertNewHead(Node** Head, Node* NewHead){
    if (*Head == NULL){
        (*Head) = NewHead;
    }
    else{
        NewHead->NextNode = (*Head);
        (*Head) = NewHead;
    }
}

/* Count Nodes */
int SLL_GetNodeCount(Node* Head){
    int Count = 0;
    Node* Current = Head;

    while (Current != NULL){
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}

void SLL_DestoryNode(Node* Node){
    free(Node);
}