/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <flood/in_stream.h>
#include <flood/out_stream.h>
#include <udp-connections-serialize/serialize.h>

int udpConnectionsSerializeWriteConnectionId(struct FldOutStream* outStream, UdpConnectionsSerializeConnectionId id)
{
    return fldOutStreamWriteUInt64(outStream, id);
}

int udpConnectionsSerializeReadConnectionId(struct FldInStream* inStream, UdpConnectionsSerializeConnectionId* id)
{
    return fldInStreamReadUInt64(inStream, id);
}

int udpConnectionsSerializeWriteClientNonce(struct FldOutStream* outStream, UdpConnectionsSerializeClientNonce id)
{
    return fldOutStreamWriteUInt64(outStream, id);
}

int udpConnectionsSerializeReadClientNonce(struct FldInStream* inStream, UdpConnectionsSerializeClientNonce* id)
{
    return fldInStreamReadUInt64(inStream, id);
}

int udpConnectionsSerializeWriteServerChallenge(struct FldOutStream* outStream,
                                                UdpConnectionsSerializeServerChallenge id)
{
    return fldOutStreamWriteUInt64(outStream, id);
}

int udpConnectionsSerializeReadServerChallenge(struct FldInStream* inStream, UdpConnectionsSerializeServerChallenge* id)
{
    return fldInStreamReadUInt64(inStream, id);
}

int udpConnectionsSerializeCmd(struct FldOutStream* outStream, uint8_t cmd)
{
    return fldOutStreamWriteUInt8(outStream, cmd);
}
