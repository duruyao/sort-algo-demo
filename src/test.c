/**
 * @file test.c 
 * test sort algorithm.
 *
 * @author  duruyao
 * @version 1.0  19-12-19
 * @update  [id] [yy-mm-dd] [author] [description] 
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>

#include "sort_algo.h"

#define ELEM_NUM    (256 * 256)
#define SAMPLE_NUM  (ELEM_NUM <= 128 ? ELEM_NUM : 128)
#define COLM_NUM    8
#define SEED        996U
#define NO_SHOW     0
#define SHOW_IT     1

#define GAP_NUM     ((ELEM_NUM) / (SAMPLE_NUM))

#define FORMAT_STR  "algorithm   : %s sort\n"           \
                    "size of set : %" PRIu64            \
                    " = %.3f K = %.3f M\n"              \
                    "time of sort: [ %lf S ]\n"         \
                    "have checked: %s\n"

void rand_arr(double *, double **, double, double, unsigned);

void print_info(double **, char *, double, int, int);

int check_ok(double **);

int main(int argc, char **argv) {
    clock_t begin;
    clock_t end;
    double  cost_time;
    
    double  min = 256.0;
    double  max = 65536.0;
    double  val[ELEM_NUM];
    double *ptr[ELEM_NUM];


    rand_arr(val, ptr, min, max, SEED);
    begin = clock();
    insert_sort_p((void **)ptr, ELEM_NUM, &cmp_dbl);
    end = clock();
    cost_time = (double)(end - begin) / CLOCKS_PER_SEC;
    print_info(ptr, "insert", cost_time, check_ok(ptr), NO_SHOW);
    
    
    rand_arr(val, ptr, min, max, SEED);
    begin = clock();
    select_sort_p((void **)ptr, ELEM_NUM, &cmp_dbl);
    end = clock();
    cost_time = (double)(end - begin) / CLOCKS_PER_SEC;
    print_info(ptr, "select", cost_time, check_ok(ptr), NO_SHOW);
    
    
    rand_arr(val, ptr, min, max, SEED);
    begin = clock();
    bubble_sort_p((void **)ptr, ELEM_NUM, &cmp_dbl);
    end = clock();
    cost_time = (double)(end - begin) / CLOCKS_PER_SEC;
    print_info(ptr, "bubble", cost_time, check_ok(ptr), NO_SHOW);
    
    
    rand_arr(val, ptr, min, max, SEED);
    begin = clock();
    heap_sort_p((void **)ptr, ELEM_NUM, &cmp_dbl);
    end = clock();
    cost_time = (double)(end - begin) / CLOCKS_PER_SEC;
    print_info(ptr, "heap", cost_time, check_ok(ptr), NO_SHOW);
    
    
    rand_arr(val, ptr, min, max, SEED);
    begin = clock();
    quick_sort_p((void **)ptr, 0, ELEM_NUM, &cmp_dbl);
    end = clock();
    cost_time = (double)(end - begin) / CLOCKS_PER_SEC;
    print_info(ptr, "quick", cost_time, check_ok(ptr), NO_SHOW);
    
    
    rand_arr(val, ptr, min, max, SEED);
    begin = clock();
    bucket_sort_p((void **)ptr, ELEM_NUM, &nb_bkts_p, &hash_idx_p, &cmp_dbl);
    end = clock();
    cost_time = (double)(end - begin) / CLOCKS_PER_SEC;
    print_info(ptr, "bucket", cost_time, check_ok(ptr), NO_SHOW);


    rand_arr(val, ptr, min, max, SEED);
    begin = clock();
    merge_sort_p((void **)ptr, ELEM_NUM, &cmp_dbl);
    end = clock();
    cost_time = (double)(end - begin) / CLOCKS_PER_SEC;
    print_info(ptr, "merge", cost_time, check_ok(ptr), NO_SHOW);
    
    
    rand_arr(val, ptr, min, max, SEED);
    begin = clock();
    shell_sort_p((void **)ptr, ELEM_NUM, &cmp_dbl);
    end = clock();
    cost_time = (double)(end - begin) / CLOCKS_PER_SEC;
    print_info(ptr, "shell", cost_time, check_ok(ptr), NO_SHOW);
    
    
    return 0;
}

void rand_arr(double *val, double **ptr, 
              double min, double max, unsigned seed) {
    seed = (seed == 0 ? (unsigned)time(NULL) : seed); 
    srand(seed);
    
    /* initialize val[] randomly, ptr[] point to val[] */
    for (int i = 0; i < ELEM_NUM; i++) {
        ptr[i] = &val[i];
        val[i] = RAND_DBL(min, max);
    }
}

int check_ok(double **ptr) {
    for (int i = 0; i < ELEM_NUM - GAP_NUM; i += GAP_NUM)
        if (*(ptr[i]) > *(ptr[i + GAP_NUM])) return 0;
    return 1;
}

void print_info(double **ptr, char *algo_name,
                double cost_time, int pass, int show) {
    printf(FORMAT_STR, algo_name,
           (uint64_t)ELEM_NUM, (float)ELEM_NUM / 1024, 
           (float)ELEM_NUM / (1024 * 1024), cost_time, 
           pass == 1 ? "pass" : "no pass");
    if (show == 1) {
        for (int i = 0, j = 0; i < ELEM_NUM; j++) {
            printf("%10.3lf ", *(ptr[i]));
            if (((j + 1) % COLM_NUM == 0) || j == ELEM_NUM - 1) 
                printf("\n"); 
            i += GAP_NUM;
        }
    }
    printf("------------------------------------------------\n");
}

