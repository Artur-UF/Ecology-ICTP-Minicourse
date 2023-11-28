#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 50       // Size of system
#define TT 5000       // Iterations
#define NSIM 1000       // # of sims

/*
A = 0   Big
B = 1   Small
*/


int main(int argc, char *argv[]){
    double uniform(double min, double max);

    // Setting parameters
    double rhoa = atof(argv[1]);
    double gb = atof(argv[2]);

    // Creating system array
    int *sys = (int*)malloc(N*sizeof(int));

    // Creating output file
    char name[50];
    sprintf(name, "avg_rhoa_%.2lf_gb_%.2lf.dat", rhoa, gb);
    
    FILE *out = fopen(name, "w");

    // Creating array for the averages
    double *avgnumB = (double*)calloc(TT, sizeof(double));

    // Simulation
    int node, nn, numB;

    for(int sim = 0; sim < NSIM; ++sim){
        // Inicial condition
        for(int i = 0; i < N; ++i){
            sys[i] = (uniform(0., 1.) < rhoa) ? 0 : 1 ;
        }
    
        // Dynamics
        for(int t = 0; t < TT; ++t){
    
            // Random node
            node = (int) uniform(0, N);
    
            // Conditions for A
            if(!sys[node]){
                nn = (int)uniform(0., 2.);
                
                // Right neighbour
                if(nn){
                    if(node+1 == N) sys[0] = 0;
                    else sys[node+1] = 0;
                }
    
                // Left neighbour
                else{
                    if(node-1 < 0) sys[N-1] = 0;
                    else sys[node-1] = 0;
                }
            }
    
            // Conditions for B
            else{
                if(uniform(0., 1.) < gb) sys[(int)uniform(0, N)] = 1;
            }

            for(int i = 0; i < N; ++i) numB += sys[1];
            avgnumB[t] += numB;
            numB = 0;
        }
    }

    // Saving averages
    for(int i = 0; i < TT; ++i){
        avgnumB[i] /= NSIM;
        fprintf(out, "%lf\n", avgnumB[i]);
    }
    return 0;
}

double uniform(double min, double max) {
    /*
    Function that generates a random number with a uniform distribution
    For int: [min, max)
    */
    double random  = ((double) rand()) / RAND_MAX;
    double range = (max - min) * random;
    double n = range + min;	
    
    return n;
}
