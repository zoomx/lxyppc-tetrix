#include "stdint.h"
#include "ring_buffer.h"
#include "string.h"

#define RING_MASK        (RING_BUFFER_COUNT-1)
typedef uint8_t ring_buf_t[RING_BUFFER_SIZE];
struct ring_buffer_t
{
    uint32_t rdIdx;
    uint32_t wrIdx;
    ring_buf_t  buffers[RING_BUFFER_COUNT];
};


void ring_buf_init(ring_buffer_t* buf)
{
    buf->rdIdx = buf->wrIdx = 0;
}

int ring_buf_is_empty(ring_buffer_t* buf)
{
    return buf->rdIdx == buf->wrIdx;
}
     
int ring_buf_is_full(ring_buffer_t* buf)
{
    if(ring_buf_is_empty(buf)){
        return 0;
    }
    if( (buf->rdIdx & RING_MASK) ==  (buf->wrIdx & RING_MASK)){
        return 1;
    }
    return 0;
}

int ring_buf_push(ring_buffer_t* buf,const void *p ,uint32_t len)
{
    if(len>RING_BUFFER_SIZE) len = RING_BUFFER_SIZE;
    if(ring_buf_is_full(buf)){
        return 0;
    }
    mymemcpy(&buf->buffers[buf->wrIdx & RING_MASK],p,len);
    buf->wrIdx++;
    return 1;
}

int ring_buf_pop(ring_buffer_t* buf, void* p ,uint32_t len)
{
    if(len>RING_BUFFER_SIZE) len = RING_BUFFER_SIZE;
    if(ring_buf_is_empty(buf)){
        return 0;
    }
    mymemcpy(p, &buf->buffers[buf->rdIdx & RING_MASK],len);
    buf->rdIdx++;
    return 1;
}

