#include <stdio.h>

//// //잠만.#include<stdio.h>
#include<malloc.h>


typedef struct node
{
    int data;
    struct node* link;

}node, Stack;

Stack* getNode(); //노드생성함수
void push(Stack** top, int data); // 데이터 입력 함수
void pop(Stack** top); //데이터 삭제 함수
void peek(Stack** top);//데이터 출력함수 가장위에 데이터만
void Allpeek(Stack** top); //전체 데이터 출력
int main(void)
{
    Stack* top = NULL;		// 구조체 Stack을 가르키는 top 포인터 변수
    pop(&top);
    push(&top, 10);
    peek(&top);
    push(&top, 20);
    peek(&top);
    pop(&top);
    push(&top, 30);
    Allpeek(&top);
    pop(&top);
    pop(&top);
    peek(&top);
    pop(&top);
    peek(&top);
    pop(&top);
    return 0;
}

Stack* getNode()
{
    Stack* tmp = (Stack*)malloc(sizeof(Stack));
    (*tmp).link = NULL;
    return tmp;
}

void push(Stack** top, int data)
{//실행해봐바 다시 왜 아무 내용이 없어. 그러게요  
    Stack* tmp = getNode(); 
    (*tmp).data = data;
    (*tmp).link = *top;
    *top = tmp;
}

void pop(Stack** top)
{
    Stack* tmp = NULL;

    if ((*top) == NULL) {
        printf("underflow\n");
        return ;
    }

    tmp = (*top);
    (*top) = (**top).link;
    free(tmp);
}

void peek(Stack** top)
{
    if ((*top) == NULL) {
        printf("No Data\n");
        return ;
    }
    
    printf("%d\n", (**top).data);
}

void Allpeek(Stack** top)
{
    if ((*top) == NULL)
    {
        printf("DATA출력완료\n");
        return;
    }

    printf("%d -> ", (*top)->data);
    Allpeek(&(*top)->link);
}