#include "includes.h"

// crée une première zone dans la liste chainée
Zone* newZone(){
    Zone* zone = malloc(sizeof(Zone));

    zone->type = 0; //0 for forest, 1 for road, 2 for water
    zone->speedChange = 0;
    //Positioning
    zoneHeight = zoneHeight - 200; //change car c'est une variable globale donc à changer
    zone->height = zoneHeight;
    //Pointe sur la prochaine zone.
    zone->next = zoneHead;
    zoneHead = zone;
    return zone;
}

// Fonction pour ajouter une zone à la liste chainée
void addZone() {
    Zone *newZone = (Zone*) malloc(sizeof(Zone));
    
    // état
    newZone->type = rand()%3; //0 for forest, 1 for road, 2 for water
    if(newZone->type == 2){
        newZone->speedChange = 5;
    }
    else{
        newZone->speedChange = 0;
    }

    //Positioning
    newZone->height = zoneHeight;
    if(newZone->type == 1){
        addEnemy(newZone->height / 1.f); //ajoute un ennemi si la zone est de type "route"
    }

    zoneHeight = zoneHeight - 200;
    
    newZone->next = NULL;
    // Ajouter la nouvelle zone au début de la liste
    if (zoneHead == NULL) {
        zoneHead = newZone;
    } else {
        newZone->next = zoneHead;
        zoneHead = newZone;
    }
}


//Dessine un rectangle qui peut avoir 3 couleurs qui dépendent d'un type de zone donnée.
//0 for forest, 1 for road, 2 for water
void drawRectangle(int type, int height){

    glBegin( GL_QUADS );
    glTranslatef(0.f, height, 0.f);
    if(type == 0){ //A MODIFIER
        glColor3f( 0, 200, 0 ); //green
        glVertex2f( -leftLimit+60 / 1.f +100, -(height) / 1.f );
        glVertex2f(  leftLimit+20 / 1.f +100, -(height) / 1.f );
        glVertex2f(  leftLimit+20 / 1.f +100,  height / 1.f );
        glVertex2f( -leftLimit+60 / 1.f +100,  height / 1.f );
    glEnd();
    }
    if(type == 1){
        glColor3f( 0.7f, 0.6f, 0.6f ); //grey
        glVertex2f( -leftLimit+60 / 1.f +100, -(height) / 1.f );
        glVertex2f(  leftLimit+20 / 1.f +100, -(height) / 1.f );
        glVertex2f(  leftLimit+20 / 1.f +100,  height / 1.f );
        glVertex2f( -leftLimit+60 / 1.f +100,  height / 1.f );
    glEnd();
    }
    if(type == 2){
        glColor3f( 0.f, 0.6f, 0.8f); //blue
        glVertex2f( -leftLimit+60 / 1.f +100, -(height) / 1.f );
        glVertex2f(  leftLimit+20 / 1.f +100, -(height) / 1.f );
        glVertex2f(  leftLimit+20 / 1.f +100,  height / 1.f );
        glVertex2f( -leftLimit+60 / 1.f +100,  height / 1.f );
    glEnd();
    }
    else{
        glColor3f( 1.f, 0.f, 0.f ); //red for error
        glVertex2f( -leftLimit+60 / 1.f +100, -(height) / 1.f );
        glVertex2f(  leftLimit+20 / 1.f +100, -(height) / 1.f );
        glVertex2f(  leftLimit+20 / 1.f +100,  height / 1.f );
        glVertex2f( -leftLimit+60 / 1.f +100,  height / 1.f );
    glEnd();
    }

    //glutSwapBuffers();

}

//permet de dessiner la zone et ses éléments.
void drawZone(Zone* zone){
    drawRectangle(zone->type, zone->height);
}


// Fonction pour supprimer un ennemi de la liste chaînée
void removeZone(Zone *zoneToRemove) {
    if (zoneHead == zoneToRemove) {
        zoneHead = zoneHead->next;
    } else {

     // Sinon, chercher l'ennemi précédent
        Zone* preZone = zoneHead;
        while (preZone->next != zoneToRemove) {
            preZone = preZone->next;
        }

        // Mettre à jour le pointeur "next" du précédent pour qu'il pointe sur le suivant
        preZone->next = zoneToRemove->next;
    }

    free(zoneToRemove);
}

//met en place la carte du jeu en début de partie.
void setupMap(){
    int zoneNbr = 20;
    
    zone = newZone(); //premier élément de la liste chainée
    for(int i = 0; i < zoneNbr; i++){
        addZone();
    }
    //TODO: setup finish zone
}
