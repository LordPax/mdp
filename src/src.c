#include "../mdp.h"

void help(char *args) {
	printf("%s/help : usage %s <option> [val]\n\n", args, args);
	printf("--help           : Affiche l'aide\n");
	printf("--add            : Ajouter un mot de passe\n");
	printf("--all     <val>  : cherche tout grâce a un nom\n");
	printf("--nom     <val>  : cherche un nom grâce a un nom\n");
	printf("--email   <val>  : cherche un email grâce a un nom\n");
	printf("--mdp     <val>  : cherche un mot de passe grâce a un nom\n");
	printf("--pseudo  <val>  : cherche un pseudo grâce a un nom\n");
	printf("--version <val>  : Affiche la version\n");
}

void add(char *args) {
	char nom[STR], email[STR], mdp[STR], pseudo[STR];

	do {
		printf("%s/add : Entrer le nom du compte > ", args);
		scanf("%s", nom);
		printf("%s/add : Entrer l'email associer > ", args);
		scanf("%s", email);
		printf("%s/add : Entrer le mot de passe  > ", args);
		scanf("%s", mdp);
		printf("%s/add : Entrer le pseudo        > ", args);
		scanf("%s", pseudo);

		save(args, nom, email, mdp, pseudo);
	} while (1);
}

void save(char *args, char *nom, char *email, char *mdp, char *pseudo) {
	FILE *file = fopen(MDP, "a");

	if (file != NULL) {
		fprintf(file, "%s %s %s %s\n", nom, email, mdp, pseudo);
		printf("%s/add : Compte enregistrer\n", args);
		fclose(file);
	}
	else 
		printf("%s/add : Lecture ou création du fichier %s impossible\n", args, MDP);
}

void charge(char *args, char *mode, char *val){
	FILE *file = fopen(MDP, "r");
	char str[4][STR], ligne[STR * 4];
	int n = 0;

	if (file != NULL) {
		while (fgets(ligne, STR * 4, file) != NULL) {
			sscanf(ligne, "%s %s %s %s", str[0], str[1], str[2], str[3]);

			if (strcmp(str[0], val) == 0) {
				if (strcmp(mode, "--all") == 0){
					printf("\n%s/nom    : %s\n", args, str[0]);
					printf("%s/email  : %s\n", args, str[1]);
					printf("%s/mdp    : %s\n", args, str[2]);
					printf("%s/pseudo : %s\n", args, str[3]);
				}
				else if (strcmp(mode, "--nom") == 0)
					printf("%s/nom    : %s\n", args, str[0]);
				else if (strcmp(mode, "--email") == 0)
					printf("%s/email  : %s\n", args, str[1]);
				else if (strcmp(mode, "--mdp") == 0)
					printf("%s/mdp    : %s\n", args, str[2]);
				else if (strcmp(mode, "--pseudo") == 0)
					printf("%s/pseudo : %s\n", args, str[3]);
				n++;
			}
		}

		printf("\n%s : %d résultats pour : %s\n", args, n, val);
		fclose(file);
	}
	else
		printf("%s : Lecture du fichier %s impossible\n", args, MDP);
}

char *version(){
	return "1.0 Alpha";
}

// char *strdec(char *str, int c1, int c2){
// 	char *strd = malloc(sizeof(char) * (c2 - c1));
// 	for (int i = c1, i2 = 0; i < c2; i++, i2++) {
// 		strd[i2] = str[]
// 	}
// }