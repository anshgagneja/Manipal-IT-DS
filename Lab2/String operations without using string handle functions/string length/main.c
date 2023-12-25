
//#include <stdio.h>
//int main() {
//    char s[] = "My name is Ansh";
//    int i;
//
//    for (i = 0; s[i] != '\0'; ++i);
//
//    printf("Length of the string: %d", i);
//    return 0;
//}
#include <stdio.h>
#include <stdlib.h>

int main() {

    char str[50];
    int i,length=0;

    printf("Enter a string:\n");
    gets(str);
    for (i=0;str[i]!='\0';i++) {
         length++;
    }
    printf("Length of the String(%s) = %d\n",str,length);
    return 0;
}
