//
//  OpOCollection.h
//  OpODB
//
//  Created by BruceZCQ on 14-3-24.
//  Copyright (c) 2014年 OpeningO,Inc (http://openingo.github.io/). All rights reserved.
//

#ifndef __OpODB__OpOCollection__
#define __OpODB__OpOCollection__

#include "OpODBConfig.h"
#include "OpODBBase.h"

NS_OPODB_BEGIN

class OpOQuery;
class OpOQueryCell;
class OpODBSchema;

class OpOCollection : public OpODBBase
{
public:
    OpOCollection(const std::string *name,
                  const std::string *databasepath);
    std::vector<std::string*> *allIndexes(OPODB_SCHEMAMAP_POINTER schemas);
    std::vector<std::string*> *allIndexes(OPODB_STRINGMAP_POINTER schemas);
    void createIndex(std::string *indexName);
    void removeIndex(std::string *indexName);
    void remoteAllIndexes();
    OPODB_STRINGMAP_POINTER put(OPODB_STRINGMAP_POINTER document);
    void waitForWriting();
    void removeBykey(const std::string *documentKey);
    void removeByQuery(const std::list<OpOQueryCell*> *queries);
    void removeAll();
    void clearCache();
    OpOQuery *query();
    OpOQuery *all();
    OpOQuery *whereEqual(const std::string *indexName,
                         const std::string *value);
    OpOQuery *whereNotEqual(const std::string *indexName,
                            const std::string *value);
    OpOQuery *whereLess(const std::string *indexName,
                        const std::string *value);
    OpOQuery *whereLessEqual(const std::string *indexName,
                             const std::string *value);
    OpOQuery *whereGreater(const std::string *indexName,
                           const std::string *value);
    OpOQuery *whereGreaterEqual(const std::string *indexName,
                                const std::string *value);
    OpOQuery *whereLike(const std::string *indexName,
                        const std::string *value);
    u_int32_t count();
    u_int32_t countByQuery(const std::list<OpOQueryCell*> *queries);
    std::list<OPODB_SCHEMAMAP_POINTER> *fetchByQuery(const std::list<OpOQueryCell *> *queries,
                                         const u_int32_t skip,
                                         const u_int32_t limit);
    void removeCollectionFiles();
    void close();
    OPODB_SCHEMAMAP_POINTER schemas();
    const std::string *getName() const;
    virtual ~OpOCollection();
private:
    OPODB_BURST_LINK void loadIndexForSchema(OpODBSchema *schema,
                                             OPODB_SCHEMAMAP_POINTER schemas,
                                             std::list<std::string*> *clearedIndexBock,
                                             std::string *indexFilePath,
                                             std::string *documentFilePath);
    OPODB_SCHEMAMAP_TYPE::iterator findSchemaByKey(std::string *key,
                                             OPODB_SCHEMAMAP_POINTER schemas);
    OPODB_STRINGMAP_TYPE::iterator findSchemaByKey(std::string *key,
                                                   OPODB_STRINGMAP_POINTER schemas);
    OPODB_BURST_LINK char *serialize(OPODB_STRINGMAP_POINTER document);
    std::string *m_documentFilePath;
    std::string *m_schemaFilePath;
    std::string *m_indexFilePath;
    u_int32_t m_idCount;
    const std::string *m_name;
    OPODB_SCHEMAMAP_POINTER m_schemas;
};

NS_OPODB_END

#endif /* defined(__OpODB__OpOCollection__) */
