#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    } while (n < 0 || n > 8 || n == 0);

    for (int i = 0; i < n ; i++)
    {
        for (int k = n - 1; k >= 0; k--)
        {
            if (k > i)
            {
                printf(" ");
            } else
            {
                printf("#");
            }
        }
        printf("  ");
        for (int j = i; j >= 0; j--)
        {
            printf("#");
        }
        printf("\n");
    }
}
