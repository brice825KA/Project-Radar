# Project-Radar
My Radar
# Step For Build Program simulation Aircraft
1- Parsing data
2- Set Window, menu
3- test simulation for one plane
4- Test simulation for two plane
4- Test simulation for many plane
# Simulation Ressource
Voici une sélection ciblée de documentations officielles, de tutoriels conceptuels et de vidéos pour apprendre à gérer le déplacement de multiples entités, leurs collisions et l'optimisation (indispensable dans My Radar lorsqu'il y a des centaines ou milliers d'avions) :

1. Documentation Officielle Raylib (Collisions & Mouvements)

• Module rshapes (Cheatsheet Raylib) : Consultez la section Basic Shapes Collision Detection Functions sur raylib.com. Vous y trouverez les signatures exactes des fonctions natives comme CheckCollisionRecs (collision entre deux hitboxes carrées d'avions) et CheckCollisionCircleRec (pour vérifier si un avion est dans la zone de sécurité d'une tour).
• Exemples officiels Raylib (shapes & textures) : Sur raylib.com, regardez particulièrement :
	• Shapes -> collision area (comprendre les hitboxes AABB).
	• Textures -> sprite explosion ou bunnymark (voir comment raylib gère et met à jour des centaines d'objets en mouvement dans une boucle avec std::vector ou des tableaux).

2. Algorithmes d'Optimisation des Collisions (Crucial pour My Radar)

Si vous testez chaque avion contre tous les autres (O(n²)), votre simulation va laguer dès que vous dépasserez quelques centaines d'avions (les tests de soutenance montent souvent à 10 000+ avions).
• Article interactif sur les Quadtrees (The Coding Train) : Lisez le guide ou regardez la vidéo "Coding Challenge #98: Quadtree" par Daniel Shiffman sur YouTube. Il explique visuellement comment découper l'écran en 4 zones récursives pour ne tester les collisions qu'entre avions proches.
• Tutoriel C++ Quadtree (GameDev / Tuts+) : L'article "Quick Tip: Use Quadtrees to Detect Likely Collisions in 2D Space" (sur Envato Tuts+) détaille la structure de données d'un arbre quaternaire et son fonctionnement pas à pas sans dépendre d'un moteur de jeu.
• Alternative plus simple — La Grille Spatiale (Spatial Hash Grid) : Recherchez l'article "Spatial Hashing" sur gamedev.net ou la vidéo "Spatial Partitioning - Game Programming Patterns" (basée sur le livre gratuit en ligne gameprogrammingpatterns.com de Robert Nystrom). C'est souvent plus rapide et plus simple à implémenter qu'un Quadtree pour une carte fixe de taille connue.

3. Mathématiques du Déplacement 2D & Vecteurs

• The Nature of Code (Chapitre 1 : Vectors) : Disponible gratuitement en ligne sur natureofcode.com. Ce chapitre explique la logique mathématique derrière le mouvement d'un point A vers un point B à vitesse constante (soustraction de vecteurs, normalisation, multiplication par la vitesse et le delta-time).
• Documentation raymath.h : Raylib inclut la bibliothèque mathématique raymath.h (documentée sur le Wiki GitHub de Raylib). Regardez les fonctions Vector2Subtract, Vector2Normalize, Vector2Scale et Vector2Distance qui évitent de réécrire les formules trigonométriques à la main.

4. Tutoriels Vidéo C++ & Raylib (Gestion d'entités multiples)

• Chaîne YouTube Programming With Nick : Recherchez sa série "Raylib C++ Tutorial" (notamment les vidéos sur Space Invaders ou Asteroids). Il montre comment structurer une classe ou une struct pour des projectiles/ennemis multiples stockés dans un std::vector, comment les faire apparaître selon un chronomètre (timer) et comment les supprimer proprement lors d'une collision.
• Chaîne YouTube Clear Code : La vidéo "The ultimate introduction to Raylib" (bien que orientée Python, toute la logique d'architecture de boucle, de gestion du temps delta_time, de listes d'entités et de hitboxes est identique en C++).
Souhaitez-vous que l'on se concentre sur un concept précis parmi ces ressources pour la suite de votre projet :
L'architecture du Quadtree ou de la grille spatiale pour passer les tests de performanceLa trigonométrie et raymath.h pour orienter et déplacer vos avionsLa gestion du chronomètre (GetFrameTime()) pour les délais de décollage
Dites-moi quel point vous voulez approfondir.
