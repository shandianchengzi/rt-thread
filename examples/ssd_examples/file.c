/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-03-08     obito0       first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>

/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date             Author      Notes
 *
 */
#include <rtthread.h>
#include <dfs_file.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/statfs.h>
#if RT_VER_NUM >= 0x40100
#include <fcntl.h>
#else
#include <dfs_posix.h>
#endif /*RT_VER_NUM >= 0x40100*/

void readwrite_sample(void)
{
    int fd, size;
    char s[] = "RT-Thread Programmer!", buffer[80];

    rt_kprintf("Write string %s to test.txt.\n", s);

    /* 以创建和读写模式打开 /text.txt 文件，如果该文件不存在则创建该文件*/
    fd = open("/text.txt", O_WRONLY | O_CREAT);
    if (fd >= 0)
    {
        write(fd, s, sizeof(s));
        close(fd);
        rt_kprintf("Write done.\n");
    }

    /* 以只读模式打开 /text.txt 文件 */
    fd = open("/text.txt", O_RDONLY);
    if (fd >= 0)
    {
        size = read(fd, buffer, sizeof(buffer));
        close(fd);
        rt_kprintf("Read from file test.txt : %s \n", buffer);
        if (size < 0)
            return ;
    }
}



void list_dir(const char* path)
{
    char * fullpath = RT_NULL;
    DIR *dir;

    dir = opendir(path);
    if (dir != RT_NULL)
    {
        struct dirent* dirent;
        struct stat s;

        fullpath = rt_malloc(256);
        if (fullpath == RT_NULL)
        {
            closedir(dir);
            rt_kprintf("no memory\n");
            return;
        }

        do
        {
            dirent = readdir(dir);
            if (dirent == RT_NULL) break;
            rt_memset(&s, 0, sizeof(struct stat));

            /* build full path for each file */
            rt_sprintf(fullpath, "%s/%s", path, dirent->d_name);

            stat(fullpath, &s);
            if ( s.st_mode & S_IFDIR )
            {
                rt_kprintf("%s\t\t<DIR>\n", dirent->d_name);
            }
            else
            {
                rt_kprintf("%s\t\t%lu\n", dirent->d_name, s.st_size);
            }
        } while (dirent != RT_NULL);

        closedir(dir);
    }
    else
    {
        rt_kprintf("open %s directory failed\n", path);
    }

    if (RT_NULL != fullpath)
    {
        rt_free(fullpath);
    }
}

#ifdef RT_USING_FINSH
#include <finsh.h>
FINSH_FUNCTION_EXPORT(list_dir, list directory);

static void cmd_list_dir(int argc, char *argv[])
{
    char* filename;

    if(argc == 2)
    {
        filename = argv[1];
    }
    else
    {
        rt_kprintf("Usage: list_dir [file_path]\n");
        return;
    }
    list_dir(filename);
}
#endif /* RT_USING_FINSH */

int main(void)
{
		// char dirname[100];
		// scanf("%s", dirname);
    while(1){
			readwrite_sample();
			// list_dir(dirname);
		}
}
