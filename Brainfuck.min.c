#include <stdio.h>
#include <stdlib.h>
char s[30000] = {0}, c[10000]; int l = 0, s[100], sl = 0;
int main(int argc, char** argv) {
  char* p = s + 10000; int i = 0, j, k; FILE* f = fopen(argv[1], "r");
  while (fread(&c[l++], 1, 1, f) == 1){};
  fclose(f); setbuf(stdout, NULL);
  while (i++ < l){
    switch (c[i]) {
      case '+': (*p)++; break; case '>': p++; break;
      case '-': (*p)--; break; case '<': p--; break;
      case '.': putchar((int)(*p)); break;
      case ',': (*p) = getchar(); while ((getchar()) != '\n'); break;
      case ']': if (*p) i = s[--sl]-1; break;
      case '[':
        if (*p) {s[sl++] = i; continue; break;} 
        k = i-1, j = 0; do {c[k] == '[' && j++; c[k] == ']' && j--;}
        while (++k < l && j != 0); if (j == 0) {i = k; continue; break;}
        fprintf(stderr, "%s:%dn", __FILE__, __LINE__); return 3; break;
      default: break;
    }
  };
  printf("\n"); system("pause"); return 0;
}