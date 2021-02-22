#include <stdio.h>
#include <malloc.h>

#define default 3

void push(int* stack, int* esp, int data);
void pop(int* stack, int* esp);
void peek(int* stack, int* esp);
void show_stack(int* stack,int* esp);

int main(void){
    int* stack = (int*)malloc(sizeof(int)*default);
    int esp = 0;
	
	// STACK
	
	// push
	push(stack, &esp, 100);
	push(stack, &esp, 50);
	push(stack, &esp, 70);
	
	// overflow(push)
	push(stack, &esp, 230);
	
	// Show STACK(status)
	show_stack(stack, &esp);
	
	// pop
	pop(stack, &esp);
	peek(stack, &esp);
	pop(stack, &esp);
	pop(stack, &esp);
	
	// underflow(pop)
	pop(stack, &esp);
	
	// no data(peek)
	peek(stack, &esp);
	
	free(stack);
	
    return 0;
}

void push(int* stack, int* esp, int data){
    
    if(default == (*esp)){
        printf("StackOverFlow!\n");
        return ;
    }

    stack[*esp] = data;
    (*esp)++;
}

void pop(int* stack, int* esp){
    
    if(*esp == 0){
        printf("StackUnderFlow!\n");
        return ;
    }
    
    printf("pop: %d\n", stack[--(*esp)]);
}

void peek(int* stack, int* esp){
    if(*esp == 0){
        printf("NoData!");
        return ;
    }
    
    printf("peek: %d\n", stack[(*esp)-1]);
}

void show_stack(int* stack, int* esp){
	int i;
	
	printf("\n-----------------\n");
	for(i=(*esp)-1;i>=0;i--){
		printf("|\t%d\t|\n", stack[i]);
	}
	printf("-----------------\n\n");
	
}
