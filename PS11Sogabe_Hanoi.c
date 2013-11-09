#include <stdio.h>
#include <assert.h>

#define N 5

int a[N], b[N], c[N];

void Init()
{
	int i;
	for(i = 0; i < N; ++i) {
		a[i] = i + 1;
		b[i] = c[i] = 0; 
	}
}

void PrintTower(int tower[]) {
	int i;
	for(i = 0; i < N; i++) {
		printf("[%d]", tower[i]);
	}
	printf("\n");
}

void Print()
{	
	printf("A: "); PrintTower(a);
	printf("B: "); PrintTower(b);
	printf("C: "); PrintTower(c);

	printf("\n");
}

// 要素を移動
int Move(int from[], int to[])
{
	int i, j;
	for(i = 0; i < N && !from[i]; i++);
	for(j = 0; j < N && !to[j]; j++);
	j--;
	
	printf("changeValue -> %d\n", from[i]);
	to[j] = from[i];
	from[i] = 0;
	
	Print();
}


void Work( int num, int from[], int to[], int other[] ) {
	if ( num - 1 != 0 ) {
		// a.上の要素を取り外す
		// ↑の要素が、4つのっている。
		// 交互に空きスペースを利用しするため、toとotherを反転させる。
		Work( num - 1, from, other, to );
	}
	
	// 上の要素 n - 1 がfromからotherに移動したため、toに移動することが可能。
	Move(from, to);
	
	
	if ( num - 1 != 0 ) {
		// b. aで取り外した↑の要素をもとに戻す。
		// ( otherに保管。本来のtoの場所に移動させたい。作業は、もともと最初に積んであったfrom） 
		Work( num - 1, other, to, from );
	}
}

void DoWork() {
	Work( 5, a, c, b );	
}

int main()
{
	Init();
	Print();
	
	DoWork();
	Print();

	return 0;
}

