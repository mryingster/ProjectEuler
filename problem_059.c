// -*- compile-command: "gcc -o problem_059 problem_059.c -Wall" -*-
// Copyright (c) 2014 Michael Caldwell
#include <stdio.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdlib.h>

FILE *cipherFile;
const int maxCipherSize = 1500;

int decode(int message[], const int length)
{
    int decode[length];
    int key1, key2, key3;

    // Go through possible cipher combinations (3 word key)
    for (key1='a' ; key1<='z' ; key1++)
        for (key2='a' ; key2<='z' ; key2++)
            for (key3='a' ; key3<='z' ; key3++)
	    {
                bool skip = false;
                int index;
                // Decipher message with key
                for (index=0 ; index<length ; index+=3)
		{
                    decode[index+0] = (message[index+0] ^ key1);
                    decode[index+1] = (message[index+1] ^ key2);
                    decode[index+2] = (message[index+2] ^ key3);
                }

                // Filter results. Return first probable result.
                int wordLen = 0;
                for (index=0 ; index<length ; index++)
                {
                    //Check for weird characters
                    if (decode[index] < ' ' || decode[index] > '}')
                    {
                        skip = true;
                        break;
                    }

                    //Check for unreasonably long words
                    if (decode[index] == 32)
                        wordLen = 0;
                    else
                        wordLen++;
                    if (wordLen > 14)
                    {
                        skip = true;
                        break;
                    }
                }

                if (skip == true) continue;

                else // We have a result
                {
                    int sum = 0;
                    // Print deciphered message
                    printf("\nCipher: %c%c%c \n", key1, key2, key3);
                    for (index=0 ; index<length ; index++)
		    {
                        printf("%c", decode[index]);
                        sum+=decode[index];
		    }
                    printf("\n");

                    // Return sum
                    return sum;
                }
            }
    return 0;
}

int main()
{
     printf("Project Euler - Problem 59:\n"
            "Decrypt the message and find the sum of the ASCII values in the original text.\n\n");

    int message[maxCipherSize];

    // Read in cipher to array; Convert ascii to numbers
    cipherFile = fopen ("problem_059.txt", "rt");
    char ch;
    int index = 0, num = 0;
    while((ch = fgetc(cipherFile)))
    {
        if (ch == EOF)
        {
            message[index] = num;
            break;
        }
        if (ch == ',')
        {
            message[index] = num;
            index++;
            num = 0;
            continue;
        }
        num *= 10;
        num += atoi(&ch);
    }
    fclose(cipherFile);

    // Get sum from decode function
    int sum = decode(message, index+1);

    printf("\nSum of decoded ASCII Chars: %i\n", sum);
    return 0;
}
