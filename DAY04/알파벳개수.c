#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int input() {
	int su;
	printf("정수 입력: ");
	scanf("%d", &su);
	
	return su;
}

void setData(char* pt, int su){
	int i;
	for(i=0;i<su;i++){
		pt[i] = rand() % 26+65;
	}
}

void disp(char* pt, int su){
	int i;
	puts("***랜덤 알파벳 출력***");
	for(i=0;i<su;i++){
		printf("%-2c", pt[i]);
		if (i%16 == 15 || i == su-1){
			puts("");
		}
	}
	puts("");
}

void check_al(char* pt, int* pt_check, int su){
	int i;
	
	for(i=0;i<su;i++){
		pt_check[pt[i]-'A']++;
	}
}

void check_output(int* pt_check){
	int i;
	
	for(i=0;i<26;i++){
		if(pt_check[i] != 0){
			printf("%c: %d개 \n", i+'A', pt_check[i]);
		}	
	}
}

int main(){
	int su = input();
	char* ptr_char = (char *)malloc(sizeof(char)*su);
	int ptr_check[26] = {0,};
	srand((unsigned)time(NULL));
	
	setData(ptr_char, su);
	disp(ptr_char, su);
	check_al(ptr_char, ptr_check, su);
	check_output(ptr_check);

	free(ptr_char);
	
    return 0;
    
}
