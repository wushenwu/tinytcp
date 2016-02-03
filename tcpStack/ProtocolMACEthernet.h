//----------------------------------------------------------------------------
// Copyright( c ) 2015, Robert Kimball
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its
//    contributors may be used to endorse or promote products derived from
//    this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//----------------------------------------------------------------------------

#ifndef PROTOCOLMACETHERNET_H
#define PROTOCOLMACETHERNET_H

#include <inttypes.h>
#include "DataBuffer.h"
#include "osQueue.h"
#include "NetworkInterface.h"

#define MAC_HEADER_SIZE (14)

class ProtocolMACEthernet
{
public:
   static void Initialize( NetworkInterface* dataInterface );

   static void ProcessRx( uint8_t* buffer, int length );

   static void Transmit( DataBuffer*, uint8_t* targetMAC, uint16_t type );
   static void Retransmit( DataBuffer* buffer );

   static DataBuffer* GetTxBuffer();
   static void FreeTxBuffer( DataBuffer* );
   static void FreeRxBuffer( DataBuffer* );
   static bool IsLocalAddress( uint8_t* addr );

   static void Show( osPrintfInterface* pfunc );

   static int HeaderSize()
   {
      return MAC_HEADER_SIZE;
   }
private:
   static osQueue TxBufferQueue;
   static osQueue RxBufferQueue;
   static NetworkInterface* DataInterface;

   ProtocolMACEthernet( ProtocolMACEthernet& );
   ProtocolMACEthernet();
};

#endif
