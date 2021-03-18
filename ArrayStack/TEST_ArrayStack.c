#include "ArrayStack.h"

int main(void){
    int i = 0;
    int Size = 0;
    ArrayStack* Stack = NULL;

    AS_CreateStack(&Stack, 10);

    for(i=0; i<13; i++){
        AS_Push(Stack, i);
    }

    Size = AS_GetSize(Stack);

    printf("Capacity: %d, Size: %d, Top: %d\n\n",
            Stack->Capacity, Size, AS_Top(Stack));

    printf("Is it full? : %s\n\n", AS_IsFull(Stack) == 1? "TRUE" : "FALSE");

    for (i=0; i<Size; i++){
        if(AS_IsEmpty(Stack)){
            break;
        }

        printf("Popped: %d, ", AS_Pop(Stack));

        if(!AS_IsEmpty(Stack)){
            printf(" Current Top: %d\n", AS_Top(Stack));
        }else{
            printf("Stack Is Empty.\n");
        }
    }
    
    AS_DestroyStack(Stack);

    return 0;
}