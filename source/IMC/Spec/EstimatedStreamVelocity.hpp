//***************************************************************************
// Copyright 2017 OceanScan - Marine Systems & Technology, Lda.             *
//***************************************************************************
// Licensed under the Apache License, Version 2.0 (the "License");          *
// you may not use this file except in compliance with the License.         *
// You may obtain a copy of the License at                                  *
//                                                                          *
// http://www.apache.org/licenses/LICENSE-2.0                               *
//                                                                          *
// Unless required by applicable law or agreed to in writing, software      *
// distributed under the License is distributed on an "AS IS" BASIS,        *
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
// See the License for the specific language governing permissions and      *
// limitations under the License.                                           *
//***************************************************************************
// Author: Ricardo Martins                                                  *
//***************************************************************************
// Automatically generated.                                                 *
//***************************************************************************
// IMC XML MD5: 009a5046be102f40bfccc623630722a7                            *
//***************************************************************************

#ifndef IMC_ESTIMATEDSTREAMVELOCITY_HPP_INCLUDED_
#define IMC_ESTIMATEDSTREAMVELOCITY_HPP_INCLUDED_

// ISO C++ 98 headers.
#include <ostream>
#include <string>
#include <vector>

// IMC headers.
#include <IMC/Base/Config.hpp>
#include <IMC/Base/Message.hpp>
#include <IMC/Base/InlineMessage.hpp>
#include <IMC/Base/MessageList.hpp>
#include <IMC/Base/JSON.hpp>
#include <IMC/Base/Serialization.hpp>
#include <IMC/Spec/Enumerations.hpp>
#include <IMC/Spec/Bitfields.hpp>

namespace IMC
{
  //! Estimated Stream Velocity.
  class EstimatedStreamVelocity: public Message
  {
  public:
    //! X component (North).
    double x;
    //! Y component (East).
    double y;
    //! Z component (Down).
    double z;

    static uint16_t
    getIdStatic(void)
    {
      return 351;
    }

    static EstimatedStreamVelocity*
    cast(Message* msg__)
    {
      return (EstimatedStreamVelocity*)msg__;
    }

    EstimatedStreamVelocity(void)
    {
      m_header.mgid = EstimatedStreamVelocity::getIdStatic();
      clear();
    }

    EstimatedStreamVelocity*
    clone(void) const
    {
      return new EstimatedStreamVelocity(*this);
    }

    void
    clear(void)
    {
      x = 0;
      y = 0;
      z = 0;
    }

    bool
    fieldsEqual(const Message& msg__) const
    {
      const IMC::EstimatedStreamVelocity& other__ = static_cast<const EstimatedStreamVelocity&>(msg__);
      if (x != other__.x) return false;
      if (y != other__.y) return false;
      if (z != other__.z) return false;
      return true;
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(x, ptr__);
      ptr__ += IMC::serialize(y, ptr__);
      ptr__ += IMC::serialize(z, ptr__);
      return ptr__;
    }

    size_t
    deserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(x, bfr__, size__);
      bfr__ += IMC::deserialize(y, bfr__, size__);
      bfr__ += IMC::deserialize(z, bfr__, size__);
      return bfr__ - start__;
    }

    size_t
    reverseDeserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::reverseDeserialize(x, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(y, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(z, bfr__, size__);
      return bfr__ - start__;
    }

    uint16_t
    getId(void) const
    {
      return EstimatedStreamVelocity::getIdStatic();
    }

    const char*
    getName(void) const
    {
      return "EstimatedStreamVelocity";
    }

    size_t
    getFixedSerializationSize(void) const
    {
      return 24;
    }

    void
    fieldsToJSON(std::ostream& os__, unsigned nindent__) const
    {
      IMC::toJSON(os__, "x", x, nindent__);
      IMC::toJSON(os__, "y", y, nindent__);
      IMC::toJSON(os__, "z", z, nindent__);
    }
  };
}

#endif
