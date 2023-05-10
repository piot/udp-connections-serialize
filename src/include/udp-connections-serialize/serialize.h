/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef UDP_CONNECTIONS_SERIALIZE_SERIALIZE_H
#define UDP_CONNECTIONS_SERIALIZE_SERIALIZE_H

#define UdpConnectionsSerializeCmdChallenge (0x01)
#define UdpConnectionsSerializeCmdConnect (0x02)
#define UdpConnectionsSerializeCmdPacket (0x03)

#define UdpConnectionsSerializeCmdChallengeResponse (0x11)
#define UdpConnectionsSerializeCmdConnectResponse (0x12)
#define UdpConnectionsSerializeCmdPacketToClient (0x13)

#include <stdint.h>

typedef uint64_t UdpConnectionsSerializeConnectionId;
typedef uint64_t UdpConnectionsSerializeClientNonce;
typedef uint64_t UdpConnectionsSerializeServerChallenge;

struct FldOutStream;
struct FldInStream;

int udpConnectionsSerializeWriteConnectionId(struct FldOutStream* outStream, UdpConnectionsSerializeConnectionId id);
int udpConnectionsSerializeReadConnectionId(struct FldInStream* inStream, UdpConnectionsSerializeConnectionId* id);

int udpConnectionsSerializeWriteClientNonce(struct FldOutStream* outStream, UdpConnectionsSerializeClientNonce id);
int udpConnectionsSerializeReadClientNonce(struct FldInStream* inStream, UdpConnectionsSerializeClientNonce* id);

int udpConnectionsSerializeWriteServerChallenge(struct FldOutStream* outStream, UdpConnectionsSerializeServerChallenge id);
int udpConnectionsSerializeReadServerChallenge(struct FldInStream* inStream, UdpConnectionsSerializeServerChallenge* id);

int udpConnectionsSerializeCmd(struct FldOutStream* outStream, uint8_t cmd);

#endif
