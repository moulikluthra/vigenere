#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

#pragma warning(disable : 4996)

char* vigenere_encrypt(char* plain_text, char* key, char* alphabet) 
{
    static char encrypted_text[1000]; // Assuming a maximum length of 1000 characters for the encrypted text
    int key_length = strlen(key);
    int text_length = strlen(plain_text);

    for (int i = 0, j = 0; i < text_length; i++, j = (j + 1) % key_length) {
        char current_char = plain_text[i];
        if (isalpha(current_char)) 
        {
            char shift = key[j] - (isupper(key[j]) ? 'A' : 'a');
            encrypted_text[i] = alphabet[(toupper(current_char) - 'A' + shift) % ALPHABET_SIZE];
        }
        else 
        {
            encrypted_text[i] = current_char;
        }
    }

    encrypted_text[text_length] = '\0';
    return encrypted_text;
}

char* vigenere_decrypt(char* encrypted_text, char* key, char* alphabet)
{
    static char decrypted_text[1000]; // Assuming a maximum length of 1000 characters for the decrypted text
    int key_length = strlen(key);
    int text_length = strlen(encrypted_text);

    for (int i = 0, j = 0; i < text_length; i++, j = (j + 1) % key_length) 
    {
        char current_char = encrypted_text[i];
        if (isalpha(current_char)) 
        {
            char shift = key[j] - (isupper(key[j]) ? 'A' : 'a');
            decrypted_text[i] = alphabet[(toupper(current_char) - 'A' - shift + ALPHABET_SIZE) % ALPHABET_SIZE];
        }
        else 
        {
            decrypted_text[i] = current_char;
        }
    }

    decrypted_text[text_length] = '\0';
    return decrypted_text;
}

int main()
{
    char alphabet[ALPHABET_SIZE + 1];
    char key[100];
    char text[1000];
    int choice;

    printf("Enter the alphabets : ");
    scanf("%s", alphabet);

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);

    printf("Enter the text: ");
    scanf(" %[^\n]s", text);

    if (choice == 1)
    {
        char* encrypted_text = vigenere_encrypt(text, key, alphabet);
        printf("Encrypted text: %s\n", encrypted_text);
    }
    else if (choice == 2) 
    {
        char* decrypted_text = vigenere_decrypt(text, key, alphabet);
        printf("Decrypted text: %s\n", decrypted_text);
    }
    else
    {
        printf("Invalid choice.\n");
    }

    return 0;
}