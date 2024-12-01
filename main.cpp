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

Niveau 0 (Fini et push):
Votre programme calcule le nombre de points lorsqu’une seule équipe joue, jusqu’à sa victoire. Les
valeurs des quilles tombées étant saisies par l’utilisateur.

Niveau 1 (Fini et push):
Votre programme détermine aléatoirement les quilles tombées et calcule le nombre de points lors d’un
match entre deux équipes, jusqu’à la victoire d’une équipe.

Niveau 2 (non fait):
Votre programme pourra gérer les matchs entre trois équipes.
*/

// Variable global
constexpr int MAX_SCORE(50), SCORE_OF_EXCEED(25);
int teamScore(0), team1Score(0), team2Score(0), round(0);

// Sous-Programmes
void maxScoreExceed(int &_teamScore = teamScore);
void game(const int _gameMode = 0);
void lvl0();
void lvl1(); // void lvl2();
void shootKeel(int &_teamScore);

/**
* @fn int cheakTypeEntire(int& _entire);
* @brief Fonction de vérification des entiers
* @param int& _entire : Pointeur sur un int (varable à vérifier)
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
* @param int &_teamScore
* @return bool : Retourne un booléen nous disant si oui ou non la condition n'est pas réspecté
*/
bool isntWinCondition(int &_teamScore = teamScore) {
    return !(_teamScore == MAX_SCORE);
}

int main() {
    int answer(0);
    bool isntGoodNumber(true);
    system("cls");
    srand(time(0));

    cout << "Choisissez un niveau de jeu :" << endl;
    cout << " - Niveau 0 = Comptage de point" << endl;
    cout << " - Niveau 1 = team 1 vs team 2 (automatique)" << endl;
    cout << " - Niveau 2 = team 1 vs team 2 vs team 3 (automatique)" << endl;

    while (isntGoodNumber) {
        cout << "Votre reponse >";
        cheakTypeEntire(answer);
        isntGoodNumber = !(answer == 0 || answer == 1 || answer == 2);
    }
    system("cls");
    game(answer); // Lancement de la partie
    return 0;
}

/**
* @fn void game(int _gameMode);
* @brief Fonction de choix du mode de jeu
* @param const int _gameMode : varable de choix de jeu
*/
void game(const int _gameMode) {
    if (_gameMode == 0) {
        lvl0();
    }
    else if (_gameMode == 1) {
        lvl1();
    }
    /*
    else if (_gameMode == 2) {
        lvl2();
    }
     */
    else {
        return;
    }
}

/**
* @fn void lvl0();
* @brief Niveau 0 du tp
*/
void lvl0() {
    int score(0), keelFallen(0);
    while (isntWinCondition()) {
        cout << "Combien de quilles sont tombees > "; cheakTypeEntire(keelFallen);
        if (keelFallen == 0) {
            cout << "Aucune quille tombe, Dommage" << endl;
            cout << "Le score d'equipe est maintenant de : " << teamScore << endl;
        }
        else if (keelFallen == 1) {
            cout << "Quel est ton score de la quille >"; cheakTypeEntire(score);

            if (score <= 12 && score >= 0) {
                teamScore += score;
                maxScoreExceed();
                cout << "Le score d'equipe est maintenant de : " << teamScore << endl;
            }
            else {
                cout << "Veuillez entrer nombre compris entre 0 et 12 inclue !" << endl;
            }
        }
        else {
            if (keelFallen <= 12 && keelFallen >= 2) {
                teamScore += keelFallen;
                maxScoreExceed();
                cout << "Le score d'equipe est maintenant de : " << teamScore << endl;
            }
            else {
                cout << ((keelFallen > 12) ? "Impossible, il n'y a que 12 quilles" : "Impossible, vous avez fait tomber plus d'unr 1 quille") << endl; // Pas atteignable
            }
        }
    }
    cout << "Gagne" << endl;
}

/**
* @fn void lvl1();
* @brief Niveau 1 du tp
*/
void lvl1() {
    while (true) {
        // Tour de l'équipe 2
        if (isntWinCondition(team2Score)) {
            cout << "---- Tour " << ++round << " ----" <<  endl;
            shootKeel(team1Score);
        }
        else {
            cout << "L'equipe 2 a gagnee !" << endl;
            break;
        }

        // Tour de l'équipe 2
        if (isntWinCondition(team1Score)) {
            shootKeel(team2Score);
        }
        else {
            cout << "L'equipe 1 a gagnee !" << endl;
            break;
        }
    }
}


/**
* @fn void lvl2();
* @brief Niveau 2 du tp
*/
/*
void lvl2() {
    return;
}
*/

/**
* @fn void shootKeel(int &_teamScore);
* @param int &_teamScore : Pointeur sur un int
* @brief Niveau 0 du tp
*/
void shootKeel(int &_teamScore) {
    int score(0), keelFallen(0);
    keelFallen = rand() % 13; // Nombre de quille tombé (0 à 12)
    if (keelFallen == 0) { // 0 quille tombée
        cout << "Aucune quille tombe, Dommage" << endl;
        cout << "Le score d'equipe est maintenant de : " << _teamScore << endl;

    }
    else if (keelFallen == 1) { // 1 quille tombée
        score = rand() % 13; // de 0 à 12
        _teamScore += score;
        maxScoreExceed(_teamScore);
        cout << "Le score d'equipe est maintenant de : " << _teamScore << endl;
    }
    else { // De 2 à 12 quilles tombées
        _teamScore += keelFallen;
        maxScoreExceed(_teamScore);
        cout << "Le score d'equipe est maintenant de : " << _teamScore << endl;
    }
}

/**
* @fn void maxScoreExceed();
* @brief Fonction de vérification de dépassement du score d'équipe (si teamScore dépasse de 50 alors &_teamScore = 25)
*/
void maxScoreExceed(int &_teamScore) {
    if (_teamScore > MAX_SCORE) {
        cout << "Vous avez depasser du score max (" << MAX_SCORE << "), votre score a ete reinitialise a " << SCORE_OF_EXCEED << endl;
        _teamScore = SCORE_OF_EXCEED;
    }
}