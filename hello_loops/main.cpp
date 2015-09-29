// This is a template for an mpi main.cpp file

#include <iostream>
#include <stdio.h>
#include <cmath>
#include "omp.h"
#include <chrono>
using namespace std;

size_t gIdx(size_t i, size_t j, size_t N)
{
  return i * N + j;
}

void makeMatrix(const int size)
{
  double * sinTable = new double[(size+1)*(size+1)];
  for(size_t n=0; n<=size; n++)
    for(size_t m=0; m <= size; m++)
      sinTable[gIdx(n,m,size)] = std::sin(2 * M_PI * n / size + m*M_PI/size/2);
  
  
  if(size < 16)
  {
    for(size_t i = 0; i <= size; i++)
    {
      printf("[");
      for(size_t j = 0; j< size; j++)
      {
        printf("%1.2f \t", sinTable[gIdx(i,j,size)]);
      }
      printf("%1.2f]\n",sinTable[gIdx(i,size,size)]);
    }
  }
  
  delete [] sinTable;
}

void makeMatrixPar(const int size)
{
  double * sinTable = new double[(size+1)*(size+1)];
#pragma omp parallel for
  for(size_t n=0; n<=size; n++)
#pragma omp parallel for
    for(size_t m=0; m <= size; m++)
      sinTable[gIdx(n,m,size)] = std::sin(2 * M_PI * n / size + m*M_PI/size/2);
  
  
  if(size < 16)
  {
    for(size_t i = 0; i <= size; i++)
    {
      printf("[");
      for(size_t j = 0; j< size; j++)
      {
        printf("%1.2f \t", sinTable[gIdx(i,j,size)]);
      }
      printf("%1.2f]\n",sinTable[gIdx(i,size,size)]);
    }
  }
  
  delete [] sinTable;

}

int main(int argc, char ** argv)
{
  printf("Begin hello openmp...\n");
  //omp_set_dynamic(0);     // Explicitly disable dynamic teams
  //omp_set_num_threads(4); // Use 4 threads for all consecutive parallel regions
  //#pragma omp parallel
  //  {
  //    // insert code here
  //    int pid = omp_get_thread_num();
  //    int nt = omp_get_num_threads();
  //    fprintf(stdout,"Hello World: thread %d out of %d\n",pid, nt);
  //  }
  
  int size = 8;
  if(argc == 2) size = atoi(argv[1]);
  
  printf("Size of matrix: [%d, %d]\n", size, size);
  printf("Serial Construction:\n");
  auto start_time = chrono::high_resolution_clock::now();
  makeMatrix(size);
  auto end_time = chrono::high_resolution_clock::now();
  printf("Serial Construction Time: %lld[us]\n",chrono::duration_cast<chrono::microseconds>(end_time - start_time).count());
  
  
  printf("\n\nParallel Construction:\n");
  auto start_time_par = chrono::high_resolution_clock::now();
  makeMatrixPar(size);
  auto end_time_par = chrono::high_resolution_clock::now();
  printf("Parallel Construction Time: %lld[us]\n\n\n",chrono::duration_cast<chrono::microseconds>(end_time_par - start_time_par).count());

  return 0;
}
