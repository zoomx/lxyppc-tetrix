#ifndef RING_BUFFER_H
#define RING_BUFFER_H


#define RING_BUFFER_COUNT       16
#define RING_BUFFER_SIZE        64

typedef struct ring_buffer_t  ring_buffer_t;

void ring_buf_init(ring_buffer_t* buf);
int ring_buf_is_empty(ring_buffer_t* buf);
int ring_buf_is_full(ring_buffer_t* buf);
int ring_buf_push(ring_buffer_t* buf,const void *p ,uint32_t len);
int ring_buf_pop(ring_buffer_t* buf, void* p ,uint32_t len);


#define  DECLRAE_RING_BUFFER(name)  \
    uint32_t  name##_mem[(RING_BUFFER_SIZE/4)*RING_BUFFER_COUNT + 2];\
    ring_buffer_t* name = (ring_buffer_t*)&name##_mem;
    

#include "string.h"
#define mymemcpy    memcpy
    
#endif
