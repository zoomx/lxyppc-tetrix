#ifndef RING_BUFFER_H
#define RING_BUFFER_H

typedef struct ring_buffer_t  ring_buffer_t;
typedef struct ring_buffer_contect_t ring_buffer_contect_t;

void ring_buf_init(const ring_buffer_t* buf);
int ring_buf_is_empty(const ring_buffer_t* buf);
int ring_buf_is_full(const ring_buffer_t* buf);
int ring_buf_push(const ring_buffer_t* buf,const void *p ,uint32_t len);
int ring_buf_pop(const ring_buffer_t* buf, void* p ,uint32_t len);


#define  DECLRAE_RING_BUFFER(name,size,len)  \
    uint32_t  name##_mem[(size/4)*len + 2];\
    const uint32_t   name##_check_param[len & (len-1) ? -1 : 1];\
    const uint32_t name##_const[3] = {len, size, (uint32_t)name##_mem };\
    const ring_buffer_t* name = (const ring_buffer_t*)&name##_const;
    
    
uint32_t ring_buffer_size(const ring_buffer_t* buf);
uint32_t ring_buffer_length(const ring_buffer_t* buf);

#include "string.h"
#define mymemcpy    memcpy
    
#endif
