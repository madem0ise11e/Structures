#include <stdio.h>
#include<string.h>
#define MAXLEN 30
#define MAX_NUM 50

struct esame {
char nome[MAXLEN];
int voto;
};

void riempiArrayEsami(struct esame e[], int n);
void stampaArrayEsami(struct esame e[], int n);
int cercaEsame(struct esame e[], int n, char es);

int main() {

  struct esame e[MAXLEN];
  int i, n, res;
  char es;
   printf("Inserisci numero di esami che ha fatto lo studente: ");
   scanf("%d", &n);
   riempiArrayEsami(e,n);
   stampaArrayEsami(e,n);
   printf("\nInserisci l'esame da cercare: ");
   scanf("%s", es);
   res = cercaEsame(e, n, es);
   if (res == 1 || res == -1)
   printf("\nL'esame non e' presente!\n");
   else printf("\nIl voto dell'esame  %s è: %d \n",  e[i].nome, e[i].voto);
return 0;
}

struct esame riempiEsame() {
    struct esame e;
    printf("Dammi esame: ");
    scanf("%s", e.nome);
    printf("Dammi voto: ");
    scanf("%d", &(e.voto));
    return e;
}
void riempiArrayEsami(struct esame e[], int n){
  int i;
  for(i=0; i<n; ++i){
    e[i] = riempiEsame();
  }
}


int cercaEsame(struct esame e[],int n, char es){
  int res = 0, i=0;
  while (i<n && e[i].voto != es)    ++i;
  if (i<n) res = i;
  else res = -1;

  //  res = strcmp(e[i].nome, es);
    //printf("%d", res);
    return res;
}

void stampaArrayEsami(struct esame e[], int n){
  int i;
    for(i=0; i<n; ++i){
      printf("\nEsame %s fatto con voto %d.\n", e[i].nome, e[i].voto);
    }
  }
