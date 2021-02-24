#include <stdio.h>

//// //�Ḹ.#include<stdio.h>
#include<malloc.h>


typedef struct node
{
    int data;
    struct node* link;

}node, Stack;

Stack* getNode(); //�������Լ�
void push(Stack** top, int data); // ������ �Է� �Լ�
void pop(Stack** top); //������ ���� �Լ�
void peek(Stack** top);//������ ����Լ� �������� �����͸�
void Allpeek(Stack** top); //��ü ������ ���
int main(void)
{
    Stack* top = NULL;		// ����ü Stack�� ����Ű�� top ������ ����
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
{//�����غ��� �ٽ� �� �ƹ� ������ ����. �׷��Կ�  
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
        printf("DATA��¿Ϸ�\n");
        return;
    }

    printf("%d -> ", (*top)->data);
    Allpeek(&(*top)->link);
}