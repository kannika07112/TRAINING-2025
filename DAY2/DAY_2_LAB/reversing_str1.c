#include <stdio.h>
#include <string.h>
int findlength(char *str)
{
    int length = 0;
    for (char *p_ch = str; (*p_ch) != 0; p_ch++)
    {
        length++;
    }
    return length;
}
void reversestring(char *str)
{
    int len = findlength(str);
    for (int left = 0, right = len - 1; left < right; left++, right--)
    {
        char temp = *(str + left);
        *(str + left) = *(str + right);
        *(str + right) = temp;
    }
}
int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Before swapping:%s\n", str);
    reversestring(str);
    printf("Reversed string:%s\n", str);
    return 0;
}