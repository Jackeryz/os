#include<dirent.h>
#include<stdio.h>
#include<sys/types.h>
int main()
{
DIR *dir_ptr;
struct dirent *read_dir;
dir_ptr=opendir(".");
if(dir_ptr==NULL)
{
perror("cannot open the file\n");
return 1;
}
while((read_dir=readdir(dir_ptr))!=NULL)
if(read_dir->d_type==DT_REG){
printf("FILE:%s\n",read_dir->d_name);
}
else if(read_dir->d_type==DT_DIR)
{
printf("DIR:%s\n",read_dir->d_name);
}
if(closedir(dir_ptr)==-1)
{
perror("cannot close\n");
return 1;
}
return 0;
}
