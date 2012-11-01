#include "stdint.h"
#include "ring_buffer.h"
#include "string.h"

struct ring_buffer_contect_t
{
    uint32_t rdIdx;
    uint32_t wrIdx;
    uint8_t  buffer[];
};

struct ring_buffer_t
{
    uint32_t    len;        // ring buffer length
    uint32_t    size;       // ring buffer size
    ring_buffer_contect_t*  content;
};


void ring_buf_init(const ring_buffer_t* buf)
{
    buf->content->rdIdx = buf->content->wrIdx = 0;
}

int ring_buf_is_empty(const ring_buffer_t* buf)
{
    return buf->content->rdIdx == buf->content->wrIdx;
}
     
int ring_buf_is_full(const ring_buffer_t* buf)
{
    if(ring_buf_is_empty(buf)){
        return 0;
    }
    if( (buf->content->rdIdx & (buf->len-1)) ==  (buf->content->wrIdx & (buf->len-1))){
        return 1;
    }
    return 0;
}

int ring_buf_push(const ring_buffer_t* buf,const void *p ,uint32_t len)
{
    if(len>buf->size) len = buf->size;
    if(ring_buf_is_full(buf)){
        return 0;
    }
    mymemcpy(&buf->content->buffer[(buf->content->wrIdx & (buf->len-1))*buf->size],p,len);
    buf->content->wrIdx++;
    return 1;
}

int ring_buf_pop(const ring_buffer_t* buf, void* p ,uint32_t len)
{
    if(len>buf->size) len = buf->size;
    if(ring_buf_is_empty(buf)){
        return 0;
    }
    mymemcpy(p, &buf->content->buffer[(buf->content->rdIdx & (buf->len-1))*buf->size],len);
    buf->content->rdIdx++;
    return 1;
}

uint32_t ring_buffer_size(const ring_buffer_t* buf)
{
    return buf->size;
}

uint32_t ring_buffer_length(const ring_buffer_t* buf)
{
    return buf->len;
}

