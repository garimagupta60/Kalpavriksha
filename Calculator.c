#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define LEN 64
int precedence(char operatorSymbol){
    if(operatorSymbol == '*' || operatorSymbol == '/') return 2;
    if(operatorSymbol == '+' || operatorSymbol == '-') return 1;
    return 0;
}
int isoperator(char ch){
    return (ch == '*' || ch == '/' || ch == '-' || ch == '+');
}
int calculation(int firstNum, int secondNum, char operatorSymbol){
    switch(operatorSymbol){
        case '+' : return firstNum+secondNum;
        case '-' : return firstNum-secondNum;
        case '*' : return firstNum*secondNum;
        case '/' :
            if(secondNum==0){
                printf("'Error: Divison by zero'");
                exit(1);
            }
            return firstNum/secondNum;
        default:
            printf("'Error: Invalid expression'");
            exit(1);
    }
}

int evaluate(char *expression){
    int valueStack[LEN];
    char operatorStack[LEN];
    int valueTop = -1;
    int operatorTop = -1;
    int lastSymbolWasOperator = 1;  
    for(int i=0; expression[i]!='\0'; i++){
        char ch = expression[i];
        if(isspace(ch)) continue;
        
        if(isdigit(ch) || ch=='-' && (i==0 || isoperator(expression[i-1]))){
            int num = 0;
            if(ch == '-'){
                i++;
                ch = expression[i];
                while (isdigit(ch)) {
                    num = num * 10 + (ch - '0');
                    i++;
                    ch = expression[i];
                }
                num = -num;
                i--;

            }else{
                while (isdigit(ch)) {
                    num = num * 10 + (ch - '0');
                    i++;
                    ch = expression[i];
                }
                i--;
            }
            valueTop++;
            valueStack[valueTop] = num;
            lastSymbolWasOperator = 0;
        }
        else if(isoperator(ch)){
            if(lastSymbolWasOperator){
                printf("'Error: Invalid expression, consecutive operators found.'");
                exit(1);
            }
            while(operatorTop!=-1 && (precedence(operatorStack[operatorTop])>=precedence(ch))){
                int secondNum = valueStack[valueTop--];
                int firstNum = valueStack[valueTop--];
                char operatorSymbol = operatorStack[operatorTop--]; 
                valueTop++;
                valueStack[valueTop] = calculation(firstNum,secondNum,operatorSymbol);
            }
            operatorTop++;
            operatorStack[operatorTop] = ch;
            lastSymbolWasOperator = 1;
        }
        else{
            printf("'Error: Invalid expression'");
            exit(1);
        }
    }
    while(operatorTop!=-1){
        int secondNum = valueStack[valueTop--];
        int firstNum = valueStack[valueTop--];
        char operatorSymbol = operatorStack[operatorTop--]; 
        valueTop++;
        valueStack[valueTop] = calculation(firstNum,secondNum,operatorSymbol);
    }
    return valueStack[valueTop];
}
int main(){
    char expression[LEN];
    printf("Enter string to evaluate\n");
    fgets(expression, sizeof(expression), stdin);
    int result  = evaluate(expression);
    printf("Result: %d\n", result);
    return 0;
    
}