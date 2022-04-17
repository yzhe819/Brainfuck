#include <stdio.h>
#include <stdlib.h>

char s[30000] = {0};
char code[10000];
int length = 0;
int stack[100];
int stack_length = 0;

int main(int argc, char** argv) {
    char c;  // the current character
    int i = 0, j, k;
    FILE* f;
    char* p = s + 10000;

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
                break;
            case '[':
                // Jump forward past the matching ] if the byte at the
                // pointer is zero.
                if (*p) {
                    // mark the current position into the stack
                    stack[stack_length++] = i;
                } else {
                    // this for loop this used to handle multiple nested []
                    // loops in brainfuck
                    for (k = i, j = 0; k < length; k++) {
                        // count the required number of ]
                        code[k] == '[' && j++;
                        // find the match ], reduce the counter
                        code[k] == ']' && j--;
                        if (j == 0)
                            // if the counter is zero, which means jump to the
                            // next ] position, break the switch (NOT the while
                            // loop)
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
                // return to the marked position and continue the while loop
                // this minus 1 will be cancel by i++ at the end of the loop
                i = stack[--stack_length] - 1;
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