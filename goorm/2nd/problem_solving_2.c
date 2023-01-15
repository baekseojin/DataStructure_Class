// [문제해결 2-2] 메모리 동적할당

#include <stdio.h>
#include <stdlib.h>

/*
int maxh(int* h[], int n) { // int* h == int h[]
	for(i=1; i<=n; i++) {
		if(max<h[i]) {
			max = h[i];
		}
	}
	return max;
}
// malloc : memory allocation 
int main(){
  int n;
  int i;
	int* h = (int*)malloc(sizeof(int)*100); // == int h[100]; 
	scanf("%d", &n); 
	for(i=0; i<n; i++) {  
		scanf("%d", &h[i]);
	}
	printf("%d\n", maxh(h, n)) ; // 160, 171, 180 ,162, 165, 5
	free(h);
  return 0; 
}
*/

// *(h+1) = h[1]
int maxh(int* h, int n) { // int* h == int h[]
	int i;
	int max = *(h+0); 
	for(i=1; i<=n; i++) {
		if(max<*(h+i)) {
			max = *(h+i);
		}
	}
	return max;
}
// malloc : memory allocation 
int main(){
  int n;
  int i;
	int* h = (int*)malloc(sizeof(int)*100); // == int h[100]; 
	scanf("%d", &n); 
	for(i=0; i<n; i++) {  
		scanf("%d", h+i);
	}
	printf("%d\n", maxh(h, n)) ; // 160, 171, 180 ,162, 165, 5
	free(h);
  return 0; 
}