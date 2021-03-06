/*
 * Copyright 2003-2021 The Music Player Daemon Project
 * http://www.musicpd.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef MPD_OUTPUT_SNAPCAST_PROTOCOL_HXX
#define MPD_OUTPUT_SNAPCAST_PROTOCOL_HXX

#include "util/ByteOrder.hxx"

// see https://github.com/badaix/snapcast/blob/master/doc/binary_protocol.md

enum class SnapcastMessageType : uint16_t {
	CODEC_HEADER = 1,
	WIRE_CHUNK = 2,
	SERVER_SETTINGS = 3,
	TIME = 4,
	HELLO = 5,
	STREAM_TAGS = 6,
};

struct SnapcastTimestamp {
	PackedLE32 sec, usec;
};

struct SnapcastBase {
	PackedLE16 type;
	PackedLE16 id;
	PackedLE16 refers_to;
	SnapcastTimestamp received;
	SnapcastTimestamp sent;
	PackedLE32 size;
};

static_assert(sizeof(SnapcastBase) == 26);

struct SnapcastWireChunk {
	SnapcastTimestamp timestamp;
	PackedLE32 size;
};

struct SnapcastTime {
	SnapcastTimestamp latency;
};

#endif
