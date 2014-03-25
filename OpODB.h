//
//  OpODB.h
//  OpODB
//
//  Created by BruceZCQ on 14-3-25.
//  Copyright (c) 2014年 OpeningO,Inc (http://openingo.github.io/). All rights reserved.
//

#ifndef __OpODB__OpODB__
#define __OpODB__OpODB__

#include "OpODBConfig.h"
#include "OpODBBase.h"

NS_OPODB_BEGIN

class OpOCollection;

class OpODB : public OpODBBase
{
public:
    OpODB();
    OpODB(std::string *path);
    std::list<std::string*> *collections();
    OpOCollection *collection(std::string *name);
    void removeCollection(std::string *name);
    void removeAllCollections();
    void close();
    std::string *getDataBasePath();
    virtual ~OpODB();
    static OpODB *instance();
    static void reset();
private:
    static OpODB *m_opoDB;
    std::string *m_databaepath;
    std::map<std::string*,std::string*> *m_collections;
};

NS_OPODB_END

#endif /* defined(__OpODB__OpODB__) */
