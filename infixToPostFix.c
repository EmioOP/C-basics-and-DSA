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
      printf("Stack OverFlow \n");
      return 0;
   }else{
      ptr->top = ptr->top + 1;
      ptr->arr[ptr->top] = ch;
      return 1;
   }
}

char pop(struct stack * ptr){
   if(isEmpty(ptr)){
      printf("Stack UnderFlow");
      return '\0';
   } else{
      char ch = ptr->arr[ptr->top];
      ptr->top = ptr->top - 1;
      return ch;
   }
}

char stackTop(struct stack * ptr){
   if(ptr->top == -1) return '\0';
   return ptr->arr[ptr->top];
}

int precedence(char ch){
   if(ch == '^'){
      return 4;
   }else if(ch == '*' || ch == '/'){
      return 3;
   }else if(ch == '+' || ch== '-'){
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
      //checks if the element is an operator or not
      if(!isOperator(infix[i]) && infix[i] != '(' && infix[i] !=')'){
         postFix[j] = infix[i]; // if not an operator it will push to Postfix.
         j++;
         i++;
      } 
      //checking the opening parantheses 
      else if(infix[i] == '('){
         push(sp,infix[i]); // if present the ( will be pushed to stack
         i++;
      } 
      //handling )
      else if(infix[i] == ')'){
         //when infix is a closing parantheses then operator in the stack will be added to postfix.
         while(!isEmpty(sp) && stackTop(sp) != '('){
            postFix[j] = pop(sp);
            j++;
         } if(!isEmpty(sp) && stackTop(sp) == '(' ){
            pop(sp); //when the infix is  ) and top element in stack is ( then we should just pop it
         }
         i++;
      }
      else{
            while(!isEmpty(sp) && stackTop(sp) != '(' && 
                  precedence(infix[i]) <= precedence(stackTop(sp))){
                postFix[j] = pop(sp);
                j++;
            }
            push(sp, infix[i]);
            i++;
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
   
   char * infix = "a+(b*c-(d/e^f)*g)*f";
   printf("PostFix : %s", infixToPostfix(infix));


   return 0;
}

