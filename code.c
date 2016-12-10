/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2016年10月11日 星期二 17时41分35秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
int len;
int word_num(char *a) //字符数
{
    char *s = a;
    int n = 0;
    while(s != '\0'){
        printf("%c",*s);
        n++;
        s++;
    }
    return n;
}
int c_line(char *a) //行数
{
    int num = 0;
    int i;
    for(i = 0;i < len;i++){
        if(a[i] == '\n')
           num++;
    }
    return num;
}

int c_e_line(char *a) //空行数
{
    int num = 0;
    int i;
    for(i = 0;i < len;i++){
        if(a[i] == '\n' && a[i+1] == '\n')
           num++;
    }
    return num;
}

int Zhu_shi(char *a) //注释行数
{
    int num = 0;
    int i;
    for(i = 0;i < len;i++){
        if(a[i] == '/' && a[i+1] == '/'){
            num++;
        }
        else if(a[i] == '/' && a[i+1] == '*'){
            for(i;i < len;i++){
                if(a[i] == '\n'){
                    num++;
                }
                else if(a[i] == '*' && a[i+1] == '/'){
                    num++;
                    i++;
                    break;
                }
            }
        }
    }
    return num;
}

int main(int argc,char *argv[])
{
    if(argc != 2){
        printf("use: ./code <file name>");
        exit(0);
    }

    int fd;

    fd = open(argv[1],O_RDONLY);
    lseek(fd,0,SEEK_END);

    len = lseek(fd,0,SEEK_CUR);

    lseek(fd,0,SEEK_SET);



    char *file_list = malloc(sizeof(char) * len + 1);
    memset(file_list,0,sizeof(file_list));
    read(fd,file_list,len);
    printf("字符数:%d<br />",len);//文件大小
    printf("行数:%d<br />",c_line(file_list));
    printf("空行数:%d<br />",c_e_line(file_list));
    printf("注释行数:%d<br />",Zhu_shi(file_list));
    printf("注释率:%.2f\%<br />",Zhu_shi(file_list) * 10.0 / c_line(file_list));
    printf("空行率:%.2f\%<br />",c_e_line(file_list) * 10.0 / c_line(file_list));
    return 0;
}
