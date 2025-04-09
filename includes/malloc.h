#ifndef MALLOC_H
#define MALLOC_H

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <execinfo.h> 
#include <sys/resource.h>
#include <sys/mman.h>

# define TINY_HEAP_ALLOCATION_SIZE (4 * sysconf(_SC_PAGESIZE))
# define TINY_BLOCK_SIZE (TINY_HEAP_ALLOCATION_SIZE / 128)
# define SMALL_HEAP_ALLOCATION_SIZE (16 * sysconf(_SC_PAGESIZE))
# define SMALL_BLOCK_SIZE (SMALL_HEAP_ALLOCATION_SIZE / 128)

typedef enum s_pagetype
{
    TINY,
    SMALL,
    LARGE,
} t_pagetype;

typedef struct s_page
{
    struct s_page       *next;
    struct s_page       *prev;
    size_t              size;
    size_t              aligned_size;
    bool                is_free;
    bool                empty;
} t_page;

typedef struct s_data
{
    void    *ptr_tiny;
    void    *ptr_small;
    void    *ptr_large;
    size_t  total_size_tiny;
    size_t  total_size_small;
} t_data;

extern          t_data *g_data; 

void            *malloc(size_t size);
void            *start_malloc(size_t size);
static bool     init_struct();

void            *alloc_large_memory(const size_t size);

void            *small_alloc_memory(size_t size, t_pagetype type);
static void     *small_alloc_memory2(size_t size, t_pagetype type, void *ptr);
static bool	    alloc_new_slot(void *ptr, t_pagetype type);
static bool     init(t_pagetype type);

t_pagetype      get_type(size_t size);
void            fill_struct_alloc(t_page *heap, t_page *prev, size_t size);

void		    show_alloc_mem(void);

void            *ft_memcpy(void *dst, const void *src, size_t n);
void            *ft_memset(void *b, int c, size_t len);
void            ft_putstr(char const *s);
void            ft_bzero(void *s, size_t n);
void            ft_itoa_base(size_t nb, char base, char lenght, bool prefixe);

#endif