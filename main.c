#include "includes.h"

int main(int argc, char** argv) {
    srand( time( NULL ) ); // permet d'avoir des nombres aléatoires
    Enemy *head = NULL; 
    Zone* zoneHead = NULL;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Crossy Road - SOS animaux sauvages");

    setupMap();

    enemy = newEnemy();
    player = newPlayer();
    bird = newBird();

    glutDisplayFunc(display);
    if( !initGL() )
    {
        printf( "Unable to initialize graphics library!\n" );
        return 1;
    }
    
    glutTimerFunc(timerInterval, update, 0);  // Met à jour le premier interval de temps
    glutSpecialFunc(arrowFunc); //interractions avec le clavier
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glutReshapeFunc(reshapeWindow);
    glutMainLoop();
    return 0;
}