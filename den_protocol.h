#ifndef DEN_PROTOCOL_INCLUDED
#define DEN_PROTOCOL_INCLUDED

//defines the encryption block size
#define BLOCK_SIZE 1048576

//encrypts the file part by part and writes it
void write_and_encrypt(char*,char*,char*,long int,int);

//decrypts the file part by part
void write_and_decrypt(char*,char*,char*,long int, int);

#endif // DEN_PROTOCOL_INCLUDED
