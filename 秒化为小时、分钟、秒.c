#include<stdio.h>

/* floor(a,b): 向下取整的整数除法（等价于 a / b） */
static unsigned int floor(unsigned int a, unsigned int b) {
    return a / b;
}

int main() {
    unsigned int u_num_time;
    unsigned int u_num_time_sec;
    unsigned int u_num_time_min;
    unsigned int u_num_time_hour;
    unsigned int in_sec;


    printf("请输入秒数:\a");
    scanf_s("%u", &u_num_time);
    if (u_num_time >= 60)
    {
        if (u_num_time < 3600)
        {
            /* 分钟=整除，秒=余数（用 floor 表达） */
            u_num_time_min = floor(u_num_time, 60);
            u_num_time_sec = u_num_time - u_num_time_min * 60;
            printf("time>>00:%u:%u\a", u_num_time_min, u_num_time_sec);
        }
        if (u_num_time >= 3600)
        {
            /* 小时=整除，in_sec 为去掉小时后的剩余秒 */
            u_num_time_hour = floor(u_num_time, 3600);
            if ((in_sec = u_num_time - u_num_time_hour * 3600) < 60)
            {
                printf("time>>%u:00:%u\a", u_num_time_hour, in_sec);
            }
            else
            {
                /* 分钟=整除，秒=余数（用 floor 表达） */
                u_num_time_min = floor(in_sec, 60);
                u_num_time_sec = in_sec - u_num_time_min * 60;
                printf("time>>%u:%u:%u\a", u_num_time_hour, u_num_time_min, u_num_time_sec);
            }

        }

    }
    else
    {
        printf("time>>00:00:%u\a", u_num_time);
    }
    return 0;



}