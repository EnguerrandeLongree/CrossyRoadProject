#ifndef BIRD_H_INCLUDED
#define BIRD_H_INCLUDED

typedef struct bird{
    //life, state, position, score, shots, color, shape, …
    
    //State
    int life;
    int state; 

    //Positioning
    int Xposition;
    int Yposition;
    int direction; 
}Bird;
Bird* newBird();
void killBird();
float orientBird();
void moveBird(float angle);
void trackPlayer();
void drawBird();
#endif