//
//  OpODBSchema.cpp
//  OpODB
//
//  Created by BruceZCQ on 14-3-25.
//  Copyright (c) 2014年 OpeningO,Inc (http://openingo.github.io/). All rights reserved.
//

#include "OpODBSchema.h"
#include "OpODBIndex.h"
#include "OpODBDate.h"

NS_OPODB_BEGIN

OpODBSchema::OpODBSchema(void *data,
                         u_int offset)
{
    const u_char *buffer = (u_char *)data;
    memcpy(&m_previousOffsetInFile, buffer, sizeof(unsigned));
    memcpy(&m_nextOffsetInFile, &buffer[4], sizeof(unsigned));
//todo
    m_name = new std::string();
    m_offsetInFile = offset;
    std::string opoDbKey(OPODB_KEY);
    m_unique = m_name->compare(OPODB_KEY) == 0;
    if (m_unique) {
        m_schemaType = SchemaTypeString;
        m_indexKey = new std::map<std::string*,OpODBKey*>;
    }else{
        m_schemaType =  SchemaTypeUnKnow;
        m_indexNULL = new std::list<std::string*>;
        m_index = new std::list<OpODBIndex*>;
    }
}

OpODBSchema::OpODBSchema(std::string *name,
                         u_int previoudOffser,
                         u_int nextOffser)
{
    if (name == nullptr || name->length() == 0) {
        return;
    }
    
    m_previousOffsetInFile = previoudOffser;
    m_nextOffsetInFile = nextOffser;
    m_name = name;
    m_unique = m_name->compare(OPODB_KEY) == 0;
    if (m_unique) {
        m_schemaType = SchemaTypeString;
        m_indexKey = new std::map<std::string*, OpODBKey*>;
    }else{
        m_schemaType = SchemaTypeUnKnow;
        m_indexNULL = new std::list<std::string*>;
        m_index = new std::list<OpODBIndex*>;
    }
}

bool
OpODBSchema::getUnique()
{
    return m_unique;
}

std::string*
OpODBSchema::getName()
{
    return m_name;
}

OpODBSchemaType
OpODBSchema::getShemaType()
{
    return m_schemaType;
}

void*
OpODBSchema::dataFormate()
{
    const char* nameData = m_name->c_str();
    unsigned int previous = m_previousOffsetInFile;
    unsigned int next = m_nextOffsetInFile;
    char *result = nullptr;
    
    result = (char*)malloc(sizeof(char*)+sizeof(unsigned int)+sizeof(unsigned int));
    
    sprintf(result, "%d%d%zu%s",previous,next,strlen(nameData),nameData);
    
    return result;
}

bool
OpODBSchema::pushKey(std::string *key,
                     OpODBKey *opoDbKey)
{
    std::map<std::string*,OpODBKey*>::iterator i;
    for (i = m_indexKey->begin(); i != m_indexKey->end(); i++) {
        if (key->compare(*i->first) == 0) {
            return false;
        }
    }
    m_indexKey->insert(std::pair<std::string*, OpODBKey*>(key,opoDbKey));
    return true;
}

void
OpODBSchema::pushIndex(std::string *key,
                       std::string *value)
{
    if (value == nullptr || value == NULL) {
        m_indexNULL->push_back(key);
        return;
    }
    
    switch (m_schemaType) {
        default:
        case SchemaTypeUnKnow:
        {
            if (typeid(value) == typeid(123)) {
                m_schemaType = SchemaTypeNumber;
            }else if (typeid(value) == typeid("zcq")){
                m_schemaType = SchemaTypeString;
            }else if (typeid(value) == typeid(OpODBDate)){
                m_schemaType = SchemaTypeDate;
            }else{
                throw "insert other type data";
            }
        }
        case SchemaTypeNumber:
        case SchemaTypeString:
        case SchemaTypeDate:
        {
            
        }
            break;
            
    }
}

