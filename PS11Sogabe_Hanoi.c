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

// �v�f���ړ�
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
		// a.��̗v�f�����O��
		// ���̗v�f���A4�̂��Ă���B
		// ���݂ɋ󂫃X�y�[�X�𗘗p�����邽�߁Ato��other�𔽓]������B
		Work( num - 1, from, other, to );
	}
	
	// ��̗v�f n - 1 ��from����other�Ɉړ��������߁Ato�Ɉړ����邱�Ƃ��\�B
	Move(from, to);
	
	
	if ( num - 1 != 0 ) {
		// b. a�Ŏ��O�������̗v�f�����Ƃɖ߂��B
		// ( other�ɕۊǁB�{����to�̏ꏊ�Ɉړ����������B��Ƃ́A���Ƃ��ƍŏ��ɐς�ł�����from�j 
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

