//
//  OpOQuery.cpp
//  OpODB
//
//  Created by BruceZCQ on 14-3-25.
//  Copyright (c) 2014年 OpeningO,Inc (http://openingo.github.io/). All rights reserved.
//

#include "OpOQuery.h"
#include "OpOCollection.h"

NS_OPODB_BEGIN

OpOQuery::OpOQuery(OpOCollection *collection)
{
    m_collection = collection;
}

OpOCollection*
OpOQuery::getCollection()
{
    return m_collection;
}

OpOQuery*
OpOQuery::queryAndEqual(const std::string *indexName,
                        const std::string *value)
{
    return nullptr;
}

OpOQuery*
OpOQuery::queryAndNotEqual(const std::string *indexName,
                           const std::string *value)
{
    return nullptr;
}

OpOQuery*
OpOQuery::queryAndLess(const std::string *indexName,
                       const std::string *value)
{
    return nullptr;
}

OpOQuery*
OpOQuery::queryAndLessEqual(const std::string *indexName,
                            const std::string *value)
{
    return nullptr;
}

OpOQuery*
OpOQuery::queryAndGreater(const std::string *indexName,
                          const std::string *value)
{
    return nullptr;
}

OpOQuery*
OpOQuery::queryAndGreaterEqual(const std::string *indexName,
                               const std::string *value)
{
    return nullptr;
}

OpOQuery*
OpOQuery::queryAndLike(const std::string *indexName,
                       const std::string *value)
{
    return nullptr;
}

OpOQuery*
OpOQuery::queryOrAll()
{
    return nullptr;
}

OpOQuery*
OpOQuery::queryOrEqual(const std::string *indexName,
                       const std::string *value)
{
    return nullptr;
}

OpOQuery*
OpOQuery::queryOrNotEqual(const std::string *indexName,
                          const std::string *value)
{
    return nullptr;
}

OpOQuery*
OpOQuery::queryOrLess(const std::string *indexName,
                      const std::string *value)
{
    return nullptr;
}

OpOQuery*
OpOQuery::queryOrLessEqual(const std::string *indexName,
                           const std::string *value)
{
    return nullptr;
}

OpOQuery*
OpOQuery::queryOrGreater(const std::string *indexName,
                         const std::string *value)
{
    return nullptr;
}

OpOQuery*
OpOQuery::queryOrGreaterEqual(const std::string *indexName,
                              const std::string *value)
{
    return nullptr;
}

OpOQuery*
OpOQuery::queryOrLike(const std::string *indexName,
                      const std::string *value)
{
    return nullptr;
}

OpOQuery*
OpOQuery::orderByIndexName(const std::string *indexName)
{
    return nullptr;
}

OpOQuery*
OpOQuery::orderByDESC(const std::string *indexName)
{
    return nullptr;
}

u_int32_t
OpOQuery::count()
{
    return 0;
}

std::list<std::string *>*
OpOQuery::fetch()
{
    return nullptr;
}

std::list<std::string *>*
OpOQuery::fetch(u_int32_t limit)
{
    return nullptr;
}

std::list<std::string *>*
OpOQuery::fetch(u_int32_t limit, u_int32_t skip)
{
    return nullptr;
}

std::map<std::string *, std::string *>*
OpOQuery::fetchFirst()
{
    return nullptr;
}

void
OpOQuery::remove()
{
    
}

OpOQuery::~OpOQuery()
{
    m_collection->release();
    delete m_queries;
    this->release();
}

NS_OPODB_END