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
    query->setOperation((OpODBQueryOperation)(QueryEqual | QueryIntersection));
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
    query->setOperation((OpODBQueryOperation)(QueryUnEqual | QueryIntersection));
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
    query->setOperation((OpODBQueryOperation)(QueryLess|QueryIntersection));
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
    query->setOperation((OpODBQueryOperation)(QueryLessEqual|QueryIntersection));
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
    query->setOperation((OpODBQueryOperation)(QueryGreater|QueryIntersection));
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
    query->setOperation((OpODBQueryOperation)(QueryGreaterEqual|QueryIntersection));
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
    query->setOperation((OpODBQueryOperation)(QueryLike|QueryIntersection));
    query->setValue(value);
    m_queries->push_back(query);
    return this;
}

OpOQuery*
OpOQuery::queryOrAll()
{
    OpOQueryCell *query = new OpOQueryCell();
    query->setOperation((OpODBQueryOperation)(QueryAll|QueryIntersection));
    m_queries->push_back(query);
    return this;
}

OpOQuery*
OpOQuery::queryOrEqual(const std::string *indexName,
                       const std::string *value)
{
    OpOQueryCell *query = new OpOQueryCell();
    query->setSchemaName(indexName);
    query->setOperation((OpODBQueryOperation)(QueryEqual|QueryUnion));
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
    query->setOperation((OpODBQueryOperation)(QueryUnEqual|QueryUnion));
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
    query->setOperation((OpODBQueryOperation)(QueryLess|QueryUnion));
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
    return m_collection->countByQuery(m_queries);
}

std::list<OPODB_SCHEMAMAP_POINTER>*
OpOQuery::fetch()
{
    return m_collection->fetchByQuery(m_queries, 0, 0);
}

std::list<OPODB_SCHEMAMAP_POINTER>*
OpOQuery::fetch(u_int32_t limit)
{
    return m_collection->fetchByQuery(m_queries, 0, limit);
}

std::list<OPODB_SCHEMAMAP_POINTER>*
OpOQuery::fetch(u_int32_t limit, u_int32_t skip)
{
    return m_collection->fetchByQuery(m_queries, skip, limit);
}

OPODB_SCHEMAMAP_POINTER
OpOQuery::fetchFirst()
{
    std::list<OPODB_SCHEMAMAP_POINTER>* docs = m_collection->fetchByQuery(m_queries, 0, 1);
    if (docs->size() == 0) {
        return nullptr;
    }else{
        return docs->front();
    }
}

void
OpOQuery::remove()
{
    m_collection->removeByQuery(m_queries);
}

OpOQuery::~OpOQuery()
{
    m_collection->release();
    delete m_queries;
    this->release();
}

NS_OPODB_END