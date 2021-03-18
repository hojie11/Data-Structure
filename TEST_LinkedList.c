#include "LinkedList.h"
#include <stdio.h>

int main(void)
{
    int i = 0;
    int Count = 0;
    Node* List = NULL;
    Node* Current = NULL;
    Node* NewNode = NULL;

    /* Add 5 nodes */
    for (i = 0; i < 5; i++){
        NewNode = SLL_CreateNode(i);
        SLL_AppendNode(&List, NewNode);
    }

    NewNode = SLL_CreateNode(-1);
    SLL_InsertNewHead(&List, NewNode);

    NewNode = SLL_CreateNode(-2);
    SLL_InsertNewHead(&List, NewNode);

    /* Print List */
    Count = SLL_GetNodeCount(List);
    for (i = 0; i < Count; i++){
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    /* Insert new node after the third node */
    printf("\nInserting 3000 after [2]....\n");

    Current = SLL_GetNodeAt(List, 2);
    NewNode = SLL_CreateNode(3000);

    SLL_InsertAfter(Current, NewNode);

    /* Print List */
    Count = SLL_GetNodeCount(List);
    for (i = 0; i < Count; i++){
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    /* Delete the memory of all nodes */
    printf("\nDestorying List....\n");

    for (i = 0; i < Count; i++){
        Current = SLL_GetNodeAt(List, 0);

        if(Current != NULL){
            SLL_RemoveNode(&List, Current);
            SLL_DestoryNode(Current);
        }
    }

    return 0;
}