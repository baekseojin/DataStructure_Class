// [실습과제 2-4] 알파벳출력

#include <stdio.h>
#include <string.h>
int main() {
	char s[1000001];
	int max=0;
	int size;
	char ans;
	int arr[26];
	
	scanf("%s", s);
	size = strlen(s);
	
	for(int i=0; i<size; i++) {
		if(s[i]>='a') {
			arr[s[i]-'a']++;
		}
		else {
			arr[s[i]-'A']++;
		}
	}
	
	for(int i=0; i<26; i++) {
		if(arr[i]==max) {
			ans = '?';
		}
		else if(arr[i]>max) {
			max = arr[i];
			ans = 'A'+i;
		}
	}
	
	printf("%c", ans);
	return 0;
}