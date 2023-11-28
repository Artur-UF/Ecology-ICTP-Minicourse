#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 50       // Size of system
#define RHOA .5          // Proportion of A
#define TT 1000       // Iterations
#define GB .7        // Germination rate


/*
A = 0   Big
B = 1   Small
*/


int main(){
    double uniform(double min, double max);
    int *sys = (int*)malloc(N*sizeof(int));
    
    FILE *out = fopen("out.dat", "w");

    int node, nn;
    double gb = GB;

    // Inicial condition
    for(int i = 0; i < N; ++i){
        sys[i] = (uniform(0., 1.) < RHOA) ? 0 : 1 ;
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
        for(int i = 0; i < N; ++i) fprintf(out, "%d\n", sys[i]);
        fprintf(out, "-1\n");
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
