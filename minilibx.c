#include "mlx_Linux/mlx.h"
#include <error.h>
  #include <stdlib.h>

#include <mlx.h>
#include "includes/fdf.h"

#include <mlx.h>

typedef struct s_datas {
    void *mlx;
    void *win;
    void *img1; // Première image
    void *img2; // Deuxième image
    char *addr1; // Adresse de la première image
    char *addr2; // Adresse de la deuxième image
    int bits_per_pixel;
    int line;
    int line_length;
    int endian;
    int width;
    int height;
    float transition; // Valeur de transition pour l'interpolation linéaire
} t_datas;


char *interpolate(char *addr1, char *addr2, float transition)
{
    char *result = malloc(sizeof(char) * WINDOW_WIDTH * WINDOW_HEIGHT * 4); // Taille de l'image en RGBA

    for (int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT * 4; i++)
    {
        // Interpolation linéaire entre les valeurs des pixels des deux images
        result[i] = (1 - transition) * addr1[i] + transition * addr2[i];
    }

    return result;
}


void draw_image(t_datas *data)
{
    char *current_addr;

    // Interpolation linéaire entre les adresses des deux images
    current_addr = interpolate(data->addr1, data->addr2, data->transition);

    // Dessiner l'image sur la fenêtre MLX
    mlx_put_image_to_window(data->mlx, data->win, current_addr, 0, 0);
}

void update_transition(t_datas *data)
{
    // Mettre à jour la valeur de transition (par exemple, de 0 à 1 pour une transition complète)
    data->transition += 0.01; // Augmentez la valeur de transition en fonction de vos besoins

    // Assurez-vous que la valeur de transition reste dans la plage [0, 1]
    if (data->transition > 1.0)
        data->transition = 1.0;

    // Dessiner l'image mise à jour
    draw_image(data);
}

int main()
{
    t_datas data;

    // Initialisation de la connexion MLX
    data.mlx = mlx_init();

    // Création d'une fenêtre MLX
    data.win = mlx_new_window(data.mlx, 800, 600, "Image Transition");

    // Chargement des images
    data.img1 = mlx_xpm_file_to_image(data.mlx, "image1.xpm", &data.width, &data.height);
    data.img2 = mlx_xpm_file_to_image(data.mlx, "image2.xpm", &data.width, &data.height);

    // Obtention des adresses des images
    data.addr1 = mlx_get_data_addr(data.img1, &data.bits_per_pixel, &data.line_length, &data.endian);
    data.addr2 = mlx_get_data_addr(data.img2, &data.bits_per_pixel, &data.line_length, &data.endian);

    // Initialisation de la valeur de transition à 0
    data.transition = 0.0;

    // Dessiner l'image initiale
    draw_image(&data);

    // Boucle d'événements MLX principale
    mlx_loop(data.mlx);

    return 0;
}