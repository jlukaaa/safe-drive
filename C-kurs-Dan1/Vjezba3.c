
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int dalijepalindrom(char s[])
{
    char temp[100];
    int j = 0;
    for (int i = 0;s[i] != '\n'; i++)
        {
            if (isalpha(s[i]))
                {
                    temp[j++] = tolower(s[i]);
                }
        }
    temp[j] = '\0';

    int lijevo = 0;
    int desno = j - 1;

    while (lijevo < desno)
        {
            if (temp[lijevo] != temp[desno])
                return 0;

            lijevo++;
            desno--;
        }

        return 1;

}


int main ()
{
    char s[100];

    printf("Unesi string: ");
    fgets(s, sizeof(s), stdin);
    if (dalijepalindrom(s))
        printf ("String je palindrom!\n");
    else
        printf ("String nije palindrom!\n");

    return 0;
}