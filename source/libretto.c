#include "libretto.h"

struct libretto{
	int numEsami;
	esame esami[MAX_ESAMI];
};

libretto readLibretto(){
	FILE *esami;
	char nome[MAX_BUFF];
	int voto, crediti;
	char lode;
	//int i = 0;
	esame e;

	mkdir("DATI", 493);
	esami = fopen("DATI/esami.txt", "a+"); //Se non esiste viene creato. Leggo o scrivo a fine file.
	
	printf("Questo è il tuo libretto.\n");
	
	struct libretto *l = malloc(sizeof(struct libretto));
	l->numEsami = 0;
	
	printf("Nome\t\t\tCrediti\t\tValutazione\t\tLode\n\n");
	
	while(fscanf(esami, "%s\t%d\t%d\t%c", nome, &crediti, &voto, &lode) != EOF){
	
		if(l != NULL){
			e = newEsame(nome, voto, lode, crediti);
			l->esami[l->numEsami] = e;
			l->numEsami++;	
			printf("%s\t\t%d\t\t%d\t\t%c\n", nome, crediti, voto, lode);
					
		} else{
			printf("Errore nella lettura dell'esame.\n");
			return NULL;
		}
		
	}
	
	if(l->numEsami == 0)
		printf("Non ci sono esami all'interno del tuo libretto.\n");
		
	fclose(esami);	
	return l;
}

void addEsameInLibretto(libretto l, esame e){
	FILE *esami;
	int i;
	esame ex;

	if(l->numEsami == MAX_ESAMI){
		printf("Hai raggiunto il massimo numero di esami.\n");
		return;
	}
	
	for(i = 0; i < l->numEsami; i++){
		ex = l->esami[i];
		
		if(strcmp(getNomeEsame(e), getNomeEsame(ex)) == 0){
			printf("Questo esame è già presente sul libretto.\n");
			return;
		}
	}
	
	l->numEsami++;
	l->esami[l->numEsami] = e;
	
	esami = fopen("DATI/esami.txt", "a+");
	fprintf(esami, "%s\t%d\t%d\t%c\n", getNomeEsame(e), getCreditiEsame(e), getVotoEsame(e) - 1, getLodeEsame(e));
	
	fclose(esami);
	return;
}

void toStringLibretto(libretto l){
	int i;

	printf("\n\nEsami Sostenuti: %d\n\n", l->numEsami);

	for(i = 0; i < l->numEsami; i++){
		toStringEsame(l->esami[i]);
	}
}

void ordinePerVoto(libretto l){
	FILE *voti;
	esame eTemp;
	int i, j, minIdx;
	
	voti = fopen("DATI/ordinatiPerVoto.txt", "w");
	
	for (i = 0; i < l->numEsami-1; i++){
		minIdx = i;
	
		for(j = i+1; j < l->numEsami; j++){
		
			if((getVotoEsame(l->esami[j])) < getVotoEsame(l->esami[minIdx]))
				minIdx = j;
				
			eTemp = l->esami[minIdx];
			l->esami[minIdx] = l->esami[i];
			l->esami[i] = eTemp;
			
		}
	}
	
	printf("Nome\t\t\tCrediti\t\tValutazione\t\tLode\n\n");
	
	for(i = l->numEsami-1; i > -1; i--){
		eTemp = l->esami[i];
		
		fprintf(voti, "%s\t%d\t%d\t%c\n", getNomeEsame(eTemp), getCreditiEsame(eTemp), getVotoEsame(eTemp), getLodeEsame(eTemp));
		printf("%s\t\t%d\t\t%d\t\t%c\n", getNomeEsame(eTemp), getCreditiEsame(eTemp), getVotoEsame(eTemp), getLodeEsame(eTemp));
	}
	
	fclose(voti);
	
	return;
}

void ordineAlfabetico(libretto l){
	FILE *alfabetico;
	esame eTemp;
	int i, j, minIdx;
	
	alfabetico = fopen("DATI/ordineAlfabetico.txt", "w");
	
	for (i = 0; i < l->numEsami-1; i++){
		minIdx = i;
	
		for(j = i+1; j < l->numEsami; j++){
		
			if(strcmp(getNomeEsame(l->esami[j]), getNomeEsame(l->esami[minIdx])) < 0)
				minIdx = j;
				
			eTemp = l->esami[minIdx];
			l->esami[minIdx] = l->esami[i];
			l->esami[i] = eTemp;
			
		}
	}
	
	printf("Nome\t\t\tCrediti\t\tValutazione\t\tLode\n\n");
	
	for(i = 0; i < l->numEsami; i++){
		eTemp = l->esami[i];
		
		fprintf(alfabetico, "%s\t%d\t%d\t%c\n", getNomeEsame(eTemp), getCreditiEsame(eTemp), getVotoEsame(eTemp), getLodeEsame(eTemp));
		printf("%s\t\t%d\t\t%d\t\t%c\n", getNomeEsame(eTemp), getCreditiEsame(eTemp), getVotoEsame(eTemp), getLodeEsame(eTemp));
	}
	
	fclose(alfabetico);
	
	return;
}

void getMedia(libretto l){
	esame e;
	float media = 0, mediaP = 0, tempP;
	int i, crediti;
	
	for(i = 0; i < l->numEsami; i++){
		e = l->esami[i];
		media += getVotoEsame(e);
		tempP = getVotoEsame(e) * getCreditiEsame(e);
		mediaP += tempP;
		crediti += getCreditiEsame(e);
	}
	
	media /= l->numEsami;
	
	mediaP /= crediti;
	mediaP /= 3;
	mediaP *= 11;
	
	printf("La media aritmetica è: %.2f.\nLa media ponderata è: %.2f\n\n", media, mediaP);
	
	return;
}
