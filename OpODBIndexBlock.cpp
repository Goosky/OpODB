//
//  OpODBIndexBlock.cpp
//  OpODB
//
//  Created by BruceZCQ on 14-3-25.
//  Copyright (c) 2014年 OpeningO,Inc (http://openingo.github.io/). All rights reserved.
//

#include "OpODBIndexBlock.h"


NS_OPODB_BEGIN

OpODBIndexBlock::OpODBIndexBlock(u_int indexOffset,
                                 u_int blockLength)
{
    m_indexOffset = indexOffset;
    m_blockLength = blockLength;
}

u_int
OpODBIndexBlock::getBlockLength()
{
    return m_blockLength;
}

u_int
OpODBIndexBlock::getIndexOffset()
{
    return m_indexOffset;
}

OpODBIndexBlock::~OpODBIndexBlock()
{
    this->release();
}

NS_OPODB_END