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

#ifndef IMC_LEDBRIGHTNESS_HPP_INCLUDED_
#define IMC_LEDBRIGHTNESS_HPP_INCLUDED_

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
  //! LED Brightness.
  class LedBrightness: public Message
  {
  public:
    //! Name.
    std::string name;
    //! Value.
    uint8_t value;

    static uint16_t
    getIdStatic(void)
    {
      return 312;
    }

    static LedBrightness*
    cast(Message* msg__)
    {
      return (LedBrightness*)msg__;
    }

    LedBrightness(void)
    {
      m_header.mgid = LedBrightness::getIdStatic();
      clear();
    }

    LedBrightness*
    clone(void) const
    {
      return new LedBrightness(*this);
    }

    void
    clear(void)
    {
      name.clear();
      value = 0;
    }

    bool
    fieldsEqual(const Message& msg__) const
    {
      const IMC::LedBrightness& other__ = static_cast<const LedBrightness&>(msg__);
      if (name != other__.name) return false;
      if (value != other__.value) return false;
      return true;
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(name, ptr__);
      ptr__ += IMC::serialize(value, ptr__);
      return ptr__;
    }

    size_t
    deserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(name, bfr__, size__);
      bfr__ += IMC::deserialize(value, bfr__, size__);
      return bfr__ - start__;
    }

    size_t
    reverseDeserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::reverseDeserialize(name, bfr__, size__);
      bfr__ += IMC::deserialize(value, bfr__, size__);
      return bfr__ - start__;
    }

    uint16_t
    getId(void) const
    {
      return LedBrightness::getIdStatic();
    }

    const char*
    getName(void) const
    {
      return "LedBrightness";
    }

    size_t
    getFixedSerializationSize(void) const
    {
      return 1;
    }

    size_t
    getVariableSerializationSize(void) const
    {
      return IMC::getSerializationSize(name);
    }

    double
    getValueFP(void) const
    {
      return static_cast<double>(value);
    }

    void
    setValueFP(double val)
    {
      value = static_cast<uint8_t>(val);
    }

    void
    fieldsToJSON(std::ostream& os__, unsigned nindent__) const
    {
      IMC::toJSON(os__, "name", name, nindent__);
      IMC::toJSON(os__, "value", value, nindent__);
    }
  };
}

#endif
