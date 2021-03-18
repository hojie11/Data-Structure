#include "DoubleLinkedList.h"

int main(void){
    int i = 0;
    unsigned int Count = 0;
    Node* List = NULL;
    Node* NewNode = NULL;
    Node* Current = NULL;

    /* Add five nodes */
    for(i=0; i<5; i++){
        NewNode = DLL_CreateNode(i);
        DLL_AppendNode(&List, NewNode);
    }

    /* Print List */
    Count = DLL_GetNodeCount(List);
    for(i=0; i<Count; i++){
        Current = DLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    /* Insert a Node after List [2] */
    printf("\nInserting 3000 after [2] .... \n\n");

    Current = DLL_GetNodeAt(List, 2);
    NewNode = DLL_CreateNode(3000);
    DLL_InsertNode(Current, NewNode);

    /* Print List */
    Count = DLL_GetNodeCount(List);
    for(i=0; i<Count; i++){
        Current = DLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    /* Print all data */
    printf("\nPrint All Data ....\n\n");
    PrintReverse(List);

    /* Delete all Nodes in Memory */
    printf("\nDestroying List ... \n");

    Count = DLL_GetNodeCount(List);
    for(i=0; i<Count; i++){
        Current = DLL_GetNodeAt(List, 0);

        if(Current != NULL){
            DLL_RemoveNode(&List, Current);
            DLL_DestroyNode(Current);
        }
    }

    return 0;
}