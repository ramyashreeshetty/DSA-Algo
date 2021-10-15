//Q Implement algo to find if string has all unique characters.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    char str[100];
    printf("enter:");
    scanf("%s",str);
    int n=strlen(str);
    int flag=0;


//you cant form a string of 280unique chars out of 128 chars (can assume 256 chars too)
    if(n>128)
    {
        flag=1;
        printf("Not unique");
        exit(0);
    }


//here we are comparing each letter with other best case:O(1) worst case:O(n2) and space:O(1).
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(str[i]==str[j])
            {
                flag=1;
                printf("Not unique");
                exit(0);

            }
        }
    }
    if(flag==0)
    {
        printf("Unique");
    }

}