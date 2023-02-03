#include <cstdio>
#include "unistd.h"
#include <cstring>

using namespace std;

// 最后回传的绝对路径名称结尾没有'/'
bool getAbsolutePath(char* absolutePath, const char *execName)
{
    if(*(execName) == '/')
    {
        sprintf(absolutePath, "%s", execName);
    }
    else
    {
        char temp[1024];
        getcwd(temp, 4096);
        sprintf(absolutePath, "%s/%s", temp, execName);
    }
    char *ptr = strrchr(absolutePath, '/');
    *ptr = '\0';
    return true;
}



int main(int argc, char *argv[])
{
    char absolutePath[128];
    getAbsolutePath(absolutePath, argv[0]);

    char absolutePath1[128];
    char absolutePath2[128];

    strcpy(absolutePath1,absolutePath);
    strcpy(absolutePath2,absolutePath);

    strcat(absolutePath1,"/.gitignore");
    strcat(absolutePath2,"/.gitignore");

    if(!access(absolutePath1,F_OK) || !access(absolutePath2,F_OK)){
		system("git add .");
		system("git commit -m 'git'");
		system("git push all");
	}

    return 0;
}