//
//  OpODBIndex.cpp
//  OpODB
//
//  Created by BruceZCQ on 14-3-25.
//  Copyright (c) 2014年 OpeningO,Inc (http://openingo.github.io/). All rights reserved.
//

#include "OpODBIndex.h"

NS_OPODB_BEGIN

OpODBIndex::OpODBIndex(std::string *indexValue,
                       std::string *key)
{
    m_keySet = new std::set<std::string*>;
    m_keySet->insert(key);
}


std::set<std::string *>*
OpODBIndex::getKeySet()
{
    return m_keySet;
}

void
OpODBIndex::setValue(std::string *value)
{
    m_value = value;
}

std::string*
OpODBIndex::getValue()
{
    return m_value;
}

OpODBIndex::~OpODBIndex()
{
    delete m_value;
    delete m_keySet;
    this->release();
}


NS_OPODB_END