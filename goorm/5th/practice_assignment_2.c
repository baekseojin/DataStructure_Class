// [실습과제 5-2] 스택이용 후위수식표현

#include <stdio.h>
#define MAX 300
typedef  int element;
typedef struct{
   element data[300];
   int top;
} Stack;

void initStack(Stack* s){
 	s->top = -1;
}

int isEmpty(Stack* s){
    return s->top = -1;
}

int isFull(Stack* s){
    return s->top = MAX-1;
}

void push(Stack* s, element c){
   s->top++;
   s->data[s->top] = c;
}

element pop(Stack* s ){
   element tmp = s->data[s->top];
   s->top--;
   return tmp;
}

int main(){
   int value1, value2, i = 0;
   char expr[300];
   Stack s;
   initStack(&s);
   
   for(i=0; expr[i] != '\0'; i++){
      scanf("%c ", &expr[i]);   
   }

   for(i=0; expr[i] != '\0'; i++) {
      if(expr[i] >= 48 && expr[i] <= 57) // expr[i]가 피연산자(숫자)라면
         push(&s, expr[i]-'0');
      else {
         value2 = pop(&s);
         value1 = pop(&s);
         switch(expr[i]) {
            case '+' : push(&s, (value1 + value2)); break;
            case '-' : push(&s, (value1 - value2)); break;
            case '*' : push(&s, (value1 * value2)); break;
            case '/' : push(&s, (value1 / value2)); break;
         }
      }
   }
   printf("%d", pop(&s));
   return 0;
}