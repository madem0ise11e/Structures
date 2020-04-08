#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 50
#define MAX_NUM 30

struct studente{
  /*char cognome[MAXLEN];
  char nome[MAXLEN];*/
  char *cognome;
  char *nome;
  int matricola;
  float media;
};

int caricaStudenti(struct studente *studenti[]);
struct studente * riempiStudente();
void stampaStudente(struct studente *p);
void eliminaStudente(struct studente *s);
void inizializza(struct studente *studenti[]);
int main(){
    /*  struct studente *s;        // s è un puntatore a struct studente. Non è allocata memoria per la struct
        s = riempiStudente();   //CREO ESPLICITAMENTE LA STRUCT STUDENTE
        stampaStudente(s);     //PASSO L'INDIRIZZO DI MEMORIA (non è creata una coppia)
        eliminaStudente(s);    //ESPLICITAMENTE ELELMINO LA STRUCT
    */
    /*dopo aver creato int caricaStudenti(struct studente *studenti[]); */
    struct studente *tuttiglistudenti[MAX_NUM]; // alloco max_num puntatori
  //  struct studente tuttiglistudenti2[MAX_NUM]; // alloco max_num struct studente
  return 0;
}

struct studente * riempiStudente(){
    struct studente *s = NULL; // s è una variabiale allocata AUTOMATICAMENTE
    //che riempe 8 o piu byte che dovrà contenere un indirizzo di memoria
    //corrispondente ad un struct studente
    struct studente s1;
    // printf("%s\n ", s->studente); da segmentation fault perché tocco la memoria che non c'è
    //Allocazione dinamica della memoria per struct studente
    s = (struct studente *) malloc(sizeof(struct studente));
    s->cognome = (char*) malloc(sizeof(char)*MAXLEN);
    s->nome = (char*) malloc(sizeof(char)*MAXLEN);
    // s->nome = (char*) calloc(MAXLEN, sizeof(char));
    // s->cognome = (char*) calloc(MAXLEN, sizeof(char));
    // si differenzia perché vado ad inizializzare a zero la memoria
    printf("Dammi cognome e nome: ");
    scanf("%s %s", s->cognome, s->nome);          //equivalenti
    //scanf("%s %s", (*s).cognome, (*s).nome);    //equivalenti
    printf("Dammi matricola e media: ");
    scanf("%d %f", &(s->matricola), &(s->media));
    // return &s1; MAI !!!
    return s;
}
void stampaStudente(struct studente *p){
    printf("Cognome: %s  Nome: %s \n", p->cognome, p->nome );
    printf("Matricola: %d  Media: %f \n", p->matricola, p->media );
}
void eliminaStudente(struct studente *s){
  /*
  s = (struct studente *) malloc(sizeof(struct studente));
  s->cognome = (char*) malloc(sizeof(char)*MAXLEN);
  s->nome = (char*) malloc(sizeof(char)*MAXLEN);
  */
    free(s->nome);
    free(s->cognome);
    free(s);
}

int caricaStudenti(struct studente *studenti[]){
  int len,i;
  printf("Quanti studenti vuoi inserire? ");
  scanf("%d", &len);
  for(i=0; i<len; ++i){
    studenti[i] = riempiStudente();
    //studenti[i] è un puntatore alla struttura
  return len;
  }
}

void inizializza(struct studente *studenti[]){
  int i;
  for(i=0; i<MAX_NUM; ++i) studenti[i] = NULL;
}
