#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode{
    ElementType Data;
}Node;

typedef struct tagArrayStack{
    int Capacity;
    int Top; // Loacation of the top node
    Node* Nodes; // Node Array
} ArrayStack;

/* Create Stack and Node */
void AS_CreateStack(ArrayStack** Stack, int Capacity){
    /* Create Stack in Dynamic Storage */
    (*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

    /* Create Nodes as much as input Capacity in Dynamic Storage */
    (*Stack)->Nodes = (Node*)malloc(sizeof(Node)*Capacity);

    /* Initialize Capacity and Top */
    (*Stack)->Capacity = Capacity;
    (*Stack)->Top = 0;
}

/* Destroy Stack and Node */
void AS_DestroyStack(ArrayStack* Stack){
    /* Destroy node in Dynamic Storage */
    free(Stack->Nodes);

    /* Destroy stack in Dynamic Storage */
    free(Stack);
}

/* Push Data to the top of Stack */
void AS_Push(ArrayStack* Stack, ElementType Data){
    int Position = Stack->Top;

    if(Position == Stack->Capacity){
        Stack->Capacity = (int)(Stack->Capacity * 1.3);
        Node* NewNode = (Node*)malloc(sizeof(Node) * Stack->Capacity);

        for(int i=0; i<Stack->Capacity; i++){
            NewNode[i].Data = Stack->Nodes[i].Data;
        }

        free(Stack->Nodes);
        Stack->Nodes = NewNode;
        printf("\nChange Capacity: %d\n\n", Stack->Capacity);
    }
    
    Stack->Nodes[Position].Data = Data;
    Stack->Top++;
}

/* Get Data from the Stack and decrease the top of Stack */
ElementType AS_Pop(ArrayStack* Stack){
    int Position = --(Stack->Top);

    if(Stack->Top < (int)(Stack->Capacity * 0.7)){
        Stack->Capacity = (int)(Stack->Capacity * 0.7);
        Node* NewNode = (Node*)malloc(sizeof(Node) * Stack->Capacity);

        for(int i=0; i<Stack->Capacity; i++){
            NewNode[i].Data = Stack->Nodes[i].Data;
        }

        free(Stack->Nodes);
        Stack->Nodes = NewNode;
        printf("\nChange Capacity: %d\n\n", Stack->Capacity);
    }

    return Stack->Nodes[Position].Data;
}

/* Return the top's value */
ElementType AS_Top(ArrayStack* Stack){
    int Position = Stack->Top-1;

    return Stack->Nodes[Position].Data;
}

/* Get size of Stack*/
int AS_GetSize(ArrayStack* Stack){
    return Stack->Top;
}

/* Check whether Stack is empty */
int AS_IsEmpty(ArrayStack* Stack){
    return (Stack->Top == 0);
}

int AS_IsFull(ArrayStack* Stack){
    return (Stack->Top == Stack->Capacity);
}

#endif