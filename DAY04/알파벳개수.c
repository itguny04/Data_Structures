#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int input() {
	int su;
	printf("���� �Է�: ");
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
	puts("***���� ���ĺ� ���***");
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
		} //���� ��Ȳ���� ������Ѻ��� �Ұ��̿�.. ��ǥ�������� ���ѵ帱��� �� ���ݵ� �����մϴ� �������������������������� � ���ܰ�..? �ֳ���..? 
	}
		
} //������ ��ǰ???????????????? 

int main(void){
	int su = input();
	char* ptr_char = (char *)malloc(sizeof(char)*su);
	//�׸��� �̰Ŷ����� �̹��� ���ſ�... ����غ��ÿ�.. ��Ʈ �ֳ�������� ���ݾ� ��ݤ����������������������� ���Ϲ����ٴ� ���������� ���Ƶ� ����  
	srand((unsigned)time(NULL));
	
	setData(ptr_char, su);
	disp(ptr_char, su);
	check_output(ptr_char, su);

	free(ptr_char);
	
    return 0;
}
