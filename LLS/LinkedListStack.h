#ifndef LINKEDLISTSTACK_H
#define LINKEDLISTSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode{
    char* Data;
    struct tagNode* NextNode;
} Node;

typedef struct tagLinkedListStack{
    Node* List; // List pointer
    Node* Top; // Tail pointer
}LinkedListStack;

void LLS_CreateStack(LinkedListStack** Stack){
    /* Create Stack in Dynamic storage */
    (*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
    (*Stack)->List = NULL;
    (*Stack)->Top = NULL;
}

void  LLS_DestroyNode(Node* _Node){
    free(_Node->Data);
    free(_Node);
}

Node* LLS_Pop(LinkedListStack* Stack){
    Node* TopNode = Stack->Top;

    if(Stack->List == Stack->Top){
        Stack->List = NULL;
        Stack->Top = NULL;
    }else{
        /* Register the new most top Node in the Top field of Stack */
        Node* CurrentTop = Stack->List;
        while(CurrentTop != NULL && CurrentTop->NextNode != Stack->Top){
            CurrentTop = CurrentTop->NextNode;
        }

        Stack->Top = CurrentTop;
        CurrentTop->NextNode = NULL;
    }

    return TopNode;
}

int LLS_IsEmpty(LinkedListStack* Stack){
    return (Stack->List == NULL);
}

void LLS_DestroyStack(LinkedListStack* Stack){
    while(!LLS_IsEmpty(Stack)){ // Repeat until Stack is empty
        Node* Popped = LLS_Pop(Stack); // Destroy a Node after remove from Stack
        LLS_DestroyNode(Popped);
    }

    /* Destroy Stack in Dynamic Storage */
    free(Stack);
}

Node* LLS_CreateNode(char* NewData){
    /* Create a Node in Dynamic Storage */
    Node* NewNode = (Node*)malloc(sizeof(Node));

    /* Create string as big as input string */
    NewNode->Data = (char*)malloc(strlen(NewData) + 1);

    /* Copy string to Dynamic Storage */
    strcpy(NewNode->Data, NewData); // Save data

    NewNode->NextNode = NULL; // Initialize the pointer of Next Node

    return NewNode; // Return New Node
}

void LLS_Push(LinkedListStack* Stack, Node* NewNode){
    if(Stack->List == NULL){
        Stack->List = NewNode;
    }else{
        /* Find the most top Node and connect New Node */
        Node* OldTop = Stack->List;
        while(OldTop->NextNode != NULL){
            OldTop = OldTop->NextNode;
        }

        OldTop->NextNode = NewNode;
        
    }

    /* Register New Node's address in the top field of Stack */
    Stack->Top = NewNode;
}

Node* LLS_Top(LinkedListStack* Stack){
    return Stack->Top;
}

int LLS_GetSize(LinkedListStack* Stack){
    int Count = 0;
    Node* Current = Stack->List;

    while(Current != NULL){
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}

#endif