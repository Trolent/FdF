#include <mlx.h>
#include "includes/fdf.h"
#include <stdio.h>

int mouse_scroll(int button, int x, int y, void *param)
{
    // Param contient des informations supplémentaires sur l'événement de souris
    printf("Mouse scroll event: Button %d, position (%d, %d)\n", button, x, y);
    
    // Vous pouvez effectuer des actions en fonction de l'événement de molette de la souris ici

    return (0);
}

int main()
{
    void *mlx;
    void *win;

    // Initialisation de la connexion MLX
    mlx = mlx_init();
    if (!mlx)
        return (1);

    // Création d'une fenêtre MLX
    win = mlx_new_window(mlx, 800, 600, "Mouse Scroll Example");
    if (!win)
        return (1);

    // Associer la fonction de rappel à la fenêtre pour gérer les événements de molette de la souris
    mlx_mouse_hook(win, mouse_scroll, NULL);

    // Boucle d'événements MLX principale
    mlx_loop(mlx);

    return (0);
}
