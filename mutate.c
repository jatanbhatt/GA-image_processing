#include "a4.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mutate(Individual *individual, double rate)
{
    int total_pixels = individual->image.width * individual->image.height;
    int num_random = (rate / 100) * total_pixels;
    int r_index;

    for (int i = 0; i < num_random; i++)
    {
        r_index = rand()%(total_pixels+1);

        individual->image.data[r_index].r = rand()%256;
        individual->image.data[r_index].g = rand()%256;
        individual->image.data[r_index].b = rand()%256;
    }
}

void mutate_population(Individual *individual, int population_size, double rate)
{
    Individual *curr = individual + population_size/4;

    for (int i = population_size/4; i < population_size; i++)
    {
        mutate(curr, rate);
        curr++;
    }
}
