#include "mdp.h"

int main(int argc, char **argv) {
	if (argc >= 2) {
		if (strcmp(argv[1], "--help") == 0)
			help(argv[0]);
		else if (strcmp(argv[1], "--add") == 0)
			add(argv[0]);
		else if ((strcmp(argv[1], "--nom") == 0) || (strcmp(argv[1], "--email") == 0) || (strcmp(argv[1], "--mdp") == 0) || (strcmp(argv[1], "--all") == 0) || (strcmp(argv[1], "--pseudo") == 0)){
			if (argc >= 3)
				charge(argv[0], argv[1], argv[2]);
			else
				printf("%s : usage %s <option> <val>\n", argv[0], argv[0]);
		}
		else if (strcmp(argv[1], "--version") == 0)
			printf("%s/version : %s\n", argv[0], version());
		else
			printf("%s : Option non valide, faite --help\n", argv[0]);
	}
	else
		printf("%s : usage %s [option]\n", argv[0], argv[0]);

	return 0;
}