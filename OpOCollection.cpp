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
    m_schemas = new OPODB_SCHEMAMAP_TYPE;
}

std::vector<std::string*>*
OpOCollection::allIndexes(OPODB_SCHEMAMAP_POINTER schemas)
{
    std::vector<std::string*> *keys = new std::vector<std::string*>;
    for (auto i = schemas->begin(); i != schemas->end(); i++) {
        keys->push_back(i->first);
    }
    return keys;
}

std::vector<std::string*>*
OpOCollection::allIndexes(OPODB_STRINGMAP_POINTER schemas)
{
    std::vector<std::string*> *keys = new std::vector<std::string*>;
    for (auto i = schemas->begin(); i != schemas->end(); i++) {
        keys->push_back(i->first);
    }
    return keys;
}


OPODB_SCHEMAMAP_TYPE::iterator
OpOCollection::findSchemaByKey(std::string *key,
                               OPODB_SCHEMAMAP_POINTER schemas)
{
    decltype(schemas->begin()) iterator;
    for (auto i = schemas->begin(); i != schemas->end(); i++) {
        if (key->compare(*i->first) == 0) {
            iterator = i;
        }
    }
    return iterator;
}



OPODB_STRINGMAP_TYPE::iterator
OpOCollection::findSchemaByKey(std::string *key,
                                               OPODB_STRINGMAP_POINTER schemas)
{
//    auto iterator = findSchemaByKey(key, schemas);
//    return iterator;
    decltype(schemas->begin()) iterator;
    for (auto i = schemas->begin(); i != schemas->end(); i++) {
        if (key->compare(*i->first) == 0) {
            iterator = i;
        }
    }
    return iterator;
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
//        std::vector<std::string*> *allIndex = allIndexes();
//        for (auto i = allIndex->begin(); i != allIndex->end(); i++) {
//            if (indexName->compare(**i) == 0) {
//                return;
//            }
//        }
        OpODBSchema *findedSchema = findSchemaByKey(indexName,m_schemas)->second;
        if (findedSchema->getName()->compare(*indexName) == 0) {
            return;
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
                                         OPODB_SCHEMAMAP_POINTER schemas,
                                         std::list<std::string*> *clearedIndexBock,
                                         std::string *indexFilePath,
                                         std::string *documentFilePath)
{
    if (schema->getUnique()) {
        return;
    }
    
    
}

void
OpOCollection::removeIndex(std::string *indexName)
{
    std::string key(OPODB_KEY);
    if (indexName->compare(key) == 0) {
        throw "index 'key' could not be remove";
    }
    
    //thread
    do {
        OpODBSchema *schema = findSchemaByKey(indexName,m_schemas)->second;
        if (schema) {
//            NSFileHandle *file = [NSFileHandle fileHandleForWritingAtPath:_schemaFilePath];
            unsigned offset;
            if (schema->getPreviousOffsetInFile() > 0U) {
                offset = schema->getNextOffsetInFile();
//                [file seekToFileOffset:schema.previousOffsetInFile + 4U];
//                [file writeData:[NSData dataWithBytes:&offset length:sizeof(offset)]];
            }else if (schema->getNextOffsetInFile() > 0U){
                offset = schema->getPreviousOffsetInFile();
//                [file seekToFileOffset:schema.nextOffsetInFile];
//                [file writeData:[NSData dataWithBytes:&offset length:sizeof(offset)]];
            }
//                        [file closeFile];
            m_schemas->erase(findSchemaByKey(indexName,m_schemas));
        }
    } while (0);
}

void
OpOCollection::remoteAllIndexes()
{
    std::vector<std::string*> *allkeys = allIndexes(m_schemas);
    for (auto i = allkeys->begin(); i != allkeys->end(); i++) {
        removeIndex(*i);
    }
}

OPODB_STRINGMAP_POINTER
OpOCollection::put(OPODB_STRINGMAP_POINTER document)
{
    if (!document) {
        throw "document could not be nil";
        return nullptr;
    }
    
    OPODB_STRINGMAP_POINTER documentCopy = document;
    std::string *schema = findSchemaByKey(new std::string(OPODB_KEY),documentCopy)->second;
    
    if (schema == NULL || schema == nullptr || schema->length() == 0) {
        do {//thread
//            CFUUIDRef uuid = CFUUIDCreate(NULL);
//            CFStringRef result = CFUUIDCreateString(NULL, uuid);
//            [doc setObject:[NSString stringWithString:(__bridge NSString *)result] forKey:NYARU_KEY];
//            CFRelease(result);
//            CFRelease(uuid);
        } while (0);
    }
    
    
    //serialize document
    
    
    return nullptr;
}

char *
OpOCollection::serialize(OPODB_STRINGMAP_POINTER document)
{
    std::string *key = new std::string("");
    std::string *value = new std::string("");
    unsigned char *buffer = NULL;
    unsigned bufferLen = 0U;
    u_char valueType;
    u_char *bufferValue;
    unsigned bufferValueLen = 0U;
    
//    std::vector<std::string*>* allkeys = allIndexes(document);
    
    
    return 0;
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

std::list<OPODB_SCHEMAMAP_POINTER>*
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

OPODB_SCHEMAMAP_POINTER
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