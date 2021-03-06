#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int input() {
	int su;
	printf("舛呪 脊径: ");
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
	puts("***沓棋 硝督昏 窒径***");
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
		} //食君 雌伐拭辞 叔楳獣佃坐醤 拝依戚食.. 企妊旋生叔楳 獣佃球険猿推 焼 拭鋼汽 姶紫杯艦陥 せせせせせせせせせせせせ稽 嬢恐 森須亜..? 赤蟹食..? 
	}
		
} //煽庚薦 照念???????????????? 

int main(void){
	int su = input();
	char* ptr_char = (char *)malloc(sizeof(char)*su);
	//益軒壱 戚暗凶庚拭 戚庚薦 浬暗食... 壱肯背左獣神.. 微闘 赤蟹推づ是拭 早摂焼 号榎せせせせせせせせせせせせ 人析庚左陥澗 戚掻匂庚戚 蟹斉牛 さぁ  
	srand((unsigned)time(NULL));
	
	setData(ptr_char, su);
	disp(ptr_char, su);
	check_output(ptr_char, su);

	free(ptr_char);
	
    return 0;
}
