#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
   int size;
   int top;
   char * arr; 
};

int isEmpty(struct stack * ptr){
   if(ptr->top == -1){
      return 1;
   }
   return 0;
}

int isFull(struct stack * ptr){
   if(ptr->top == ptr->size - 1){
      return 1;
   }   
   return 0;
}

int push(struct stack * ptr, char ch){
   if(isFull(ptr)){
      printf("Stack OverFlow");
      return 0;
   }else{
      ptr->top = ptr->top + 1;
      ptr->arr[ptr->top] = ch;
   }
}

char pop(struct stack * ptr){
   if(isEmpty(ptr)){
      printf("Stack UnderFlow");
      return 0;
   } else{
      char ch = ptr->arr[ptr->top];
      ptr->top = ptr->top - 1;
      return ch;
   }
}

int stackTop(struct stack * ptr){
   if(ptr->top == -1) return 0;
   return ptr->arr[ptr->top];
}

int precedence(char ch){
   if(ch == '*' || ch == '/'){
      return 3;
   } else if(ch == '+' || ch== '-'){
      return 2;
   } else 
      return 0;
}

int isOperator(char op){
   if(op == '+' || op == '-' || op == '*' || op== '/' || op== '^'){
      return 1;
   }
   return 0;
}


char * infixToPostfix(char * infix){
   struct stack * sp =(struct stack *)malloc(sizeof(struct stack));
   sp->size = 50;
   sp->top = -1;
   sp->arr = (char *)malloc(sp->size * sizeof(char));

   char * postFix = (char *) malloc((strlen(infix)+1) * sizeof(char));
   int i = 0; //track the infix traversal
   int j = 0; //post fix addition

   while(infix[i] != '\0'){
      if(!isOperator(infix[i]) ){
         postFix[j] = infix[i];
         j++;
         i++;
      }else{
         if(precedence(infix[i]) > precedence(stackTop(sp)) || stackTop(sp) == '(' || stackTop(sp) == ')'){
            push(sp,infix[i]);
            i++;
         }else{
            if(isOperator(stackTop(sp))){
               postFix[j] = pop(sp);
               j++;
            } else{
               pop(sp);
            }
            
         }
      }

   }
   while(!isEmpty(sp)){
      if(isOperator(stackTop(sp))){
         postFix[j] = pop(sp);
         j++;
      } else{
         pop(sp);
      }
   }

   postFix[j] = '\0';
   return postFix;
}


int main(){
   
   char * infix = "a+(b*c-(d/e)*g)*h";
   printf("PostFix is %s", infixToPostfix(infix));


   return 0;
}