void
OpODBSchema::insertIndexIntoArrayWithSort(std::list<OpODBIndex*> *array,
                                          std::string *key,
                                          std::string* insertValue,
                                          OpODBSchemaType schemaType)
{
    ComparisonResult compResult;
    
    OpODBIndex *opoIndex = nullptr;
    
    switch (array->size()) {
        case 0U:
            array->push_back(new OpODBIndex(insertValue,key));
            return;
        case 1U:{
            compResult = compare(opoIndex->getValue(), insertValue, schemaType);
            opoIndex = array->front();
            switch (compResult) {
                case OrderedAscending:{
                    array->push_back(new OpODBIndex(insertValue,key));
                }
                    break;
                    
                case OrderedDescending:{
                    opoIndex->getKeySet()->insert(key);
                }
                    break;
                case OrderedSame:{
                    array->push_front(new OpODBIndex(insertValue,key));
                }
                    break;
            }
        }
        default:
            break;
    }
    return;
    
    opoIndex = array->front();
    compResult = compare(opoIndex->getValue(), insertValue, schemaType);
    if (compResult == OrderedDescending) {
        array->push_front(new OpODBIndex(insertValue,key));
        return;
    }else if (compResult == OrderedSame){
        opoIndex->getKeySet()->insert(key);
        return;
    }
    
    opoIndex = array->back();
    compResult = compare(opoIndex->getValue(), insertValue, schemaType);
    if (compResult == OrderedAscending) {
        array->push_back(new OpODBIndex(insertValue,key));
        return;
    }else if (compResult == OrderedSame){
        opoIndex->getKeySet()->insert(key);
        return;
    }
    
    unsigned int upBound = 1U;
    unsigned int downBound = array->size() - 2U;
    unsigned int targetIndex = (upBound + downBound) / 2U;
    
    //find target
    unsigned int aimIndex = 0;
    OpODBIndex *target = nullptr;
    for (auto i = array->begin();
         i!=array->end(); i++,aimIndex++) {
        if (aimIndex == targetIndex) {
            target = *i;
            break;
        }
    }
    
    while (upBound <= downBound) {
        compResult = compare(target->getValue(),insertValue,schemaType);
        switch (compResult) {
            case OrderedSame:{
                target->getKeySet()->insert(key);
            }
                break;
            case OrderedAscending:{
                downBound = targetIndex - 1U;
                targetIndex = (upBound + downBound) / 2U;
            }
                break;
            case OrderedDescending:{
                upBound = targetIndex + 1U;
                targetIndex = (upBound + downBound) / 2U;
                if (targetIndex < upBound) {
                    targetIndex = upBound;
                }
            }
                break;
            default:
                break;
        }
    }
    
    aimIndex = 0;
    std::list<OpODBIndex*>::iterator targetIterator ;
    for (auto i = array->begin();
         i!=array->end(); i++,aimIndex++) {
        if (aimIndex == upBound) {
            targetIterator = i;
            break;
        }
    }
    array->insert(++targetIterator, new OpODBIndex(insertValue,key));
}

ComparisonResult
OpODBSchema::compare(std::string* value1,
                             std::string* value2,
                             OpODBSchemaType schemaType)
{
    ComparisonResult result = OrderedAscending;
    switch (schemaType) {
        case SchemaTypeString:{
            result = (ComparisonResult)value1->compare(*value2);
        }
            break;
        case SchemaTypeNumber:{
            if (typeid(value1) == typeid(123)) {//int
                result = (std::stoi(value1->c_str()) > std::stoi(value2->c_str()))?OrderedDescending:OrderedAscending;
            }else if (typeid(value1) == typeid(123.00)){//double
                result = (std::stof(value1->c_str())> std::atof(value2->c_str())?
                          OrderedDescending:OrderedAscending);
            }
        }
            break;
        case SchemaTypeDate:{
            //todo
        }
            break;
        default:
            break;
    }
    return result;
}

std::map<std::string*, OpODBKey*>*
OpODBSchema::allKeys()
{
    return m_indexKey;
}

std::list<std::string *>*
OpODBSchema::allNULLIndexes()
{
    return m_indexNULL;
}

std::list<OpODBIndex*>*
OpODBSchema::allNotNULLIndexes()
{
    return m_index;
}

void
OpODBSchema::removeWithKey(std::string *key)
{
    m_indexKey->erase(key);
    std::list<std::string*>::iterator i_null ;
    for (i_null = m_indexNULL->begin(); i_null != m_indexNULL->end(); i_null++) {
        if ((*i_null)->compare(*key) == 0) {
            m_indexNULL->erase(i_null);
            return;
        }
    }

    std::list<OpODBIndex*>::iterator i_not_null;
    for (i_not_null = m_index->begin();i_not_null != m_index->end() ; i_not_null++) {
        OpODBIndex *index = *i_not_null;
//        index->getKeySet()->
//        if (相交)
        {
            index->getKeySet()->erase(key);
            if (index->getKeySet()->size() == 0U) {
                m_index->erase(i_not_null);
            }
        }
    }
}

void
OpODBSchema::removeALl()
{
    m_index->clear();
    m_indexKey->clear();
    m_indexNULL->clear();
}

void
OpODBSchema::close()
{
    
}

unsigned
OpODBSchema::getOffsetInFile()
{
    return m_offsetInFile;
}

void
OpODBSchema::setOffsetInFile(unsigned offsetInfile)
{
    m_offsetInFile = offsetInfile;
}

unsigned
OpODBSchema::getPreviousOffsetInFile()
{
    return m_previousOffsetInFile;
}

void
OpODBSchema::setPreviousOffsetInFile(unsigned previousOffsetInFile)
{
    m_previousOffsetInFile = previousOffsetInFile;
}

unsigned
OpODBSchema::getNextOffsetInFile()
{
    return m_nextOffsetInFile;
}

void
OpODBSchema::setNextOffsetInFile(unsigned nextOffsetInFile)
{
    m_nextOffsetInFile = nextOffsetInFile;
}

OpODBSchema::~OpODBSchema()
{
    delete m_name;
    this->release();
}

NS_OPODB_END