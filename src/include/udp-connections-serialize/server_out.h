/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef UDP_CONNECTIONS_SERIALIZE_SERVER_OUT_H
#define UDP_CONNECTIONS_SERIALIZE_SERVER_OUT_H

#include <stddef.h>
#include <stdint.h>
#include <udp-connections-serialize/serialize.h>

struct FldOutStream;

int udpConnectionsSerializeServerOutConnectResponse(struct FldOutStream* outStream,
                                                    UdpConnectionsSerializeClientNonce clientId,
                                                    UdpConnectionsSerializeConnectionId connectionId);
int udpConnectionsSerializeServerOutChallengeResponse(struct FldOutStream* outStream,
                                                      UdpConnectionsSerializeClientNonce clientId,
                                                      UdpConnectionsSerializeServerChallenge challenge);

int udpConnectionsSerializeServerOutPacketHeader(struct FldOutStream* outStream,
                                                 UdpConnectionsSerializeConnectionId connectionId, uint16_t octetCount);
#endif
