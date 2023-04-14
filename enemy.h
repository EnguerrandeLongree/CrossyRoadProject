#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

//structure qui définit un ennemi.
typedef struct enemy{
    //life, state, position, score, shots, color, shape, …
    
    //State
    int life;
    int state; 

    //Positioning
    int Xposition;
    int Yposition;
    int direction; 

    //prochain element de la liste chainee.
    struct enemy* next;
}Enemy;

Enemy* newEnemy();
void addEnemy(int positionY);
void removeEnemy(Enemy *enemyToRemove);
void drawEnemy(Enemy *enemy);

#endif