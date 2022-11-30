#ifndef TK_SCHEDULE_BS_H_
#define TK_SCHEDULE_BS_H_

#include <stdint.h>

typedef uint8_t 	u8;
typedef uint32_t 	u32;

typedef struct {
	u8 tk1[16];
	u8 tk2[16];
	u8 tk3[16];
} tweakey;
	
void packing(u32* out, const u8* in, const u8* in_bis);
void unpacking(u8* out, u8* out_bis, u32 *in);
void precompute_tk(u32* rtk, const tweakey tk, const tweakey tk_bis,
				int rounds);
#define packing_bitslice( out_0,  out_1, out_2, out_3, out_4, out_5, out_6, out_7,  block0, block1)({	\
	u32 tmp;	\
	LE_LOAD(out_0, block0);	\
	LE_LOAD(out_1, block1);	\
	LE_LOAD(out_2, block0 + 4);	\
	LE_LOAD(out_3, block1 + 4);	\
	LE_LOAD(out_4, block0 + 8);	\
	LE_LOAD(out_5, block1 + 8);	\
	LE_LOAD(out_6, block0 + 12);	\
	LE_LOAD(out_7, block1 + 12);	\
	SWAPMOVE(out_1[0], out_0[0], 0x55555555, 1);	\
	SWAPMOVE(out_3[0], out_2[0], 0x55555555, 1);	\
	SWAPMOVE(out_5[0], out_4[0], 0x55555555, 1);	\
	SWAPMOVE(out_7[0], out_6[0], 0x55555555, 1);	\
	SWAPMOVE(out_2[0], out_0[0], 0x30303030, 2);	\
	SWAPMOVE(out_4[0], out_0[0], 0x0c0c0c0c, 4);	\
	SWAPMOVE(out_6[0], out_0[0], 0x03030303, 6);	\
	SWAPMOVE(out_3[0], out_1[0], 0x30303030, 2);	\
	SWAPMOVE(out_5[0], out_1[0], 0x0c0c0c0c, 4);	\
	SWAPMOVE(out_7[0], out_1[0], 0x03030303, 6);	\
	SWAPMOVE(out_4[0], out_2[0], 0x0c0c0c0c, 2);	\
	SWAPMOVE(out_6[0], out_2[0], 0x03030303, 4);	\
	SWAPMOVE(out_5[0], out_3[0], 0x0c0c0c0c, 2);	\
	SWAPMOVE(out_7[0], out_3[0], 0x03030303, 4);	\
	SWAPMOVE(out_6[0], out_4[0], 0x03030303, 2);	\
	SWAPMOVE(out_7[0], out_5[0], 0x03030303, 2);	\
})

#define ROR(x,y) (((x) >> (y)) | ((x) << (32 - (y))))

#define LFSR2(tk) ({				\
	tmp = (tk)[0] ^ (tk)[2];		\
	(tk)[0] = (tk)[1]; 				\
	(tk)[1] = (tk)[2];				\
	(tk)[2] = (tk)[3];				\
	(tk)[3] = (tk)[4];				\
	(tk)[4] = (tk)[5];				\
	(tk)[5] = (tk)[6];				\
	(tk)[6] = (tk)[7];				\
	(tk)[7] = tmp;					\
})

#define LFSR3(tk) ({				\
	tmp = (tk)[7] ^ (tk)[1]; 		\
	(tk)[7] = (tk)[6];				\
	(tk)[6] = (tk)[5];				\
	(tk)[5] = (tk)[4];				\
	(tk)[4] = (tk)[3];				\
	(tk)[3] = (tk)[2];				\
	(tk)[2] = (tk)[1];				\
	(tk)[1] = (tk)[0];				\
	(tk)[0] = tmp;					\
})

#define XOR_BLOCKS(x,y) ({ 			\
	(x)[0] ^= (y)[0];				\
	(x)[1] ^= (y)[1];				\
	(x)[2] ^= (y)[2];				\
	(x)[3] ^= (y)[3];				\
	(x)[4] ^= (y)[4];				\
	(x)[5] ^= (y)[5];				\
	(x)[6] ^= (y)[6];				\
	(x)[7] ^= (y)[7];				\
})

#define SWAPMOVE(a, b, mask, n)	({	\
	tmp = (b ^ (a >> n)) & mask;	\
	b ^= tmp;						\
	a ^= (tmp << n);				\
})

#define LE_LOAD(x, y) 				\
	*(x) = (((u32)(y)[3] << 24) | 	\
		((u32)(y)[2] << 16) 	| 	\
		((u32)(y)[1] << 8) 		| 	\
		(y)[0]);

#define LE_STORE(x, y)				\
	(x)[0] = (y) & 0xff; 			\
	(x)[1] = ((y) >> 8) & 0xff; 	\
	(x)[2] = ((y) >> 16) & 0xff; 	\
	(x)[3] = (y) >> 24;

#endif  // TK_SCHEDULE_BS_H_