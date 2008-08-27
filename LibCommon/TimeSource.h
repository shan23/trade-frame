#pragma once

#include "boost/date_time/posix_time/posix_time.hpp"
using namespace boost::posix_time;
using namespace boost::gregorian;

class CTimeSource : boost::noncopyable {
public:
  CTimeSource(void);
  ~CTimeSource(void);
  static ptime External( void ) { return boost::posix_time::microsec_clock::local_time(); };
  static ptime Internal( void ) { 
    if ( m_bInSimulation ) 
      return m_dtSimulationTime;
    else 
      return External(); 
  };
  static void SetSimulationMode( void ) { m_bInSimulation = true; m_dtSimulationTime = boost::date_time::not_a_date_time; };
  static void ResetSimulationMode( void ) { m_bInSimulation = false; };
  static bool GetSimulationMode( void ) { return m_bInSimulation; };
  static void SetSimulationTime( const ptime &dt ) { m_bInSimulation = true; m_dtSimulationTime = dt; };
protected:
  static bool m_bInSimulation;
  static ptime m_dtSimulationTime;
private:
};
