//
//  OpODBBase.cpp
//  OpODB
//
//  Created by BruceZCQ on 14-3-25.
//  Copyright (c) 2014年 OpeningO,Inc (http://openingo.github.io/). All rights reserved.
//

#include "OpODBBase.h"

NS_OPODB_BEGIN

void
OpODBBase::release()
{
    delete this;
}

NS_OPODB_END