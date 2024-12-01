# Projet Mölkky

## Description
Le projet Mölkky simule une partie du jeu Mölkky, où des équipes essaient de marquer exactement 50 points en faisant tomber des quilles numérotées de 1 à 12. Le jeu prend en compte des règles spécifiques où une équipe qui dépasse 50 points retombe à 25 points. Ce projet implémente un jeu entre plusieurs équipes avec des fonctionnalités variées selon le mode de jeu choisi.

## Fonctionnalités

Le programme propose trois modes de jeu différents :

1. **Niveau 0** : Comptage des points d'une seule équipe. L'utilisateur entre manuellement le nombre de quilles tombées et leur score. L'objectif est d'atteindre 50 points sans les dépasser. Si une équipe dépasse 50, son score est réinitialisé à 25.
2. **Niveau 1** : Jeu entre deux équipes avec des quilles tombées générées aléatoirement. La première équipe à atteindre 50 points gagne.
3. **Niveau 2** : Jeu entre trois équipes avec des quilles tombées générées aléatoirement. La première équipe à atteindre 50 points gagne.

## Instructions

### Compilation et Exécution

1. **Compilation** :
   Pour compiler le projet, utilisez un compilateur C++ compatible avec le standard C++11 ou supérieur, comme `g++` :
   
   ```bash
   g++ -o molkky main.cpp
   ```

2. **Exécution** : Après la compilation, exécutez le programme :
   ```bash
    ./molkky
   ```

### Choix du niveau :

    Niveau 0 : Comptage de points d'une équipe (entrées manuelles).
    Niveau 1 : Match entre deux équipes (quilles tombées aléatoirement).
    Niveau 2 : Match entre trois équipes (quilles tombées aléatoirement).

### **Auteur**

- Enzo Tsangouabeka
- enzo.t@lycee-de-beauvoir.education