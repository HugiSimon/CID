#include <stdio.h>
#include <string>
#include <string.h>

#define TAILLETAB 1 //La nombre d'enregistrement de CID

typedef enum class civ {H, F}civ; //Un enum pour Homme et Femme

typedef struct ddn { //Un struct de date de naissance

	int n_jour;
	int n_mois;
	int n_annee;

}ddn;

typedef struct adresse { //Un struct d'adresse postale

	char* str_rue;
	int n_cp;
	char* str_ville;

}adresse;

typedef struct CID { //Le struct principal qui regroupe les deux précédent plus prenom/nom et identifiant

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

	cid* tablo[TAILLETAB] = {}; //Initialisation du tableau
	tablo[0] = nullptr;

	for (int numero = 0; numero < TAILLETAB; numero++) { //Le nombre de fois que le code va demander toutes les informations 

		tablo[numero] = (cid*)malloc(sizeof(cid)); //Allocation de la taille du tableau

		printf_s("CID numero : %d \n\n", numero); //Juste pour la forme, et savoir ou en est en terme de nombre d'enregistrement

		if (tablo[numero] != nullptr) {
			*tablo[numero] = askCid(); //Fonction pour l'identité
		}

		tablo[numero]->t_ddn = (ddn*)malloc(sizeof(ddn));
		if (tablo[numero]->t_ddn != nullptr) {
			*tablo[numero]->t_ddn = askDdn(); //Fonction pour la date de naissance
		}

		tablo[numero]->t_adr = (adresse*)malloc(sizeof(adresse));
		if (tablo[numero]->t_adr != nullptr) {
			*tablo[numero]->t_adr = askAdr(); //Fonction pour l'adresse
		}

		printf_s("\n\n");

	}

	impTab(tablo); //Fonction pour print tout les CID

	return 0;
}


/***********

 askCid :

 Demande la civilité, nom, prénom

***********/

cid askCid() {

	CID tempo; //Enregistre toutes les réponse en attendant de les enregistrers

	char temp;
	civ e_H = civ::H; //Création de variable pour le enum
	civ e_F = civ::F;

	printf_s("Votre civilite ? (H/F) ");
	do {

		scanf_s(" %c", &temp, 1);

	} while (temp != 'H' && temp != 'F'); //On répète tant que l'utilisateur ne donne pas la bonne réponse

	if (temp == 'H') { //En fonction, on donne la bonne civilite
		tempo.e_civ = e_H;
	}
	else {
		tempo.e_civ = e_F;
	}

	printf_s("Votre prenom ? ");
	tempo.str_prenom = (char*)malloc(255 * sizeof(char)); //Allocation pour le nom, maximum 255 caractère
	scanf_s("%s", tempo.str_prenom, 255);

	printf_s("Votre nom ? ");
	tempo.str_nom = (char*)malloc(255 * sizeof(char)); //La meme chose ici
	scanf_s("%s", tempo.str_nom, 255);

	return tempo; //Et on retourne tout les resultats

}


/***********

 askDdn :

 Demande la date de naissance

***********/

ddn askDdn() {

	ddn tempo; //On recreer une variable temporaire

	printf_s("\nVotre date de naissance ? "); //Pas besoin d'allocation, ce sont des entiers
	scanf_s("%d", &tempo.n_annee);

	printf_s("Votre mois de naissance ? ");
	scanf_s("%d", &tempo.n_mois);

	printf_s("Votre jour de naissance ? ");
	scanf_s("%d", &tempo.n_jour);

	return tempo; //Et on retourne tout ca

}


/***********

 askAdr :

 Demande l'adresse

***********/

adresse askAdr() {

	adresse tempo; //Toujours une variable temporaire

	printf_s("\nTu habite dans quel ville ? ");
	tempo.str_ville = (char*)malloc(255*sizeof(char)); //Toujours la meme chose, des allocations pour les chaines de caracteres
	scanf_s("%s", tempo.str_ville, 255);

	printf_s("Code postale ? ");
	scanf_s("%d", &tempo.n_cp);

	printf_s("Numero et nom de rue ? ");
	tempo.str_rue = (char*)malloc(255*sizeof(char));
	scanf_s("%s", tempo.str_rue, 255);

	return tempo; //Et on retourne toutes les reponses

}


/***********

 impTab :

 Imprimer le tableau

***********/

void impTab(cid* tablo[TAILLETAB]) {

	for (int n_i = 0; n_i < TAILLETAB; n_i++) { //On repete pour tout le tableau

		printf_s("\n- - - - - - - - - - -"); //Et un peu de mise en forme
		printf_s("\n\nId : %d / Nom : %s / Prenom : %s", tablo[n_i]->e_civ, tablo[n_i]->str_nom, tablo[n_i]->str_prenom);
		printf_s("\n\nDate de naissance : %d / %d / %d", tablo[n_i]->t_ddn->n_jour, tablo[n_i]->t_ddn->n_mois, tablo[n_i]->t_ddn->n_annee);
		printf_s("\n\nVille : %s / Code postale : %d", tablo[n_i]->t_adr->str_ville, tablo[n_i]->t_adr->n_cp);
		printf_s("\nAdresse : %s\n", tablo[n_i]->t_adr->str_rue); // /!\ PROBLEME /!\ N'affiche que le premier mot et prend pas après les espaces, pas trouvé de soluce

	}

}