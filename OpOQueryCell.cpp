//
//  OpOQueryCell.cpp
//  OpODB
//
//  Created by BruceZCQ on 14-3-25.
//  Copyright (c) 2014年 OpeningO,Inc (http://openingo.github.io/). All rights reserved.
//

#include "OpOQueryCell.h"

NS_OPODB_BEGIN

OpOQueryCell::OpOQueryCell()
{
    
}

const std::string*
OpOQueryCell::getSchemaName()
{
    return m_schemaName;
}

void
OpOQueryCell::setSchemaName(const std::string *schemaName)
{
    m_schemaName = schemaName;
}

OpODBQueryOperation
OpOQueryCell::getOperation()
{
    return m_operation;
}

void
OpOQueryCell::setOperation(OpODBQueryOperation operation)
{
    m_operation = operation;
}

const std::string*
OpOQueryCell::getValue()
{
    return m_value;
}

void
OpOQueryCell::setValue(const std::string *value)
{
    m_value = value;
}

OpOQueryCell::~OpOQueryCell()
{
    delete m_value;
    delete m_schemaName;
    this->release();
}

NS_OPODB_END