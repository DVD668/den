#include "den_protocol.h"
#include "dvfiles.h"
#include "libdvden.h"

//encrypts the file part by part and writes it
void write_and_encrypt(char* temporary_output_file_name, char* input_file_name,char* key,long int file_size,int key_size){

            //encrypts the file piece by piece
        for( long int counter = 0; counter<file_size ; counter += BLOCK_SIZE){

            //declares the buffer
            char* buffer;

            //the first blocks are encrypted here
            if(counter+BLOCK_SIZE < file_size){

                //allocates memory to the buffer
                buffer = malloc(BLOCK_SIZE);

                //reads part of the file
                buffer = readfilepart(input_file_name, counter, BLOCK_SIZE);

                //encrypts it
                dvdencrypt(buffer,key,BLOCK_SIZE,key_size);

                //writes it to the output file
                appendfile(temporary_output_file_name,buffer,BLOCK_SIZE);

            }else{     //the last block of the file is encrypted here


                //allcates memory to the buffer
                buffer = malloc(file_size%BLOCK_SIZE);

                //reading the last block of data
                buffer = readfilepart(input_file_name,counter,file_size%BLOCK_SIZE);

                //encrypting it
                dvdencrypt(buffer,key,file_size%BLOCK_SIZE,key_size);

                //writing it
                appendfile(temporary_output_file_name,buffer,file_size%BLOCK_SIZE);

            }

            //frees the buffer's memory
            free(buffer);
        }

}


//decrypts the file part by part and writes it
void write_and_decrypt(char* temporary_output_file_name, char* input_file_name,char* key,long int file_size,int key_size){

            //decrypts the file piece by piece
        for( long int counter = 0; counter<file_size ; counter += BLOCK_SIZE){

            //declares the buffer
            char* buffer;

            //the first blocks are decrypted here
            if(counter+BLOCK_SIZE < file_size){

                //allocates memory to the buffer
                buffer = malloc(BLOCK_SIZE);

                //reads part of the file
                buffer = readfilepart(input_file_name, counter, BLOCK_SIZE);

                //decrypts it
                dvddecrypt(buffer,key,BLOCK_SIZE,key_size);

                //writes it to the output file
                appendfile(temporary_output_file_name,buffer,BLOCK_SIZE);

            }else{     //the last block of the file is decrypted here

                //allcates memory to the buffer
                buffer = malloc(file_size%BLOCK_SIZE);

                //reading the last block of data
                buffer = readfilepart(input_file_name,counter,file_size%BLOCK_SIZE);

                //decrypting it
                dvddecrypt(buffer,key,file_size%BLOCK_SIZE,key_size);

                //writing it
                appendfile(temporary_output_file_name,buffer,file_size%BLOCK_SIZE);

            }

            //frees the buffer's memory
            free(buffer);
        }

}
