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

void check_output(char* pt_char, int su){
	int i, j;
	int cnt = 0;
	int index = 0;
	
	for(i='A';i<='Z';i++){
		cnt = 0;
		for(j=0;j<su;j++){
			if(pt_char[j] == i){
				cnt++; 
			}	
		}
		
		if(cnt!=0){
			printf("%c:%d ", i, cnt);
			index++;
			if(index%4==0 || index =='Z'){
				printf("\n");
			}
		}
		
		else if(index%4==0 && i=='Z'){
			printf("\n");
		} //여러 상황에서 실행시켜봐야 할것이여.. 대표적으실행 시켜드릴까요 아 에반데 감사합니다 ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ로 어떤 예외가..? 있나여..? 
	}
		
} //저문제 안품???????????????? 

int main(void){
	int su = input();
	char* ptr_char = (char *)malloc(sizeof(char)*su);
	//그리고 이거때문에 이문제 낸거여... 고민해보시오.. 힌트 있나요ㅕ위에 줬잖아 방금ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ 와일문보다는 이중포문이 나읗듯 ㅅㄱ  
	srand((unsigned)time(NULL));
	
	setData(ptr_char, su);
	disp(ptr_char, su);
	check_output(ptr_char, su);

	free(ptr_char);
	
    return 0;
}
