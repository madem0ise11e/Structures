/* ESERCIZI lezione 14: Esempio puntatore a struct ed allocazione dinamica della struct e delle stringhe*/
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 50
#define MAX_NUM 30

struct studente {
	char *nome;
	char *cognome;
	int matricola;
	float media;
}; /*NON ALLOCO MEMORIA, NON C'E' NESSUNA VARIABILE*/

struct studente *riempiStudente();
void stampaStudente(struct studente *p);
void eliminaStudente(struct studente *s);

int main(){
	struct studente *s; //s è un puntatore a struct studente. Non e' allocata
			    //memoria per la struct 
	s=riempiStudente(); // QUI CREO ESPLICITAMENTE LA STRUCT STUDENTE
	stampaStudente(s); //QUI PASSO L'INDIRIZZO DI MEMORIA (NON E' CREATA UNA COPIA)	
	eliminaStudente(s); // QUI ESPLICITAMENTE ELIMINO LA STRUCT
	return 0;
}

struct studente *riempiStudente(){
	struct studente *s=NULL; //s è una variabile allocata AUTOMATOCAMENTE che riempie
				 // 8 byte che dovrà contenere un indirizzo di memoria
				// corrispondente ad un struct studente 
	struct studente s1;
	
	/*ALLOCAZIONE DINAMCA DELLA MEMORIA per struct studente*/
	s= (struct studente *) malloc(sizeof(struct studente));
	s->nome= (char *) malloc(sizeof(char)*MAXLEN);
	s->cognome= (char *) malloc(sizeof(char)*MAXLEN);
	//s->nome== (char *) calloc(MAXLEN,sizeof(char));
	// s->cognome= (char *) calloc(MAXLEN,sizeof(char));
	//calloc si differenzia da malloc perchè vado, nel caso di calloc, ad inizializzare
	// a zero la memoria.
	/*
	struct studente {
		char *nome;
		char *cognome;
		int matricola;
		float media;
	};*/
	printf("Dammi cognome e nome:");
	scanf("%s %s", s->cognome, s->nome);
	printf("Dammi matricola e media:");
	scanf("%d %f", &(s->matricola), &(s->media));
	//scanf("%s %s", (*s).cognome, (*s).nome);
	// return &s1; MAI FARE!!!!!! 
	return s;	

}
void stampaStudente(struct studente *p){
	printf("Cog: %s Nome: %s \n", p->cognome, p->nome);
	printf("Mat: %d media: %f \n", p->matricola, p->media);
}
void eliminaStudente(struct studente *s){
	/*
	s= (struct studente *) malloc(sizeof(struct studente));
	s->nome= (char *) malloc(sizeof(char)*MAXLEN);
	s->cognome= (char *) malloc(sizeof(char)*MAXLEN);
	
	*/
	free(s->nome);
	free(s->cognome);
	free(s);
}

