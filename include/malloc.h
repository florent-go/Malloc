#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/resource.h>
#include <sys/mman.h>

# define HEAP_SHIFT(start) ((void *)start + sizeof(page_memory_t))
# define BLOCK_SHIFT(start) ((void *)start + sizeof(block_memory_t))

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

typedef struct block_memory
{
    size_t              len;
	struct block_memory	*prev;
	struct block_memory	*next;
	bool			    freed;
} block_memory_t;

typedef struct page_memory
{
    struct page_memory *next;
    struct page_memory *prev;
    size_t              total_len;
    size_t              free_len;
    size_t              block_count;
    t_zoneMemoireType   type;
} page_memory_t;

extern page_memory_t *g_page_memory;




void setup_block(block_memory_t *block, size_t size);
void *Add_Empty_Block(page_memory_t *heap, size_t size);
void find_available_block(size_t size, page_memory_t **res_heap, block_memory_t **res_block);
static void divide_block(block_memory_t *block, size_t size, page_memory_t *heap);
block_memory_t *try_fill_block(size_t size);
t_zoneMemoireType get_heap_group(size_t size);