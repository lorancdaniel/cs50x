#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int getStringLength(string text);
char replaceChar(char x, string arg1, string arg2);
string replaceText(string text, string lowAsci, string highAsci, string argv);
string changeToUpper(string text);
string changeToLower(string text);
bool isUniqueKey(string text);
bool isDuplicate(string text);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage ./substitution key\n");
        return 1;
    }
    int substitutionLength = getStringLength(argv[1]);
    if (substitutionLength != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    if (!(isUniqueKey(argv[1])) || !(isDuplicate(argv[1])))
    {
        printf("Invalid key.\n");
        return 1;
    }
    else
    {
        string plainText = get_string("Plain text:  ");
        string asciiArrayLower = "abcdefghijklmnopqrstuvwxyz";
        string asciiArrayUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string cipherText = replaceText(plainText, asciiArrayLower, asciiArrayUpper, argv[1]);
        printf("ciphertext: %s\n", cipherText);
        return 0;
    }
}

bool isDuplicate(string text)
{
    int count = 0;
    for (int i = 0; i < getStringLength(text); i++)
    {
        for (int j = 1; j < getStringLength(text); j++)
        {
            if (text[i] == text[j] && i != j)
            {
                count++;
            }
        }
    }
    if (count != 0)
    {
        return false;
    }
    return true;
}

bool isUniqueKey(string text)
{
    for (int i = 0; i < getStringLength(text); i++)
    {
        if (!((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122)))
        {
            return false;
        }
    }
    return true;
}

string changeToUpper(string text)
{
    string tempText = text;
    for (int i = 0; i < getStringLength(text); i++)
    {
        tempText[i] = toupper(tempText[i]);
    }
    return tempText;
}

string changeToLower(string text)
{
    string tempText = text;
    for (int i = 0; i < getStringLength(text); i++)
    {
        tempText[i] = tolower(tempText[i]);
    }
    return tempText;
}

string replaceText(string text, string lowAsci, string highAsci, string argv)
{
    int textLength = getStringLength(text);
    string tempArr = text;
    for (int i = 0; i < textLength; i++)
    {
        if (isupper(tempArr[i]))
        {
            argv = changeToUpper(argv);
            tempArr[i] = replaceChar(tempArr[i], argv, highAsci);
        }
        else
        {
            argv = changeToLower(argv);
            tempArr[i] = replaceChar(tempArr[i], argv, lowAsci);
        }
    }
    return tempArr;
}

int getStringLength(string text)
{
    int i = 0;
    while (text[i] != '\0')
    {
        i++;
    }
    return i;
}

char replaceChar(char x, string arg1, string arg2)
{
    for (int i = 0; i < 26; i++)
    {
        if ((int) x == arg2[i])
        {
            return arg1[i];
        }
    }
    return x;
}

