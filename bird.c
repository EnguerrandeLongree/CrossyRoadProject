#include "includes.h"

// crée un nouvel ennemi (oiseau)
Bird* newBird(){
    Bird* bird = malloc(sizeof(Bird));

    // état
    bird->life = 1; // L'ennemi n'a qu'une seule vie
    bird->state = 1; // L'état 1 correspond à un état "vivant", l'état 0 correspond à un état "mort".

    // position 
    bird->Yposition = 2000;  //TODO: Position du nouvel oiseau loin pour qu'il mette du temps à arriver
    bird->Xposition = -300;
    return bird;
}

//fonction qui permet de tuer un oiseau
void killBird(){
    if(bird->life == 0){
        free(bird);
    }
}

// Calculer la direction de l'oiseau vers le joueur
float orientBird(){
    float deltaX = player->Xposition - bird->Xposition;
    float deltaY = player->Yposition - bird->Yposition;
    float angle = atan2(deltaY, deltaX);
    return angle;
}

// permet de déplacer l'oiseau 
void moveBird(float angle){
    double speed = 2;
    bird->Xposition += speed * cos(angle);
    bird->Yposition += speed * sin(angle);
}

// Fonction qui permet à un oiseau de tracker un joueur en suivant sa position
void trackPlayer(){
    moveBird(orientBird());
}

//permet d'afficher un oiseau.
void drawBird(){
    glRasterPos2s(cameraX -500, cameraY); //camera
    glColor3f(100, 200, 100); //blue
    glBitmap(64, 64, bird->Xposition, bird->Yposition, 0, 0, birdy);
}