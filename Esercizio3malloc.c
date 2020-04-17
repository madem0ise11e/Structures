#include <stdio.h>
#include<stdlib.h>
#define MAXLEN 50

struct studente {
char *cognome;
int votoBasso;
int votoAlto;
float mediaVoti;
};

int menu();
void riempiArrayDati(struct studente s*, int n);
void stampaArrayDati(struct studente *p);
void stampaArrayStudente(struct studente *p);
void cercaMedia(struct studente *s, int n);
void eliminaStudente(struct studente *s);

int main() {
  	struct studente *s;
  int n, selezione, i;
  printf("Quanti studenti vuoi inserire? ");
  scanf("%d", &n);
  printf("Riempi i dati per gli studenti:\n");
  s = riempiArrayDati();


    printf("\n\nProgramma menu a selezione\n");
      do {
      printf("\nDigita il numero corrispondente:\n");
      printf("1 per visualizzare i dati dei %d studenti\n2 per vedere i dati dello studente con la media piu' alta\n4 per uscire\n\n", n);
      printf("Selezione: ");
      scanf("%d", &selezione);
      switch(selezione) {
       case 1:

        printf("\nDati dei %d studenti: \n", n);
      stampaArrayStudente(s);
          break;
       case 2:
      //  cercaMedia(s,n);
       break;
       case 4:
       	printf (" USCITA \n");
      break;
        default:
          printf (" Scelta non corretta \n");
        break;
      }
    } while (selezione!=4);
    return 0;
}

/*struct studente riempiDati() {
    struct studente s;
    printf("\nDammi Cognome: ");
    scanf("%s", s.cognome);
    printf("Dammi il voto piu' basso: ");
    scanf("%d", &(s.votoBasso));
    printf("Dammi il voto piu' alto: ");
    scanf("%d", &(s.votoAlto));
    printf("Dammi la media di voti: ");
    scanf("%f", &(s.mediaVoti));
    return s;
}*/

struct studente *riempiDati() {
  struct studente *s=NULL;
  	struct studente s1;
    s= (struct studente *) malloc(sizeof(struct studente));

    s->cognome= (char *) malloc(sizeof(char)*MAXLEN);

    printf("Dammi cognome: ");
    scanf("%s %s", s->cognome);
    printf("Dammi voto piu' basso: ");
    scanf("%d", &(s->votoBasso));
    printf("Dammi voto piu' alto: ");
    scanf("%d", &(s->votoAlto));
    printf("Dammi media voti: ");
    scanf("%f", &(s->mediaVoti));
    	return s;
  }

void riempiArrayDati(struct studente s*, int n){
  int i;
  for(i=0; i<n; ++i){
    s[i] = riempiDati();
  }
}

/*void stampaArrayDati(struct studente s[], int n){
  int i;
    for(i=0; i<n; ++i){
      stampaArrayStudente(s[i]);
    }
  }*/

  void stampaArrayStudente(struct studente *p){
    printf("Studente %s ha il voto piu' alto %d, voto piu' basso %d, media voti %f\n", p->cognome, p->votoAlto, p->votoBasso, p->mediaVoti);
  }



/*void cercaMedia(struct studente *s,int n){
  int i,largest, stud=0;
  largest = s[0].mediaVoti;
  for(i=0; i<n; ++i){
    if (largest < s[i].mediaVoti){
    largest = s[i].mediaVoti;
    stud = i;
    }
  }
  stampaArrayStudente(s[stud]);
}*/

void eliminaStudente(struct studente *s){
  free(s->cognome);
  free(s);
}
