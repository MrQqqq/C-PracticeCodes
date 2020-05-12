// #include <string.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <io.h>
// #include<process.h>
// int main(){
//     int result;

//     int r_num;
//     int pipe_fd[2];
//     char buf_r[100],buf_w[100];
//     //把buf_r所指的内存区域的前sizeof(buf_r)得到的字节置为0，初始化清空的操作
//     memset(buf_r,0,sizeof(buf_r));
//     if(pipe(pipe_fd)<0){
//         printf("创建管道失败\n");
//         return -1;
//     }
//     result = fork();
//     if(result < 0){
//         perror("创建子程序失败");
//         exit(0);
//     }
//     else if(result == 0){
//         close(pipe_fd[0]);
//         if((r_num == read(pipe_fd[0],buf_r,100))>0){
//             printf("子进程从管道读取%d个字符，读取的字符串是:%s\n",r_num,buf_r);
//         }
//         close(pipe_fd[0]);
//         exit(0);
//     }
//     else{
//         close(pipe_fd[0]);
//         printf("请从键盘输入写入管道的字符串\n");
//         scanf("%s",buf_w);
//         if(write(pipe_fd[1],buf_w,strlen(buf_w))!=-1){
//             printf("父进程想管道写入：%s\n",buf_w);
//         }
//         close(pipe_fd[1]);
//         waitpid(result,NULL,0);
//         exit(0);
//     }

//     return 0;
// }


/*这是一个调用fork()函数创建一个子进程,然后分别打印输出子进程和父进程中的变量的实例*/
#include<io.h>
#include<process.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int glob = 6;
int main(int argc,char *argv[])
{
    int var;    //内部变量
    int pid;      //文件标识符
    var = 88;   //内部变量赋值
    printf("创建新进程之前.\n");   //还没有创建子进程
    if((pid=fork())<0)
    {
      perror("创建子进程失败!\n");
    }
    else if(pid==0)
    {
      glob++;
      var++;
    }
    else
    {
      sleep(2); //父进程阻塞两秒
    }
    printf("进程标识符为=%d,glob=%d,var=%d\n",getpid(),glob,var);//分别在子进程中输出两个变量的值
    exit(0);
}