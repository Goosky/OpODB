//
//  OpOQuery.h
//  OpODB
//
//  Created by BruceZCQ on 14-3-25.
//  Copyright (c) 2014年 OpeningO,Inc (http://openingo.github.io/). All rights reserved.
//

#ifndef __OpODB__OpOQuery__
#define __OpODB__OpOQuery__

#include "OpODBConfig.h"
#include "OpODBBase.h"

NS_OPODB_BEGIN

class OpOCollection;

class OpOQuery : public OpODBBase
{
public:
    OpOQuery(OpOCollection *collection);
    OpOCollection *getCollection();
    OpOQuery* queryAndEqual(const std::string *indexName,
                            const std::string *value);
    OpOQuery* queryAndNotEqual(const std::string *indexName,
                               const std::string *value);
    OpOQuery* queryAndLess(const std::string *indexName,
                           const std::string *value);
    OpOQuery* queryAndLessEqual(const std::string *indexName,
                                const std::string *value);
    OpOQuery* queryAndGreater(const std::string *indexName,
                              const std::string *value);
    OpOQuery* queryAndGreaterEqual(const std::string *indexName,
                                   const std::string *value);
    OpOQuery* queryAndLike(const std::string *indexName,
                           const std::string *value);
    OpOQuery* queryOrAll();
    OpOQuery* queryOrEqual(const std::string *indexName,
                           const std::string *value);
    OpOQuery* queryOrNotEqual(const std::string *indexName,
                              const std::string *value);
    OpOQuery* queryOrLess(const std::string *indexName,
                          const std::string *value);
    OpOQuery* queryOrLessEqual(const std::string *indexName,
                               const std::string *value);
    OpOQuery* queryOrGreater(const std::string *indexName,
                             const std::string *value);
    OpOQuery* queryOrGreaterEqual(const std::string *indexName,
                                  const std::string *value);
    OpOQuery* queryOrLike(const std::string *indexName,
                          const std::string *value);
    OpOQuery* orderByIndexName(const std::string *indexName);
    OpOQuery* orderByDESC(const std::string *indexName);
    u_int32_t count();
    std::list<std::string *> *fetch();
    std::list<std::string *> *fetch(u_int32_t limit);
    std::list<std::string *> *fetch(u_int32_t limit,
                                   u_int32_t skip);
    std::map<std::string*, std::string*> *fetchFirst();
    void remove();
    virtual ~OpOQuery();
private:
    std::list<std::string *> *m_queries;
    OpOCollection *m_collection;
};

NS_OPODB_END

#endif /* defined(__OpODB__OpOQuery__) */
