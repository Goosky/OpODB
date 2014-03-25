//
//  OpOQueryCell.h
//  OpODB
//
//  Created by BruceZCQ on 14-3-25.
//  Copyright (c) 2014年 OpeningO,Inc (http://openingo.github.io/). All rights reserved.
//

#ifndef __OpODB__OpOQueryCell__
#define __OpODB__OpOQueryCell__

#include "OpODBConfig.h"
#include "OpODBBase.h"

NS_OPODB_BEGIN

enum OpODBQueryOperation {
    QueryUnEqual = 0U,
    QueryEqual = 1U,
    QueryLess = 2U,
    QueryLessEqual = 3U,
    QueryGreater = 4U,
    QueryGreaterEqual = 5U,
    QueryLike = 0x30U,
    QueryIntersection = 0x40U,
    QueryUnion = 0x00U,
    QueryAll = 0x80U,
    QueryOrderASC = 0x100U,
    QueryOrderDESC = 0x200U
    };

class OpOQueryCell : public OpODBBase
{
public:
    OpOQueryCell();
    const std::string* getSchemaName();
    void setSchemaName(const std::string *schemaName);
    OpODBQueryOperation getOperation();
    void setOperation(OpODBQueryOperation operation);
    const std::string *getValue();
    void setValue(const std::string *value);
    virtual ~OpOQueryCell();
private:
    const std::string *m_schemaName;
    OpODBQueryOperation m_operation;
    const std::string *m_value;
};

NS_OPODB_END

#endif /* defined(__OpODB__OpOQueryCell__) */
