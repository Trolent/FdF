typedef struct s_test {
	int x[2];
	int y[2];
	int z[2];
} t_test;

#define NORM 0
#define ISO 1


void process_map(t_test *map, int use_iso)
{
	int coord;

	if (use_iso == 1)
		coord = ISO;
	else
		coord = NORM;
	if (coord == 1)
		printf(" ISO\n");
	else
		printf(" NORM\n");
	printf(" x = %d, y = %d, z = %d\n", map->x[coord], map->y[coord], map->z[coord]);
}

int main() {
    t_test test = {1, 2, 3, 4, 5, 6};
    int use_iso = 1; // Change this value to switch between normal and iso values

    process_map(&test, use_iso); // Example usage for x-axis value

    return 0;
}