//
// BlockSize.cpp
//
// Created on: 20/03/2017
//
// Copyright (c) 2017 Allan Doensen (www.doesnen.com)
//
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "blocksize.h"


// CORE CONSENSUS DEFAULTS!
unsigned int CHECKED_MAX_BLOCK_BASE_SIZE = 1000000;
unsigned int MINED_MAX_BLOCK_BASE_SIZE = 1000000;
int64_t MAX_BLOCK_SIGOPS_COST = 80000;
unsigned int MAX_BLOCK_WEIGHT = 4000000;

namespace EmergentConsensus
{

    bool BlockSize::validateBlockSizeCfg(BlockCount_t maxGenBlockSize,
            BlockCount_t excessiveBlockSize)
    {
        if ((!maxGenBlockSize) || (!maxGenBlockSize)
                || (maxGenBlockSize > excessiveBlockSize))
        {
            return false;
        }

        return true;
    }

    BlockSize::BlockCount_t BlockSize::getMaximumGeneratedBlockSize(void)
    {
        return GetArg("-blockmaxsize",
                (int64_t) BlockSize::defaultMaximumGeneratedBlockSize);
    }

    BlockSize::BlockCount_t BlockSize::gettExcessiveBlockSize(void)
    {
        return GetArg("-excessiveblocksize",
                (int64_t) BlockSize::defaultExcessiveBlockSize);
    }

    BlockSize::BlockCount_t BlockSize::getExcessiveAcceptanceDepth(void)
    {
        return GetArg("-excessiveacceptdepth",
                (int64_t) BlockSize::defaultExcessiveAcceptanceDepth);
    }

    void BlockSize::rebuild(void)
    {
        CHECKED_MAX_BLOCK_BASE_SIZE = EmergentConsensus::BlockSize::gettExcessiveBlockSize();
        MINED_MAX_BLOCK_BASE_SIZE = EmergentConsensus::BlockSize::getMaximumGeneratedBlockSize();
        MAX_BLOCK_SIGOPS_COST = 80000 * (CHECKED_MAX_BLOCK_BASE_SIZE / 1000000 );
        MAX_BLOCK_WEIGHT = 4000000 * (CHECKED_MAX_BLOCK_BASE_SIZE / 1000000 );
    }

}; /* namespace EmergentConsensus */

