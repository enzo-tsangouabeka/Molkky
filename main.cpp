/**
* @file main.cpp
* @brief Projet Mölkky
* @author Enzo Tsangouabeka
* @version v1.0
* @date 29/11/2024
*/

#include <iostream>
#include <array>
#include <limits>

using namespace std;

/*CONSIGNE
Il y a 12 quilles numérotées de 1 à 12. Pour abattre les quilles, les joueurs lancent le Mölkky.
Il y a deux façons de marquer des points :
    → Si un joueur fait tomber plusieurs quilles, il gagne autant de points que de quilles abattues.
    → Si un joueur fait tomber une seule quille, il gagne autant de points que le nombre inscrit dessus,
    (s’il ne fait tomber que la quille numérotée 4, il inscrira 4 points).

L’équipe gagnante est la première qui arrive à totaliser exactement 50 points.
Si une équipe dépasse ce score, elle retombe à 25 points.

Lorsqu’une quille a été abattue, on la redresse sur son pied, le numéro face à la zone de lancer, juste là
où elle se trouve. L’objectif de ce mini-projet va être de créer un programme permettant de compter les points
au Mölkky au cours d’une partie.

Niveau 0 (en cours):
Votre programme calcule le nombre de points lorsqu’une seule équipe joue, jusqu’à sa victoire. Les
valeurs des quilles tombées étant saisies par l’utilisateur.

Niveau 1 (non fait):
Votre programme détermine aléatoirement les quilles tombées et calcule le nombre de points lors d’un
match entre deux équipes, jusqu’à la victoire d’une équipe.

Niveau 2 (non fait):
Votre programme pourra gérer les matchs entre trois équipes.
*/

array<int, 12> keel{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

// Valeur constante
const int MAX_SCORE(50);
const int SCORE_OF_EXCEED(25);
int teamScore(0);

/**
* @fn int cheakTypeEntire(int& _entire);
* @brief Fonction de vérification des entiers
* @return int : Retourne un entier valide
*/
int cheakTypeEntire(int& _entire) {
    while (!(cin >> _entire)) {
        cin.clear();  // Efface le message d'erreur de cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore la dernière mauvaise entrées
        cout << "Erreur : Veuillez entrer un nombre entier :";
    }
    return _entire;  // Retourner l'entier validé
}

/**
* @fn bool isntWinCondition();
* @brief Fonction de vérification de la condition de vicoire
* @return bool : Retourne un booléen nous disant si oui ou non la condition n'est pas réspecté
*/
bool isntWinCondition() {
    return !(teamScore == MAX_SCORE);
}

int main() {
    int score(0);
    while (isntWinCondition()) {
        cout << "Quel est ton score de quille >";
        cheakTypeEntire(score);

        if (score <= 12 && score >= 0) {
            teamScore += score;
            if (teamScore > MAX_SCORE) {
                cout << "Vous avez depasser du score max (" << MAX_SCORE << "), votre score a ete reinitialise a " << SCORE_OF_EXCEED << endl;
                teamScore = SCORE_OF_EXCEED;
            }
            cout << "Le score d'equipe est maintenant de : " << teamScore << endl;
        }
        else {
            cout << "Veuillez entrer nombre compris entre 0 et 12 inclue !" << endl;
        }
    }
    cout << "Gagne" << endl;
    return 0;
}