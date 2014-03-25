//
//  OpOCollection.cpp
//  OpODB
//
//  Created by BruceZCQ on 14-3-24.
//  Copyright (c) 2014年 OpeningO,Inc (http://openingo.github.io/). All rights reserved.
//

#include "OpOCollection.h"

NS_OPODB_BEGIN

OpOCollection::OpOCollection(const std::string *name,
                                             const std::string *databasepath)
{
    m_name = name;
}

std::list<std::string> * OpOCollection::allIndexes()
{
    return nullptr;
}

void
OpOCollection::createIndex(const std::string *indexName)
{
    
}

void
OpOCollection::removeIndex(const std::string *indexName)
{
    
}

void
OpOCollection::remoteAllIndexes()
{
    
}

std::map<std::string, std::string>*
OpOCollection::put(std::map<std::string*,std::string*> *document)
{
    return nullptr;
}

void
OpOCollection::waitForWriting()
{
    
}

void
OpOCollection::removeBykey(const std::string *documentKey)
{
    
}

void
OpOCollection::removeByQuery(const std::list<std::string*> *queries)
{
    
}

void OpOCollection::removeAll()
{
    
}

void OpOCollection::clearCache()
{
    
}

OpOQuery*
OpOCollection::query()
{
    return nullptr;
}

OpOQuery*
OpOCollection::all()
{
    return nullptr;
}

OpOQuery*
OpOCollection::whereEqual(const std::string *indexName,
                          const std::string *value)
{
    return nullptr;
}

OpOQuery*
OpOCollection::whereNotEqual(const std::string *indexName,
                             const std::string *value)
{
    return nullptr;
}

OpOQuery*
OpOCollection::whereLess(const std::string *indexName,
                         const std::string *value)
{
    return nullptr;
}

OpOQuery*
OpOCollection::whereLessEqual(const std::string *indexName,
                              const std::string *value)
{
    return nullptr;
}

OpOQuery*
OpOCollection::whereGreater(const std::string *indexName,
                            const std::string *value)
{
    return nullptr;
}

OpOQuery*
OpOCollection::whereGreaterEqual(const std::string *indexName,
                                 const std::string *value)
{
    return nullptr;
}

OpOQuery*
OpOCollection::whereLike(const std::string *indexName,
                         const std::string *value)
{
    return nullptr;
}

u_int32_t
OpOCollection::count()
{
    return 0;
}

u_int32_t
OpOCollection::countByQuery(const std::list<std::string *> *queries)
{
    return 0;
}

std::list<std::string *>*
OpOCollection::fetchByQuery(const std::list<std::string *> *queries,
                            const u_int32_t kip,
                            const u_int32_t limit)
{
    return nullptr;
}

void
OpOCollection::removeCollectionFiles()
{
    
}

void
OpOCollection::close()
{
    
}

std::map<std::string *, std::string *>*
OpOCollection::schemas()
{
    return nullptr;
}


const std::string*
OpOCollection::getName() const
{
    return m_name;
}

OpOCollection::~OpOCollection()
{
    delete m_documentFilePath;
    delete m_indexFilePath;
    delete m_name;
    delete m_schemaFilePath;
    this->release();
}

NS_OPODB_END