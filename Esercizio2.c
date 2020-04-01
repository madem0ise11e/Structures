#include <stdio.h>
#define MAXLEN 30

struct esame {
char esame;
int voto;
};

int main() {

  struct esame numEsami[MAXLEN];
  int i, n;

  printf("Inserisci numero di esami che ha fatto lo studente: ");
  scanf("%d", &n);

  for(i = 0; i < n; ++i){
    printf("Esame e voto dello studente: ");
    scanf("%s %d", numEsami[i].esame, &(numEsami[i].voto));
  }


  printf("\nInserisci l'esame da cercare: ");
  scanf("%s", numEsami[i].esame);

  printf("Il voto dell'esame  %s è: %d",  numEsami[i].esame, &(numEsami[i].voto));
// una condizione if else se l'esame non è presente
  printf("\nL'esame non è presente.");
}
