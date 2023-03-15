# PROJET INFORMATIQUE GRAPHIQUE M2-IAFA <!-- omit in toc -->

| Prénom |  NOM  | numéro étudiant |                               github |
| :----- | :---: | :-------------: | -----------------------------------: |
| César  | PUJOL |    21702647     | https://github.com/magjico/Projet_M2 |

## Utilisation 

Placez-vous dans le fichier **PROJET_M2** et tapez **cmake .** puis **make**.

Lancer ensuite l'éxécutable **./GraphiqueEnv \<version> \<numéro démo>**

version été supposé être les différentes versions de mon projet ici il y en a qu'une donc **version = 1**.

numéro démo :
- 0 --> fenêtre vide
- 1 --> Hello Triangle
- 2 --> Surface Besier
- 3 --> Hello Cube  
  
**controles** :

- Enter --> Visualiser les TriangleMesh
___
## Structuration de l'application et les étapes réalisées pour ça création

### L'architecture fichier :
- Un **CMakeLists** qui relie les librairies installés localement pour mon projet ainsi que de créer l'éxécutable à partir des différents fichier de code que j'ai écrit.
- Un dossier **shader** contenant les différents vertex shader et fragment shader.
- Un dossier **src** qui contient le code que j'ai écris pour le développement de cette application
- Un dossier **lib** qui contient les librairies externes importées pour ce projet ( glad, glfw, glm  et anciennement aussi qt5 et assimp)

### L'architecture code :
- **basic** : (situé dans le répertoire ___./src/basic_function___)<br /> ce fichier contient des fonctions utilitaire qui n'appartiennent à aucun objet. 
- L'objet **openglObject** : (situé dans le répertoire ___./src/openglObject___).<br /> Il sert de base à tous les objets pour lesquels je souhaite avassimpn de créer un shader et de construire un objet program qui me permet de faire éxécuter les shaders par la carte graphique.
- L'objet **SimpleTriangle** : (situé dans le répertoire ___./src/hello_triangles___). <br /> Il hérite de **openglObject**. Il me permet de générer à partir d'un ensemble de sommet et d'indices un affichage de la figure correspondant il possède aussi un contructeur vide pour générer la démo.
- L'objet **BesierCurve** : (situé dans le répertoire ___./src/besier_curves___).<br /> Il représente la représentation paramétrique d'une courbe de bézier avec une longueur de décomposition donnée.
- L'objet **BesierSurface** : (situé dans le répertoire ___./src/besier_surface___).<br />Il hérite de **openglObject**. Il me permet de générer des surfaces de bézier en lui passant en entrée des points de controle et une taille de décomposition. Il possède un objet SimpleTriangle qui me permet de l'afficher.
- L'objet **mainwindow** : (situé dans ___./src/windowGLFW___)
me permet de générer l'affichage de la fenetre et de stocker d'afficher les objets **openglObject** ou les objets qui en hérite c'est lui qui est inclu dans le main.
- **hellocube** construit un cube et retranscrit ça géométrie en triangle mesh
- **lightning** début d'une implémentation d'un éclairage basic en suivant les tutoriels openGL
- **skeleton** début d'implémentation de LBS
