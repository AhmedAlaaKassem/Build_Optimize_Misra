/*
 *
 * Chinese Academy of Sciences
 * State Key Laboratory of Information Security
 * Institute of Information Engineering
 *
 * Copyright (C) 2016 Chinese Academy of Sciences
 *
 * LuoPeng, luopeng@iie.ac.cn
 * Updated in May 2016
 *
 */
#ifndef AES_SCHEDULE_128_H
#define AES_SCHEDULE_128_H

/**
 * @purpose:            Key schedule for AES-128
 * @par[in]key:         16 bytes of master keys
 * @par[out]roundkeys:  176 bytes of round keys
 */
void aes_key_schedule_128(const uint8_t *key, uint8_t *roundkeys);
#endif
