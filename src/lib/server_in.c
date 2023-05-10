/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <flood/in_stream.h>
#include <udp-connections-serialize/server_in.h>

int udpConnectionsSerializeServerInChallenge(FldInStream* inStream, UdpConnectionsSerializeClientNonce* clientNonce)
{
    return udpConnectionsSerializeReadClientNonce(inStream, clientNonce);
}

int udpConnectionsSerializeServerInConnect(FldInStream* inStream, UdpConnectionsSerializeClientNonce* clientNonce,
                                           UdpConnectionsSerializeServerChallenge* serverChallenge)
{
    udpConnectionsSerializeReadClientNonce(inStream, clientNonce);
    return udpConnectionsSerializeReadServerChallenge(inStream, serverChallenge);
}

int udpConnectionsSerializeServerInPacketFromClient(struct FldInStream* inStream,
                                                    UdpConnectionsSerializeConnectionId* connectionId,
                                                    uint16_t* octetCount)
{
    udpConnectionsSerializeReadConnectionId(inStream, connectionId);
    return fldInStreamReadUInt16(inStream, octetCount);
}
