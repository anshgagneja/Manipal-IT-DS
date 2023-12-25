#include <stdio.h>

int strlength(char s[]){
    int l=0;
    for(int i=0;s[i]!='\0';i++){
        l++;
    }
    return l;
}

int strcomp(char s1[], char s2[], int n){
    int i;
    for(i=0;i<n;i++){
        if(s1[i]!=s2[i]){
            break;
        }

    }
    return s1[i]-s2[i];

}

void strcct(char s1[],char s2[], char s3[], int n1, int n2){
    for(int i=0;i<n1;i++){
        s3[i]=s1[i];
    }
    for(int j=0;j<=n2;j++){
        s3[n1+j]=s2[j];
    }
}

void substring(char s1[],char sub[], int pos){
    int l = strlength(s1);
    int l2 = strlength(sub);
    int i=0;
    for(int i=1;i<=(l-pos);i++){
        s1[l+l2-i]=s1[l-i];
    }
    s1[l+l2]='\0';
    for(int j=0;j<l2;j++){
        s1[pos+j]=sub[j];
    }
}

int delstring(char a[], char b[]){
    int flag=0;
    int loc=-1;

    int al=strlength(a);
    int bl=strlength(b);

    for(int i=0;i<=al-bl;i++){
        for(int j=i;j<i+bl;j++){
            flag=1;
            if(a[j]!=b[j-i]){
                flag=0;
                break;
            }
        }
        if(flag==1){
            loc=i;
            break;
        }
    }
    if (loc==-1){
        printf("Substring not found in string");
        return 0;
    }
    for(int i=0;i<al-loc;i++){
        a[loc+i]=a[loc+bl+i];
    }
}

void main(){
    char s1[100],s2[100],s3[100],s4[100],sub[100],del[100];
    int pos,op;

        printf("Enter a string:\n");
        fflush(stdin);
        gets(s1);
        do{
        printf("\nSelect option:\n 1:Length\n 2:Concatenate\n 3:Compare\n 4:Enter substring\n 5:Delete substring\n 6:Exit\n");
        scanf("%d",&op);
        int comp;


        switch(op){
            case 1:
                printf("\nLength of first string is: %d\n",strlength(s1));
                break;

            case 2:
                printf("\nEnter another string:\n");
                fflush(stdin);
                gets(s2);
                int len=strlength(s1);
                int len1=strlength(s2);
                strcct(s1,s2,s3,len,len1);
                printf("Concatenated string is %s\n",s3);
                break;

            case 3:
                printf("\nEnter another string:\n");
                fflush(stdin);
                gets(s4);
                comp=strcomp(s1,s4,len);
                if(comp==0)
                    printf("Strings are identical\n");
                else if(comp>0)
                    printf("String 1 is greater by %d",comp);
                else
                    printf("String 1 is lesser by %d",comp);
                break;

            case 4:
                printf("\nEnter substring\n");
                fflush(stdin);
                gets(sub);
                printf("Enter position to insert\n");
                scanf("%d",&pos);
                substring(s1,sub,pos);
                puts(s1);
                break;

            case 5:
                printf("\nEnter substring to delete\n");
                fflush(stdin);
                gets(del);
                delstring(s1,del);
                puts(s1);
                break;
            case 6:
                break;

            default:
                printf("Enter number only from 1 to 5");
            }
    }
    while(op!=6);

}
