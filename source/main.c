#include "libretto.h"

int main(void){
	char decisione[MAX_BUFF];
	bool aggiungere = true;
	int op;
	libretto l;
	esame e;
	
	l = readLibretto();
	
	do{
		printf("\nDigitare 1:\tAggiungere esame\nDigitare 2:\tStampare il libretto\nDigitare 3:\tStampare il libretto in ordine decrescente di voto.\nDigitare 4:\tStampare il libretto in ordine alfabetico.\nDigitare 5:\tStampare la media aritmetica e ponderata dei tuoi esami.\n");
		scanf("%d", &op);

		switch(op){
			case 1:
				printf("\nAggiungiamo degli esami.\n\n");
				e = insertEsame();
				addEsameInLibretto(l, e);
				break;
				
			case 2:
				printf("\nStampo il libretto.\n\n");
				l = readLibretto();
				break;
				
			case 3:
				printf("\nStampo il libretto in ordine decrescente di voto.\n\n");
				ordinePerVoto(l);
				break;
				
			case 4:
				printf("\nStampo la media del tuo libretto.\n\n");
				ordineAlfabetico(l);
				break;
				
			case 5:
				printf("\nStampo il libretto in ordine alfabetico.\n\n");
				getMedia(l);
				break;

			default:
				printf("Nessun'operazione scelta\n");
		}
		
		printf("Vuoi fare altro? ");
		scanf("%s", decisione);

		if(strcmp(decisione, "n") == 0)
			aggiungere = false;

	} while(aggiungere == true);	

	return 0;
	
	exit(0);
}
