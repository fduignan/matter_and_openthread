#include <stdint.h>
#include <zephyr/logging/log.h>
#include <zephyr/kernel.h>
#include <errno.h>
#include <stdio.h>
#include <zephyr/net/socket.h>
#include <zephyr/drivers/gpio.h>
#include "matrix.h"

int initIO()
{
    int ret=0;
    ret=matrix_begin();
    return ret;
}
void udp_send_receive(uint8_t *buffer, uint32_t len)
{
    // print the message out for debugging purposes
    if (len)
    {
        int index=0;
        while(index < len)
        {
            printk("%x ",buffer[index]);
            index++;
        }
    }
    matrix_put_pattern(buffer[0],buffer[1]);
    buffer[2]='a';
    buffer[3]='b';
}
