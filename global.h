#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

extern GLsizei  windowHeight;
extern GLsizei  windowWidth;
extern int timerInterval;
extern GLint cameraX, cameraY;
extern GLfloat gcameraY; 

extern int leftLimit;
extern int rightLimit;
extern int zoneHeight;

extern Player* player;
extern Enemy* enemy;
extern Enemy* currentEnemy;
extern Enemy *head;
extern Zone* currentZone;
extern Zone* zoneHead;

extern Bird* bird;
extern Zone* zone;

extern bool UP;
extern bool LEFT;
extern bool RIGHT;
extern bool DOWN;

#endif