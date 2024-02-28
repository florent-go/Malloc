// https://medium.com/a-42-journey/how-to-create-your-own-malloc-library-b86fedd39b96
#include "malloc.h"
// void *malloc(size_t taille)
// {
//     // Calculer la taille du bloc à allouer
//     size_t taille_bloc = taille + sizeof(bloc_memoire_t);
//     size_t taille_page = getpagesize();
//     printf("taille de getpagesize = %zu\n", taille_page);
//     taille_bloc = (taille_bloc + taille_page - 1) & ~(taille_page - 1);

//     printf("taille de getpagesize = %zu\n", taille_bloc);

//     // Appeler la fonction mmap pour mapper une zone de mémoire de la taille souhaitée
//     void *zone_memoire = mmap(NULL, taille_bloc, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
//     if (zone_memoire == MAP_FAILED) {
//         return NULL;
//     }

//     // Initialiser la structure de données du bloc
//     bloc_memoire_t *bloc = (bloc_memoire_t *)zone_memoire;
//     bloc->taille = taille;
//     // bloc->zone_memoire = zone_memoire;
//     bloc->suivant = NULL;

//     // Retourner un pointeur vers le début de la zone de mémoire mappée
//     return zone_memoire + sizeof(bloc_memoire_t);
// }

// void show_alloc_mem()
// {
//     // Parcourir tous les blocs de mémoire alloués
//     bloc_memoire_t *bloc = premier_bloc_libre;
//     while (bloc != NULL) {
//         // Afficher des informations sur le bloc
//         printf("Taille du bloc : %zu\n", bloc->taille);
//         printf("Zone de mémoire : %p\n", bloc->zone_memoire);

//         // Afficher des informations supplémentaires si nécessaire

//         bloc = bloc->suivant;
//     }
// }

int main()
{

    printf("======================= Ma Function ========================\n");
    
    size_t taille_bloc = sizeof(int) + sizeof(bloc_memoire_t);
    size_t taille_page = getpagesize();
    printf("taille de getpagesize = %zu\n", taille_page);
    // taille_bloc = (taille_bloc + taille_page - 1) & ~(taille_page - 1);

    printf("taille de getpagesize = %zu\n", taille_bloc);

    // size_t taille_page = getpagesize();
    // printf("%zu\n",taille_page);
    // void *ptr = malloc(sizeof(int));

    // MALLOC_CHECK(ptr);

    // printf("======================= Cas Iniatial ========================\n");

    // int *trueptr = (int *)malloc(8);
    
    // *trueptr = 10;

    // free(trueptr);

    // *trueptr = 15;
    
    // printf("%d\n", *trueptr);
    // free(ptr);
    // munmap(trueptr, 20000000);
    return 0;
}