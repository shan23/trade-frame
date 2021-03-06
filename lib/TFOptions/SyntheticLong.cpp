/************************************************************************
 * Copyright(c) 2019, One Unified. All rights reserved.                 *
 * email: info@oneunified.net                                           *
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

/* 
 * File:    SyntheticLong.cpp
 * Author:  raymond@burkholder.net
 * Project: TFOptions
 * Created on June 23, 2019, 10:49 AM
 */

#include <array>

#include "LegDef.h"
#include "SyntheticLong.h"

namespace ou { // One Unified
namespace tf { // TradeFrame
namespace option { // options
namespace spread { // spread

namespace {

  static const size_t nStrikes( 2 );
  static const boost::gregorian::days nDaysToExpiry( 1 );

  using LegDef = ou::tf::option::LegDef;
  using rLegDef_t = std::array<LegDef,nStrikes>;

  static const rLegDef_t m_rLegDefLong = {
    LegDef( LegDef::EOrderSide::Buy,  1, LegDef::EOptionSide::Call ),
    LegDef( LegDef::EOrderSide::Sell, 1, LegDef::EOptionSide::Put )
  };

  static const rLegDef_t m_rLegDefShort = {
    LegDef( LegDef::EOrderSide::Sell, 1, LegDef::EOptionSide::Call ),
    LegDef( LegDef::EOrderSide::Buy,  1, LegDef::EOptionSide::Put )
  };

}

SyntheticLong::SyntheticLong( )
: Combo()
{
}

SyntheticLong::SyntheticLong( SyntheticLong&& rhs )
: Combo( std::move( rhs ) )
{
}

SyntheticLong::~SyntheticLong( ) { }

SyntheticLong::strike_pair_t SyntheticLong::ChooseStrikes( const Chain& chain, double price ) {

  double strikeItmCall {};
  double strikePut {};

  strikeItmCall = chain.Call_Itm( price );
  strikePut = strikeItmCall;

  return strike_pair_t( strikeItmCall, strikePut );
}

} // namespace spread
} // namespace option
} // namespace tf
} // namespace ou

