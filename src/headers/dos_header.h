#ifndef DOS_HEADER_H
#define DOS_HEADER_H

#include <string>
#include <cstdint>
#include <file_reader.h>

using namespace std;

struct DOSHeader {
	uint16_t e_magic;
	uint16_t e_cblp;
	uint16_t e_cp;
	uint16_t e_crlc;
	uint16_t e_cparhdr;
	uint16_t e_minalloc;
	uint16_t e_maxalloc;
	uint16_t e_ss;
	uint16_t e_sp;
	uint16_t e_csum;
	uint16_t e_ip;
	uint16_t e_cs;
	uint16_t e_lfarlc;
	uint16_t e_ovno;
	uint16_t e_res[4];
	uint16_t e_oemid;
	uint16_t e_oeminfo;
	uint16_t e_res2[10];
	int32_t e_lfanew;

	string toString() const;
};

DOSHeader readDOSHeader(FileReader& reader);

#endif // DOS_HEADER_H