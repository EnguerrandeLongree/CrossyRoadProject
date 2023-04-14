#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
    //structure qui définit une zone.
typedef struct zone{
    
    //State
    int type; //0 for forest, 1 for road, 2 for water
    int speedChange;

    //Positioning
    int height;

    struct zone* next;
}Zone;

void addZone();
void drawRectangle(int type, int height);
Zone* createZone(int Ycoord);
void drawZone(Zone* zone);
void removeZone(Zone *zoneToRemove);
void setupMap();
#endif