#  Corewar
Le Corewar est un jeu de mémoire.
Le but pour chaque joueur est de créer un champion en langage ASM qui sera confronté aux champions des autres joueurs dans une machine virtuelle.
L'objectif de ce projet est de coder un assembleur ainsi qu'une machine virtuelle capable d'accueillir les champions (de le chargé en mémoire).
## Installation
1. `make`
## Usage
### Main program
1. `./asm`
2. `./corewar`
### Unit-tests
(Les tests comparent la sortie standard avec ou sans les options. L'option 14 représente l'affichage des cycles et des actions effectuées par les processus)
1. `make tests OPT=`
2. `make tests OPT=14`
## Credits
Projet de l'école 42
