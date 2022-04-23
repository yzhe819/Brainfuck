#include <stdio.h>
#include <stdlib.h>

char s[30000] = {0};
char code[10000];
int length = 0;
int stack[100];
int stack_length = 0;

int main(int argc, char** argv) {
    FILE* f;
    char* p = s + 10000;
    int i = 0, j, k;

    // read the input file
    f = fopen(argv[1], "r");
    while (fread(&code[length], 1, 1, f) == 1) {
        length++;
    }

    setbuf(stdout, NULL);

    // the main loop
    while (i < length) {
        // check each character
        switch (code[i]) {
            case '+':
                (*p)++;  // Increment current value
                break;
            case '-':
                (*p)--;  // Decrement current value
                break;
            case '>':
                p++;  // Increment pointer position
                break;
            case '<':
                p--;  // Decrement cursor position
                break;
            case '.':  // Output current value
                putchar((int)(*p));
                break;
            case ',':  // Input current value
                (*p) = getchar();
                while ((getchar()) != '\n');  // flushes the standard input
                break;
            case '[':
                // Jump forward past the matching ] if the byte at the
                // pointer is zero.
                if (*p) {
                    // mark the current position into the stack
                    stack[stack_length++] = i;
                } else {
                    // this for loop is used to handle multiple nested []
                    for (k = i, j = 0; k < length; k++) {
                        // count the required number of ]
                        code[k] == '[' && j++;
                        // found the matching ], reduce the counter
                        code[k] == ']' && j--;
                        if (j == 0)
                            // if the counter is zero, which means found the
                            // matching ], break for loop
                            break;
                    }
                    if (j == 0) {
                        i = k;
                    } else {
                        // the matching ] is not found, file error
                        // print error message
                        fprintf(stderr, "%s:%dn", __FILE__, __LINE__);
                        return 3;
                    }
                }
                break;
            case ']':
                // Jump back to the matching [ if the byte at the pointer
                // is nonzero.
                if (*p) {
                    i = stack[--stack_length];
                    i--;  // this minus 1 will be cancel by following i++
                }
                break;
            default:
                break;
        }
        i++;
    }
    printf("\n");
    system("pause");
    return 0;
}