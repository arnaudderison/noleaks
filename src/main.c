#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "../include/noleaks.h"  // Assurez-vous que le chemin d'accès est correct

void *thread_function(void *arg) {
    (void )arg;
    unsigned int rand_state = time(NULL) ^ (unsigned int)pthread_self(); // État initial pour rand_r
    for (int i = 0; i < 100; i++) {
        int test_size = (rand_r(&rand_state) % 500) + 1; // Taille aléatoire entre 1 et 1000
        char *memory = nlmalloc(test_size);
        if (memory == NULL) {
            fprintf(stderr, "Erreur d'allocation mémoire\n");
            continue;  // Poursuivre avec la prochaine itération
        }

        // Utilisation fictive de la mémoire
        for (int j = 0; j < test_size; ++j) {
            memory[j] = 'a';
        }

        nlfree(memory);
    }
    pthread_exit(NULL);
}

int main() {
    const int num_threads = 10; // Nombre de threads pour le test
    pthread_t threads[num_threads];

    // Création de threads
    for (int i = 0; i < num_threads; ++i) {
        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0) {
            fprintf(stderr, "Erreur de création de thread\n");
            return 1;
        }
    }

    // Attendre la fin de tous les threads
    for (int i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], NULL);
    }

    check_fragmentation();
    printf("Test multithread avec rand_r réussi.\n");
    return 0;
}
