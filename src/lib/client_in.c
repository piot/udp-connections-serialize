/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <flood/in_stream.h>
#include <udp-connections-serialize/client_in.h>

int udpConnectionsSerializeClientInChallengeResponse(FldInStream* inStream,
                                                     UdpConnectionsSerializeClientNonce* clientId,
                                                     UdpConnectionsSerializeServerChallenge* challenge)
{
    udpConnectionsSerializeReadClientNonce(inStream, clientId);
    return udpConnectionsSerializeReadServerChallenge(inStream, challenge);
}

int udpConnectionsSerializeClientInConnectResponse(FldInStream* inStream, UdpConnectionsSerializeClientNonce* clientId,
                                                   UdpConnectionsSerializeConnectionId* connectionId)
{
    udpConnectionsSerializeReadClientNonce(inStream, clientId);
    return udpConnectionsSerializeReadConnectionId(inStream, connectionId);
}

int udpConnectionsSerializeClientInPacket(struct FldInStream* inStream,
                                          UdpConnectionsSerializeConnectionId* connectionId, uint16_t* octetCount)
{
    udpConnectionsSerializeReadConnectionId(inStream, connectionId);
    return fldInStreamReadUInt16(inStream, octetCount);
}
