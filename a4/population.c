#include "a4.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

PIXEL *generate_random_image(int width, int height, int max_color)
{
    int total_pixels = width*height;
    PIXEL *pixels = malloc(total_pixels*sizeof(PIXEL));

    for (int i = 0; i < total_pixels; i++)
    {
        pixels[i].r = rand()%(max_color+1);
        pixels[i].g = rand()%(max_color+1);
        pixels[i].b = rand()%(max_color+1);
    }
    return pixels;
}

Individual *generate_population(int population_size, int width, int height, int max_color)
{
    srand(time(NULL));
    Individual *population;
    population = malloc(population_size*sizeof(Individual));

    for (int i = 0; i < population_size; i++)
    {
        PPM_IMAGE image;
        image.width = width;
        image.height = height;
        image.max_color = max_color;
        image.data = generate_random_image(width, height, max_color);
        population[i].image = image;
        population[i].fitness = 0;
    }
    return population;
}
