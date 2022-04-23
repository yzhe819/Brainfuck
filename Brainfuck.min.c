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
    while (fread(&code[length], 1, 1, f) == 1) { length++; }
    setbuf(stdout, NULL);

    // parse the code
    while (i < length) {
        switch (code[i]) { // check each character
            case '+': (*p)++; break;  // Increment current value
            case '-': (*p)--; break;  // Decrement current value
            case '>': p++; break;  // Increment pointer position
            case '<': p--; break;  // Decrement cursor position
            case '.': putchar((int)(*p)); break;  // Output current value
            case ',': (*p) = getchar(); break;  // Input current value
            case '[': // Jump forward to the matching ] if the byte at the pointer is zero.
                if (*p) { stack[stack_length++] = i; } // is not zero, mark the [ position into the stack
                else {
                    k = i, j = 0; // init the position and counter
                    do { // count and check ]
                        code[k] == '[' && j++; code[k] == ']' && j--;
                    } while (++k < length && j != 0); // looping for multiple nested []
                    if (j == 0) { i = k; } // find the matching ] and jump to it
                    else { fprintf(stderr, "%s:%dn", __FILE__, __LINE__); return 3; } // file error, not matching ]
                }
                break;
            case ']': // Jump back to the previous [ if the byte at the pointer is nonzero.
                if (*p) { i = stack[--stack_length] - 1; break; }
            default: break;
        }
        i++;
    }
    printf("\n");
    system("pause");
    return 0;
}