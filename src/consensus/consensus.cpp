//
// consensus.cpp
//
// Created on: 20/03/2017
//
// Copyright (c) 2017 Buck Rogers & the Bitcoin Buck Party
//
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include "consensus/consensus.h"

static unsigned int s_MAX_BLOCK_WEIGHT = DEFAULT_MAX_BLOCK_WEIGHT;

unsigned int MAX_BLOCK_SERIALIZED_SIZE(void) {
    return MAX_BLOCK_WEIGHT();
}

unsigned int MAX_BLOCK_BASE_SIZE(void) {
	return MAX_BLOCK_WEIGHT() / BLOCK_WEIGHT_2_SIZE_RATIO;
}

int64_t MAX_BLOCK_SIGOPS_COST(void) {
	return MAX_BLOCK_WEIGHT() / BLOCK_WEIGHT_2_SIGOPS_RATIO;
}

unsigned int MAX_BLOCK_WEIGHT(void) {
	return s_MAX_BLOCK_WEIGHT;
}

void set_max_block_weight(unsigned int max_block_weight) {
	s_MAX_BLOCK_WEIGHT = std::max(DEFAULT_MAX_BLOCK_WEIGHT, max_block_weight);
}
