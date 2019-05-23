#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void cipher(int key);
string moveAscii(int i, int key, int min, int max, string ciphTxt);

int main(int argc, string argv[])
{
    // Check whether there are precisely 2 cmd args
    if (argc == 2)
    {   
        // Check the second argv (user input)
        string checkIt = argv[1];
        int key = atoi(checkIt);
        // Loop through each char
        for (int i = 0; i < strlen(checkIt); i++)
        {   
            // if any char is no a digit, exit
            if (!isdigit(checkIt[i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            } 
        }  
        cipher(key);
    }
    // Else print and exit the program
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }    
}

//Function to get User message and decrypt it
void cipher(int key)
{
    string plainTxt = get_string("Enter you message: \n");
    string ciphTxt = plainTxt;
    
    printf("Plaintext: %s\n", plainTxt);
    
    // Loop through the chars, and offset them in ascii
    for (int i = 0; i < strlen(plainTxt); i++)
    {
        // Check if punctuation
        if (isalnum(ciphTxt[i]))
        {
            // min / max = starting / end point in ascii lower / upper alphabet
            int min;
            int max;
            // Check upper or lower case
            if (isupper(ciphTxt[i]))
            {
                min = 65;
                max = 90;
                moveAscii(i, key, min, max, ciphTxt);                     
            }
            else
            {
                min = 97;
                max = 122;
                moveAscii(i, key, min, max, ciphTxt);   
            }                    
        }
    }        
    printf("Ciphertext: %s\n", ciphTxt);
}

string moveAscii(int i, int key, int min, int max, string ciphTxt)
{
    int counter = 0;
    // Go through upper chars
    while (counter < key)
    {
        // Wrap from every loop add one, as long as the ascii is < 90
        if (ciphTxt[i] < max)
        {
            ciphTxt[i]++;   
            counter++;                        
        }
        // if the ascii is >= 90, wrap back to A
        else
        {
            ciphTxt[i] = min; 
            counter++;
        }
    } 
    return ciphTxt;
}
