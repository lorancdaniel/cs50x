#include <cs50.h>
#include <stdio.h>

bool isCardNumberValid(long card);
long get_long_len(long value);
string checkCardProvider(long value);

int main(void)
{
    long cardNumber = get_long("Ender card number: ");
    long cardNumberLength = get_long_len(cardNumber);
    bool isValidLength = (cardNumberLength == 16 || cardNumberLength == 15 || cardNumberLength == 13);
    if (isCardNumberValid(cardNumber) && isValidLength)
    {
        string cardProvider = checkCardProvider(cardNumber);
        printf("%s", cardProvider);
    }
    else
    {
        printf("INVALID\n");
    }
}

string checkCardProvider(long value)
{
    while (value != 0)
    {
        if (value > 9)
        {
            value /= 10;
            if (value < 100)
            {
                break;
            }
        }
    }
    switch (value)
    {
        case 34:
        case 37:
            return "AMEX\n";
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
            return "MASTERCARD\n";
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
            return "VISA\n";
        default:
            return "INVALID\n";
    }
}

long get_long_len(long value)
{
    int l = 1;
    while (value > 9)
    {
        l++;
        value /= 10;
    }
    return l;
}

bool isCardNumberValid(long card)
{
    long cardNumber = card;
    long uneven = cardNumber;
    long even = cardNumber;
    long sumEven = 0, sumUneven = 0;
    even /= 10;
    while (even != 0)
    {
        long i = ((even % 10) * 2);
        if (i >= 10)
        {
            long doubleI = i;
            while (doubleI != 0)
            {
                sumEven += doubleI % 10;
                doubleI /= 10;

            }
            even /= 100;
        }
        else
        {
            sumEven += i;
            even /= 100;
        }
    }
    while (uneven != 0)
    {
        sumUneven += uneven % 10;
        uneven /= 100;
    }
    long checkSum = sumEven + sumUneven;
    if (checkSum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

