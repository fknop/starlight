# Participants au projet
  
* Knop Florian
* Bovyn Gatien

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
