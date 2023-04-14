#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

//structure qui définit un joueur.
typedef struct player{
    //life, state, position, score, shots, color, shape, …
    
    //State
    int life;
    int state; 
    int score;

    //Positioning
    int Xposition;
    int Yposition;
    int direction; // Vaut 0 si le joueur regarde vers le haut, 1 s'il regarde vers la droite, 2 vers le bas et 3 vers la gauche. 
}Player;
Player* newPlayer();
void killPlayer();
void drawPlayer();
void blockPlayer();
void playerCollision();
#endif