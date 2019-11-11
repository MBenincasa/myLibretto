#include "esame.h"

struct esame{
	char nome[MAX_BUFF];
	int voto;
	int crediti;
	char lode;
	//struct tm *time
};

esame insertEsame(){
	char nome[MAX_BUFF];
	int voto, crediti;
	char lode = 'n';
	//int giorno, mese, anno;
	
	printf("Nome dell'esame da inserire: ");
	scanf("%s", nome);
	
	printf("L'esame da quanti crediti è: ");
	scanf("%d", &crediti);
	
	do{
		printf("La valutazione finale (31 se è stata raggiunta la lode): ");
		scanf("%d", &voto);
		
		if(voto == 31)
			lode = 's';
		
	} while(voto < 18 || voto > 31);
	
	newEsame(nome, voto, lode, crediti);
/*	
	printf("L'anno del conseguimento: ");
	scanf("%d", anno);
	printf("Il mese del conseguimento: ");
	scanf("%d", mese);
	printf("Il giorno del conseguimento: ");
	scanf("%d", giorno);
*/	
	
}

esame newEsame(char *nome, int voto, char lode, int crediti){
	
	struct esame *e = malloc(sizeof(struct esame));
	
	if(e != NULL){
		strcpy(e->nome, nome);
		e->voto = voto;
		e->lode = lode;
		e->crediti = crediti;
		//e->time->tm_year = anno;
		//e->time->tm_mon = mese;
		//e->time->tm_mday = giorno;
	} else{
		printf("Errore nell'inserimento dell'esame.\n");
		return NULL;
	}
	
	return e;
}

void toStringEsame(esame e){
	printf("Esame: %s\tCrediti: %d\tValutazione: %d\tLode: %c\n", e->nome, e->crediti, e->voto, e->lode);
}

/*GETTERS*/

char *getNomeEsame(esame e){
	if(e == NULL)
		return NULL;

	char *nome = malloc(sizeof(char)*strlen(e->nome));

	strcpy(nome, e->nome);

	return nome;
}

int getVotoEsame(esame e){
	if(e == NULL)
		return NULL;
		
	int voto;
	voto = e->voto;
	
	return voto;
}

char getLodeEsame(esame e){
	if(e == NULL)
		return NULL;
		
	char lode;
	lode = e->lode;
	
	return lode;
}

int getCreditiEsame(esame e){
	if(e == NULL)
		return NULL;
		
	int crediti;
	crediti = e->crediti;
	
	return crediti;
}
