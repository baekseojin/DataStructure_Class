// [문제해결 2-6]문자열별삼각형(재귀)

 #include <stdio.h>

/* 재귀함수로 풀기
//   void f(int n) { // n=5
//   	if(n<1) return; // n이 0이면 함수 호출  
// 		f(n-1);
// 		for(int i=1; i<=n; i++) {
// 			printf("*\n");
// 		}
// 	} 

//  int main() {
//     int n;
//     scanf("%d", &n); // n=5
//     f(n);
//  }
*/

char star[20];
  void f(int n) { 
  	if(n==0) return;  
		f(n-1);
		star[n]='*';
		printf("%s\n", star+1);
	} 

 int main() {
    int n;
    scanf("%d", &n); // n=5
    f(n);
 }