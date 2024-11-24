#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define LEN 256
int precedence(char op){
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}
int isoperator(char ch){
    return (ch == '*' || ch == '/' || ch == '-' || ch == '+');
}
int calculation(int a, int b, char op){
    switch(op){
        case '+' : return a+b;
        case '-' : return a-b;
        case '*' : return a*b;
        case '/' :
            if(b==0){
                printf("'Error: Divison by zero'");
                exit(1);
            }
            return a/b;
        default:
            printf("'Error: Invalid expression'");
            exit(1);
    }
}

int evaluate(char *s){
    int valueStack[LEN];
    char operatorStack[LEN];
    int valueTop = -1;
    int operatorTop = -1;
    
    for(int i=0; s[i]!='\0'; i++){
        char ch = s[i];
        if(isspace(ch)) continue;
        
        if(isdigit(ch)){
            int num = 0;
            while (isdigit(ch)) {
                num = num * 10 + (ch - '0');
                i++;
                ch = s[i];
            }
            i--;  
            valueTop++;
            valueStack[valueTop] = num;
        }
        else if(isoperator(ch)){
            while(operatorTop!=-1 && (precedence(operatorStack[operatorTop])>=precedence(ch))){
                int b = valueStack[valueTop--];
                int a = valueStack[valueTop--];
                char op = operatorStack[operatorTop--]; 
                valueTop++;
                valueStack[valueTop] = calculation(a,b,op);
            }
            operatorTop++;
            operatorStack[operatorTop] = ch;
        }
        else{
            printf("'Error: Invalid expression'");
            exit(1);
        }
    }
    while(operatorTop!=-1){
        int b = valueStack[valueTop--];
        int a = valueStack[valueTop--];
        char op = operatorStack[operatorTop--]; 
        valueTop++;
        valueStack[valueTop] = calculation(a,b,op);
    }
    return valueStack[valueTop];
}
int main(){
    char s[LEN];
    printf("Enter string to evaluate\n");
    fgets(s, sizeof(s), stdin);
    int result  = evaluate(s);
    printf("Result: %d\n", result);
    
    return 0;
    
}