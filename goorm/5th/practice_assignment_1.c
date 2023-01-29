// [실습과제 5-1] 스택이용 펠린드롬

#include <stdio.h>
#define MAX 100
typedef char element;
typedef struct Stack{
 element str[MAX];
 int top;
}Stack;

void initStack(Stack *s){
   s->top = -1;
}

int isFull(Stack *s){
 return s->top == MAX-1;
}

int empty(Stack *s){
 return s->top == -1;
}

void push(Stack* s, char c){
 if(isFull(s))
 {
  printf("FULL");
 }
 else
 {
   s->top++;
  s->str[s->top] = c;
 }
}

char pop(Stack *s){
 char Temp;
 if(empty(s)){
  printf("EMPTY");
  return 0;
 }
   Temp = s->str[s->top];
   s->top--;
 return Temp;
}

int palindrome(char String[]){
   Stack S;
   int i;
   initStack(&S);
   for(i=0; String[i]!='\0'; i++){
      push(&S, String[i]);
   }
   for(i=0; String[i]!='\0'; i++){
      if(String[i] == pop(&S))
         continue;
      else
         return 0;
   }
   return 1;
}

int main(void){
 char str[MAX];
 scanf("%s",str);

 if(palindrome(str))
  printf("TRUE");
 else
  printf("FALSE");
 return 0;
}