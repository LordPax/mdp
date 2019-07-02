# Gestionaire de mot de passe

## Description
Petit gestionaire de mot de passe écris en C

## Précaution
A mettre de préférence sur une clé USB ayant une partition chiffrer avec AES par exemple

## Compilation
```bash
gcc *.c src/*.c -o mdp_test
```

## Help
```
./mdp_test/help : usage ./mdp_test <option> [val]

--help           : Affiche l'aide
--add            : Ajouter un mot de passe
--all     <val>  : cherche tout grâce a un nom
--nom     <val>  : cherche un nom grâce a un nom
--email   <val>  : cherche un email grâce a un nom
--mdp     <val>  : cherche un mot de passe grâce a un nom
--pseudo  <val>  : cherche un pseudo grâce a un nom
--version <val>  : Affiche la version
```