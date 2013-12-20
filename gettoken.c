#include <stdio.h>
#include <ctype.h>

// 標準入力関数にて、計算式を受け取る。
// 数字と記号を分ける。
// 数字=Number
// OPPlus = +
// OPMinus = -
// OPEqual = 

/*
bool isspace( int c ) → Tab, 空白


 1 2 3 → 1,2,3
 123 → 123 として扱う


*/


enum tokType
{
	
	OpPlus,OpMinus,OpEqual,
	Number,
	EndOfFile
};

static enum tokType gettok(char *buf, int bufsize)
{
	//ここを書く

	int index = 0;
	int c;
	
	// 計算式を入力してください。
	while ( (c = getchar()) != EOF && index < bufsize ) {
		
		if ( isspace(c) ) continue;

		// bufに値を格納。
		buf[index] = c;
		index++;

		// 演算子の場合
		switch(c) {
			case '+': return OpPlus;
			case '-': return OpMinus;
			case '=': return OpEqual;
		};

		// 数字の場合
		if( isdigit(c) ) {
			while( (c = getchar()) != EOF
					 && isdigit(c)
					 && index < bufsize ) 
			{
				buf[index] = c;
				index++;
			} 
			return Number;
		} 
		
		// 意図しない文字の場合
		printf("Error!! - unknown char: %c;\n", c);
		break;
	}
	return EndOfFile;
}

int main()
{
	enum tokType tok;
	char buf[100];

	while((tok = gettok(buf, sizeof(buf))) != EndOfFile)
	{
		printf("tok = %d; buf = [%s]\n", tok, buf);
		
		int i;
        for(i = 0; i < 100; i++){
        	buf[i] = 0;
        }
            
	}
	
	return 0;
}