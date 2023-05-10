/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <udp-connections-serialize/server_out.h>

#include <flood/out_stream.h>

int udpConnectionsSerializeServerOutChallengeResponse(FldOutStream* outStream,
                                                      UdpConnectionsSerializeClientNonce clientId,
                                                      UdpConnectionsSerializeServerChallenge challenge)
{
    udpConnectionsSerializeCmd(outStream, UdpConnectionsSerializeCmdChallengeResponse);
    udpConnectionsSerializeWriteClientNonce(outStream, clientId);
    return udpConnectionsSerializeWriteServerChallenge(outStream, challenge);
}

int udpConnectionsSerializeServerOutConnectResponse(FldOutStream* outStream,
                                                    UdpConnectionsSerializeClientNonce clientId,
                                                    UdpConnectionsSerializeConnectionId connectionId)
{
    udpConnectionsSerializeCmd(outStream, UdpConnectionsSerializeCmdConnectResponse);
    udpConnectionsSerializeWriteClientNonce(outStream, clientId);
    return udpConnectionsSerializeWriteConnectionId(outStream, connectionId);
}

int udpConnectionsSerializeServerOutPacketHeader(struct FldOutStream* outStream,
                                                 UdpConnectionsSerializeConnectionId connectionId, uint16_t octetCount)
{
    udpConnectionsSerializeCmd(outStream, UdpConnectionsSerializeCmdPacketToClient);
    udpConnectionsSerializeWriteConnectionId(outStream, connectionId);
    return fldOutStreamWriteUInt16(outStream, octetCount);
}
