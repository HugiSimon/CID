#include <stdio.h>
#include <string>
#include <string.h>

#define TAILLETAB 3

typedef enum class civ {H, F}civ;

typedef struct ddn {

	int n_jour;
	int n_mois;
	int n_annee;

}ddn;

typedef struct adresse { 

	char* str_rue;
	int n_cp;
	char* str_ville;

}adresse;

typedef struct CID {

	int n_id;
	civ e_civ;
	char* str_nom;
	char* str_prenom;
	ddn* t_ddn;
	adresse* t_adr;

}cid;


/***********

 Fonction

***********/

cid askCid();
ddn askDdn();
adresse askAdr();
void impTab(cid* tablo[TAILLETAB]);


/***********
 
 Main

***********/

int main() {

	cid* tablo[TAILLETAB] = {};
	tablo[0] = nullptr;

	for (int numero = 0; numero < TAILLETAB; numero++) {

		tablo[numero] = (cid*)malloc(sizeof(cid));

		printf_s("CID numero : %d \n\n", numero);

		if (tablo[numero] != nullptr) {
			*tablo[numero] = askCid();
		}

		tablo[numero]->t_ddn = (ddn*)malloc(sizeof(ddn));
		if (tablo[numero]->t_ddn != nullptr) {
			*tablo[numero]->t_ddn = askDdn();
		}

		tablo[numero]->t_adr = (adresse*)malloc(sizeof(adresse));
		if (tablo[numero]->t_adr != nullptr) {
			*tablo[numero]->t_adr = askAdr();
		}

		printf_s("\n\n");

	}

	impTab(tablo);

	return 0;
}


/***********

 askCid :

 Demande la civilité, nom, prénom

***********/

cid askCid() {

	CID tempo;

	char temp;
	civ e_H = civ::H;
	civ e_F = civ::F;

	printf_s("Votre civilite ? (H/F) ");
	do {

		scanf_s(" %c", &temp, 1);

	} while (temp != 'H' && temp != 'F');

	if (temp == 'H') {
		tempo.e_civ = e_H;
	}
	else {
		tempo.e_civ = e_F;
	}

	printf_s("Votre prenom ? ");
	tempo.str_prenom = (char*)malloc(255 * sizeof(char));
	scanf_s("%s", tempo.str_prenom, 255);

	printf_s("Votre nom ? ");
	tempo.str_nom = (char*)malloc(255 * sizeof(char));
	scanf_s("%s", tempo.str_nom, 255);

	return tempo;

}


/***********

 askDdn :

 Demande la date de naissance

***********/

ddn askDdn() {

	ddn tempo;

	printf_s("\nVotre date de naissance ? ");
	scanf_s("%d", &tempo.n_annee);

	printf_s("Votre mois de naissance ? ");
	scanf_s("%d", &tempo.n_mois);

	printf_s("Votre jour de naissance ? ");
	scanf_s("%d", &tempo.n_jour);

	return tempo;

}


/***********

 askAdr :

 Demande l'adresse

***********/

adresse askAdr() {

	adresse tempo;

	printf_s("\nTu habite dans quel ville ? ");
	tempo.str_ville = (char*)malloc(255*sizeof(char));
	scanf_s("%s", tempo.str_ville, 255);

	printf_s("Code postale ? ");
	scanf_s("%d", &tempo.n_cp);

	printf_s("Numero et nom de rue ? ");
	tempo.str_rue = (char*)malloc(255*sizeof(char));
	scanf_s("%s", tempo.str_rue, 255);

	return tempo;

}


/***********

 impTab :

 Imprimer le tableau

***********/

void impTab(cid* tablo[TAILLETAB]) {

	for (int n_i = 0; n_i < TAILLETAB; n_i++) {

		printf_s("\n- - - - - - - - - - -");
		printf_s("\n\nId : %d / Nom : %s / Prenom : %s", tablo[n_i]->e_civ, tablo[n_i]->str_nom, tablo[n_i]->str_prenom);
		printf_s("\n\nDate de naissance : %d / %d / %d", tablo[n_i]->t_ddn->n_jour, tablo[n_i]->t_ddn->n_mois, tablo[n_i]->t_ddn->n_annee);
		printf_s("\n\nVille : %s / Code postale : %d", tablo[n_i]->t_adr->str_ville, tablo[n_i]->t_adr->n_cp);
		printf_s("\nAdresse : %s\n", tablo[n_i]->t_adr->str_rue);

	}

}