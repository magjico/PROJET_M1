# PROJET INFORMATIQUE GRAPHIQUE M1-IAFA <!-- omit in toc -->

| Prénom |  NOM  | numéro étudiant |                               github |
| :----- | :---: | :-------------: | -----------------------------------: |
| César  | PUJOL |    21702647     | https://github.com/magjico/Projet_M1 |

Fonctionnalité :

- [x] Courbe de Bézier uniforme dans l'espace paramétrique
- [ ] Courbe de Bézier uniforme en longueur de segment
- [ ] Courbe de Bézier visualisation
- [x] Surface de Bézier
- [ ] Ombrage diffus
- [ ] Visualisation de la normale sur la surface
- [ ] Visualisation de l'espace paramétrique
- [ ] Réflectance à microfacette
- [ ] Eclairage 3 points 

___
Somaire :
- [Utilisation](#utilisation)
- [Structuration de l'application et les étapes réalisées pour ça création](#structuration-de-lapplication-et-les-étapes-réalisées-pour-ça-création)
  - [L'architecture fichier :](#larchitecture-fichier-)
  - [L'architecture code :](#larchitecture-code-)
  - [résumé du travail :](#résumé-du-travail-)
- [Critique](#critique)
  - [Travail :](#travail-)
  - [Organisation :](#organisation-)
___
## Utilisation 

Placez-vous dans le fichier **PROJET_M1** et tapez **cmake .** puis **make**.

Lancer ensuite l'éxécutable **./GraphiqueEnv \<version> \<numéro démo>**

version été supposé être les différentes versions de mon projet ici il y en a qu'une donc **version = 1**.

numéro démo :
- 0 --> fenêtre vide
- 1 --> Hello Triangle
- 2 --> Surface Besier  
  
Enfin les **controles** :

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
- Les objets contenus dans les dossiers **./src/widget** et **./src/window** sont des équivalents Qt5 de **mainwindow** qui eux ne fonctionne pas très bien.

### résumé du travail :
J'ai commencé le projet avec comme objectif de le réaliser avec **Qt5**.<br />
La première chose que j'ai réalisé c'est la création d'une fenêtre vide pas de problème j'ai suivis le tutoriel fournis dans la doc Qt.<br /> J'ai ensuite suivis le tutoriel HelloTriangle de ___learnOpengl___ cependant pour la réalisation des shaders j'ai suivis cette documentation : http://sdz.tdct.org/sdz/les-shaders-en-glsl.html . Ensuite il a fallu afficher la démo Hello Triangle, cependant je n'ai pas réussi à maitriser suffisament Qt pour y arriver seul et même en m'inspirant du dépot github laissé comme aide je n'ai pas réussi, quand j'ai vu que je perdait trop de temps sur ceci alors que ça ne rentre pas dans le but du projet j'ai décidé de changer de contexte et je suis passé de Qt5 à **glfw** et **glad** en me disant que j'implémenterais une version Qt5 plus tard.<br />
Par la suite j'ai procédé à la réalisation d'une courbe de Bézier j'avais d'abord fais une implémentation avec les points de controles passé en paramètre de l'objet mais je les ai retiré pour une implémentation des Surfaces de Bézier plus simple. Une courbe de bézier et donc simplement constituer de la taille de l'échantillonage et de la fonction ___Bernstein___ qui nous permet de calculer la partie du polygone associé à un indice réel et un float ∈ [0,1] données.
<br />
Enfin j'ai réalisé l'objet Surface de Bézier qui est constitué de deux courbes de Bézier une directrice et une génératrice, des différents points de controles qui seront utilisés pour tracer la figure, et d'un vecteur _vertices et _indices qui serviront pour la mise en lien avec le vao et le vbo pour mon rendu de cette surface.<br />

___
## Critique 

### Travail :
Je penses que je me suis éssentiellement posez trop d'objectif qui n'était pas dans le cadre de ce projet (librairie locale, affichage avec Qt et glfw) et j'ai aussi passé trop de temps sur glsl, j'ai refait une documentation manuscrite alors que j'aurais du juste apprendre les 2-3 fonctions qui m'intéréssé.

### Organisation :
Il est évident que je n'ai pas accordé assez de temps pour ce projet mais une majeure partie de celà est aussi dû à l'UE projet pour laquelle nous étions 2 pour un travail de 6 et qui contrairement à l'UE IGAI nous met une pression pour fournir du travail constant, je me suis donc retrouvé en surcharge de travail et fait passé le projet au second plan.<br /> J'ai vraiment accordé au projet IGAI que la première et 2~3 dernières semaines (en plus des mercredis matin chaques semaines). Cependant je ne compte pas jeté ce projet, je penses le continuer pendant mon temps libre après les examens.


