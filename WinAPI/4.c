#include <windows.h>
#include <stdio.h>

#define BUFFERSIZE  100

#pragma comment (lib, "User32.lib")

int main()
{
    int c, i;
    char inputPrompt[BUFFERSIZE];

    // Recieve the input from the user.
    printf("Please enter the input prompt: ");
    for( i = 0 ; i < BUFFERSIZE - 1, (c = getchar()) != EOF, c != '\0', c != '\n' ; inputPrompt[i++] = c)
        ;
    inputPrompt[i] = '\0';

    printf("[%s] bext\n\n", inputPrompt);

    // A message box to display.
    MessageBox(
        NULL,           /* hWnd: A handle to the owner window. */
        inputPrompt,    /* lpText: A long-pointer to the display text. */
        NULL,           /* lpCaption: a long-pointer to the title text. */
        MB_OKCANCEL     /* uType: An bit-field value that indicates the behavior and contents of the message box. */
    );
}