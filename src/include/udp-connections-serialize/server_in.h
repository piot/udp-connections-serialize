/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef UDP_CONNECTIONS_SERIALIZE_SERVER_IN_H
#define UDP_CONNECTIONS_SERIALIZE_SERVER_IN_H

#include <stddef.h>
#include <stdint.h>
#include <udp-connections-serialize/serialize.h>

struct FldInStream;

int udpConnectionsSerializeServerInChallenge(struct FldInStream* inStream,
                                             UdpConnectionsSerializeClientNonce* clientNonce);
int udpConnectionsSerializeServerInConnect(struct FldInStream* inStream,
                                           UdpConnectionsSerializeClientNonce* clientNonce,
                                           UdpConnectionsSerializeServerChallenge* serverChallenge);
int udpConnectionsSerializeServerInPacketFromClient(struct FldInStream* inStream,
                                           UdpConnectionsSerializeConnectionId* connectionId,
                                           uint16_t* octetCount);
#endif
