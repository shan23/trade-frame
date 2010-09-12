/************************************************************************
 * Copyright(c) 2009, One Unified. All rights reserved.                 *
 *                                                                      *
 * This file is provided as is WITHOUT ANY WARRANTY                     *
 *  without even the implied warranty of                                *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                *
 *                                                                      *
 * This software may not be used nor distributed without proper license *
 * agreement.                                                           *
 *                                                                      *
 * See the file LICENSE.txt for redistribution information.             *
 ************************************************************************/

#pragma once

#include <db4/db_cxx.h>
//#include <db4/dbstl_common.h>

#include <LibCommon/Singleton.h>

// handles the environment oriented stuff

// http://www.oracle.com/technology/documentation/berkeley-db/db/ref/toc.html
// http://www.oracle.com/technology/documentation/berkeley-db/db/api_cxx/frame.html

// review the database instructions if we happen to do database stuff cross thread
// see cpp file

// CBerkeleyDBEnvManager =====

//class CBerkeleyDBEnvManager: public CMultipleInstanceTest<CBerkeleyDBEnvManager> {
class CBerkeleyDBEnvManager: public CSingleton<CBerkeleyDBEnvManager> {
public:

  CBerkeleyDBEnvManager(void);
  ~CBerkeleyDBEnvManager(void);

  inline DbEnv *GetDbEnv( void ) { 
    return m_pDbEnv; 
  }; 

  const char *GetBDBFileName( void ) { return m_BDBFileName; };

protected:

  static const char m_BDBFileName[];
  DbEnv* m_pDbEnv;

private:

};

//
// ==== singleton
//
/*
class CBerkeleyDBEnvManagerSingleton: public CSingleton<CBerkeleyDBEnvManager> {
public:
protected:
private:
};
*/