#include "libdvden.h"


//adds 128 to the caracter, making it easier to use
static inline int bitfix(int a){
    if(a<0)return a+256; else return a;
}


//encrypts the string by adding, from the beginning to the end
void da(char* str, char* key, int strl,int keyl){

    //starts from the beginning
    int counter = 0;

    //encrypts
    while(counter < strl-1){

        //sets the new bit value
        str[counter] = bitfix(str[counter]) + bitfix(str[counter+1]) + bitfix(key[counter%keyl]);

        //goes to the next bit
        counter++;
    }

    //the last caracter is encrypted after, to avoid sigmentation faults
    str[strl-1] = bitfix(str[strl-1]) + bitfix(key[(strl-1)%keyl]);
}


//encrypts the string by adding, from the end to the beginning
void rda(char* str, char* key, int strl,int keyl){
    //starts from the end
    int counter = strl-1;

    //encrypts
    while(counter>0){

        //sets the bit value
        str[counter] = bitfix(str[counter]) + bitfix(str[counter-1]) + bitfix(key[(strl-counter-1)%keyl]);

        //goes to the next bit
        counter--;
    }

    //the last caracter is encrypted after, to avoid sigmentation faults
    str[0] = bitfix(str[0]) + bitfix(key[(strl-1)%keyl]);
}


//complementar to da(); decrypts the string by removing, from the end to the beginning
void cda(char* str, char* key, int strl,int keyl){

    //the last caracter is decrypted before, to avoid sigmentation faults
    str[strl-1] = bitfix(str[strl-1]) - bitfix(key[(strl-1)%keyl]);

    //starts from the end
    int counter = strl-2;

    //encrypts
    while(counter >= 0){

        //sets the new bit value
        str[counter] = bitfix(str[counter]) - bitfix(str[counter+1]) - bitfix(key[counter%keyl]);

        //goes to the next bit
        counter--;
    }
}

//complementar to rda();    decrypts the string by removing, from the beginning to the end
void crda(char* str, char* key, int strl,int keyl){

    //starts from the beginning
    int counter = 1;

     //the first caracter is encrypted before, to avoid sigmentation faults
    str[0] = bitfix(str[0]) - bitfix(key[(strl-1)%keyl]);

    //encrypts
    while(counter<strl){

        //sets the bit value
        str[counter] = bitfix(str[counter]) - bitfix(str[counter-1]) - bitfix(key[(strl-counter-1)%keyl]);

        //goes to the next bit
        counter++;
    }
}



//default encryption procedure
void dvdencrypt(char* str,char* key,int strl,int keyl){
    da(str,key,strl,keyl);
    rda(str,key,strl,keyl);
}


//default decryption procedure
void dvddecrypt(char* str,char* key,int strl,int keyl){
    crda(str,key,strl,keyl);
    cda(str,key,strl,keyl);
}
