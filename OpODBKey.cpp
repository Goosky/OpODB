//
//  OpODBKey.cpp
//  OpODB
//
//  Created by BruceZCQ on 14-3-25.
//  Copyright (c) 2014年 OpeningO,Inc (http://openingo.github.io/). All rights reserved.
//

#include "OpODBKey.h"

NS_OPODB_BEGIN

OpODBKey::OpODBKey(u_int32_t indexOffset,
                   u_int32_t documentOffset,
                   u_int32_t documentLength,
                   u_int32_t blockLength)
{
    m_indexOffset = indexOffset;
    m_documentOffset = documentOffset;
    m_documentLength = documentLength;
    m_blockLength = blockLength;
}

OpODBKey::~OpODBKey()
{
    this->release();
}

NS_OPODB_END