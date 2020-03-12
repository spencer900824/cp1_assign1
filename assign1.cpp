#include <stdio.h>

int isbefore(int *A,int f,int l)
{
	int find_f = 0;
	for( ; 1 ; A++)
	{
		if( *A == f )
			find_f = 1;
		if( *A == l )
			return find_f ? 1 : 0;
	}
}

int max(int *A , int n)
{
	int ma=-1;
	for( int i=0; i<n ; i++)
		*(A+i)>ma ? ma=*(A+i) : ma;
	return ma;
}


int main()
{
	int n ;
	scanf("%d",&n);
	int ans[n];//正確答案
	for(int i=0 ; i<n ; i++)
		scanf("%d",ans+i);

	int sol[n];//學生的答案
	while(scanf("%d",sol)!=EOF)
	{
		for(int i=1 ; i<n ; i++)
			scanf("%d",sol+i);

	
		int score[n];//得到的分數
		for( int i=0 ; i<n ; i++)
		{
			score[i] = 1;
			for( int j=0 ; j<i ;j++)
			{
				if( isbefore(ans , sol[j] , sol[i]) && score[j]==score[i])
					score[i]++;
			}
		}

		printf("%d\n",max(score,n));
    }
	return 0;
}
