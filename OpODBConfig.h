//
//  OpODBConfig.h
//  OpODB
//
//  Created by BruceZCQ on 14-3-25.
//  Copyright (c) 2014年 OpeningO,Inc (http://openingo.github.io/). All rights reserved.
//

#ifndef OpODB_OpODBConfig_h
#define OpODB_OpODBConfig_h

#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <set>
#include <string>

#define NS_OPODB_BEGIN    namespace opodb{
#define NS_OPODB_END      }
#define USING_NS_OPODB    using namepace opodb

#define OPODB_CACHE_LIMIT       100
#define OPODB_PRODUCT           "OpODB"
#define OPODB_HEADER            "OpODB "
#define OPODB_HEADER_LENGTH     6
#define OPODB_SCHEME            "shema"
#define OPODB_INDEX             "index"
#define OPODB_DOCUMENT          "document"
#define OPODB_KEY               "key"

#define OPODB_STRINGMAP_TYPE          std::map<std::string*, std::string*>
#define OPODB_STRINGMAP_POINTER       std::map<std::string*, std::string*>*
#define OPODB_SCHEMAMAP_TYPE          std::map<std::string*, OpODBSchema*>
#define OPODB_SCHEMAMAP_POINTER       std::map<std::string*, OpODBSchema*>*

#if defined (__GNUC__) && (__GNUC__ >= 4)
#define OPODB_ATTRIBUTES(attr, ...) __attribute__((attr, ##__VA_ARGS__))
#else
#define OPODB_ATTRIBUTES(attr, ...)
#endif
#define OPODB_BURST_LINK static __inline__ OPODB_ATTRIBUTES(always_inline)

#endif
