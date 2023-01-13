// [실습과제 1-4] 1차원배열(OX점수)

#include <stdio.h>
int main() {
	int a;
	char arr[81];
	int sum=0;
	int combo=1;
	
	scanf("%d", &a);
	for(int i=0; i<a; i++) // for문 5번 반복
	{
		scanf("%s", arr);
		for(int i=0; arr[i]!='\0'; i++) 
		{
			if(arr[i]=='O')
			{
				sum+=combo; 
				combo++;
			}
			else if(arr[i]=='X') { 
				combo=1;
			}
		}
		printf("%d\n", sum);
		sum=0;
		combo=1;
	}
	
	return 0;
}
