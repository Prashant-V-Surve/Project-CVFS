//////////////////////////////////////////////////////////////////////////////
//     
//  File name :     program710.cpp
//  Descreption :   Customized Virtual File System(CVFS).
//  Author :        Prashant V. Surve
//  Date :          11/08/2025
//
//////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#include <iostream>

using namespace std;

int main()
{
    char str[80] = {'\0'};
    int iCount = 0;
    char Command[4][80];
    
    cout<<"-------------------------------------------------------------------------\n";
    cout<<"--------------- OPTIMUS CVFS started Succesfully-----------------------\n";
    cout<<"-------------------------------------------------------------------------\n";

    printf("\nOPTIMUS CVFS > ");
    fgets(str,sizeof(str),stdin);

    iCount = sscanf(str,"%s %s %s %s",Command[0],Command[1],Command[2],Command[3]);

    printf("Number of tokens are : %d\n",iCount);
        
      ///end of while (custom shell)

    return 0;
}  //end of main