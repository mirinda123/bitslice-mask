#define ORDER 4
#include <windows.h>
#include "aes.h"
uint8_t key[16] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x01};
uint8_t src[16] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x01};
uint8_t dst[16];

int main(void)
{
	// test for unprotected AES
	uint32_t q[8];
	q[0] = 8899;
	uint32_t newq0[ORDER + 1];
	uint32_t temp = 0;
	AES_CTX ctx = {{0},{0},10};
	/*
	for (int j = 0; j < ORDER; j++) {
		Sleep(1000);
		srand(time(NULL));
		uint32_t r = rand();
		newq0[j] = r;
		temp = temp ^ r;
	}
	*/
	newq0[ORDER] = q[0] ^ temp;
	ctx.num_rounds = 10;
	AES_Setkey(&ctx, key, 16);
	AES_Encrypt(&ctx, src, dst);
	int a = 0;
	int b = 0;
	int c = 0;
	return 1;
}