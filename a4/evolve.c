#include "a4.h"
#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{

  Individual *A = (Individual *)a;
  Individual *B = (Individual *)b;

  return ( A->fitness - B->fitness );
}

PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int population_size, double rate)
{
    char s[10];
    Individual *random = generate_population(population_size, image->width, image->height, image->max_color);
    
    for (int i = 0; i < num_generations; i++)
    {
        crossover(random, population_size);
        mutate_population(random, population_size, rate);
        comp_fitness_population(image->data, random, population_size);
        qsort(random,population_size,sizeof(Individual),compare);
        if (!(i%200)) {
            sprintf(s,"%d.ppm",i);
            write_ppm(s,&random[0].image);
        }
        printf("Gen: %d\tFit: %f\n", i, random[0].fitness); //for debugging
        printf("\n");
    }

    for (int j = 1; j < population_size; j++)
    {
        free(random[j].image.data);
    }
    return &random->image;
}

void free_image(PPM_IMAGE *p)
{
    free(p->data);
    free(p);
}
