// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_CONSENSUS_CONSENSUS_H
#define BITCOIN_CONSENSUS_CONSENSUS_H

#include <stdint.h>
#include <algorithm>

/** The maximum allowed size for a serialized block, in bytes (only for buffer size limits) */
static const unsigned int DEFAULT_MAX_BLOCK_SERIALIZED_SIZE = 4000000;
extern unsigned int MAX_BLOCK_SERIALIZED_SIZE(void);
/** The maximum allowed weight for a block, see BIP 141 (network rule) */
static const unsigned int DEFAULT_MAX_BLOCK_WEIGHT = 4000000;
extern unsigned int MAX_BLOCK_WEIGHT(void);
/** The maximum allowed size for a block excluding witness data, in bytes (network rule) */
static const unsigned int DEFAULT_MAX_BLOCK_BASE_SIZE = 1000000;
extern unsigned int MAX_BLOCK_BASE_SIZE(void);
/** The maximum allowed number of signature check operations in a block (network rule) */
static const int64_t DEFAULT_MAX_BLOCK_SIGOPS_COST = 80000;
extern int64_t MAX_BLOCK_SIGOPS_COST(void);
/** Coinbase transaction outputs can only be spent after this number of new blocks (network rule) */
static const int COINBASE_MATURITY = 100;

/** Flags for nSequence and nLockTime locks */
enum {
    /* Interpret sequence numbers as relative lock-time constraints. */
    LOCKTIME_VERIFY_SEQUENCE = (1 << 0),

    /* Use GetMedianTimePast() instead of nTime for end point timestamp. */
    LOCKTIME_MEDIAN_TIME_PAST = (1 << 1),
};

/** The ratio between the weight & size of a block */
static const unsigned int BLOCK_WEIGHT_2_SIZE_RATIO = (DEFAULT_MAX_BLOCK_WEIGHT / DEFAULT_MAX_BLOCK_BASE_SIZE);
/** The ratio between the weight & sigops_cost of a block */
static const unsigned int BLOCK_WEIGHT_2_SIGOPS_RATIO = (DEFAULT_MAX_BLOCK_WEIGHT / DEFAULT_MAX_BLOCK_SIGOPS_COST);
/** Sets the MAX_BLOCK_SERIALIZED_SIZE, MAX_BLOCK_WEIGHT, MAX_BLOCK_BASE_SIZE & MAX_BLOCK_SIGOPS_COST */
extern void set_max_block_weight(unsigned int max_block_weight);

#endif // BITCOIN_CONSENSUS_CONSENSUS_H
