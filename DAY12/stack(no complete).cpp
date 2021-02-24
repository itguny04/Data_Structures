#include<stdio.h>
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
        Stack* top = NULL;		// �� ���� ��Ÿ���µ�
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
	(*tmp).data = data;			// ������ ��忡 �� ����
	(*tmp).link = (**top).link;

	//ž�� �ٷ� �ٳ���ϸ� �ڵ尡 ������������.
	//�׷��� �ӽ� �����ͺ��� �����϶�� �ߴ�����. �� �� ���� ��� �����ϼ�,
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
                printf("DATA��¿Ϸ�\n");
                return;
        }

        printf("%d -> ", (*top)->data);
        Allpeek(&(*top)->link);
}