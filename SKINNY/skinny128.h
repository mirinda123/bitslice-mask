#ifndef SKINNY128_H_
#define SKINNY128_H_

#include "tk_schedule.h"

void skinny128_128_encrypt(u8* ctext, const u8* ptext, const tweakey tk, 
					u8* ctext_bis, const u8* ptext_bis, const tweakey tk_bis);
void skinny128_256_encrypt(u8* ctext, const u8* ptext, const tweakey tk, 
					u8* ctext_bis, const u8* ptext_bis, const tweakey tk_bis);
void skinny128_384_encrypt(u8* ctext, const u8* ptext, const tweakey tk, 
					u8* ctext_bis, const u8* ptext_bis, const tweakey tk_bis);
void skinny128_128_decrypt(u8* ctext, const u8* ptext, const tweakey tk, 
					u8* ctext_bis, const u8* ptext_bis, const tweakey tk_bis);
void skinny128_256_decrypt(u8* ctext, const u8* ptext, const tweakey tk, 
					u8* ctext_bis, const u8* ptext_bis, const tweakey tk_bis);
void skinny128_384_decrypt(u8* ctext, const u8* ptext, const tweakey tk, 
					u8* ctext_bis, const u8* ptext_bis, const tweakey tk_bis);

#define SKINNY128_128_ROUNDS	40
#define SKINNY128_256_ROUNDS	48
#define SKINNY128_384_ROUNDS	56

#define ROR(x,y) 		(((x) >> (y)) | ((x) << (32 - (y))))
#define QUADRUPLE_ROUND_precompute(state, tk)({	\
	sboxprecom_0();
	add_tweakey(state, tk);
	mixcolumns_0(state);
})

#define QUADRUPLE_ROUND_online(state, tk)({	\
})
#define QUADRUPLE_ROUND_old(state, tk) ({					\
	state[3] ^= (state[0] | state[1]);					\
	state[7] ^= (state[4] | state[5]);					\
	state[1] ^= (state[6] | state[5]);					\
	state[2] ^= (state[3] & state[7]);					\
	state[6] ^= (~state[7] | state[4]);					\
	state[0] ^= (state[2] | ~state[1]);					\
	state[4] ^= (~state[3] | state[2]);					\
	state[5] ^= (state[6] & state[0]);					\
	add_tweakey(state, tk); 							\
	mixcolumns_0(state);								\
	state[4] ^= (state[2] | state[3]);					\
	state[5] ^= (state[6] | state[1]);					\
	state[3] ^= (state[0] | state[1]);					\
	state[7] ^= (state[4] & state[5]);					\
	state[0] ^= (~state[5] | state[6]);					\
	state[2] ^= (state[7] | ~state[3]);					\
	state[6] ^= (~state[4] | state[7]);					\
	state[1] ^= (state[0] & state[2]);					\
	add_tweakey(state, tk+8); 							\
	mixcolumns_1(state);								\
	state[6] ^= (state[7] | state[4]);					\
	state[1] ^= (state[0] | state[3]);					\
	state[4] ^= (state[2] | state[3]);					\
	state[5] ^= (state[6] & state[1]);					\
	state[2] ^= (~state[1] | state[0]);					\
	state[7] ^= (state[5] | ~state[4]);					\
	state[0] ^= (~state[6] | state[5]);					\
	state[3] ^= (state[2] & state[7]);					\
	add_tweakey(state, tk+16); 							\
	mixcolumns_2(state);								\
	state[0] ^= (state[5] | state[6]);					\
	state[3] ^= (state[2] | state[4]);					\
	state[6] ^= (state[7] | state[4]);					\
	state[1] ^= (state[0] & state[3]);					\
	state[7] ^= (~state[3] | state[2]);					\
	state[5] ^= (state[1] | ~state[6]);					\
	state[2] ^= (~state[0] | state[1]);					\
	state[4] ^= (state[7] & state[5]);					\
	add_tweakey(state, tk+24); 							\
	mixcolumns_3(state);								\
	state[0] ^= state[1]; 								\
	state[1] ^= state[0]; 								\
	state[0] ^= state[1]; 								\
	state[2] ^= state[3]; 								\
	state[3] ^= state[2]; 								\
	state[2] ^= state[3]; 								\
	state[4] ^= state[7]; 								\
	state[7] ^= state[4]; 								\
	state[4] ^= state[7]; 								\
	state[5] ^= state[6]; 								\
	state[6] ^= state[5]; 								\
	state[5] ^= state[6]; 								\
})

#define INV_QUADRUPLE_ROUND(state, tk) ({				\
	state[0] ^= state[1]; 								\
	state[1] ^= state[0]; 								\
	state[0] ^= state[1]; 								\
	state[2] ^= state[3]; 								\
	state[3] ^= state[2]; 								\
	state[2] ^= state[3]; 								\
	state[4] ^= state[7]; 								\
	state[7] ^= state[4]; 								\
	state[4] ^= state[7]; 								\
	state[5] ^= state[6]; 								\
	state[6] ^= state[5]; 								\
	state[5] ^= state[6]; 								\
	inv_mixcolumns_3(state);							\
	add_tweakey(state, tk+24); 							\
	state[4] ^= (state[7] & state[5]);					\
	state[2] ^= (~state[0] | state[1]);					\
	state[5] ^= (state[1] | ~state[6]);					\
	state[7] ^= (~state[3] | state[2]);					\
	state[1] ^= (state[0] & state[3]);					\
	state[6] ^= (state[7] | state[4]);					\
	state[3] ^= (state[2] | state[4]);					\
	state[0] ^= (state[5] | state[6]);					\
	inv_mixcolumns_2(state);							\
	add_tweakey(state, tk+16); 							\
	state[3] ^= (state[2] & state[7]);					\
	state[0] ^= (~state[6] | state[5]);					\
	state[7] ^= (state[5] | ~state[4]);					\
	state[2] ^= (~state[1] | state[0]);					\
	state[5] ^= (state[6] & state[1]);					\
	state[4] ^= (state[2] | state[3]);					\
	state[1] ^= (state[0] | state[3]);					\
	state[6] ^= (state[7] | state[4]);					\
	inv_mixcolumns_1(state);							\
	add_tweakey(state, tk+8); 							\
	state[1] ^= (state[0] & state[2]);					\
	state[6] ^= (~state[4] | state[7]);					\
	state[2] ^= (state[7] | ~state[3]);					\
	state[0] ^= (~state[5] | state[6]);					\
	state[7] ^= (state[4] & state[5]);					\
	state[3] ^= (state[0] | state[1]);					\
	state[5] ^= (state[6] | state[1]);					\
	state[4] ^= (state[2] | state[3]);					\
	inv_mixcolumns_0(state); 							\
	add_tweakey(state, tk); 							\
	state[5] ^= (state[6] & state[0]);					\
	state[4] ^= (~state[3] | state[2]);					\
	state[0] ^= (state[2] | ~state[1]);					\
	state[6] ^= (~state[7] | state[4]);					\
	state[2] ^= (state[3] & state[7]);					\
	state[1] ^= (state[6] | state[5]);					\
	state[7] ^= (state[4] | state[5]);					\
	state[3] ^= (state[0] | state[1]);					\
})

#endif  // SKINNY128_H_
