#include "a4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

PPM_IMAGE *read_ppm(const char *file_name)
{

    FILE *file = fopen(file_name,"r");
    if (!file)
    {
        printf("File does not exist\n");
        return NULL;
    }

    PPM_IMAGE *image;
    image = malloc(sizeof(PPM_IMAGE));

    char type[100];
    fscanf(file,"%s",type);
    if (strcmp(type,"P3") != 0)
    {
        printf("Not a PPM file\n");
        exit(1);
    }
    fscanf(file,"%d %d %d",&image->width,&image->height,&image->max_color);
    printf("Width is: %d, Height is: %d, Max color is: %d\n",image->width,image->height,image->max_color);

    int total_pixels = image->width*image->height;
    image->data = malloc(total_pixels * sizeof(PIXEL));

    char red;
    char green;
    char blue;

    for (int i = 0; i < total_pixels ; i++)
    {
        fscanf(file,"%hhu %hhu %hhu",&red,&green,&blue);
        image->data[i].r = red;
        image->data[i].g = green;
        image->data[i].b = blue;
    }
    fclose(file);
    return image;

}

void write_ppm(const char *file_name, const PPM_IMAGE *image)
{
    FILE *file = fopen(file_name,"w");
    if (!file)
    {
        printf("File could not be created\n");
        exit(1);
    }

    fprintf(file,"P3\n");
    fprintf(file,"%d %d\n%d\n",image->width,image->height,image->max_color);

    int dimension = image->width*image->height;

    for (int i = 0; i < dimension; i++)
    {
        fprintf(file,"%d ",image->data[i].r);
        fprintf(file,"%d ",image->data[i].g);
        fprintf(file,"%d ",image->data[i].b);
        if (i>0 && i%image->width == 0) fprintf(file,"\n");
    }
    fclose(file);
}
