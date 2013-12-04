#include <stdio.h>
#include <stdlib.h>

void PrintError()
{
	printf("\n!!!! エラー：計算式が正しくありません。!!!!\n");
}


int LoadFile( char* fileName, char* str, int strNum )
{
	FILE* fp;
	
	fp = fopen(fileName, "r");
	if ( fp == NULL ) {
		return -1;
	}
	
	// fgetcの戻り値がintのため、intで値をとる。
	char c;
	int i;
	for( i = 0; i < strNum && (c = fgetc(fp)) != EOF; i++ ) {
		str[i] = c;
	}
	str[i] = '\n';
	
	fclose(fp);
	
	return i + 1;
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
			printf("例外：CalcValueないぶ\n");
			break;
	}
	
	return returnValue;
} 

// 計算結果を戻り値として返す関数。
int Calculate( char* str, int num )
{
	int result = 0;
	char symbol = '+';
	
	int i;
	for(i = 0; i < num; i++) {
		int numCheck;
		switch( str[i] ) {
			case ' ':
				break;
			case '=':
			case '\n':
				return result;
			case '+':
			case '-':
				// 既に符号データが入力されていた場合
				if ( symbol != 0 ) {
					PrintError();
					return 0;
				} 
			
				 symbol = str[i];
				 break;
			default:
				 numCheck = atoi( &str[i] ); 
				 if ( numCheck == 0 ) {
					PrintError();
					return 0;
				 }
				 
				 result = CalcValue( result, numCheck, symbol );
				 symbol = 0;
		}
	}	
	return result;
}

int main( int argc, char* argv[] )
{
	printf("引数の数：%d\n", argc);
	if ( argc != 2 ) {
		 printf("Error!! - 引数が正しくありません。\n");
		 return 0; 
	}
	
	char str[256];
	int num;
	
	printf("ファイル[%s]よりデータ読み込み。\n", argv[1] );
	num = LoadFile( argv[1], str, 256 );
	if ( num == -1 ) {
		printf("Error!! - ファイルを開けません。 -\n");
		return 0;
	}
	
	
	printf("入力された計算式：");
	int i;
	for(i = 0; i < num; i++) {
		printf("%c", str[i] );
	}
	printf("\n");

	
	printf("計算しています...\n");
	
	int result;
	result = Calculate( str, num ); 

	printf("計算結果：%d", result);
	
	return 0;
}


