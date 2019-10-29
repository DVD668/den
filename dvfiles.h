#ifndef DVFILES_H_INCLUDED
#define DVFILES_H_INCLUDED

//loads the file on memory
char* load(char* fname,int* fsize);

//writes char array to file
void writefile(char* filename,char* content, int contentlen);


#endif // DVFILES_H_INCLUDED
