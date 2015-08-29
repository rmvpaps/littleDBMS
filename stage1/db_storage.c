#include<stdio.h>
#define PGSIZE 10
#define SLOTSIZE 10
#include<stdlib.h>
#include<string.h>

/*

BASIC STORAGE MANAGER - INPUT AND OUTPUT FROM DB FILE AT ANY GIVEN LOCATION

*/


/*Global variables to store 
data about database */

FILE* ddb = NULL;


//open a file defualt.db in read binary mode - create if not exists
int loaddb()
{
	ddb = fopen("default.db","r+b");
}

//check if db exists- to read existing or initialize
int checkdbexists()
{
	return 0;
}


//store data into a given slot in a given page
int storerecord(int pgno, int slotno, char *temp)
{
	int location;
	char buffer[10];

	//identify actual offset of the insert location
	location = pgno*PGSIZE*SLOTSIZE + slotno*SLOTSIZE;
	printf("\n Storerecord: Intended location X--%d",location);

	//move filepointer to location
	fseek(ddb, location, SEEK_SET);

	//to check if fseek worked
	location=-1;
	location = ftell(ddb);
	printf("\n Storerecord: Actual location X--%d",location);

	//copy data from pointer into a buffer
	strcpy(buffer,temp);

	//write contents of buffer to file
	fwrite(buffer,1,10,ddb);

	
}

int readrecord(int pgno, int slotno)
{
	
	int location,ct=0;
	char buffer[10];

	//identify actual offset of the data to retrieve
	location = pgno*PGSIZE*SLOTSIZE + slotno*SLOTSIZE;

	//move filepointer to location
	fseek(ddb, location, SEEK_SET);

	//to check if fseek worked
	location=-1;
	location = ftell(ddb);

	//read from file into buffer
	ct = fread(buffer,1,10,ddb);

	printf("\n Readrecord: Read %d bytes from location X--%d",ct,location);
	printf("\n%.*s",10,buffer);
	
}

void insertcommand()
{
int pgno,sltno;
char buffdata[10];

	printf("\nEnter page number:");
	scanf("%d",&pgno);
	printf("\nEnter slot number:");
	scanf("%d",&sltno);
	printf("\nEnter data:");
	scanf("%s",buffdata);	
	storerecord(pgno,sltno,buffdata);
}

void  retrievecommand()
{
int pgno,sltno;
char buffdata[10];

	printf("\nEnter page number:");
	scanf("%d",&pgno);
	printf("\nEnter slot number:");
	scanf("%d",&sltno);
	printf("\nResult:");
	readrecord(pgno,sltno);
		
}


int main()
{

	int choice=0;

	printf("\nStarting littleDBMS.... Trying to load default DB file - default.db");
	if(!checkdbexists())
	{
		//create defaultdb if not exist
		printf("\ndefault.db not found... Creating default.db");
		loaddb();
	}
	else
	{
		//otherwise load defaultdb and populate global variables - TODO


	}

	//wait for User commands
	do
	{

		printf("\n Command code please - \n1. insert tuple, \n2. retrieve tuple \n0. exit");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1: insertcommand();
			break;
		case 2: retrievecommand();
			break;
		case 0: break;
		default: printf("\n Unsupported commands");
		}
	}while(choice!=0);

	printf("Exiting littleDBMS!");
	fclose(ddb);

	return 0;
}
