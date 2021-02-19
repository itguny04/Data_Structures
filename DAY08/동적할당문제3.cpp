#include <stdio.h>
#include <stdlib.h>
#define SWAP(a,b) {a^=b; b^=a; a^=b;} 

typedef struct People{
	char name[10];
	int math,kor,eng,score,grade;
}People;

int input(const char* msg){
	int t;
	//음... 어.. 
	printf("%s",msg);
	scanf("%d", &t);
	
	return t;
}

void input_data(int t, People* student){
	int i;
	
	for(i=0;i<t;i++){
		printf("%d번째 사람의 이름 : ", i+1);
		scanf("%s", student[i].name);
		
		student[i].kor = input("국어 점수:");
		student[i].eng = input("영어 점수:");
		student[i].math = input("수학 점수:");
	}
	
}

void sum_score(int t, People* stu){
	int i;
	
	for(i=0;i<t;i++){
		stu[i].score = stu[i].kor + stu[i].eng + stu[i].math;
		//printf("%d\n", stu[i].score);
	}
	
}

void set_rank(int t, People* stu){
	int i, j;
	for(i=0;i<t;i++){
		stu[i].grade = 1;
		for(j=0;j<t;j++){
			if(stu[i].score < stu[j].score){
				stu[i].grade++;
			}
		}	
	}
	/*
	printf("%d", stu[0].grade);
	printf("%d", stu[1].grade);
	printf("%d", stu[2].grade);
	*/	
}

void printInfo(int t, People* stu){
	int i;
	puts("이름\t국어\t영어\t수학\t총점\t순위");
	for(i=0;i<t;i++){
		printf("%s\t%d\t%d\t%d\t%d\t%d\n",stu[i].name, stu[i].kor, stu[i].eng, stu[i].math, stu[i].score, stu[i].grade);
	}
	
}

int main(void){
	People* student;
	int t;
	int i;

	t = input("인원수를 입력해주세요: ");
	student = (People *)malloc(sizeof(People)*t);

	input_data(t, student);
	sum_score(t, student);
	set_rank(t, student);
	printInfo(t, student);
	
	free(student);
	
	return 0;
}
