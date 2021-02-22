#include<stdio.h>
#include<malloc.h>
#include<Windows.h>

#define INROOM 1
#define OUTROOM 0

int input(const char* msg);
char* setRooms(int su);
void menu(char* pt, int su);
void InRoom(char* pt, int su);
void OutRoom(char *pt, int su);
void esc(char* pt);
void disp(char* pt, int su);

int main(void) {

        int su = input("�� ���� �Է�: ");
        
        char* pt = setRooms(su);

        menu(pt, su);

        return 0;
}

int input(const char* msg) {
        int su;
        printf("%s", msg);
        scanf("%d", &su);
        return su;
}

char* setRooms(int su) {
        char* pt = (char*)malloc(su);

        for (int i = 0; i < su; i++) {
                pt[i] = OUTROOM;
        }

        return pt;
}


void menu(char* pt, int su) {

        system("pause");
        system("cls");

        while (1) {
                int select = input("1.�Խ� 2.��� 3.���� 4.����: ");

                switch (select) {
                case 1:
                	InRoom(pt,su);
                	break;
                case 2:
                	OutRoom(pt,su);
					break;
                case 3:
                    disp(pt, su);
                    break;
                case 4:
                    esc(pt);
                default:
                    printf("�߸��� �޴� �Է�!!\n");
                }

                system("pause");
                system("cls");
        }
}

void InRoom(char* pt, int su){
	int RoomNumber = input("�Խ��Ͻ� ���� ��ȣ��: ");
	
	if(RoomNumber < su){
		if(pt[RoomNumber] == OUTROOM) {
			pt[RoomNumber] = INROOM;
			printf("%dȣ�ǿ� �Խ��ϼ̽��ϴ�.\n", RoomNumber);
		}
		else if(pt[RoomNumber] == INROOM){
			printf("���� ������� ���Դϴ�.\n");
		}
		else{
			printf("Error");
		} 
	}else{
		printf("���ȣ�� Ȯ���Ͽ� �ּ���.\n�������� �ʴ� ���Դϴ�.\n");
	}
}

void OutRoom(char *pt, int su){
	int RoomNumber = input("����Ͻ� ���� ��ȣ��: ");
	
	if(RoomNumber < su){
		if(pt[RoomNumber] == INROOM){
			pt[RoomNumber] = OUTROOM;
			printf("%dȣ�ǿ��� ����ϼ̽��ϴ�.\n");
		}
		else if(pt[RoomNumber] == OUTROOM){
			printf("��� �Դϴ�.\n");
		}
		else{
			printf("Error");
		}
	}else{
		printf("���ȣ�� Ȯ���Ͽ� �ּ���.\n�������� �ʴ� ���Դϴ�.\n");
	}
	
}

void esc(char* pt) {
        puts("���α׷��� ����˴ϴ�.");
        free(pt);
        exit(0);
}

void disp(char* pt, int su) {
        puts("### �� ��Ȳ ###");
        for (int i = 0; i < su; i++) {
                if (pt[i] == INROOM) {
                        printf("%dȣ�� - �Խ���\n", i);
                }
                else {
                        printf("%dȣ�� - ��  ��\n", i);
                }
        }
        puts("");
}
