#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char ElementType;

typedef struct tagSBTNode{
    ElementType Data;

    struct tagSBTNode* Left;
    struct tagSBTNode* Right;
}SBTNode;

SBTNode* SBT_CreateNode(ElementType NewData){
    SBTNode* NewNode = (SBTNode*)malloc(sizeof(SBTNode));
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

void SBT_DestroyNode(SBTNode* Node){
    free(Node);
}

void SBT_PreorderPrintTree(SBTNode* Node){
    if(Node==NULL){
        return;
    }

    printf(" %c", Node->Data);
    /* Print left sub tree */
    SBT_PreorderPrintTree(Node->Left);
    /* Print right sub tree */
    SBT_PreorderPrintTree(Node->Right);
}

void SBT_InorderPrintTree(SBTNode* Node){
    if(Node==NULL){
        return;
    }

    printf("(");
    SBT_InorderPrintTree(Node->Left);
    
    printf(" %c", Node->Data);

    SBT_InorderPrintTree(Node->Right);
    printf(")");
}

void SBT_PostorderPrintTree(SBTNode* Node){
    if(Node==NULL){
        return;
    }

    SBT_PostorderPrintTree(Node->Left);

    SBT_PostorderPrintTree(Node->Right);

    printf(" %c", Node->Data);
}

void SBT_DestroyTree(SBTNode* Root){
    if(Root==NULL){
        return;
    }

    SBT_DestroyTree(Root->Left);

    SBT_DestroyTree(Root->Right);

    SBT_DestroyNode(Root);
}

void ET_BuildExpressionTree(char* PostfixExpression, SBTNode** Node){
    int len = strlen(PostfixExpression);
    char Token = PostfixExpression[len-1];
    PostfixExpression[len-1] = '\0';

    switch(Token){
        case '+': case '-': case '*': case '/':
            (*Node) = SBT_CreateNode(Token);
            ET_BuildExpressionTree(PostfixExpression, &(*Node)->Right);
            ET_BuildExpressionTree(PostfixExpression, &(*Node)->Left);
            break;

        default:
            (*Node) = SBT_CreateNode(Token);
            break;
    }
}

double ET_Evaluate(SBTNode* Tree){
    char Temp[2];

    double Left = 0;
    double Right = 0;
    double Result = 0;

    if(Tree==NULL){
        return 0;
    }

    switch(Tree->Data){
        case '+': case '-': case '*': case '/':
            Left = ET_Evaluate(Tree->Left);
            Right = ET_Evaluate(Tree->Right);

            if(Tree->Data == '+') Result = Left + Right;
            else if(Tree->Data == '-') Result = Left - Right;
            else if(Tree->Data == '*') Result = Left * Right;
            else if(Tree->Data == '/') Result = Left / Right;

            break;
        
        default:
            memset(Temp, 0, sizeof(Temp));
            Temp[0] = Tree->Data;
            Result = atof(Temp);
            break;
    }

    return Result;
}

#endif