#include <stdio.h>

// 世界のナベアツ・・・
// 3の倍数と3が付く数字のときだけアホになります

int main()
{
	
	int i;
	for ( i = 0; i < 200; i++ ) {
		if( i % 3 == 0 || i % 10 == 3 ) {
			printf("さぁーん！?\n");
		} else {
			printf("%d\n", i);
		}
	}
	
	return 0;
}
