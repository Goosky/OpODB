//
//  OpODBIndexBlock.h
//  OpODB
//
//  Created by BruceZCQ on 14-3-25.
//  Copyright (c) 2014年 OpeningO,Inc (http://openingo.github.io/). All rights reserved.
//

#ifndef __OpODB__OpODBIndexBlock__
#define __OpODB__OpODBIndexBlock__

#include "OpODBConfig.h"
#include "OpODBBase.h"

NS_OPODB_BEGIN

class OpODBIndexBlock : public OpODBBase
{
public:
    OpODBIndexBlock(u_int indexOffset,
                    u_int blockLength);
    u_int getIndexOffset();
    u_int getBlockLength();
    virtual ~OpODBIndexBlock();
private:
    u_int m_indexOffset;
    u_int m_blockLength;
};

NS_OPODB_END

#endif /* defined(__OpODB__OpODBIndexBlock__) */
