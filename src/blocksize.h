//
// BlockSize.h
//
// Created on: 20/03/2017
//
// Copyright (c) 2017 Allan Doensen (www.doesnen.com)
//
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BLOCKSIZE_H_
#define BLOCKSIZE_H_

#include "util.h"

namespace EmergentConsensus
{

    class BlockSize
    {
        public:

            typedef uint32_t BlockCount_t;

            static const BlockCount_t defaultMaximumGeneratedBlockSize = 1000000;
            static const BlockCount_t defaultExcessiveBlockSize = 1000000;
            static const BlockCount_t defaultExcessiveAcceptanceDepth = 16;

            static bool validateBlockSizeCfg(BlockCount_t maxGenBlockSize,
                    BlockCount_t excessiveBlockSize);

            static BlockCount_t getMaximumGeneratedBlockSize(void);

            static BlockCount_t gettExcessiveBlockSize(void);

            static BlockCount_t getExcessiveAcceptanceDepth(void);

            static void rebuild(void);

    };

} /* namespace EmergentConsensus */

#endif /* BLOCKSIZE_H_ */
