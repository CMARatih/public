#include <stdio.h>

#define N 10
#define MAX_LINE 4

int main() 
{
	char s[N];
	char lines[MAX_LINE][N] = {0};
	
	int index = 0;	
	printf("sizeof s[] = %d\n", sizeof(s) );
	
	char* ret = NULL;
	while( (ret = fgets(s, sizeof(s), stdin)) != NULL) {
		//printf("ret = %x\n", ret);		
		fputs(s, stdout);
		
		int i;
		for(i = 0; i < sizeof(s); i++) {
			lines[index][i] = s[i];
		}
		index++;
		
		if ( index >= MAX_LINE ) break;
	}
	
	// 終了
	putchar('\n');
	int i;
	for (i = 0; i < MAX_LINE; i++) {
		int j;
		printf("LINE-> %d: %s\n", i, lines[i]);
	}
	
	return 0;
}
	