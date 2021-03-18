#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode{
    ElementType Data; // Data field
    struct tagNode* NextNode; // Pointer that indicate next node
} Node;

/* define function prototypes */
/* Create Node */
Node* SLL_CreateNode(int NewData);
/* Add Node */
void SLL_AppendNode(Node** Head, Node* NewNode);
/* Search Node */
Node* SLL_GetNodeAt(Node* Head, int Location);
/* Remove Node */
void SLL_RemoveNode (Node** Head, Node* Remove);
/* Insert Node */
void SLL_InsertAfter(Node* Current, Node* NewNode);
void SLL_InsertNewHead(Node** Head, Node* NewNode);
/* Count Nodes */
int SLL_GetNodeCount(Node* Head);

void SLL_DestoryNode(Node* Node);

#endif