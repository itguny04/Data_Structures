#include<stdio.h>
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
        Stack* top = NULL;		// 맨 위를 나타내는듯
        push(&top, 10);
        peek(&top);
        push(&top, 20);
        peek(&top);
        push(&top, 30);
        Allpeek(&top);
        pop(&top);
        pop(&top);
        pop(&top);
        pop(&top);
        return 0;
}

Stack* getNode()
{
        Stack* tmp = (Stack*)malloc(sizeof(Stack));
        tmp->link = NULL;
        return tmp;
}

void push(Stack** top, int data)
{
	Stack* tmp = getNode();
	(**top).link = tmp;
	(*tmp).data = data;			// 생성한 노드에 값 대입
	(*tmp).link = (**top).link;

	//탑에 바로 겟노드하면 코드가 나누어져야함.
	//그래서 임시 포인터변수 선언하라고 했던거임. 아 넵 ㅇㅋ 계속 수고하셈,
}

void pop(Stack** top)
{
	Stack* tmp = (**top).link;
	(**top).link = (*tmp).link;

}

void peek(Stack** top)
{

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