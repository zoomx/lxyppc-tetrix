#ifndef RING_BUFFER_H
#define RING_BUFFER_H
#include "stdint.h"
typedef struct ring_buffer_t  ring_buffer_t;

/**
  * @brief  initialize the ring buffer
  * @param  buf: pointer to the ring buffer
  * @retval None
  */
void ring_buf_init(const ring_buffer_t* buf);

/**
  * @brief  Check the ring buffer is empty
  * @param  buf: pointer to the ring buffer
  * @retval 0: the ring buffer is not empty
            otherwise: the ring buffer is empty
  */
int ring_buf_is_empty(const ring_buffer_t* buf);

/**
  * @brief  Check the ring buffer is full
  * @param  buf: pointer to the ring buffer
  * @retval 0: the ring buffer is not full
  *         otherwise: the ring buffer is full
  */
int ring_buf_is_full(const ring_buffer_t* buf);

/**
  * @brief  Push data to the ring buffer
  * @param  buf: pointer to the ring buffer
  * @param  p: pointer to the data
  * @param  len: length of the data
  * @retval 0: ring buffer push fail, ring buffer is full
            otherwise: push success
  */
int ring_buf_push(const ring_buffer_t* buf,const void *p ,uint32_t len);

/**
  * @brief  Pop data from the ring buffer
  * @param  buf: pointer to the ring buffer
  * @param  p: pointer to get the data
  * @param  len: length of the data
  * @retval 0: ring buffer pop fail, ring buffer is empty
            otherwise: pop success
  */
int ring_buf_pop(const ring_buffer_t* buf, void* p ,uint32_t len);

/**
  * @brief  Get the ring buffer size
  * @param  buf: pointer to the ring buffer
  * @retval ring buffer size
  */
uint32_t ring_buffer_size(const ring_buffer_t* buf);

/**
  * @brief  Get the ring buffer length
  * @param  buf: pointer to the ring buffer
  * @retval ring buffer length
  */
uint32_t ring_buffer_length(const ring_buffer_t* buf);

/**
  * @brief  Declare a ring buffer
  * @param  name: name of the ring buffer, can be used with the ring_xx functions
  * @param  size: max size of the ring buffer content
  * @param  len: length of the ring buffer
  */
#define  DECLARE_RING_BUFFER(name,size,len)  \
    uint32_t  name##_mem[( (size+3)/4)*len + 2];\
    const uint32_t   name##_check_param[len & (len-1) ? -1 : (len > 0 ? 1 : -1)];\
    const uint32_t name##_const[3] = {len, size, (uint32_t)name##_mem };\
    const ring_buffer_t* name = (const ring_buffer_t*)&name##_const;


#endif
