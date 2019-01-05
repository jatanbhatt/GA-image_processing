#include "a4.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double comp_distance(const PIXEL *A, const PIXEL *B, int image_size)
{
    long double distance = 0;
    for (int i = 0; i < image_size; i++)
    {
        distance += (A[i].r - B[i].r)*(A[i].r - B[i].r) + (A[i].b - B[i].b)*(A[i].b - B[i].b) + (A[i].g - B[i].g)*(A[i].g - B[i].g);
    }
    return sqrt(distance);
}

void comp_fitness_population(const PIXEL *image, Individual *individual, int population_size)
{
    for (int i = 0; i < population_size; i++)
    {
        int total_pixels = individual[i].image.width*individual[i].image.height;
        individual[i].fitness = comp_distance(image,individual[i].image.data,total_pixels);
    }
}
