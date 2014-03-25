//
//  OpODBIndex.h
//  OpODB
//
//  Created by BruceZCQ on 14-3-25.
//  Copyright (c) 2014年 OpeningO,Inc (http://openingo.github.io/). All rights reserved.
//

#ifndef __OpODB__OpODBIndex__
#define __OpODB__OpODBIndex__

#include "OpODBConfig.h"
#include "OpODBBase.h"

NS_OPODB_BEGIN

class OpODBIndex : public OpODBBase
{
public:
    OpODBIndex(std::string *indexValue,
               std::string *key);
    std::set<std::string*> *getKeySet();
    void setValue(std::string *value);
    std::string *getValue();
    virtual ~OpODBIndex();
private:
    std::string *m_value;
    std::set<std::string *> *m_keySet;
};

NS_OPODB_END

#endif /* defined(__OpODB__OpODBIndex__) */
