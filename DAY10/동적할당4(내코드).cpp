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

        int su = input("방 개수 입력: ");
        
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
                int select = input("1.입실 2.퇴실 3.보기 4.종료: ");

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
                    printf("잘못된 메뉴 입력!!\n");
                }

                system("pause");
                system("cls");
        }
}

void InRoom(char* pt, int su){
	int RoomNumber = input("입실하실 방의 번호는: ");
	
	if(RoomNumber < su){
		if(pt[RoomNumber] == OUTROOM) {
			pt[RoomNumber] = INROOM;
			printf("%d호실에 입실하셨습니다.\n", RoomNumber);
		}
		else if(pt[RoomNumber] == INROOM){
			printf("현재 사용중인 방입니다.\n");
		}
		else{
			printf("Error");
		} 
	}else{
		printf("방번호를 확인하여 주세요.\n존재하지 않는 방입니다.\n");
	}
}

void OutRoom(char *pt, int su){
	int RoomNumber = input("퇴실하실 방의 번호는: ");
	
	if(RoomNumber < su){
		if(pt[RoomNumber] == INROOM){
			pt[RoomNumber] = OUTROOM;
			printf("%d호실에서 퇴실하셨습니다.\n");
		}
		else if(pt[RoomNumber] == OUTROOM){
			printf("빈방 입니다.\n");
		}
		else{
			printf("Error");
		}
	}else{
		printf("방번호를 확인하여 주세요.\n존재하지 않는 방입니다.\n");
	}
	
}

void esc(char* pt) {
        puts("프로그램이 종료됩니다.");
        free(pt);
        exit(0);
}

void disp(char* pt, int su) {
        puts("### 방 현황 ###");
        for (int i = 0; i < su; i++) {
                if (pt[i] == INROOM) {
                        printf("%d호실 - 입실중\n", i);
                }
                else {
                        printf("%d호실 - 빈  방\n", i);
                }
        }
        puts("");
}
