//1

#include<stdio.h>
#include<time.h>

typedef struct Info {
        char name[10];
        int age;
        double height;
}IN,*PIN;

//typedef struct Info IN;
//typedef struct Info* PIN;

//struct Info in;
IN in;

//typedef 자료형 별칭,별칭,별칭...;
// - 자료형에 별칭을 붙이는 키워드..
// - 같은 형태와 같은 성격의 데이터들을 보다 쉽게 구분하고 관리하기 위해서 사용한다...

typedef int AGE, NUM;
typedef int SEL;
typedef char GRA;

AGE age;
NUM num;
SEL select;
NUM no;
GRA grade;

//int age;
//int num;
//int select;
//int no;
//int grade;

int main(void) {

        int a, arr[10], * pt;
        

        return 0;
}

//2
#include<stdio.h>

struct Info {
        char name[10];
        int age;
        double height;
};

int main(void) {

        //구조체 변수
        // - 구조체(사용자 정의 자료형)를 이용하여 만든 변수...
        // - 할당받은 공간은 멤버필드 선언한 그 순서대로 차례로 자리를 잡는다...
        //선언 형식
        //        자료형 변수명;

        struct Info in = { "김민준",20,177.4 };

        //호출
        // - 구조체 공간은 각각의 공간을 구분하기위해서
        //   멤버필드명을 붙인다...
        // - 형식
        //        변수명.멤버필드명

        // . (멤버참조연산자)
        //  - 구조체 또는 공용체 공간의 멤버를 참조하는 연산자..

        //in.age = 20;

        printf("이름 : %s\n", in.name);
        printf("나이 : %d\n", in.age);
        printf("키 : %f\n", in.height);



        return 0;
}

//3
#include<stdio.h>

typedef struct Info {
        char name[10];
        int age;
}IN;

int main(void) {

        //구조체 배열
        // - 구조체 가지고 만든 배열....

        IN arr[2] /*= { {"김민준",20},{"홍길동",20} }*/;

        for (int i = 0; i < 2; i++) {
                printf("이름 입력 : ");
                scanf_s("%s", arr[i].name, sizeof(arr[i].name));
                printf("나이 입력 : ");
                scanf_s("%d", &arr[i].age);
        }


        for (int i = 0; i < 2; i++) {
                printf("이름 : %s\n", arr[i].name);
                printf("나이 : %d\n", arr[i].age);
        }

        return 0;
}

//4
#include<stdio.h>

typedef struct Info {
        char name[10];
        int age;
}IN;


int main(void) {

        IN in = { "김민준",20 };

        //구조체 포인터
        // - 구조체 공간의 주소값을 저장하는 포인터 ...

        IN* pt = &in;


        //(*pt).name

        //연산자 우선순위로 인하여 괄호를 쳐주어야 한다...
        //(*pt).age = 20;
        //복잡해지면 괄호 처리가 불편하다....
        // -> == (* ).
        // - 애로우연산자 , 간접멤버 참조 연산자
        // - 주소값에 해당하는 구조체 또는 공용체 공간의 멤버를 참조하는 연산자...

        printf("이름 : %s\n", pt->name);
        printf("나이 : %d\n", (*pt).age);


        return 0;
}

//5
#include<stdio.h>

typedef struct Info {
        char name[10];
        int age;
}IN;

int main(void) {


        IN arr[2] = { {"�����",20},{"ȫ�浿",20} };

        IN* pt = arr;

        for (int i = 0; i < 2; i++) {
                printf("�̸� : %s\n", pt[i].name);
                printf("�̸� : %s\n", (*(pt + i)).name);
                printf("�̸� : %s\n", (pt + i)->name);
                printf("���� : %d\n", pt[i].age);
        }

        return 0;
}
