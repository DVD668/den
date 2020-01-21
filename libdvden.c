#include "libdvden.h"


//encrypts the string by adding, from the beginning to the end
void da(char* str, char* key, int strl,int keyl){

    //encrypts starting from the beginning
    for( int counter = 0; counter < strl-1; counter++){

        //sets the new bit value
        str[counter] = str[counter] + str[counter+1] + key[counter%keyl];

    }

    //the last caracter is encrypted after, to avoid sigmentation faults
    str[strl-1] = str[strl-1] + key[(strl-1)%keyl];
}


//encrypts the string by adding, from the end to the beginning
void rda(char* str, char* key, int strl,int keyl){

    //encrypts starting from the end
    for( int counter = strl-1 ; counter>0; counter--){

        //sets the bit value
        str[counter] = str[counter] + str[counter-1] + key[(strl-counter-1)%keyl];

    }

    //the last caracter is encrypted after, to avoid sigmentation faults
    str[0] = str[0] + key[(strl-1)%keyl];
}


//complementar to da(); decrypts the string by removing, from the end to the beginning
void cda(char* str, char* key, int strl,int keyl){

    //the last caracter is decrypted before, to avoid sigmentation faults
    str[strl-1] = str[strl-1] - key[(strl-1)%keyl];

    //encrypts starting from the end
    for(int counter = strl-2; counter >= 0; counter--){

        //sets the new bit value
        str[counter] = str[counter] - str[counter+1] - key[counter%keyl];

    }
}

//complementar to rda();    decrypts the string by removing, from the beginning to the end
void crda(char* str, char* key, int strl,int keyl){

     //the first caracter is encrypted before, to avoid sigmentation faults
    str[0] = str[0] - key[(strl-1)%keyl];

    //encrypts atarting from the beginning
    for( int counter = 1; counter<strl; counter++){

        //sets the bit value
        str[counter] = str[counter] - str[counter-1] - key[(strl-counter-1)%keyl];

    }
}



//default encryption procedure
void dvdencrypt( char *str, char *key,int strl,int keyl){
    da(str,key,strl,keyl);
    rda(str,key,strl,keyl);
}


//default decryption procedure
void dvddecrypt( char *str, char *key,int strl,int keyl){
    crda(str,key,strl,keyl);
    cda(str,key,strl,keyl);
}
