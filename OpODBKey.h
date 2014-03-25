//
//  OpODBKey.h
//  OpODB
//
//  Created by BruceZCQ on 14-3-25.
//  Copyright (c) 2014年 OpeningO,Inc (http://openingo.github.io/). All rights reserved.
//

#ifndef __OpODB__OpODBKey__
#define __OpODB__OpODBKey__

#include "OpODBConfig.h"
#include "OpODBBase.h"

NS_OPODB_BEGIN

class OpODBKey : public OpODBBase
{
public:
    OpODBKey(u_int32_t indexOffset,
             u_int32_t documentOffset,
             u_int32_t documentLength,
             u_int32_t blockLength);
    virtual ~OpODBKey();
private:
    u_int32_t m_indexOffset;
    u_int32_t m_documentOffset;
    u_int32_t m_documentLength;
    u_int32_t m_blockLength;
};

NS_OPODB_END

#endif /* defined(__OpODB__OpODBKey__) */
