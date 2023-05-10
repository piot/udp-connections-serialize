/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <flood/out_stream.h>
#include <udp-connections-serialize/client_out.h>

int udpConnectionsSerializeClientOutChallenge(struct FldOutStream* outStream, UdpConnectionsSerializeClientNonce nonce)
{
    udpConnectionsSerializeCmd(outStream, UdpConnectionsSerializeCmdChallenge);
    return udpConnectionsSerializeWriteClientNonce(outStream, nonce);
}

int udpConnectionsSerializeClientOutConnect(FldOutStream* outStream, UdpConnectionsSerializeClientNonce nonce,
                                            UdpConnectionsSerializeServerChallenge serverChallenge)
{
    udpConnectionsSerializeCmd(outStream, UdpConnectionsSerializeCmdConnect);
    udpConnectionsSerializeWriteClientNonce(outStream, nonce);
    return udpConnectionsSerializeWriteServerChallenge(outStream, serverChallenge);
}

int udpConnectionsSerializeClientOutPacketHeader(FldOutStream* outStream,
                                                 UdpConnectionsSerializeConnectionId connectionId,
                                                 uint16_t octetCountFollowing)
{
    udpConnectionsSerializeCmd(outStream, UdpConnectionsSerializeCmdPacket);
    udpConnectionsSerializeWriteConnectionId(outStream, connectionId);
    return fldOutStreamWriteUInt16(outStream, octetCountFollowing);
}
