#include<stdio.h>
#include<malloc.h>
#include<Windows.h>

#define IN 1
#define OUT 0

int input(const char* msg);
char* setRooms(int su);
void menu(char* pt, int su);
void esc(char* pt);
void disp(char* pt, int su);
void checkIn(char* pt, int su);
void checkOut(char* pt, int su);
int roomInput(const char* msg, int su);

int main(void) {

        int su = input("방 개수 입력");
        
        char* pt = setRooms(su);

        menu(pt, su);

        return 0;
}

int input(const char* msg) {
        int su;
        printf("%s : ", msg);
        scanf_s("%d", &su);
        return su;
}

char* setRooms(int su) {
        char* pt = (char*)malloc(su);

        for (int i = 0; i < su; i++) {
                pt[i] = OUT;
        }

        return pt;
}

void menu(char* pt, int su) {

        system("pause");
        system("cls");

        while (1) {
                int select = input("1.입실 2.퇴실 3.보기 4.종료");

                switch (select) {
                case 1:
                        checkIn(pt, su);
                        break;
                case 2:
                        checkOut(pt, su);
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

void esc(char* pt) {
        puts("프로그램이 종료됩니다.");
        free(pt);
        exit(0);//프로그램 종료 함수
}

void disp(char* pt, int su) {
        puts("### 방 현황 ###");
        for (int i = 0; i < su; i++) {
                if (pt[i] == IN) {
                        printf("%d호실 - 입실중\n", i + 1);
                }
                else {
                        printf("%d호실 - 빈  방\n", i + 1);
                }
        }
        puts("");
}

void checkIn(char* pt, int su) {
        disp(pt, su);
        int room = roomInput("입실할 방번호 입력", su);
        
        if (pt[room - 1] == IN) {
                printf("%d호실은 입실중입니다.\n", room);
        }
        else {
                pt[room - 1] = IN;
                printf("%d호실에 입실하셨습니다.\n", room);
        }
}
void checkOut(char* pt, int su) {
        disp(pt, su);
        int room = roomInput("퇴실할 방번호 입력", su);

        if (pt[room - 1] == OUT) {
                printf("%d호실은 빈방입니다.\n", room);
        }
        else {
                pt[room - 1] = OUT;
                printf("%d호실에 퇴실하셨습니다.\n", room);
        }
}

int roomInput(const char* msg, int su) {
        int room;
        do {
                room = input(msg);
        } while (room < 1 || room > su);

        return room;
}
