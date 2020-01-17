#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 4095

char buffer[BUFSIZE], regist[BUFSIZE], op[2];

void output(char *out, int length) {
   for (int t=0; t < length; t++) {
      printf("%i\n",*(out + t));
   }
}

int arraylen(char *out) {
   int length = 0;
   do {
      length++;
   } while (out[length] != '\0');
   return length;
}

void process(char *out, char *reg, int length) {
   int rg1[2];
   int s_pos = 0;

   for (int t=0; t < length; t++) {
      int n = *(out + t);

      // Addition
      if (n == 43) {
         reg[s_pos] = rg1[0] + rg1[1];
         s_pos++;
         int rg1[2] = {0,0};
      }
      
      // Value
      else {
         rg1[t % 2] = n;
      }

      
   }

   printf("1. %i\n",rg1[0]);
   printf("2. %i\n",rg1[1]);
}

int main() {
   // printf() displays the string inside quotation
   // malloc(BUFSIZE * sizeof(char));

   buffer[0] = '5';
   buffer[1] = '3';
   buffer[2] = '+';
   buffer[3] = '\0';

   process(buffer,regist,arraylen(buffer));
   output(buffer,arraylen(buffer));
   return 0;
}