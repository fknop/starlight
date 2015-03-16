<h1>Participants au projet</h1>

<ul>
    <li>Knop Florian</li>
    <li>Bovyn Gatien</li>
</ul>



<h1>Rules</h1>

Starlight est un puzzle à deux dimensions se jouant sur une carte rectangulaire. 
Le but du jeu est de dévier un rayon lumineux d'une source vers
une cible en évitant certains obstacles. Plus particulièrement, on trouve les
éléments suivants sur une carte.

<ul>
<li> 
Une unique source : cet élément émet un rayon 
lumineux d'une longueur d'onde donnée sous un certain angle.
</li>
<li>Une unique cible (ou destination) : cet élément doit être éclairé par un
rayon lumineux pour remporter la partie.
</li>
<li>
Un ensemble de miroirs : un miroir est un objet réfléchissant la lumière
d'un seul côté suivant le schéma naturel de la réflexion de la lumière.
Plus particulièrement, un rayon incident à un miroir sous un angle &#x3b8;i
sera réfléchi sous le même angle &#x3b8;r.
</li>
<li>
Un ensemble de
murs
: les murs ne rééchissent pas la lumière. Tout
rayon incident à un mur ne se propage pas, et  s'arrête  donc là où
il y est incident.
</li>
<li>
Un ensemble de lentilles. Les lentilles sont des objets transparents qui
ne laissent passer un rayon lumineux que dans un certain intervalle de
longueur d'onde [m,n].
Si un rayon lumineux possède une longueur d'onde &#x3d1;
telle que m &#x2264; &#x3d1;  &#x2264; n, il traverse la lentille sans subir aucune
modication. Sinon, la lentille stoppe le rayon (elle se comporte comme
un mur).
</li>
<li>
Un ensemble de cristaux : un cristal est un élément transparent qui
modifie la longueur d'onde d'un rayon, en l'augmentant ou la diminuant.
Tout rayon qui traverse un cristal le traverse donc sans subir de
modification de trajectoire, mais voit sa longueur d'onde modifiée.
</li>
<li>
Un ensemble de bombes. Les bombes sont des objets qui, si éclairés,
explosent et font automatiquement perdre la partie au joueur.
</li>
<li> 
Un ensemble de rayons. Initialement émis par la source du jeu, ils
sont rectilignes et se réfléchissent sur les miroirs. Un rayon est donc un
segment de droite. 
Un rayon possède également une autre caractéristique : sa
longueur d'onde. La longueur d'onde d'un rayon permet de déterminer,
comme mentionné ci-dessus, si oui ou non un rayon traverse une lentille.
Elle est modifiée par un cristal.
</li>
</ul>
Tous les objets ci-dessus sont immobiles, à l'exception des miroirs qui
peuvent être déplacés et pivotés dans certaines limites.
Les rayons lumineux ne sont présents dans le jeu que lorsque la source lumineuse
est allumée.