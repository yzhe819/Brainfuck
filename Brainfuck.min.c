#include <stdio.h>
#include <stdlib.h>
char s[30000]={0}, c[10000]; char* p=s+10000; int l=0, stl, st[100];
int main(int argc, char** argv) {
  FILE* f=fopen(argv[1], "r"); while (fread(&c[l], 1, 1, f)==1) {l++;}
  setbuf(stdout, NULL);
  for (int i=stl=0, j, k; i<l; i++) {
    switch (c[i]) {
      case '+': (*p)++; break; case '>': p++; break;
      case '-': (*p)--; break; case '<': p--; break;
      case '.': putchar((int)(*p)); break;
      case ',': (*p)=getchar(); while ((getchar())!='\n'); break;
      case ']': if (*p) {i=st[--stl]-1;} break;
      case '[': 
        if (*p) {st[stl++]=i; break;}
        for (k=i, j=0; k<l; k++) {c[k]=='['&&j++; c[k]==']'&&j--;}
        if (j==0) {i=k; break;} goto ERROR;
    }
  }
  fclose(f); printf("\n"); system("pause"); return 0;
  ERROR: fprintf(stderr, "%s:%dn", __FILE__, __LINE__); return 3;
}