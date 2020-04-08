#include <stdio.h>
#define MAXLEN 50
#define MAX_NUM 30
//#define somma x+y

struct studente{
    char nome[MAXLEN];
    char cognome[MAXLEN];
    int matricola;
    float media;
  }; // Non alloco memoria

void riempiArrayStudenti(struct studente s[], int n);
void stampaArrayStudenti(struct studente s[], int n);
int cercaStudente(struct studente s[], int n, int mat);
int main() {
  int len, k, res;
  /*char nome[MAXLEN];
  char cognome[MAXLEN];
  int matricola;
  float mediaVoti;*/ // tutto questo lo dichiaro in struct

/*  struct {
    char nome[MAXLEN];
    char cognome[MAXLEN];
    int matricola;
    float media;
  } s1, s2;*/ //questo dichiaro fuori main

  //struct studente s1, s2; // Alloco memoria per variabile s1 che
                      // sarà una struttura di tipo struct studente
  /* char nome[MAX_NUM][MAXLEN];
  char cognome[MAX_NUM][MAXLEN];
  int matricola[MAX_NUM];
  float media[MAX_NUM];*/
  struct studente s[MAX_NUM]; //alloco memoria per l'array s che sarà un array
                            //composto da MAX_NUM elementi di tipo struct studente
/*  printf("Dammi nome e cognome? ");
  scanf("%s %s", s1.nome, s1.cognome);
  printf("Dammi matricola e media? ");
  scanf("%d %f", &(s1.matricola), &(s1.media));
  printf("Nome: %s Cognome: %s Matricola: %d Media %f\n",
            s1.nome, s1.cognome, s1.matricola, s1.media);
  struct studente s3;
  s2 = s1;
  s3 = s1;
   s2.media += 1;*/
   printf("Quanti elementi vuoi inserire? ");
   scanf("%d", &len);
   riempiArrayStudenti(s,len);
   stampaArrayStudenti(s,len);
   printf("Dammi matricola da cercare: ");
   scanf("%d", &k);
   res = cercaStudente(s, len, k);
   if (res<0) printf("\nLo studente non c'è!\n");
   else printf("\nLo studente si trova in posizione di indice %d\n", res);
return 0;
}

int cercaStudente(struct studente s[], int n, int mat){
  int res = 0, i=0;
  while (i<n && s[i].matricola != mat)    ++i;
  if (i<n) res = i;
  else res = -1;
  return res;
}

struct studente riempiStudente() {
    struct studente s;
    printf("Dammi cognome e nome: ");
    scanf("%s %s", s.cognome, s.nome);
    printf("Dammi matricola e media: ");
    scanf("%d %f", &(s.matricola), &(s.media));
    return s;
}
void riempiArrayStudenti(struct studente s[], int n){
    int i;
    for(i=0; i<n; ++i){
      s[i] = riempiStudente();
    }
}

void stampaArrayStudenti(struct studente s[], int n){
  int i;
  for(i=0; i<n; ++i){
    printf("Studente %d: %s %s %d %f\n", i, s[i].cognome, s[i].nome, s[i].matricola, s[i].media);
  }
}
