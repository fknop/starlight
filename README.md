# Participants au projet


  
* Knop Florian
* Bovyn Gatien

# TODO

**Une fois effectué -> Barrer la ligne !**

* Editeur : Prévenir les erreurs (pour éviter de sauvegarder un objet foireux)
* ~~Bloquer le mapview une fois la partie gagnée ou perdue.~~
* ~~Editeur : pouvoir bouger les autres éléments au clavier.~~
* ~~Editeur : Modifier dynamiquement les propriétés ?~~
* ~~Editeur : Message de confirmation quand on quitte ? Pour éviter de perdre des maps non
sauvegardée~~
* ~~Editeur : Ctrl-X pour delete un objet ? :D~~
* ~~Editeur : Simple clic pour le sélectionner (c'est un peu galère) -> OSEF~~
* ~~Gérer les collisions entre miroirs de même angle.~~
* ~~Gérer la reflexion du rayon sur un miroir.  A FINIR~~
* ~~Gérer les divers évènements lors de l'intersection avec un objet.~~
* ~~Faire le cast d'un élément en sous-élément~~ !
* ~~Gérer les lignes verticales.~~
* ~~Gérer les intersections entres droites, segments, ellipses.~~
* ~~Gérer le retour du point d'intersection et de l'objet.~~
* ~~Gérer les vérifications dans les constructeurs. - A FINIR~~
* ~~Gérer le déplacement des miroirs.~~
* ~~Gérer la rotations des miroirs.   - A TESTER~~


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
Un ensemble de miroirs : un miroir est un objet réfléchissant la lumière
d'un seul côté suivant le schéma naturel de la réflexion de la lumière.
Plus particulièrement, un rayon incident à un miroir sous un angle &#x3b8;i
sera réfléchi sous le même angle &#x3b8;r.

* 
Un ensemble de murs : les murs ne réfléchissent pas la lumière. Tout
rayon incident à un mur ne se propage pas, et s'arrête donc là où
il y est incident.

* 
Un ensemble de lentilles. Les lentilles sont des objets transparents qui
ne laissent passer un rayon lumineux que dans un certain intervalle de
longueur d'onde [m,n].
Si un rayon lumineux possède une longueur d'onde &#x3d1;
telle que m &#x2264; &#x3d1;  &#x2264; n, il traverse la lentille sans subir aucune
modification. Sinon, la lentille stoppe le rayon (elle se comporte comme
un mur).

* 
Un ensemble de cristaux : un cristal est un élément transparent qui
modifie la longueur d'onde d'un rayon, en l'augmentant ou la diminuant.
Tout rayon qui traverse un cristal le traverse donc sans subir de
modification de trajectoire, mais voit sa longueur d'onde modifiée.

* 
Un ensemble de bombes. Les bombes sont des objets qui, si éclairés,
explosent et font automatiquement perdre la partie au joueur.

* 
Un ensemble de rayons. Initialement émis par la source du jeu, ils
sont rectilignes et se réfléchissent sur les miroirs. Un rayon est donc un
segment de droite. 
Un rayon possède également une autre caractéristique : sa
longueur d'onde. La longueur d'onde d'un rayon permet de déterminer,
comme mentionné ci-dessus, si oui ou non un rayon traverse une lentille.
Elle est modifiée par un cristal.


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
Par exemple, empêcher que l'extrémité des miroirs ne rentre dans les murs.

* 
**Fournir un générateur de carte aléatoire simple. 
Remarque: ce point est relativement difficile. 
N'essayez que si vous avez fini les objectifs secondaires 
précédents.**

* 
**Implémenter un algorithme permettant de résoudre le puzzle
automatiquement. Remarque : ce point est très difficile. N'essayez
que si vous n'avez rien d'autre à faire.**

### Compilation

*Nécessite g++-4.9*

Installation sous Ubuntu (testé 12.04) :

```
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt-get update
sudo apt-get install g++-4.9
cd /usr/bin
sudo rm g++
sudo ln -s g++-4.9 g++
```

### Liens utiles

* http://i.imgur.com/Vl122xn.png
* Solution Level 1 : http://i.imgur.com/StfYIJY.png