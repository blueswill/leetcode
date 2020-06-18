#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isValid(const char *s) {
    char *stack = malloc(strlen(s) + 1);
    stack[0] = '#';
    int top = 1;
    const char *p = s;
    while (*p) {
        char t = *p;
        switch (t) {
            case '(':
            case '{':
            case '[':
                stack[top++] = t;
                break;
            case ')':
                if (stack[top - 1] == '(') {
                    --top;
                    break;
                }
                goto end;
            case '}':
                if (stack[top - 1] == '{') {
                    --top;
                    break;
                }
                goto end;
            case ']':
                if (stack[top - 1] == '[') {
                    --top;
                    break;
                }
            default:
                goto end;
        }
        ++p;
    }
end:
    free(stack);
    return !*p && top == 1;
}

int main(int argc, char *argv[])
{
    printf("%d\n", isValid(argv[1]));
    return 0;
}
