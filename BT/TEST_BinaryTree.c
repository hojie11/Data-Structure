#include "BinaryTree.h"

int main(void){
    SBTNode* A = SBT_CreateNode('A');
    SBTNode* B = SBT_CreateNode('B');
    SBTNode* C = SBT_CreateNode('C');
    SBTNode* D = SBT_CreateNode('D');
    SBTNode* E = SBT_CreateNode('E');
    SBTNode* F = SBT_CreateNode('F');
    SBTNode* G = SBT_CreateNode('G');

    A->Left = B;
    B->Left = C;
    B->Right = D;

    A->Right = E;
    E->Left = F;
    E->Right = G;

    printf("Preorder...\n");
    SBT_PreorderPrintTree(A);
    printf("\n\n");

    printf("Inorder...\n");
    SBT_InorderPrintTree(A);
    printf("\n\n");

    printf("Postorder...\n");
    SBT_PostorderPrintTree(A);
    printf("\n\n");

    SBT_DestroyTree(A);

    SBTNode* Root = NULL;

    char PostfixExpression[20] = "71*52-/";
    ET_BuildExpressionTree(PostfixExpression, &Root);

    printf("Preorder...\n");
    SBT_PreorderPrintTree(Root);
    printf("\n\n");

    printf("Inorder...\n");
    SBT_InorderPrintTree(Root);
    printf("\n\n");

    printf("Postorder...\n");
    SBT_PostorderPrintTree(Root);
    printf("\n\n");

    printf("Evaulation Result : %f \n", ET_Evaluate(Root));

    SBT_DestroyTree(Root);

    return 0;
}