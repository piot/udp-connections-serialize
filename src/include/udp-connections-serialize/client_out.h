/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef UDP_CONNECTIONS_SERIALIZE_CLIENT_OUT_H
#define UDP_CONNECTIONS_SERIALIZE_CLIENT_OUT_H

#include <stdint.h>
#include <stddef.h>

#include <udp-connections-serialize/serialize.h>

struct FldOutStream;

int udpConnectionsSerializeClientOutChallenge(struct FldOutStream *outStream, UdpConnectionsSerializeClientNonce nonce);
int udpConnectionsSerializeClientOutConnect(struct FldOutStream *outStream,  UdpConnectionsSerializeClientNonce nonce, UdpConnectionsSerializeServerChallenge serverChallenge);
int udpConnectionsSerializeClientOutPacketHeader(struct FldOutStream *outStream, UdpConnectionsSerializeConnectionId connectionId, uint16_t octetCountFollowing);

#endif
