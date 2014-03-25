//
//  OpODB.cpp
//  OpODB
//
//  Created by BruceZCQ on 14-3-25.
//  Copyright (c) 2014年 OpeningO,Inc (http://openingo.github.io/). All rights reserved.
//

#include "OpODB.h"

NS_OPODB_BEGIN

OpODB* OpODB::m_opoDB = nullptr;

OpODB::OpODB()
{
    
}

OpODB::OpODB(std::string *path)
{
    m_databaepath = path;
}

std::list<std::string*>*
OpODB::collections()
{
    return nullptr;
}

OpOCollection *
OpODB::collection(std::string *name)
{
    return nullptr;
}

void
OpODB::removeCollection(std::string *name)
{
    
}

void
OpODB::removeAllCollections()
{
    
}

void
OpODB::close()
{
    
}

std::string*
OpODB::getDataBasePath()
{
    return m_databaepath;
}

OpODB::~OpODB()
{
    
}

OpODB* OpODB::instance()
{
    if (m_opoDB == nullptr) {
        m_opoDB = new OpODB();
    }
    return m_opoDB;
}

void OpODB::reset()
{
    
}

NS_OPODB_END