#include<stdio.h>
#include <string.h>
int len(char str[]){
    int i=0;
    while(str[i]!='\0'){
        i++;
    }
    return i;
}
char to_lower_case(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + 32;
    }
    return ch;
}
int is_vowel(char ch){
    if(ch=='a'||ch=='e' || ch=='i'|| ch=='o'||ch=='u'){
        return 1;
    }
    return 0;
}
int main(){
    int rows, cols;
    int maxlength=0;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    if(rows<1 || rows>10 || cols<1 || cols>101){
        printf("Enter valid row b/w 1 to 10 and valid column b/w 1 to 101\n");
    }
    while(getchar()!='\n');
    
    char student_name[100][200][50];
    int names_start_vowel = 0;
    printf("Enter the names:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Name at (%d,%d): ", i, j);
            scanf("%s",student_name[i][j]);
            getchar();
            if(len(student_name[i][j])>maxlength){
                maxlength = len(student_name[i][j]);
            }
            if(is_vowel(to_lower_case(student_name[i][j][0]))){
                names_start_vowel++;
            }
        }
    }
    printf("\nNumber of names starting with a vowel: %d\n", names_start_vowel);
    printf("\nThe longest name:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(is_vowel(to_lower_case(student_name[i][j][0])){ 
                if (len(student_name[i][j])==maxlength)
                    printf("%s\n",student_name[i][j]);
            }
        }
    }
    return 0;
}
