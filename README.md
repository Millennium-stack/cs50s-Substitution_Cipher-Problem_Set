# cs50s-Substitution_Cipher-Problem_Set
This program aims to implement the substitution cipher technique to encipher a plain text message to a cryptic text.

To do so, we use a key: in this case, a mapping of each of the letters of the alphabet to the letter it should correspond to when we encrypt it.

To “decrypt” the message, the receiver of the message would need to know the key, so that they can reverse the process: translating the encrypt text (generally called ciphertext) back into the original message (generally called plaintext).

A key, for example, might be the string NQXPOMAFTRHLZGECYJIUWSKDVB. This 26-character key means that A (the first letter of the alphabet) should be converted into N (the first character of the key), B (the second letter of the alphabet) should be converted into Q (the second character of the key), and so forth.

A message like HELLO, then, would be encrypted as FOLLE, replacing each of the letters according to the mapping determined by the key.

At the time the user executes the program, they should decide, by providing a command-line argument, on what the key should be in the secret message they’ll provide at runtime.

Neither the comma nor the space must be substituted by the cipher. We only substitute the alphabetical characters. Also, the case of the original message is preserved i.e., the lowercase letters remain lowercase and the uppercase letters remain uppercase.

Whether the characters in the key itself are uppercase or lowercase doesn’t matter. A key of VCHPRZGJNTLSKFBDQWAXEUYMOI is functionally identical to a key of vchprzgjntlskfbdqwaxeuymoi (as is, for that matter, VcHpRzGjNtLsKfBdQwAxEuYmOi).



Specification:

1. Our program accepts a single command-line argument, the key to use for the substitution. The key itself is case-insensitive, so whether any character in the key is uppercase or lowercase does not affect the behavior of our program.

2. If our program is executed without any command-line arguments or with more than one command-line argument, our program prints an error message of our choice (with printf) and returns from main a value of 1 (which tends to signify an error) immediately.

3. If the key is invalid (as by not containing 26 characters, containing any character that is not an alphabetic character, or not containing each letter exactly once), our program prints an error message of our choice (with printf) and returns from main a value of 1 immediately.

4. Our program outputs a plaintext: (without a newline) and then prompts the user for a string of plaintext (using get_string).

5. Our program outputs a ciphertext: (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext substituted for the corresponding character in the ciphertext; non-alphabetical characters is outputted unchanged.

6. Our program preserves the case: capitalized letters remain capitalized letters; lowercase letters remain lowercase letters.

7. After outputting ciphertext, we print a newline. Our program then exits by returning 0 from main.


Output: -


![alt text](https://github.com/Millennium-stack/cs50s-Substitution_Cipher-Problem_Set/blob/master/images/substitution.jpg?raw=true)
