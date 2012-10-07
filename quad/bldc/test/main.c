#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "data_process.h"

void show_bytes(const char* p, int len, const char* desc)
{
    int i;
    if(desc && *desc)printf("%s\n",desc);
    for(i=0;i<len;i++){
        printf("%02X, ", (unsigned char)p[i]);
        if( (i&15) == 15)printf("\n");
    }
    printf("\n");
}

void data_ready(const void* p, uint32_t len)
{
    show_bytes((const char*)p,len,"ready:");
}

int main()
{
    int i;
    {
        char data[] = {0x12,0x32,0x55,0x33,0,2,0,0,0,0x8a};
        show_bytes(data,sizeof(data),"Send:");
        for(i=0;i<sizeof(data);i++){
            process_data((uint8_t)data[i]);
        }
    }
    return 0;
}
