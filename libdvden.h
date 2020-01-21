#ifndef LIBDVDEN_H_INCLUDED
#define LIBDVDEN_H_INCLUDED


//encrypts the string by adding, from the beginning to the end
void da(char* str,char* key,int strl,int keyl);


//encrypts the string by adding, from the end to the beginning
void rda(char* str,char* key,int strl,int keyl);


//complementar to da; decrypts the string by removing, from the end to the beginning
void cda(char* str,char* key,int strl,int keyl);


//complementar to rda; decrypts the string by removing, from the beginning to the end
void crda(char* str,char* key,int strl,int keyl);


//default encryption procedure
void dvdencrypt( char *str, char *key,int strl,int keyl);


//default decryption procedure
void dvddecrypt( char *str, char *key,int strl,int keyl);


#endif // LIBDVDEN_H_INCLUDED
