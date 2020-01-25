#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<openssl/evp.h>
#include<ctype.h>
int main(){
	FILE *wfptr = NULL;
	ssize_t readlen=0;
	size_t len;
	char padd[16] ="###############";
	char *word = (char*) malloc(1024);
	int tmplen =0;
	unsigned char outbuf[1024 + EVP_MAX_BLOCK_LENGTH];
	EVP_CIPHER_CTX ctx;
	char inText[] = "This is a top secret.";
	unsigned char iv[] = {0xaa,0xbb,0xcc,0xdd,0xee,0xff,0x00,0x99,0x88,0x77,0x66,0x55,0x44,0x33,0x22,0x11};
	unsigned char cypher_text[] = "062ff0112cb32d04d0adcfa02d215abd40a5f932da1ebbd3744de5d16be5a4d7";
	wfptr = fopen("words.txt","r");
	if(wfptr == NULL) {
		printf("couldnt open password file");
		return 0;
	}
	int count =0,outlen = 0;
	while((readlen = getline(&word, &len, wfptr)!=-1)){
		outlen=0,tmplen=0;
		printf("\n %s  ",word);
		word[strlen(word)-1] ='\0';
		if(strlen(word)<16) {
			strncat(word,padd,16-strlen(word));
			word[strlen(word)] = '\0';
		}
		EVP_CIPHER_CTX_init(&ctx);
		EVP_EncryptInit_ex(&ctx, EVP_aes_128_cbc(), NULL, word, iv);
		if(!EVP_EncryptUpdate(&ctx, outbuf, &outlen, inText, strlen(inText)))
		{
			/* Error */
			EVP_CIPHER_CTX_cleanup(&ctx);
			return 0;
		}
		if(!EVP_EncryptFinal_ex(&ctx,outbuf+ outlen, &tmplen)){
			EVP_CIPHER_CTX_cleanup(&ctx);
		}
		outlen +=tmplen;
		char* enc_str = (char*) malloc(12*outlen +1);
		char* enc_ptr = enc_str;
		for(int i=0;i<outlen;i++) {
			enc_str +=sprintf( enc_str,"%02x",outbuf[i]);
		}
		*(enc_str + 1) = '\0';
		printf("\n%s\n", enc_ptr);
		EVP_CIPHER_CTX_cleanup(&ctx);
		
		free(enc_ptr);
		if(!strcmp(enc_ptr,cypher_text)){
			printf("Found the match");
			break;
		}
	}
	free(word);
	fclose(wfptr);
	return 0;
}
