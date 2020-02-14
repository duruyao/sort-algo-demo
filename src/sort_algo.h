/**
 * @file sort_algo.h 
 * head file contains of declaration of sort algorithm.
 *
 * @author  duruyao
 * @version 1.0  19-12-19
 * @update  [id] [yy-mm-dd] [author] [description] 
 */

#ifndef __SORTALGOH__
#define __SORTALGOH__

#ifdef  __cplusplus
extern "C" {
#endif /* __plusplus */

/* 
 * cdecl (which stands for C declaration) is a calling convention that
 * originates from the C programming language and is used by many C 
 * compilers for the x86 architecture.
 *
 * syntax of using cdecl is '__cdecl' in Microsoft Visual C/C++, and it 
 * is '__attribute__((__cdecl__))' in Linuxu GCC.
 */

#ifdef  __GNUC__
#define __cdecl __attribute__((__cdecl__))
#endif


/*****************************************************************************/
/*                                                                           */
/* macro defination                                                          */
/*                                                                           */
/*****************************************************************************/


/*
 * swap two variable of same type.
 *
 * if params contain of '++' or '--', macro produce error:
 * e.g. SWAP(p1++, p2--)
 */

#define SWAP(p1, p2) ({                                 \
    if ((p1) != (p2)) {                                 \
        (p1) ^= (p2);                                   \
        (p2) ^= (p1);                                   \
        (p1) ^= (p2);                                   \
    }                                                   \
})

/*
 * swap two variables of pointer type with using XRO.
 *
 * if params contain of '++' or '--', macro produce error:
 * e.g. SWAP_PTR(ptr1++, ptr2--)
 */

#define SWAP_PTR(ptr1, ptr2) ({                         \
    if (ptr1 != ptr2) {                                 \
        unsigned long p1_ = (unsigned long)(ptr1);      \
        unsigned long p2_ = (unsigned long)(ptr2);      \
        p1_ ^= p2_;                                     \
        p2_ ^= p1_;                                     \
        p1_ ^= p2_;                                     \
        (ptr1) = (typeof(ptr1))p1_;                     \
        (ptr2) = (typeof(ptr2))p2_;                     \
    }                                                   \
})

/*
 * swap two variables of pointer type without using XOR.
 *
 * if params contain of '++' or '--', macro produce error:
 * e.g. SWAP_PTR_ERR(ptr1++, ptr2--)
 *
 * ERROR MACRO
 */

#define SWAP_PTR_ERR(p1, p2) ({                         \
    (p1) = (p1) + (unsigned long)(p2);                  \
    (p2) = (void *)((p1) - (p2));                       \
    (p1) = (void *)((p1) - (p2));                       \
})

/*
 * swap s byte memory pointed by pointer p1 and p2.
 *
 * pt is a temporary pointer point to a allocted s byte memory, which 
 * requires manual release by calling free().
 *
 * if params contain of '++' or '--', macro produce error:
 * e.g. SWAP_MEM(ptr1++, ptr2--, ptrt++, s--)
 */

#define SWAP_MEM(p1, p2, pt, s) ({                      \
    memmove(pt, p1, s);                                 \
    memmove(p1, p2, s);                                 \
    memmove(p2, pt, s);                                 \
})

/*
 * find medium value from 3 variables of the same type.
 */

#define MEDIUM(p1, p2, p3) ({                           \
    typeof(p1) p1_ = (p1);                              \
    typeof(p2) p2_ = (p2);                              \
    typeof(p3) p3_ = (p3);                              \
    (void)((&p1_ == &p2_) || (&p2_ == &p3_));           \
    (p1_ - p2_) * (p1_ - p3_) <= 0 ? p1_ :              \
    ((p2_ - p1_) * (p2_ - p3_) > 0 ? p3_ : p2_);        \
})

/*
 * generate double floating point data which scope is [min, max]
 *
 *
 * if params contain of '++' or '--', macro produce error:
 * e.g. RAND_DBL(p1++, p2--)
 */

#define RAND_DBL(min, max) (                            \
    (max - min) * ((double)rand() / RAND_MAX) + (min)   \
)

