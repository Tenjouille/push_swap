# push_swap

## Description

**push_swap** est un projet de l'école 42 qui consiste à trier une liste d'entiers en utilisant un ensemble limité d'instructions sur deux piles : `a` et `b`. Le programme doit afficher un programme composé de la plus courte suite d’instructions possible. Les entiers donnés en entrée de programme sont envoyés dans la pile `a`, et doivent être dans l'ordre chronologique dans cette même pile `a` à la fin du programme. La pile `b` servant de pile de stockage.

## Fonctionnalités

- Tri de nombres entiers en utilisant des opérations prédéfinies sur deux piles.
- Optimisation du nombre d'opérations pour atteindre le tri complet.

## Fonctionnalité bonus
- Vérification de la validité des opérations via un programme `checker`.

## Structure du projet

Le projet est organisé en plusieurs fichiers, chacun ayant un rôle spécifique :

- **`main.c`** : Point d'entrée du programme `push_swap`.
- **`checker.c`** : Programme permettant de vérifier la validité des opérations générées.
- **`algorithm.c`** et **`algorithm_utils.c`** : Implémentation des algorithmes de tri et fonctions associées.
- **`instr_push_n_swap.c`**, **`instr_rotates.c`**, **`instr_global.c`** : Définition des différentes instructions de manipulation des piles.
- **`list_manip.c`** et **`list_manip_utils.c`** : Fonctions de manipulation des listes chaînées représentant les piles.
- **`parsing.c`** : Gestion de l'analyse des arguments en entrée.
- **`get_next_line.c`**, **`get_next_line_utils.c`** : Fonctions utilitaires pour la lecture de l'entrée standard (issu d'un précédent projet proposé par l'école).
- **`push_swap.h`** et **`push_swap_bonus.h`** : Fichiers d'en-tête contenant les déclarations de fonctions et les définitions de structures.
- **`Makefile`** : Automatisation de la compilation du projet.

## Instructions d'utilisation

### Compilation

1. Clonez le dépôt :
   ```bash
   git clone https://github.com/Tenjouille/push_swap.git
   cd push_swap
   ```
2. Compilez le projet en utilisant `make` :
   ```bash
   make
   ```

### Exécution

- Pour générer les instructions de tri :
  ```bash
  ./push_swap 2 1 3 6 5 8
  ```
  Cela affichera une liste d'instructions pour trier les nombres donnés.

- Pour vérifier les instructions générées :
  ```bash
  ./push_swap 2 1 3 6 5 8 | ./checker 2 1 3 6 5 8
  ```
  Le programme `checker` indiquera si les nombres sont correctement triés après l'application des instructions.

## Instructions disponibles

Les opérations suivantes peuvent être utilisées pour manipuler les piles :

- **`sa`** : Échange les deux premiers éléments de la pile `a`.
- **`sb`** : Échange les deux premiers éléments de la pile `b`.
- **`ss`** : Effectue `sa` et `sb` simultanément.
- **`pa`** : Prend le premier élément de `b` et le place sur `a`.
- **`pb`** : Prend le premier élément de `a` et le place sur `b`.
- **`ra`** : Fait une rotation de `a` vers le haut. Le premier élement de `a` devient le dernier, le second devient le premier et ainsi de suite.
- **`rb`** : Fait une rotation de `b` vers le haut.Le premier élement de `b` devient le dernier, le second devient le premier et ainsi de suite.
- **`rr`** : Effectue `ra` et `rb` simultanément.
- **`rra`** : Fait une rotation de `a` vers le bas. Le dernier élement de `a` devient le premier, le premier devient le second et ainsi de suite.
- **`rrb`** : Fait une rotation de `b` vers le bas. Le dernier élement de `b` devient le premier, le premier devient le second et ainsi de suite.
- **`rrr`** : Effectue `rra` et `rrb` simultanément.

## Algorithme utilisé

Plusieurs approches sont possible pour réaliser ce projet. Parmi les plus courantes, on retrouve :

- [Le radix sort](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)
- [L'insertion sort](https://en.wikipedia.org/wiki/Insertion_sort)

  J'ai pour ma part décidé de partir sur un algorithme baptisé [The Turk algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

  Un algorithme qui consiste à calculer le nombre d'instruction nécessaire pour envoyer un élement de `a` à sa place déjà triée dans `b`, et ainsi choisir le "chemin" de plus court pour avoir tous les nombres triés dans l'ordre décroissant dans `b` pour ensuite tous les renvoyer dans `a`par une suite d'instructions `pa`.
  Méthode que j'ai quelque peu modifié en intégrant les instructions `rr` et `rrr` d'une manière plutôt originale. En effet les instructions ne sont jamais utilisées pour trier les entiers entrés à proprement parlé, mais plutôt affichés dans la suite d'instructions finale, chaque `rr` remplaçant un `ra` + un `rb` et chaque `rrr` remplaçant un `rra` + un `rrb` si les deux instructions sont toutes deux situées entre deux `pa`/`pb`. Ce stratagème fait la surtout la différence lorsqu'un nombre important d'entier est donné en entrée du programme.
## Auteur

- Tanguy BOURDEAU

