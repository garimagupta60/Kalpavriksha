#include <stdio.h>

long int calculate_power(long int x,long int y,long int modulus){
    long int ans = 1;
    x = x % modulus;
    while(y>0){
        if(y%2==1){
            ans = (ans * x)% modulus;
            y = y -1;
        }else{
            x = (x * x) % modulus;
            y = y/2;
        }
    }
    return ans;
}
int main() {
    long int base,modulus;
    long int exponent;
    printf("Base (B) : ");
    scanf("%ld",&base);
    while(1){
        printf("Exponent (N): ");
        scanf("%ld",&exponent);
        if(exponent<0){
            printf("Enter valid exponent\n");
            continue;
        }
        
        if(exponent>=0)break;
    }
    while(1){
        printf("Modulus (M): ");
        scanf("%ld",&modulus);
        if(modulus<=1){
            printf("Enter valid modulus\n");
            continue;
        }
        
        if(modulus>1)break;
    }
    long int res = calculate_power(base,exponent, modulus);
    printf("%ld\n",res);
    return 0;
}