/*
 * push new element to heap.
 */

#define heap_push_p                                     \
    heap_insert_p

/*
 * pop top of heap.
 */

#define heap_pop_p                                      \
    heap_del_p


/*****************************************************************************/
/*                                                                           */
/* struct defination                                                         */
/*                                                                           */
/*****************************************************************************/


struct entry;
typedef struct entry Entry;

struct bucket;
typedef struct bucket Bucket;


/*****************************************************************************/
/*                                                                           */
/* function declaration                                                      */
/*                                                                           */
/*****************************************************************************/


/*****************************************************************************/
/* compare func                                                              */
/*****************************************************************************/

extern int  cmp_uint8       (const void *, const void *);

extern int  cmp_dbl         (const void *, const void *);

extern int  cmp_dbl_rev     (const void *, const void *);

/*****************************************************************************/
/* insert sort                                                               */
/*****************************************************************************/

extern void insert_sort     (void *,  int, size_t, 
                                      int(*)(const void *, const void *));

extern void insert_sort_p   (void **, int,
                                      int(*)(const void *, const void *));

/*****************************************************************************/
/* select sort                                                               */
/*****************************************************************************/

extern void select_sort     (void *,  int, size_t, 
                                      int(*)(const void *, const void *));

extern void select_sort_p   (void **, int, 
                                      int(*)(const void *, const void *));

/*****************************************************************************/
/* heap sort                                                                 */
/*****************************************************************************/

extern void heapify_p       (void **, int, int,
                                      int(*)(const void *, const void *));

extern void heap_build_p    (void **, int,
                                      int(*)(const void *, const void *));

extern void *heap_top_p     (void **);

extern void heap_insert_p   (void **, void *, int, int,
                                      int(*)(const void *, const void *));

extern void heap_repl_p     (void **, void *, int,
                                      int(*)(const void *, const void *));

extern void *heap_del_p     (void **, int,
                                      int(*)(const void *, const void *));

extern void heap_sort_p     (void **, int,
                                      int(*)(const void *, const void *));

extern void *heap_top_k_p   (void **, int, int,
                                      int(*)(const void *, const void *));

/*****************************************************************************/
/* quick sort                                                                */
/*****************************************************************************/

extern int  three_med_val_p (void **, int, int,
                                      int(*)(const void *, const void *));

extern void quick_sort_p    (void **, int, int,
                                      int(*)(const void *, const void *));

/*****************************************************************************/
/* bucket sort                                                               */
/*****************************************************************************/

extern int  num_bucket_p    (int);

extern int  hash_idx_p      (void *, int);

extern void ext_bucket_p    (void **, Bucket *, int, int,
                                      int(*)(const void *, const void *));

extern void bucket_sort_p   (void **, int, int(*)(int), 
                                      int(*)(void *, int),
                                      int(*)(const void *, const void *));

/*****************************************************************************/
/* merge sort                                                                */
/*****************************************************************************/

extern void m_sort_p        (void **, void **, int, int,
                                      int(*)(const void *, const void *));

extern void merge_sort_p    (void **, int,
                                      int(*)(const void *, const void *));

/*****************************************************************************/
/* shell sort                                                                */
/*****************************************************************************/

extern int  gen_gap_p       (int **gap, int n);

extern void shell_sort_p    (void **, int,
                                      int(*)(const void *, const void *));

/*****************************************************************************/
/* bubble sort                                                               */
/*****************************************************************************/

extern void bubble_sort_p   (void **, int,
                                      int(*)(const void *, const void *));

/*****************************************************************************/
/* BFPRT                                                                     */
/*****************************************************************************/

extern int  BFPRT_p_idx_p   (void **, int, int,
                                      int(*)(const void *, const void *));

extern int  partition_p     (void **, int, int, int,
                                      int(*)(const void *, const void *));

extern int  BFPRT_k_idx_p   (void **, int, int, int,
                                      int(*)(const void *, const void *));

#ifdef __cplusplus
}
#endif /* __plusplus */

#endif /* !__SORTALGOH__ */

