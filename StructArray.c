#include<stdio.h>
#define MAXLEN 5

struct studente {
char cognome[MAXLEN];
int numEsami;
};

int main() {
struct studente arrayStudenti[MAXLEN];
  //Leggi
  int i;
  for(i = 0; i < MAXLEN; ++i){
    printf("Cognome e numero esami dello studente %d: ", i+1);
    scanf("%s %d", arrayStudenti[i].cognome, &(arrayStudenti[i].numEsami));
  }
  printf("\n");
  //Stampa
 for(i=0; i<MAXLEN; ++i){
   printf("Cognome e numero esami dello studente %d: ", i+1);
   printf("%s %d\n", arrayStudenti[i].cognome, arrayStudenti[i].numEsami);
 }
 return 0;
}
