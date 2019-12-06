
/*
 *
 * Chinese Academy of Sciences
 * State Key Laboratory of Information Security
 * Institute of Information Engineering
 *
 * Copyright (C) 2016 Chinese Academy of Sciences
 *
 * LuoPeng, luopeng@iie.ac.cn
 * Updated in Oct 2016
 * Updated in Jan 2017, update muliple function on GF(2^8).
 *
 */
/* #include <stdint.h> */

#include "data_types.h"
#include "aes_schedule.h"
#include "aes_encrypt.h"


/*
 * round constants
 */

#define AES_BLOCK_SIZE      16U
#define AES_ROUNDS          10U  /* 12, 14 */
#define AES_ROUND_KEY_SIZE  176U /* AES-128 has 10 rounds, and there is a AddRoundKey before first round. (10+1)x16=176. */


void aes_key_schedule_128(const uint8_t *key, uint8_t *roundkeys) {

    uint8_t temp[4];
    uint8_t *last4bytes; /* point to the last 4 bytes of one round */
    uint8_t *lastround;
    uint8_t i;

    static uint8_t RC[10] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36};
    for (i = 0U; i < 16U; ++i) {
        *roundkeys = *key;
        roundkeys++;
        key++;

    }

    last4bytes = roundkeys-4;
    for (i = 0U; i < AES_ROUNDS; ++i) {
        /* k0-k3 for next round */
        temp[3U] = SBOX[*last4bytes];
        last4bytes++;
        temp[0U] = SBOX[*last4bytes];
        last4bytes++;
        temp[1U] = SBOX[*last4bytes];
        last4bytes++;
        temp[2U] = SBOX[*last4bytes];
        last4bytes++;
        temp[0U] ^= RC[i];
        lastround = roundkeys-16;
        *roundkeys = temp[0U] ^ *lastround;
        roundkeys++;
        lastround++;
        *roundkeys = temp[1U] ^ *lastround;
        roundkeys++;
        lastround++;
        *roundkeys = temp[2U] ^ *lastround;
        roundkeys++;
        lastround++;
        *roundkeys = temp[3U] ^ *lastround;
        roundkeys++;
        lastround++;
        /* k4-k7 for next round  */
        *roundkeys = *last4bytes ^ *lastround;
        roundkeys++;
        last4bytes++;
        lastround++;
        *roundkeys = *last4bytes ^ *lastround;
        roundkeys++;
        last4bytes++;
        lastround++;
        *roundkeys = *last4bytes ^ *lastround;
        roundkeys++;
        last4bytes++;
        lastround++;
        *roundkeys = *last4bytes ^ *lastround;
        roundkeys++;
        last4bytes++;
        lastround++;
        /* k8-k11 for next round */
        *roundkeys = *last4bytes ^ *lastround;
        roundkeys++;
        last4bytes++;
        lastround++;
        *roundkeys = *last4bytes ^ *lastround;
        roundkeys++;
        last4bytes++;
        lastround++;
        *roundkeys = *last4bytes ^ *lastround;
        roundkeys++;
        last4bytes++;
        lastround++;
        *roundkeys = *last4bytes ^ *lastround;
        roundkeys++;
        last4bytes++;
        lastround++;
        /* k12-k15 for next round */
        *roundkeys = *last4bytes ^ *lastround;
        roundkeys++;
        last4bytes++;
        lastround++;
        *roundkeys = *last4bytes ^ *lastround;
        roundkeys++;
        last4bytes++;
        lastround++;
        *roundkeys = *last4bytes ^ *lastround;
        roundkeys++;
        last4bytes++;
        lastround++;
        *roundkeys = *last4bytes ^ *lastround;
        roundkeys++;
        last4bytes++;
        lastround++;
    }
}
