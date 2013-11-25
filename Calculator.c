#include <stdio.h>
#include <stdlib.h>

void PrintError()
{
	printf("\n!!!! エラー：計算式が正しくありません。!!!!\n");
}

int CalcValue( int a, int b, char symbol )
{	
	int returnValue = a;
	switch( symbol ) {
		case '+':
			returnValue += b;
			break;
		case '-':
			returnValue -= b;
			break;
		case '0':
			printf("例外：CalcValueないぶ\n")
			returnValue;
			break;
	}
	
	return returnValue;
} 


int main( int argc, char* argv[] )
{
	printf("入力された計算式：");
	int i;
	for(i = 0; i < argc; i++) {
		printf("%s ", argv[i]);
	}
	printf("\n");	
	printf("引数の数：%d\n", argc);
	
	int result = 0;
	char symbol = '+';
	
	for(i = 1; i < argc; i++) {
		int numCheck;		
		switch( *argv[i] ) {
			case '+':
			case '-':
				// 既に符号データが入力されていた場合
				if ( symbol != 0 ) {
					PrintError();
					return 0;
				} 
			
				 symbol = *argv[i];
				 break;
			default:
				 numCheck = atoi( argv[i] ); 
				 if ( numCheck == 0 ) {
					PrintError();
					return 0;
				 }
				 
				 result = CalcValue( result, numCheck, symbol );
				 symbol = 0;
		}
	}
	
	printf("計算結果：%d", result);
	
	return 0;
}


