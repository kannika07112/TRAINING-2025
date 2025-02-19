#include<stdio.h>
#include<string.h>
void reversestring(char *str)
{
    int len = strlen(str);
    for (int left = 0, right = len - 1; left < right; left++, right--)
    {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
    }
}
int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Before swapping:%s\n",str);
    reversestring(str);
    printf("Reversed string:%s\n",str);
    return 0;
}