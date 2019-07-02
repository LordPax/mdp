#ifndef MDP_H
#define MDP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR 100
#define MDP "mot_de_passe.mdp"

void help(char *args);
void add(char *args);
void save(char *argv, char *nom, char *email, char *mdp, char *pseudo);
void charge(char *args, char *mode, char *val);
char *version();
int main(int argc, char **argv);

#endif