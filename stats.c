#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <math.h>
int main(){
    struct stat* garbagefile=malloc(sizeof(struct stat));
    stat("stats.c",garbagefile);   
    char* suffixes[7] = {"bytes","kilobytes","megabytes","gigabytes","terabytes","petabytes","yottabytes"};
    int logp = log(garbagefile->st_size)/log(1024);
    printf("Size of the file is:%.1f %s\n",garbagefile->st_size/pow(1024,logp),suffixes[logp]);
    printf("Permissions mode of the file are %o\n",garbagefile->st_mode&0777);
    printf("Last time of access: %s\n",ctime(&(garbagefile->st_atime))); 
    return 0;
}
