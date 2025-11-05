//////////////////////////////////////////////////////////////////////////////
//     
//  File name :     program706.cpp
//  Descreption :   Customized Virtual File System(CVFS).
//  Author :        Prashant V. Surve
//  Date :          10/08/2025
//
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////
//
//  Header files inclusion
//
///////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
//#include <cstring>

#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////////////////////
//
//   User Defined Macros 
//
///////////////////////////////////////////////////////////////////////////////////

# define MAXFILESIZE 100

# define MAXINODE 5

# define READ 1
# define WRITE 2
# define EXECUTE 4

# define REGULARFILE 1
# define SPECIALFILE 2

# define START 0
# define CURRENT 1
# define END 2

///////////////////////////////////////////////////////////////////////////////////
//
//   Structure Name :   BootBlock
//   Description :     Holds information to boot Operating System.    
//
///////////////////////////////////////////////////////////////////////////////////

struct BootBlock
{
    char Information[100];

};

///////////////////////////////////////////////////////////////////////////////////
//
//   Structure Name :   SuperBlock
//   Description :     Holds information about the file systems.    
//
///////////////////////////////////////////////////////////////////////////////////

struct SuperBlock
{
    int TotalInodes;
    int FreeInodes;
};

///////////////////////////////////////////////////////////////////////////////////
//
//   Structure Name :   Inode
//   Description :     Holds information about the file.    
//
///////////////////////////////////////////////////////////////////////////////////

typedef struct Inode
{
    char FileName[50];
    int InodeNumber;
    int FileSize;
    int ActualFileSize;
    int FileTypes;
    int ReferanceCount;
    int Permission;
    int LinkCount;
    char *Buffer;

    struct Inode *next;
}INODE, *PINODE,**PPINODE;

///////////////////////////////////////////////////////////////////////////////////
//
//   Structure Name :   FileTable
//   Description :     Holds information about the opened file.    
//
///////////////////////////////////////////////////////////////////////////////////

typedef struct FileTable
{
    int ReadOffset;
    int WriteOffset;
    int Count;
    int Mode;
    PINODE ptrinode;
}FILETABLE,*PFILETABLE;

///////////////////////////////////////////////////////////////////////////////////
//
//   Structure Name:   UAREA
//   Description :     Holds information about the process.    
//
///////////////////////////////////////////////////////////////////////////////////

struct UAREA
{
    char ProcessName[50];
    PFILETABLE UFDT[MAXINODE];
};

///////////////////////////////////////////////////////////////////////////////////
//
//   Global variables or objects used in the project. 
//
///////////////////////////////////////////////////////////////////////////////////

BootBlock bootobj;
SuperBlock superobj;
PINODE head = NULL;
UAREA uareaobj;

///////////////////////////////////////////////////////////////////////////////////
//
//   Function Name :    Initialise SuperBlock
//   Description :      It is used initialize the contents of Super block.
//   Author ;           Prashant Vilas Surve
//   Date:              10/8/2025
//
///////////////////////////////////////////////////////////////////////////////////

void InitialiseSuperBlock()
{
    superobj.TotalInodes = MAXINODE;
    superobj.FreeInodes = MAXINODE;

    cout<<"Marvellous CVFS : Superblock initialised Successfully.\n";
}

///////////////////////////////////////////////////////////////////////////////////
//
//   Function Name :    CreateDILB
//   Description :      It is used create linkedlist of Inodes.
//   Author ;           Prashant Vilas Surve
//   Date:              10/8/2025
//
///////////////////////////////////////////////////////////////////////////////////

void CreateDILB()
{    
    int i = 1;
    PINODE newn = NULL;
    PINODE temp = head;

    while( i <= MAXINODE)
    {
        newn = new INODE;
        newn->InodeNumber = 0;
        newn->FileSize = 0;
        newn->ActualFileSize = 0;
        newn->LinkCount = 0;
        newn->Permission = 0;
        newn->Buffer = NULL;
        newn->next = NULL;

        if (temp == NULL)
        {
            head = newn;
            temp = head;
        }
        else
        {
            temp->next = newn;
            temp = temp->next;
        }

        i++;
    }

    cout<<"Marvellous CVFS : DILB created Successfully.\n";
}

///////////////////////////////////////////////////////////////////////////////////
//
//   Function Name :    StartAuxilaryDataInitialisation
//   Description :      It is used initialize the Auxilary data.
//   Author ;           Prashant Vilas Surve
//   Date:              10/8/2025
//
///////////////////////////////////////////////////////////////////////////////////

void StartAuxilaryDataInitialisation ()
{
    strcpy(bootobj.Information,"Boot process of Operating System Done");

    cout<<bootobj.Information<<"\n";

    InitialiseSuperBlock();

    CreateDILB();

    cout<<"Marvellous CVFS : Auxilary data initialised succesfully\n";
}



/////////////////////////////////////////////////////////////
//
//   Entry point function of project (main)
//
//////////////////////////////////////////////////////////////

int main()
{
    StartAuxilaryDataInitialisation();

    return 0;
}