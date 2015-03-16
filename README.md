# Participants au projet


  
* Knop Florian
* Bovyn Gatien

***

# Rules

Starlight est un puzzle à deux dimensions se jouant sur une carte rectangulaire. 
Le but du jeu est de dévier un rayon lumineux d'une source vers
une cible en évitant certains obstacles. Plus particulièrement, on trouve les
éléments suivants sur une carte.

* 
Une unique source : cet élément émet un rayon 
lumineux d'une longueur d'onde donnée sous un certain angle.

* 
Une unique cible (ou destination) : cet élément doit être éclairé par un
rayon lumineux pour remporter la partie.

* 
Un ensemble de miroirs : un miroir est un objet réfléchissant la lumière
d'un seul côté suivant le schéma naturel de la réflexion de la lumière.
Plus particulièrement, un rayon incident à un miroir sous un angle &#x3b8;i
sera réfléchi sous le même angle &#x3b8;r.

* 
Un ensemble de murs : les murs ne réfléchissent pas la lumière. Tout
rayon incident à un mur ne se propage pas, et s'arrête donc là où
il y est incident.

* 
Un ensemble de lentilles. Les lentilles sont des objets transparents qui
ne laissent passer un rayon lumineux que dans un certain intervalle de
longueur d'onde [m,n].
Si un rayon lumineux possède une longueur d'onde &#x3d1;
telle que m &#x2264; &#x3d1;  &#x2264; n, il traverse la lentille sans subir aucune
modication. Sinon, la lentille stoppe le rayon (elle se comporte comme
un mur).

* 
Un ensemble de cristaux : un cristal est un élément transparent qui
modifie la longueur d'onde d'un rayon, en l'augmentant ou la diminuant.
Tout rayon qui traverse un cristal le traverse donc sans subir de
modification de trajectoire, mais voit sa longueur d'onde modifiée.

* 
Un ensemble de bombes. Les bombes sont des objets qui, si éclairés,
explosent et font automatiquement perdre la partie au joueur.

* 
Un ensemble de rayons. Initialement émis par la source du jeu, ils
sont rectilignes et se réfléchissent sur les miroirs. Un rayon est donc un
segment de droite. 
Un rayon possède également une autre caractéristique : sa
longueur d'onde. La longueur d'onde d'un rayon permet de déterminer,
comme mentionné ci-dessus, si oui ou non un rayon traverse une lentille.
Elle est modifiée par un cristal.


Tous les objets ci-dessus sont immobiles, à l'exception des miroirs qui
peuvent être déplacés et pivotés dans certaines limites.
Les rayons lumineux ne sont présents dans le jeu que lorsque la source lumineuse
est allumée.

***

# Exigences et remise

* 
Fournir une interface graphique permettant de jouer à Starlight
en respectant les règles décrites dans ce document et les propriétés 
de chacun des éléments de la carte.

* 
L'interface graphique doit être batie sur l'architecture *Observateur/observé*

*  
Être capable de lire et de charger des cartes depuis un fichier texte dont le format
est décrit.

*  
Le joueur doit être capable d'allumer et d'éteindre la source. Les rayons
sont automatiquement calculés quand la source est allumée. Ils disparaissent quand
la source est éteinte.

* **Remise le 24 avril 2015**

***

## Points facultatifs

### Objectifs techniques

* 
Changer la couleur du rayon en fonction de sa longueur d'onde.

*   
Changer l'apparence des rayons lumineux et des éléments de la carte, par exemple via
des textures (images).

* 
Ajouter des effets sonores.

* 
**Fournir un éditeur de carte intuitif, par exemple, permettant
de placer les composants à la souris. Sa modélisation et conception sont 
laissées à votre discrétion.**

### Objectifs algorithmiques

*   
Permettre de changer les formes de base des éléments du jeu.

*  
Gérer les collisions entre les miroirs et les autres éléments du jeu. 
Par exemple, empêcher de l'extrémité des miroirs ne rentre dans les murs.

* 
**Fournir un générateur de carte aléatoire simple. 
Remarque: ce point est relativement difficile. 
N'essayez que si vous avez fini les objectifs secondaires 
précédents.**

* 
**Implémenter un algorithme permettant de résoudre le puzzle
automatiquement. Remarque : ce point est très difficile. N'essayez
que si vous n'avez rien d'autre à faire.**


