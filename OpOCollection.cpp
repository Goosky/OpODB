//
//  OpOCollection.cpp
//  OpODB
//
//  Created by BruceZCQ on 14-3-24.
//  Copyright (c) 2014年 OpeningO,Inc (http://openingo.github.io/). All rights reserved.
//

#include "OpOCollection.h"
#include "OpODBSchema.h"

NS_OPODB_BEGIN

OpOCollection::OpOCollection(const std::string *name,
                             const std::string *databasepath)
{
    m_name = name;
    m_idCount = 0U;
    char m_databasepath[ 1024 ] = {0};
    sprintf(m_databasepath, "%s%s",m_name->c_str(),OPODB_INDEX);
    m_indexFilePath = new std::string(m_databasepath);
    
    sprintf(m_databasepath, "%s%s",m_name->c_str(),OPODB_SCHEME);
    m_schemaFilePath = new std::string(m_databasepath);
    
    sprintf(m_databasepath, "%s%s",m_name->c_str(),OPODB_DOCUMENT);
    m_indexFilePath = new std::string(m_databasepath);
    
    //delete old files
    //create file
    m_schemas = new std::map<std::string*, OpODBSchema *>;
}

std::vector<std::string*> * OpOCollection::allIndexes()
{
    std::vector<std::string*> *keys = new std::vector<std::string*>;
    for (auto i = m_schemas->begin(); i != m_schemas->end(); i++) {
        keys->push_back(i->first);
    }
    return keys;
}

void
OpOCollection::createIndex(std::string *indexName)
{
    if (indexName == nullptr
        || indexName == NULL
        || indexName->length()) {
        return;
    }
    //in thread
    do {
        
        //exist
        std::vector<std::string*> *allIndex = allIndexes();
        for (auto i = allIndex->begin(); i != allIndex->end(); i++) {
            if (indexName->compare(**i) == 0) {
                return;
            }
        }
        
        auto mapIt = m_schemas->end();
        OpODBSchema *lastSchema = (OpODBSchema*)(--mapIt)->second;
        unsigned previous = 0U;
        if (lastSchema) {
            previous = lastSchema->getOffsetInFile();
        }
        
        //NSFileHandle *file = [NSFileHandle fileHandleForWritingAtPath:_schemaFilePath];
        OpODBSchema *schema = new OpODBSchema(indexName,previous,0U);
        //    schema.offsetInFile = [file seekToEndOfFile];
        //    [file writeData:schema.dataFormate];
        if (lastSchema) {
            unsigned offset = schema->getOffsetInFile();
            lastSchema->setNextOffsetInFile(offset);
            //        [file seekToFileOffset:lastSchema.offsetInFile + 4];
            //        [file writeData:[NSData dataWithBytes:&offset length:sizeof(offset)]];
        }
        //            [file closeFile];
        m_schemas->insert(std::pair<std::string*, OpODBSchema*>(schema->getName(),schema));
        //load
    } while (0);
}

void
OpOCollection::loadIndexForSchema(OpODBSchema *schema,
                                         std::map<std::string*, OpODBSchema*> *schemas,
                                         std::list<std::string*> *clearedIndexBock,
                                         std::string *indexFilePath,
                                         std::string *documentFilePath)
{
    if (schema->getUnique()) {
        return;
    }
    
    
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
OpOCollection::removeByQuery(const std::list<OpOQueryCell*> *queries)
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
OpOCollection::countByQuery(const std::list<OpOQueryCell *> *queries)
{
    return 0;
}

std::list<OPODB_MAP>*
OpOCollection::fetchByQuery(const std::list<OpOQueryCell *> *queries,
                            const u_int32_t skip,
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