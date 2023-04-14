#include "includes.h"

// crée un nouveau joueur
Player* newPlayer(){
    Player* player = malloc(sizeof(Player));

    // état
    player->life = 3; // Le joueur a 3 vies
    player->state = 1; // L'état 1 correspond à un état "vivant", l'état 0 correspond à un état "mort".
    player->score = 0;  

    // position 
    player->Xposition = -600; //Position du nouveau joueur est en (100; 100)
    player->Yposition = 0;
    player->direction = 0; // le joueur regarde vers le haut

    return player;
}

//fonction qui permet de tuer un joueur. Elle vérifie que le joueur a bien 0 vie.
void killPlayer(){
    if(player->life == 0){
        free(player);
        //TODO : changer de menu et passer au menu game over
    }
}

//permet de déplacer le joueur
void drawPlayer(){
    if(player->direction == 0){
        glRasterPos2s(cameraX -500, cameraY); //camera
        glColor3f(0.0f, 1.0f, 1.0f); 
        glBitmap(64, 64, player->Xposition, player->Yposition, 0, 0, movingraccoonUp);
    }
    if(player->direction == 1){
        glRasterPos2s(cameraX -500, cameraY); //camera
        glColor3f(0.0f, 1.0f, 1.0f); //truquoise
        glBitmap(64, 64, player->Xposition, player->Yposition, 0, 0, movingraccoonRight);
    }
    if(player->direction == 2){
        glRasterPos2s(cameraX -500, cameraY); //camera
        glColor3f(0.0f, 1.0f, 1.0f); //truquoise
        glBitmap(64, 64, player->Xposition, player->Yposition, 0, 0, movingraccoonDown);
    }
    if(player->direction == 3){
        glRasterPos2s(cameraX -500, cameraY); //camera
        glColor3f(0.0f, 1.0f, 1.0f); //truquoise
        glBitmap(64, 64, player->Xposition, player->Yposition, 0, 0, movingraccoonLeft);
    }
}

//Fonction qui permet de gérer les collisions bloquantes avec le joueur
void blockPlayer(){
    if (player->Xposition > leftLimit) {
        player->Xposition = leftLimit;
    }
    if (player->Xposition < rightLimit) {
        player->Xposition = rightLimit;
    }
    if (player->Yposition < -600) {
        player->Yposition = -600;
            gcameraY -= 16.f;
        currentEnemy = head;
        while (currentEnemy != NULL) {
            currentEnemy->Yposition = currentEnemy->Yposition + 14.f;
            currentEnemy = currentEnemy->next;
        }
        bird->Yposition = bird->Yposition + 10.f;
    }
    if (player->Yposition > -10) {
        player->Yposition = -10;
    }
}

void playerCollision(){
    if(player->Xposition == enemy->Xposition && player->Yposition == enemy->Yposition){
        player->life--;
        enemy->life--;
    }
    if(player->Xposition == bird->Xposition && player->Yposition == bird->Yposition){
        player->life--;
        bird->life--;
    }
}
