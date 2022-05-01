#include <stdio.h>
#include <stdlib.h>

char s[30000] = {0};
char code[10000];
int length = 0;
int stack[100];
int stack_length = 0;

int main(int argc, char** argv) {
    char* p = s + 10000;
    int i = 0, j, k;

    // Read the input file
    FILE* f = fopen(argv[1], "r");
    while (fread(&code[length], 1, 1, f) == 1) { length++; }
    fclose(f);
    setbuf(stdout, NULL);

    // Parse the code and check each character
    while (i < length) {
        switch (code[i]) {
            case '+': (*p)++; break;  // Increment current value
            case '-': (*p)--; break;  // Decrement current value
            case '>': p++; break;  // Increment pointer position
            case '<': p--; break;  // Decrement pointer position
            case '.': putchar((int)(*p)); break;  // Output current value
            case ',': (*p) = getchar(); while ((getchar()) != '\n'); break;  // Input current value
            case ']': // Jump back to the previous [ if the byte at the pointer is nonzero.
                if (*p) { i = stack[--stack_length] - 1; } break;
            case '[': // Jump forward to the matching ] if the byte at the pointer is zero.
                if (*p) { stack[stack_length++] = i; } // is not zero, mark the [ position into the stack
                else {
                    for (k = i, j = 0; k < length; k++) { 
                        code[k] == '[' && j++; // Count the required number of ]
                        code[k] == ']' && j--; // Reduce the counter when found ]
                    } // Looping for multiple nested []
                    if (j == 0) { i = k; } // Found the matching ] and jump to it
                    else { fprintf(stderr, "%s:%dn", __FILE__, __LINE__); return 3; } // File error, not matching ]
                }
                break;
            default: break;
        }
        i++;
    }
    printf("\n");
    system("pause");
    return 0;
}