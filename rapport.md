% Rapport du projet Starlight
% Florian Knop (39310) - Gatien Bovyn (39189)
% 29/03/2015

# Table des matières


# Introduction


Ce document vise à présenter le travail d’analyse et de programmation effectué
lors de la réalisation du projet du laboratoire Langage C++ : Starlight.

Ce projet a été réalisé en binôme par Florian Knop, matricule 39310 groupe 2G13,
et Gatien Bovyn, matricule 39189 groupe 2G11.

Le programme à concevoir consiste en une implémentation du modèle et d’une interface
graphique du jeu baptisé Starlight, puzzle à 2 dimensions basé sur la lumière.


# Sections


# Présentation des différentes classes


L’implémentation du projet est divisée entre la partie modèle et la partie vue.
Elle est également basée sur le design pattern  Observeur / Observé  comme demandé
dans les consignes.


## Modèle


Un squelette de l’application nous a été fourni par Monsieur Absil. Ce squelette contient les fichiers suivants :

`point.h, source.h, dest.h, nuke.h, wall.h, crystal.h, lens.h, mirror.h, ray.h, level.h`.


## Vue


L’interface graphique a été réalisée en `Qt` à la main.

Les classes composant la partie vue de l’application sont :

### DestinationView


#### Description

Classe modélisant la destination à atteindre par le rayon émis depuis la source pour gagner la partie.

#### MapView


#### MirrorView


#### NukeView


#### SourceView


#### WallView




# Conclusion


# Bibliographie


# Annexes (facultatif)


