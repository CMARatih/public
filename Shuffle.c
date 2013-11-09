#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define N 5

int a[] = { 1, 2, 3, 4, 5 };

void Print()
{
	printf("a[] = ");
	
	int i;
	for(i = 0; i < 5; i++) {
		printf("[%d]", a[i]);
	}
	printf("\n");
}

void Shuffle1()
{	
	int b[N];
	int index = 0;
	
	int i = 0;
	while( i < N && index < N ) {
		int r = rand() % N;
		
		if ( a[r] > 0 ) {
			// データを移動する。
			b[index] = a[r];
			a[r] = 0;
			
			i++;
			index++;		
		}
	} 
	
	// 箱に入れなおす	
	for( i = 0; i < N; i++ ) {
		a[i] = b[i];
	}
}

int main() 
{
	srand(time(NULL));
	printf("rand = %d\n", rand());
	
	Print();
	Shuffle1();
	Print();
	
	return 0;
}

