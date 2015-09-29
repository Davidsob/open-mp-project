// This is a template for an mpi main.cpp file

#include <iostream>
#include <stdio.h>
#include "omp.h"

int main(int argc, char ** argv)
{
printf("Begin hello openmp...\n");
//omp_set_dynamic(0);     // Explicitly disable dynamic teams
//omp_set_num_threads(4); // Use 4 threads for all consecutive parallel regions
#pragma omp parallel
{
    // insert code here
    int pid = omp_get_thread_num();
    int nt = omp_get_num_threads();
    fprintf(stdout,"Hello World: thread %d out of %d\n",pid, nt);
}

printf("Finish hello openmp...\n");

return 0;
}
