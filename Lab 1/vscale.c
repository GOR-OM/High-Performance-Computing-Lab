#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void dummy(int);

int main() {
    int minSize = pow(2, 3);
    int maxSize = pow(2, 29);
    int total = maxSize;

     double *a, *b, *c;
    clock_t start, end;

    for(int size=minSize; size<=maxSize; size*=2) {
        
        /* init data */
        a = (double*) malloc(size * sizeof(double));
        b = (double*) malloc(size * sizeof(double));
        c = (double*) malloc(size * sizeof(double));
        for(int i=0; i<size; i++) {
            b[i]=3;
            c[i]=2;
        }

        int RUNS = total/size;
        double wallTime = 0;

        start = clock();
        for(int run=0; run<RUNS; run++) {
            /* vector triad */
            for(int ind=0; ind<size; ind++) {
                a[ind] = b[ind] * c[ind];
                if(((double)ind)==333.333)
                    dummy(ind);
            }
        }
        end = clock();
        wallTime = (end - start)/((double)CLOCKS_PER_SEC);
        /* Avg throughput */
        double throughput = ((double)sizeof(double) * total * 2)/wallTime;
        printf("%d, %d, %d, %lf\n", size, RUNS, size*RUNS, throughput);

        /* free data */
        free(a);
        free(b);
        free(c);
        
    }

}

void dummy(int n) {
    n = 10 * sin(n/10);
}
