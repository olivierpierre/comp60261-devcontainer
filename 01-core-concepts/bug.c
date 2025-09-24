#include <stdio.h>

int main() {
    int char_num;
    char password[16] = "supersecret";
    char name[16];

    // Prompt the user for their name
    printf("How many characters are in your name? ");
    scanf("%d", &char_num);
    printf("Enter your name: ");
    scanf("%s", name);

    // Print the name character by character
    printf("you entered: ");
    for(int i=0; i<char_num; i++)
        printf("%c", name[i]);
}