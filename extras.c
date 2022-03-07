#include <stdio.h>
#include <stdlib.h>

struct Message {
    char msg[1024];
    int status; // 0: for ok status; -1: for unable to find status; 1: for send again
};

void error_handle(char *message);
char* substr(char* str, int position, int length);

char *substr(char *str, int position, int length)
{
    char *p;
    p = malloc(length + 1);
    if (p == NULL)
        error_handle("Unable to allocate memory.\n");
    int i;
    for (i = 0; i < length; i++)
    {
        *(p + i) = *(str + position - 1);
        str++;
    }

    *(p + i) = '\0';
    return p;
}
void error_handle(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(EXIT_FAILURE);
}