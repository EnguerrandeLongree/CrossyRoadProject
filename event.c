#include "includes.h"

//Initialise les éléments visuels du jeu.
bool initGL()
{
    glViewport( 0.f, 0.f, windowWidth, windowHeight);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( 0.0, windowWidth, windowHeight, -1.0, 1.0, -1.0 );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glPushMatrix();
    glClearColor( 0.f, 0.f, 0.f, 1.f );

    GLenum error = glGetError();
    if( error != GL_NO_ERROR )
    {
        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        return false;
    }
    return true;
}

// function to handle special key events
void arrowFunc(int key, int x, int y) { //x et y sont les coordonnées de la souris donc rav avec les coordonnées de l'objet à bouger mdr 
    switch (key) {
        case GLUT_KEY_LEFT:
            //update direction of player
            player->direction = 3;
            player->Xposition += 20;
            glutPostRedisplay();
            break;
        case GLUT_KEY_UP:
            player->direction = 0;
            player->Yposition -= 20;
            glutPostRedisplay();
            break;
        case GLUT_KEY_RIGHT:
            player->direction = 1;
            player->Xposition -= 20;
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            player->direction = 2;
            player->Yposition += 20;
            glutPostRedisplay();
        /*case SPACE:
            le joueur tire 
        */
    }
    glMatrixMode( GL_MODELVIEW );
    glPopMatrix();
    glLoadIdentity(); 
  
    //déplace la caméra
    glTranslatef( 0.f, gcameraY, 0.f );
   
    glPushMatrix();
}


// Fonction qui met à jour l'affichage
void update(int value) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2s(cameraX -500, cameraY); //camera

    //Bloque le joueur aux limites de l'écran de jeu.
    blockPlayer();

    //fait réapparaitre l'ennemi à l'endroit où il est apparu
    currentEnemy = head;
    while (currentEnemy != NULL) {
        currentEnemy->Xposition -= 1;
        if(currentEnemy->Xposition <= rightLimit){
            currentEnemy->Xposition = leftLimit;
        }
        currentEnemy = currentEnemy->next;
    }
    
    //s'occupe de déplacer le joueur vers la droite s'il est dans une zone d'eau
    /*currentZone = zoneHead;
    while (currentZone != NULL) {
        if(currentZone->type == 2){
            if(player->Yposition <= currentZone->height && player->Yposition > currentZone->height - 200){
                player->Xposition -= currentZone->speedChange ;
                break;
            }

        }
        currentZone = currentZone->next;
    }*/

    //l'oiseau traque le joueur.
    trackPlayer();

    // Redessine les évènements
    glutPostRedisplay();
    glFlush();
    glutSwapBuffers();

    // remet le timer à jour
    glutTimerFunc(timerInterval, update, 0);
}


// Permet de mettre à jour la taille de la fenêtre.
void reshapeWindow(int width, int height) {
    windowWidth = width;
    windowHeight = height;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D((GLdouble)-500, (GLdouble)500, (GLdouble)cameraY, (GLdouble)1000);
    glMatrixMode(GL_MODELVIEW);
    glViewport(cameraX, cameraY, windowWidth, windowHeight);
    gluLookAt(windowWidth, windowHeight, 1.0f, 1000.0F, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f);

}

//to KILL maybe
/*void camera(){
    glMatrixMode(GL_MODELVIEW);
    glViewport(cameraX, cameraY, windowWidth, windowHeight);
    gluLookAt(0.0f, 0.0f, 1.0f, cameraX, cameraY, 0.0f, -1.0f, 1.0f, 1.0f);
}*/

// Permet d'afficher les évènements à l'écran.
void display() {
    glClear( GL_COLOR_BUFFER_BIT );   
    glMatrixMode( GL_MODELVIEW );
    glPopMatrix();

    currentZone = zoneHead;
    while (currentZone != NULL) {
        drawZone(currentZone);
        currentZone = currentZone->next;
    }

    glPushMatrix();
    glLoadIdentity();

    drawPlayer();

    currentEnemy = head;
    while (currentEnemy != NULL) {
        drawEnemy(currentEnemy);
        currentEnemy = currentEnemy->next;
    }

    drawBird();
    
    playerCollision();
    //camera(); //KICK
    if(enemy->life <= 0){
        removeEnemy(currentEnemy);
    }

    if(bird->life == 0){
        killBird();
        bird = newBird(); 
    }

    //TODO : killPlayer();

    glutSwapBuffers();
}

