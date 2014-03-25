//
//  OpOQuery.cpp
//  OpODB
//
//  Created by BruceZCQ on 14-3-25.
//  Copyright (c) 2014年 OpeningO,Inc (http://openingo.github.io/). All rights reserved.
//

#include "OpOQuery.h"
#include "OpOCollection.h"
#include "OpOQueryCell.h"

NS_OPODB_BEGIN

OpOQuery::OpOQuery(OpOCollection *collection)
{
    m_collection = collection;
    m_queries = new std::list<OpOQueryCell*>;
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
    OpOQueryCell *query = new OpOQueryCell();
    query->setSchemaName(indexName);
//    query->setOperation((OpODBQueryOperation)(QueryEqual | QueryIntersection));
    query->setValue(value);
    m_queries->push_back(query);
    return this;
}

OpOQuery*
OpOQuery::queryAndNotEqual(const std::string *indexName,
                           const std::string *value)
{
    OpOQueryCell *query = new OpOQueryCell();
    query->setSchemaName(indexName);
//    query->setOperation((OpODBQueryOperation)(QueryUnEqual | QueryIntersection));
    query->setValue(value);
    m_queries->push_back(query);
    return this;
}

OpOQuery*
OpOQuery::queryAndLess(const std::string *indexName,
                       const std::string *value)
{
    OpOQueryCell *query = new OpOQueryCell();
    query->setSchemaName(indexName);
//    query->setOperation((OpODBQueryOperation)(QueryLess|QueryIntersection));
    query->setValue(value);
    m_queries->push_back(query);
    return this;
}

OpOQuery*
OpOQuery::queryAndLessEqual(const std::string *indexName,
                            const std::string *value)
{
    OpOQueryCell *query = new OpOQueryCell();
    query->setSchemaName(indexName);
//    query->setOperation((OpODBQueryOperation)(QueryLessEqual|QueryIntersection));
    query->setValue(value);
    m_queries->push_back(query);
    return this;
}

OpOQuery*
OpOQuery::queryAndGreater(const std::string *indexName,
                          const std::string *value)
{
    OpOQueryCell *query = new OpOQueryCell();
    query->setSchemaName(indexName);
//    query->setOperation((OpODBQueryOperation)(QueryGreater|QueryIntersection));
    query->setValue(value);
    m_queries->push_back(query);
    return this;
}

OpOQuery*
OpOQuery::queryAndGreaterEqual(const std::string *indexName,
                               const std::string *value)
{
    OpOQueryCell *query = new OpOQueryCell();
    query->setSchemaName(indexName);
//    query->setOperation((OpODBQueryOperation)(QueryGreaterEqual|QueryIntersection));
    query->setValue(value);
    m_queries->push_back(query);
    return this;
}

OpOQuery*
OpOQuery::queryAndLike(const std::string *indexName,
                       const std::string *value)
{
    OpOQueryCell *query = new OpOQueryCell();
    query->setSchemaName(indexName);
//    query->setOperation((OpODBQueryOperation)(QueryLike|QueryIntersection));
    query->setValue(value);
    m_queries->push_back(query);
    return this;
}

OpOQuery*
OpOQuery::queryOrAll()
{
    OpOQueryCell *query = new OpOQueryCell();
//    query->setOperation((OpODBQueryOperation)(QueryAll|QueryIntersection));
    m_queries->push_back(query);
    return this;
}

OpOQuery*
OpOQuery::queryOrEqual(const std::string *indexName,
                       const std::string *value)
{
    OpOQueryCell *query = new OpOQueryCell();
    query->setSchemaName(indexName);
//    query->setOperation((OpODBQueryOperation)(QueryEqual|QueryUnion));
    query->setValue(value);
    m_queries->push_back(query);
    return this;
}

OpOQuery*
OpOQuery::queryOrNotEqual(const std::string *indexName,
                          const std::string *value)
{
    OpOQueryCell *query = new OpOQueryCell();
    query->setSchemaName(indexName);
//    query->setOperation((OpODBQueryOperation)(QueryUnEqual|QueryUnion));
    query->setValue(value);
    m_queries->push_back(query);
    return this;
}

OpOQuery*
OpOQuery::queryOrLess(const std::string *indexName,
                      const std::string *value)
{
    OpOQueryCell *query = new OpOQueryCell();
    query->setSchemaName(indexName);
//    query->setOperation((OpODBQueryOperation)(QueryLess|QueryUnion));
    query->setValue(value);
    m_queries->push_back(query);
    return this;
}

OpOQuery*
OpOQuery::queryOrLessEqual(const std::string *indexName,
                           const std::string *value)
{
    OpOQueryCell *query = new OpOQueryCell();
    query->setSchemaName(indexName);
    query->setOperation((OpODBQueryOperation)(QueryLessEqual|QueryUnion));
    query->setValue(value);
    m_queries->push_back(query);
    return this;
}

OpOQuery*
OpOQuery::queryOrGreater(const std::string *indexName,
                         const std::string *value)
{
    OpOQueryCell *query = new OpOQueryCell();
    query->setSchemaName(indexName);
    query->setOperation((OpODBQueryOperation)(QueryGreater|QueryUnion));
    query->setValue(value);
    m_queries->push_back(query);
    return this;
}

OpOQuery*
OpOQuery::queryOrGreaterEqual(const std::string *indexName,
                              const std::string *value)
{
    OpOQueryCell *query = new OpOQueryCell();
    query->setSchemaName(indexName);
    query->setOperation((OpODBQueryOperation)(QueryGreaterEqual|QueryUnion));
    query->setValue(value);
    m_queries->push_back(query);
    return this;
}

OpOQuery*
OpOQuery::queryOrLike(const std::string *indexName,
                      const std::string *value)
{
    OpOQueryCell *query = new OpOQueryCell();
    query->setSchemaName(indexName);
    query->setOperation((OpODBQueryOperation)(QueryLike|QueryUnion));
    query->setValue(value);
    m_queries->push_back(query);
    return this;
}

OpOQuery*
OpOQuery::orderByIndexName(const std::string *indexName)
{
    OpOQueryCell *query = new OpOQueryCell();
    query->setSchemaName(indexName);
    query->setOperation(QueryOrderASC);
    m_queries->push_back(query);
    return this;
}

OpOQuery*
OpOQuery::orderByDESC(const std::string *indexName)
{
    OpOQueryCell *query = new OpOQueryCell();
    query->setSchemaName(indexName);
    query->setOperation(QueryOrderDESC);
    m_queries->push_back(query);
    return this;
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