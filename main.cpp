#include "stdio.h"
#include "unistd.h"
#include "string.h"
#include <stdlib.h>
#include <iostream>

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
    
	char *ig = "/.gitignore";

	strcat(absolutePath,ig);

	int check = access(absolutePath,F_OK);

    if(check == 0){
		system("git add .");
		system("git commit -m 'git'");
		system("git push all");
	}

    return 0;
}