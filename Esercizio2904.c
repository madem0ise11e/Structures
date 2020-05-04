#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 50
#define MAX_NUM 30

struct studente {
char cognome[MAXLEN];
char nome[MAXLEN];
float mediaVoti;
int matricola;
};

void riempiArrayDati(struct studente *s[], int n);
void stampaArrayDati(struct studente *s[], int n);
void stampaArrayStudente(struct studente *s);
void cercaMedia(struct studente *s[], int n);
void eliminaStudente(struct studente *s[]);
int cercaXmatricola(struct studente *s[], int n, int mat);
void cercaxCognome(struct studente *s[], int n);
void cercaxNome(struct studente *s[], int n);


int main() {
  struct studente *s[MAXLEN];
  int n, selezione, i,k,res;
  printf("Quanti studenti vuoi inserire? ");
  scanf("%d", &n);
  printf("Riempi i dati per gli studenti:\n");
  riempiArrayDati(s, n);


    printf("\n\n*********** PROGRAMMA MENU A SELEZIONE **********\n");
      do {
      printf("\nDigita il numero corrispondente:\n");
      printf("1 Per visualizzare i dati dei %d studenti\n");
      printf("2 Per vedere i dati dello studente che sta nel certo intervallo di media voti \n");
      printf("3 Per cercare lo studente con la matricola\n");
      printf("4 Per cercare lo studente per cognome\n");
      printf("5 Per cercare lo studente per nome \n");
      printf("0 Per uscire\n\n", n);
      printf("SELEZIONE: ");
      scanf("%d", &selezione);

      switch(selezione) {

       case 1:
        printf("\nDati dei %d studenti: \n", n);
        stampaArrayDati(s,n);
       break;
       case 2:
        cercaMedia(s,n);
       break;
       case 3:
        printf("Dammi matricola da cercare: ");
        scanf("%d", &k);
        res = cercaXmatricola(s, n, k);
        if (res<0) printf("\nLo studente non c'è!\n");
        else printf("\nLo studente si trova in posizione di indice %d\n", res);
       break;
       case 4:
        cercaxCognome(s,n);
       break;
       case 5:
        cercaxNome(s,n);
       break;
       case 0:
        eliminaStudente(s);
        printf (" \n\n******** USCITA ********\n");
       break;
       default:
          printf (" Scelta non corretta \n");
       break;
      }
    } while (selezione!=0);

    return 0;
}

void riempiDati(struct studente *s) {

    printf("\nDammi Cognome: ");
    scanf("%s", s->cognome);
    printf("Dammi Nome: ");
    scanf("%s", s->nome);
    printf("Dammi Matricola: ");
    scanf("%d", &(s->matricola));
    printf("Dammi la media di voti: ");
    scanf("%f", &(s->mediaVoti));

}

void riempiArrayDati(struct studente *s[], int n){
  int i;
  struct studente *p=NULL;
  for(i=0; i<n; ++i){
    p= (struct studente *)malloc(sizeof(struct studente));
    s[i] = p;
    riempiDati(p);
  }
}

void stampaArrayDati(struct studente *s[], int n){
  int i;
  for(i=0; i<n; ++i){
  stampaArrayStudente(s[i]);
  }
}

  void stampaArrayStudente(struct studente *s){
    printf("\nStudente %s %s con matricola %d, \nMedia voti: %f.\n", s->cognome, s->nome, s->matricola, s->mediaVoti);
  }

int cercaXmatricola(struct studente *s[], int n, int mat){
    int res = 0, i=0;
    while (i<n && s[i]->matricola != mat)    ++i;
    if (i<n) res = i;
    else res = -1;
    return res;
  }

void cercaMedia(struct studente *s[], int n){
  int i, pos1, pos2;
  printf("Inserisci intervallo (esempio: 18 25) ->  ");
  scanf("%d %d", &pos1, &pos2);
  for(i=0; i<n; ++i){
    if (s[i]->mediaVoti >= pos1 && s[i]->mediaVoti <= pos2)
      stampaArrayStudente(s[i]);
  }
}

void cercaxCognome(struct studente *s[], int n){
  int res, i=0;
  char cog[MAX_NUM];
  printf("\nInserisci cognome da cercare: ");
  scanf("%s", cog);
  for (i = 0; i<n; ++i){
    res = strcmp(s[i]->cognome, cog);
    if (res == 0){
        stampaArrayStudente(s[i]);
    }
  }
  if(res!=0){
    printf("\nLo studente non e' presente!\n");
  }
}

void cercaxNome(struct studente *s[], int n){
  int res, i=0;
  char nom[MAX_NUM];
  printf("\nInserisci nome da cercare: ");
  scanf("%s", nom);
  for (i = 0; i<n; ++i){
    res = strcmp(s[i]->nome, nom);
    if (res == 0){
        stampaArrayStudente(s[i]);
    }
  }
  if(res!=0){
    printf("\nLo studente non e' presente!\n");
  }
}

void eliminaStudente(struct studente *s[]){
	free(s);
  printf("\nLibero la memoria.");
}
