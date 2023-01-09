// [실습과제1-2] 1차원배열(부등호)

#include <stdio.h>
 
int main()
{
    int arr[1001];
    int n;
    
    scanf("%d",&n);
    for(int i = 0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    for(int k = 0; k<n; k++){
        printf("%d:",k+1);
        for(int j = 0; j < n; j++){
            if(k != j){ // k와 j가 다를 때, 즉 k 자신과 비교를 안하고 부등호 출력
                if(arr[k] > arr[j]){printf(" >");} // 
                else if(arr[k] < arr[j]){printf(" <");}
                else{printf(" =");}
            }
        }
        printf("\n");
    }
    return 0;
}
