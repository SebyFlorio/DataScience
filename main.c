/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct {
    int matricola;
	char cognome[30];
	char nome[20];
	char sesso;
}studente;

int menu() {
    int scelta;
    printf("MENU PRINCIPALE\n 1.INSERISCI STUDENTE\n 2. CERCA\n 3.SCRIVI SU FILE\n 4.ESCI\n");
    scanf("%d",&scelta);
    return scelta;
}

void inserisci_studente(studente vett[], int i) {
    char sesso;
    printf ("\n...INSERIMENTO STUDENTE...");
    printf("\nInserisci matricola: ");
    scanf("%d",&vett[i].matricola);
    printf("\nInserisci cognome: ");
    scanf("%s",vett[i].cognome);
    printf("\nInserisci nome: ");
    scanf("%s",vett[i].nome);
    scanf("%c");

    
    while(sesso!='F' && sesso!='M') {
        printf("\nInserisci sesso:");
        scanf("%c",&sesso);
        scanf("%c");

        if(sesso=='M' || sesso=='F') {
            vett[i].sesso=sesso;
        }
    }

}

void ricerca_cognome(char cognome[],studente vett[], int dim) {
    printf("Cognome da ricercare : %s", cognome);
    for(int i=0;i<dim;i++) {
        if (strcmp(vett[i].cognome,cognome)==0) {
            printf("MATRICOLA : %d - NOME: %s - COGNOME : %s -SESSO : %c", vett[i].matricola,vett[i].nome,vett[i].cognome,vett[i].sesso);
        }
    }
}

int main()
{
    studente s[MAX];
    int num_studenti=0;
    char cognome[30];
    int opzione;
    do {
        opzione=menu();
        switch(opzione) {
            case 1: {inserisci_studente(s,num_studenti);num_studenti+=1;break;}
            case 2: {printf("Ricerca cognome : ");scanf("%s",cognome);ricerca_cognome(cognome,s,num_studenti);break;}
            case 3: break;
            case 4: break;
        }
    } while (opzione!=4);
    
}
