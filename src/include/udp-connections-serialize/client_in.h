/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef UDP_CONNECTIONS_SERIALIZE_CLIENT_IN_H
#define UDP_CONNECTIONS_SERIALIZE_CLIENT_IN_H

#include <stddef.h>
#include <stdint.h>
#include <udp-connections-serialize/serialize.h>

struct FldInStream;

int udpConnectionsSerializeClientInChallengeResponse(struct FldInStream* inStream,
                                                     UdpConnectionsSerializeClientNonce* clientId,
                                                     UdpConnectionsSerializeServerChallenge* challenge);

int udpConnectionsSerializeClientInConnectResponse(struct FldInStream* inStream,
                                                   UdpConnectionsSerializeClientNonce* clientId,
                                                   UdpConnectionsSerializeConnectionId* connectionId);

int udpConnectionsSerializeClientInPacket(struct FldInStream* inStream,
                                                   UdpConnectionsSerializeConnectionId* connectionId,
                                                   uint16_t* octetCount);

#endif
