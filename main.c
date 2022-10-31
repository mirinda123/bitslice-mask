#define ORDER 4
#include "aes.h"
uint8_t key[16] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x01};
uint8_t src[16] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x01};
uint8_t dst[16];

int main(void)
{
	// test for unprotected AES
	
	AES_CTX ctx = {{0},{0},10};
	
	ctx.num_rounds = 10;
	AES_Setkey(&ctx, key, 16);
	AES_Encrypt(&ctx, key, dst);
	int a = 0;
	int b = 0;
	int c = 0;
	return 1;
}