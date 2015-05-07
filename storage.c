/*-----*/

//Store data into given slot
int storerecord(int pgno, int slotno, char *temp)
{
	int location;
	char buffer[SLOTSIZE];
	location = (pgno * PGSIZE) * SLOTSIZE + slotno * SLOTSIZE;
	//ddb is the file pointer to database file
	fseek(ddb, location, SEEK_SET);
	strcpy(buffer,temp);
	fwrite(buffer,1,SLOTSIZE,ddb);
}
/*-----*/
