# 🕹️ so_long – Mini jeu 2D avec MiniLibX avec windows

Ce projet 42 consiste à créer un petit jeu en 2D où le joueur (Stitch 🛸) doit collecter tous les objets (fleurs 🌺) pour pouvoir rejoindre la sortie et retrouver Lilo. Le tout est réalisé en C avec la bibliothèque MiniLibX.

---

## 🎮 Objectifs

- Charger une carte au format `.ber`
- Afficher la map graphiquement (murs, sol, joueur, objets, sortie…)
- Permettre les déplacements avec le clavier (ZQSD)
- Empêcher de traverser les murs
- Compter les mouvements du joueur
- Ne permettre la sortie que si tous les objets sont collectés
- Fermer proprement le programme (ESC ou croix)

---

## 📁 Fichiers

| Fichier              | Description                                       |
|----------------------|---------------------------------------------------|
| `main.c`             | Fonction principale, gestion des erreurs          |
| `parser.c`           | Chargement et lecture du fichier `.ber`          |
| `map_utils.c`        | Vérifications : murs, contenu, accès              |
| `path_checker.c`     | Algorithme de flood fill (accessibilité)         |
| `render.c`           | Affichage des éléments à l’écran                  |
| `player.c`           | Gestion des déplacements                         |
| `images.c`           | Chargement des textures `.xpm`                   |
| `utils.c`            | Fonctions utilitaires (erreurs, affichage)       |
| `so_long.h`          | Header principal du projet                        |

---

🧱 Objectifs

🗺️ Charger une carte .ber
🧍 Contrôler le joueur avec Z, Q, S, D
🧱 Bloquer les murs (1)
🌺 Ramasser les objets (C)
🚪 Déverrouiller la sortie (E) après avoir tout collecté
📊 Afficher le nombre de mouvements
❌ Fermer proprement avec ESC ou la croix

📂 Exemple de carte:
1111111
1P0C0E1
1000001
1111111

🔧 Compilation & Exécution
# make
# ./so_long maps/ma_map.ber

🧪 Norminette & Valgrind
✅ Conforme Norminette
✅ Zéro fuite mémoire (valgrind --leak-check=full)

🖼️ Aperçu visuel
* Murs style Pac-Man
* Arbres personnalisés (A)
* Interface minimaliste et propre
* Message de victoire stylé :

★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆
    Bravo ! Stitch a retrouvé Lilo 🌺
★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆ ★ ☆
👨‍💻 Auteur
🎓 Projet 42 – réalisé par Hind EL MOUTAWAKIL (hinel-mo)

Développement, debug, graphismes et stylisation ✨

📎 Prêt à tester ? Envoie-moi une map .ber et je te montre Stitch en action ! 💥
