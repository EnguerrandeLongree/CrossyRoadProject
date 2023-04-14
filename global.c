#include "includes.h"

GLsizei windowWidth = 1000;
GLsizei windowHeight = 1000;
GLint cameraX = 0, cameraY = 0;
GLfloat gcameraY = 0;

int leftLimit = -300;
int rightLimit = -900;
int zoneHeight = 0;
int timerInterval = 10;  // Timer interval en millisecondes

Player* player;
Enemy* enemy;
Enemy* currentEnemy;
Enemy *head;
Zone* currentZone;
Zone* zoneHead;

Bird* bird;
Zone* zone;

bool UP = false;
bool LEFT = false;
bool RIGHT = false;
bool DOWN = false;

