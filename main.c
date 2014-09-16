#include <stdio.h>
#include <string.h>
#include <ctype.h>
static void trim(char *s){char *p=s;while(isspace((unsigned char)*p))p++;memmove(s,p,strlen(p)+1);
 size_t n=strlen(s);while(n && isspace((unsigned char)s[n-1]))s[--n]=0;}
int main(int argc,char **argv){if(argc>1 && strcmp(argv[1],"--help")==0){puts("Usage: tiny-ini [file|-]");return 0;}FILE *in=stdin;char line[2048],section[128]="";unsigned entries=0;
 if(argc>1 && strcmp(argv[1],"-")!=0){in=fopen(argv[1],"r");if(!in){perror(argv[1]);return 2;}}
 while(fgets(line,sizeof line,in)){trim(line);if(!*line||*line==';'||*line=='#')continue;
 if(line[0]=='['){char *end=strchr(line,']');if(end){*end=0;snprintf(section,sizeof section,"%s",line+1);}continue;}
 char *sep=strchr(line,'=');if(!sep)continue;*sep++=0;trim(line);trim(sep);
 if(!*line)continue;printf("%s.%s=%s\n",*section?section:"default",line,sep);entries++;}
 if(in!=stdin)fclose(in);fprintf(stderr,"%u entries\n",entries);return 0;}
