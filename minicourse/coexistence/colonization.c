#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 1e+4       // Size of system
#define TT 1e+9     // Iterations


/*
A = 0   Big
B = 1   Small
*/


int main(int argc, char *argv[]){
    double uniform(double min, double max);
    int **neighbour(int n);

    double RHOA = atof(argv[1]);

    int *sys = (int*)malloc(N*sizeof(int));
   
    char nome[50];
    sprintf(nome, "out_N_%d_rhoa_%.2lf_ga_0.3.dat", (int)N, RHOA);

    FILE *out = fopen(nome, "w");


    int node, nn, numA, numB, dis;
    double ga, gb;

    int **mtx = neighbour(N);

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
                if(sys[mtx[mtx[node][0]][0]] == 1) ga = 1.;
                else ga = .5; //uniform(0.1, .5);                
                if(uniform(0., 1.) < ga) sys[mtx[node][0]] = 0;
            }

            // Left neighbour
            else{
                if(sys[mtx[mtx[node][1]][1]] == 1) ga = 1.;
                else ga = .5; //uniform(0.1, .5);                
                if(uniform(0., 1.) < ga) sys[mtx[node][1]] = 0;
            }
        }

        // Conditions for B
        else{
            dis = (int)uniform(0, N);
            if(sys[mtx[dis][0]] + sys[mtx[dis][1]] + sys[dis] == 0) gb = 1.;
            else if(sys[mtx[dis][0]] + sys[mtx[dis][1]] == 1) gb = .5;//uniform(0.5, 1.);
            else if(sys[mtx[dis][0]] + sys[mtx[dis][1]] == 2) gb = .3;//uniform(.1, .5);
            if(uniform(0., 1.) < gb) sys[dis] = 1;
        }

        if(t%10000000 == 0){
            for(int i = 0; i < N; ++i) fprintf(out, "%d\n", sys[i]);
            fprintf(out, "-1\n");
        }
    }

    fclose(out);
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

int **neighbour(int n){
    int **mtx = (int**)malloc(n*sizeof(int*));    
    for(int i = 0; i < n; ++i){
        mtx[i] = (int*)malloc(2*sizeof(int));
    }

    for(int i = 0; i < n; ++i){
        if(i == n-1){
            mtx[i][0] = 0;
            mtx[i][1] = n-2;
        }
        if(i == 0){
            mtx[i][0] = 1;
            mtx[i][1] = n-1;
        }
        if((i != N-1) && (i != 0)){
            mtx[i][0] = i+1;
            mtx[i][1] = i-1;
        }
    }
    return mtx;
}



