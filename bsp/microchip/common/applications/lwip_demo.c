/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-01-24     ChungHsuan   improve code comments
 */

#include <rtthread.h>
#include <string.h>

#if !defined(SAL_USING_POSIX)
#error "Please enable SAL_USING_POSIX!"
#else
#include <sys/time.h>
#include <sys/select.h>
#endif
#include <sys/socket.h> /* socket.h header file is needed when using BSD socket */ /* BSD socketsocket.h */
#include "netdb.h"

#define DEBUG_TCP_CLIENT

#define DBG_TAG               "TCP"
#ifdef DEBUG_TCP_CLIENT
#define DBG_LVL               DBG_LOG
#else
#define DBG_LVL               DBG_INFO /* DBG_ERROR */
#endif
#include <rtdbg.h>

#include "lwip_demo.h"

#ifdef SAM_LWIP_EXAMPLE

#define BUFSZ   1024

static int started = 0;
static int is_running = 0;
static char url[256] = "www.baidu.com";
static int port = 8080;
static const char send_data[] = "This is TCP Client from RT-Thread."; /* The message be sent */ /*  */

/**
* @brief  This function is for creating a tcp client on RT-Thread
*/
static void tcpclient(void *arg)
{
    int ret;
    char *recv_data;
    int bytes_received;
    int sock = -1;
    struct hostent *host = RT_NULL;
    struct sockaddr_in server_addr;

    struct timeval timeout;
    fd_set readset;
    /* Get host address by parameter url(Domain name resolution if input domain) */
    /* urlhost */
    host = gethostbyname(url);
    if (host == RT_NULL)
    {
        LOG_E("Get host by name failed!");
        return;
    }
    /* Allocate space for recv_data */
    /*  */
    recv_data = rt_malloc(BUFSZ);
    if (recv_data == RT_NULL)
    {
        LOG_E("No memory");
        return;
    }
    /* Create a socket and set it to SOCK_STREAM(TCP) */
    /* socketSOCKET_STREAMTCP */
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        /* Failed on creatinf socket */
        /* socket */
        LOG_E("Create socket error");
        goto __exit;
    }
    /* Initialize server side address */
    /*  */
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);
    rt_memset(&(server_addr.sin_zero), 0, sizeof(server_addr.sin_zero));
    /* Connect to server */
    /*  */
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1)
    {
        /*Failed on connecting to server*/
        /*  */
        LOG_E("Connect fail!");
        goto __exit;
    }

    started = 1;
    is_running = 1;

    timeout.tv_sec = 3;
    timeout.tv_usec = 0;

    while (is_running)
    {
        FD_ZERO(&readset);
        FD_SET(sock, &readset);

        /* Wait for read */
        if (select(sock + 1, &readset, RT_NULL, RT_NULL, &timeout) == 0)
            continue;
        /* Receive the maximum size 1024 bytes from socket */
        /* sockBUFSZ - 1 */
        bytes_received = recv(sock, recv_data, BUFSZ - 1, 0);
        if (bytes_received < 0)
        {
            /* Receive failed and close the connection */
            /*  */
            LOG_E("Received error, close the socket.");
            goto __exit;
        }
        else if (bytes_received == 0)
        {
            /* Print warning message when recv function return 0 */
            /* recv0 */
            LOG_W("Received warning, recv function return 0.");
            continue;
        }
        else
        {
            /* Receive data sucessfully and append '\0' at the end of message */
            /*  */
            recv_data[bytes_received] = '\0';

            if (rt_strcmp(recv_data, "q") == 0 || rt_strcmp(recv_data, "Q") == 0)
            {
                /* If the first letter is 'q' or 'Q', close the connection */
                /* qQ */
                LOG_I("Got a 'q' or 'Q', close the socket.");
                goto __exit;
            }
            else
            {
                /* Show the message in terminal */
                /*  */
                LOG_D("Received data = %s", recv_data);
            }
        }
        /* Send message to connected socket */
        /* sock */
        ret = send(sock, send_data, rt_strlen(send_data), 0);
        if (ret < 0)
        {
            /* Send failed, close the connection */
            /*  */
            LOG_I("send error, close the socket.");
            goto __exit;
        }
        else if (ret == 0)
        {
            /* Print warning message when send function return 0 */
            /* send0 */
            LOG_W("Send warning, send function return 0.");
        }
    }

__exit:
    if (recv_data)
    {
        rt_free(recv_data);
        recv_data = RT_NULL;
    }
    if (sock >= 0)
    {
        closesocket(sock);
        sock = -1;
    }
    started = 0;
    is_running = 0;
    return;
}

/**
 * @brief    Call this function will run LWIP example code.
 *
 * @note     .
 *
 * @param    None.
 *
 * @return   RT_OK or -RT_ERROR.
 */

rt_err_t lwip_demo_run(void)
{
    rt_thread_t tid;

    tid = rt_thread_create("tcp_client",
                           tcpclient, RT_NULL,
                           2048, RT_THREAD_PRIORITY_MAX/3, 20);
    if (tid != RT_NULL)
    {
        rt_thread_startup(tid);
    }

    return RT_EOK;
}
#endif

/*@}*/
