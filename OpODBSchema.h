//
//  OpODBSchema.h
//  OpODB
//
//  Created by BruceZCQ on 14-3-25.
//  Copyright (c) 2014年 OpeningO,Inc (http://openingo.github.io/). All rights reserved.
//

#ifndef __OpODB__OpODBSchema__
#define __OpODB__OpODBSchema__

#include "OpODBConfig.h"
#include "OpODBBase.h"

NS_OPODB_BEGIN

class OpODBKey;
class OpODBIndex;
class OpODBDate;

enum OpODBSchemaType {
    SchemaTypeNumber = 0U,
    SchemaTypeString = 1U,
    SchemaTypeDate = 2U,
    SchemaTypeNULL = 3U,
    SchemaTypeUnKnow = 4U
    };

enum ComparisonResult {
    OrderedAscending = -1L,
    OrderedSame,
    OrderedDescending
    };

class OpODBSchema : public OpODBBase
{
public:
    OpODBSchema(void *data,
                u_int offset);
    OpODBSchema(std::string *name,
                unsigned previoudOffser,
                unsigned nextOffser);
    bool getUnique();
    std::string *getName();
    OpODBSchemaType getShemaType();
    void *dataFormate();
    bool pushKey(std::string *key,
                 OpODBKey *opoDbKey);
    void pushIndex(std::string *key,
                   std::string* value);
    std::map<std::string*, OpODBKey*> *allKeys();
    std::list<std::string *> *allNULLIndexes();
    std::list<OpODBIndex*> *allNotNULLIndexes();
    void removeWithKey(std::string *key);
    void removeALl();
    void close();
    virtual ~OpODBSchema();
private:
    OPODB_BURST_LINK void insertIndexIntoArrayWithSort(std::list<OpODBIndex*> *array,
                                                       std::string *key,
                                                       std::string* insertValue, OpODBSchemaType schemaType);
    OPODB_BURST_LINK ComparisonResult compare(std::string* value1,
                                                std::string* value2,
                                                OpODBSchemaType schemaType);
    unsigned m_offsetInFile;
    unsigned m_previousOffsetInFile;
    unsigned m_nextOffsetInFile;
    std::string *m_name;
    bool m_unique;
    OpODBSchemaType m_schemaType;
    std::map<std::string*, OpODBKey*> *m_indexKey;
    std::list<std::string *> *m_indexNULL;
    std::list<OpODBIndex*> *m_index;
};

NS_OPODB_END

#endif /* defined(__OpODB__OpODBSchema__) */
