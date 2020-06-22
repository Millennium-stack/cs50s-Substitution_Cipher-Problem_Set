/*
This program aims to implement the substitution cipher technique to encipher a plain text message to a cryptic text.
*/

// Include the header files
#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

bool validateKey (int, string); // aims to validate the entered key
bool repeatAlpha (string); // checks for repeated alphabets in the key
bool checkAlpha (string); // checks for anyother character i.e. a non -alphabet in the key
string encipherText(string, string); // encrypts the plaintext to a cryptic text

int main(int argc, string argv[])
{
    if (!validateKey(argc, argv[1])) // validating the key
    {
        return 1; // returns 1 if the key is invalid
    }

    else // executes the inner statements if the key is valid
    {
        string s = get_string("plaintext: "); // prompts the user for the plaintext

        printf("ciphertext: %s\n", encipherText(s, argv[1])); // prints the cipher text

        return 0; // returns 0 after execution
    }
}


// This function accepts 2 inputs, the number of command-line arguments and the key to encipher the text.
bool validateKey (int argLen, string key)
{
    if (key == '\0' || argLen > 2) // checks for a null key or the number command line arguments entered
    {
        printf("Usage: ./substitution key\n");
        return false;
    }

    else if (strlen(key) != 26) // checks for the length of entered key
    {
        printf("Key must contain 26 characters\n");
        return false;
    }

    else if (repeatAlpha(key)) // checks for any repeated character in the key
    {
        printf("Key must not repeat an alphabet\n");
        return false;
    }

    else if (checkAlpha(key)) // checks for any other character except the alphabets
    {
        printf("Key must contain only alphabets\n");
        return false;
    }

    else     // else returns true if none of the above conditions are satisfied i.e., the key is valid
        return true;
}


// This function accepts the key as input and checks for repeated alphabets.
bool repeatAlpha (string key)
{
    int count = 0; // counter variable

    for (int i = 0, n = strlen(key); i < n ; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            // This condition checks every individual charcter to the next character simultaneously.
            if (key[i] == key[j] || key [i] == toupper(key [j]))
            {
                count++; // this counter is used to validate the function later on.
                break; // if match found break.
            }

            else
            {
                continue; // else move to the next iteration.
            }
        }
    }

    if (count > 0) // if the counter is greater than 0, (counter == 1), an alphabet has repeated
    {
        return true;
    }

    else // else no repetition
    {
        return false;
    }
}


// This function accepts the key and checks for anyother character except alphabets.
bool checkAlpha (string key)
{
    int count = 0; // counter variable

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        // This condition isalpha() checks every character in the key for an alphabet and executes the statement if not.
        if (!isalpha(key[i]))
        {
            count = 1; // this counter is used to validate the function.
            break; // if true then break the iteration.
        }

        else
        {
            continue; // else continue
        }
    }

    if (count == 1) // if the counter == 1, there's a non-alphabetic character.
    {
        return true;
    }

    else // else the key contains only the alphabets
    {
        return false;
    }
}


// This function accepts 2 inputs, the plaintext to be encrypted and the ket to encrypt the text
string encipherText(string s, string key)
{
    string ref = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // This is a reference to the standard alphabetical order of english letters.

    for (int i = 0, m = strlen(s); i < m; i++)
    {
        for (int j = 0, n = strlen(ref); j < n; j++)
        {
            if (s[i] == ref[j] || s[i] == tolower(ref[j])) // This condition maps the plaintext alphabets to the standard alphabetical text order
            {
                if (isupper(s[i])) //checks for uppercase letter in the plaintext
                {
                    s[i] = toupper(key[j]); // assigns the key value of the mapped index i from the reference alphabets
                }

                else // else if lowercase then
                {
                    s[i] = tolower(key[j]); // assign the key value of the mapped index i from the reference alphabets
                }

                break; // break the iteraion of the key after substitution
            }

            else
                continue; // move to the next iteration
        }
    }

    return s; // returns the enciphered text
}