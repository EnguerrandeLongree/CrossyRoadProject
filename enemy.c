#include "includes.h"

// crée le premier ennemi de la liste chainée
Enemy* newEnemy(){
    Enemy* enemy = malloc(sizeof(Enemy));

    // état
    enemy->life = 1; // L'ennemi n'a qu'une seule vie
    enemy->state = 1; // L'état 1 correspond à un état "vivant", l'état 0 correspond à un état "mort".

    // position 
    enemy->direction = 0; // si 0 l'ennemi regarde vers la droite, si 1 l'ennemi regarde vers la gauche.
    enemy->Yposition = 0;  //TODO: Position du nouvel ennemi dépend de la zone où il doit apparaître. Pour le moment 
    enemy->Xposition = leftLimit;

    /*enemy->direction = rand()%1; // si 0 l'ennemi regarde vers la droite, si 1 l'ennemi regarde vers la gauche.
    if(enemy->direction == 1){
    }
    if(enemy->direction == 0){
        enemy->Xposition = 0;
    }*/

    //Pointe sur le prochain ennemi.
    enemy->next = head;
    head = enemy;
    return enemy;
}

// Fonction pour ajouter un ennemi à la liste chaînée
void addEnemy(int positionY) {

    // Allouer de la mémoire pour le nouvel ennemi
    Enemy *newEnemy = (Enemy*) malloc(sizeof(Enemy));
    
    // état
    newEnemy->life = 1; // L'ennemi n'a qu'une seule vie
    newEnemy->state = 1; // L'état 1 correspond à un état "vivant", l'état 0 correspond à un état "mort".

    // position 
    newEnemy->direction = 0; // si 0 l'ennemi regarde vers la droite, si 1 l'ennemi regarde vers la gauche.
    newEnemy->Yposition = positionY;  //TODO: Position du nouvel ennemi dépend de la zone où il doit apparaître.
    newEnemy->Xposition = leftLimit;
    
    newEnemy->next = NULL;
    // Ajouter le nouvel ennemi au début de la liste
    if (head == NULL) {
        head = newEnemy;
    } else {
        newEnemy->next = head;
        head = newEnemy;
    }
}

//A MODIFIER car elle entraine du core dumping.
// Fonction pour supprimer un ennemi de la liste chaînée
void removeEnemy(Enemy *enemyToRemove) {
    if (head == enemyToRemove) {
        head = head->next;
    } else {
       /* currentEnemy = head; //redefined?
        while (currentEnemy != NULL && currentEnemy->next != enemyToRemove) {
            currentEnemy = currentEnemy->next;
        }
        if (currentEnemy != NULL) {
            currentEnemy->next = enemyToRemove->next;
        }
    }*/

        // Cherche l'ennemi suivant.
        Enemy* prevEnemy = head;
        while (prevEnemy->next != enemyToRemove) {
            prevEnemy = prevEnemy->next;
        }

        // Mettre à jour le pointeur "next" du précédent pour qu'il pointe sur le suivant
        prevEnemy->next = enemyToRemove->next;
    }
    free(enemyToRemove);
}


//permet d'afficher un ennemi.
void drawEnemy(Enemy *enemy){
    if(enemy->direction == 0){
        glRasterPos2s(cameraX -500, cameraY); //camera
        glColor3f(100, 50, 50);
        glBitmap(64, 64, enemy->Xposition, enemy->Yposition, 0, 0, car);
    }
    if(enemy->direction == 3){
        glBitmap(64, 64, enemy->Xposition, enemy->Yposition, 0, 0, car);
    }
}
