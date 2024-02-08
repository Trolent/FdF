#include "mlx_Linux/mlx.h"
#include <error.h>
  #include <stdlib.h>


#define MAX 1000
#define MIN 10


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 32)
		printf("space\n");
	if (keycode == 0x0061)
		printf("a\n");
	if (keycode == 0xffe5)
		if (keycode == 0x0061)
			printf("A\n");
	if (keycode == 0xff1b)
		exit(0);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
