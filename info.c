/*
TO COMPILE:
gcc main.c event.c pictures.c global.c player.c enemy.c bird.c map.c includes.h -o run -lglut -lGLU -lGL -lm


############################################

PHASE 1: 
*Il y a un personnable affiché à l'écran qui peut se déplacer.
*Il y a des collisions et des déplacements possibles de la caméra vers le haut.
*Les ennemis (voitures) sont dans une liste chainée mais leur position n'est pas encore sur les routes.
*L'ennemi de type oiseau traque le joueur en suivant sa position et meurt quand il touche le joueur, le joueur perd une vie.
*La map est composée liste chainée de zones créées aléatoirement.

Ce qu'il faut rajouter:
- Ajouter une colorimétrie agréable
- La possibilité pour le joueur de tirer
- La position des ennemis sur la route
- Une meilleur gestion des collisions
- l'effet de la zone "eau" qui déplace le joueur horizontalement
- La possibilité d'écrire du texte pour afficher les vies du joueur et le score
- Un objet collectable
- Un menu global, un menu de game over


############################################


Player{life, state, position, score, shots, color, shape, …}
Enemy{position, shots, speed, color, shape, …} 
Obstacle{position, state, color, shape, …}
Collectable{state, speed, color, shape, …}
Position{posX, posY}
Screen{title, color, items, …}
Zone{color, items, enemy, obstacle, …}
Context{enemynbr, collectablenbr, zonetype, Player, …}


############################################


Bird.c : S'occupe de la gestion de l'oiseau qui attaque le joueur

Enemy.c : Contient les fonctions qui articulent le comportement et l’aspect des ennemis.

Event.c : S’occupe de tous les éléments d’interaction avec l’utilisation comme le clic de la souris, l’interaction avec le clavier, …

Global.c : Contient toutes les variables globales.

Includes.h : Contient les fichiers "include" et les assemble.

Main.c : Il assemblera tous les éléments de manière claire et succincte afin que le code fonctionne correctement.

Map.c : S’occupe d’afficher les éléments du fond d’écran et des zones de jeu.

Pictures.c : Contient les différents dessins pixelisés du jeu sous la forme d’un code hexadécimal. Un dessin peut être appelé par son nom à une position voulue.

State.c : Contiendra les fonctions qui permettent de changer l’état du jeu, d’afficher un écran comme le menu, comparer le high score, …

Player.c : Contient les fonctions nécessaires à l’utilisation du personnage comme son déplacement, son affichage, sa vie, …

Save.c : S’occupe d’extraire les données actuelles du jeu dans un fichier texte et permet de les récupérer par la suite.

state.c : S'occupe de changer l'état du jeu. Menu, partie en cours, game over, ...


############################################


*/