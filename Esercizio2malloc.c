#include <stdio.h>
#include<string.h>

#define MAXLEN 50
#define MAX_NUM 30

struct esame {
char nome[MAXLEN];
int voto;
};
void riempiArrayEsami(struct esame *e[], int n);
void stampaArrayEsami(struct esame *e[], int n);
void cercaEsame(struct esame *e[], int n);

int main() {

  struct esame *e[MAXLEN];
  int i, n, res;

   printf("Inserisci numero di esami che ha fatto lo studente: ");
   scanf("%d", &n);
   riempiArrayEsami(e,n);
   stampaArrayEsami(e,n);

   cercaEsame(e, n);

return 0;
}

void riempiEsame(struct esame *e) {

    printf("Dammi esame: ");
    scanf("%s", e->nome);
    printf("Dammi voto: ");
    scanf("%d", &(e->voto));

}
void riempiArrayEsami(struct esame *e[], int n){
  struct esame *p;
  int i;
  for(i=0; i<n; ++i){
    p= (struct esame *)malloc(sizeof(struct esame));
    e[i] = p;
    riempiEsame(p);
  }
}

void cercaEsame(struct esame *e[],int n){
  int res, i=0;
  char es[MAX_NUM];
  printf("\nInserisci l'esame da cercare: ");
  scanf("%s", es);
  for (i = 0; i<n; ++i){
    res = strcmp(e[i]->nome, es);
    if (res == 0){
      printf("\nIl voto dell'esame  %s e': %d \n",  e[i]->nome, e[i]->voto);
    break;}
  }
  if(res!=0){
  printf("\nL'esame non e' presente!\n");
}
  //  res = strcmp(e[i].nome, es);
    //printf("%d", res);
}

void stampaArrayEsami(struct esame *e[], int n){
  int i;
    for(i=0; i<n; ++i){
      printf("\nEsame %s fatto con voto %d.\n", e[i]->nome, e[i]->voto);
    }
  }
