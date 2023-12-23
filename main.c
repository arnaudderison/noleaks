#include "./include/noleaks.h"

int	main(void)
{
	int *array;

	// Allocation de mémoire pour un tableau de 10 entiers
	array = (int *)nlmalloc(10 * sizeof(int));
	// Vérification si l'allocation a réussi
	if (array == NULL)
	{
		ft_printf("Erreur d'allocation de mémoire\n");
		return (1);
	}
	// Remplissage du tableau avec des valeurs
	for (int i = 0; i < 10; i++)
	{
		array[i] = i;
	}
	// Affichage des valeurs du tableau
	for (int i = 0; i < 10; i++)
	{
		ft_printf("%d ", array[i]);
	}
	ft_printf("\n");
	// Libération de la mémoire allouée
	nlfree(array);
	// (Optionnel) Vérification des fuites de mémoire à la fin du programme
	check_memory_leaks();
	return (0);
}