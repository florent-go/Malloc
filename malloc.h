#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

# define HEAP_SHIFT(start) ((void *)start + sizeof(zone_memoire_t))
# define BLOCK_SHIFT(start) ((void *)start + sizeof(bloc_memoire_t))

# define TINY_HEAP_ALLOCATION_SIZE (4 * getpagesize())
# define TINY_BLOCK_SIZE (TINY_HEAP_ALLOCATION_SIZE / 128)
# define SMALL_HEAP_ALLOCATION_SIZE (16 * getpagesize())
# define SMALL_BLOCK_SIZE (SMALL_HEAP_ALLOCATION_SIZE / 128)

typedef enum e_zoneMemoireType
{
    TINY,
    SMALL,
    LARGE,
} t_zoneMemoireType;

typedef struct bloc_memoire
{
    size_t              len;
	struct bloc_memoire	*prev;
	struct bloc_memoire	*next;
	bool			    freed;
} bloc_memoire_t;

typedef struct zone_memoire
{
    struct zone_memoire *next;
    struct zone_memoire *prev;
    size_t              total_len;
    size_t              free_len;
    size_t              block_count;
    t_zoneMemoireType   type;
} zone_memoire_t;