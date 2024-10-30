#include "dos_header.h"
#include <sstream>
#include <iomanip>

DOSHeader readDOSHeader(FileReader& reader) {
	reader.seek(0);

	DOSHeader dosHeader;
	dosHeader.e_magic = reader.read<uint16_t>();
	dosHeader.e_cblp = reader.read<uint16_t>();
	dosHeader.e_cp = reader.read<uint16_t>();
	dosHeader.e_crlc = reader.read<uint16_t>();
	dosHeader.e_cparhdr = reader.read<uint16_t>();
	dosHeader.e_minalloc = reader.read<uint16_t>();
	dosHeader.e_maxalloc = reader.read<uint16_t>();
	dosHeader.e_ss = reader.read<uint16_t>();
	dosHeader.e_sp = reader.read<uint16_t>();
	dosHeader.e_csum = reader.read<uint16_t>();
	dosHeader.e_ip = reader.read<uint16_t>();
	dosHeader.e_cs = reader.read<uint16_t>();
	dosHeader.e_lfarlc = reader.read<uint16_t>();
	dosHeader.e_ovno = reader.read<uint16_t>();
	for (int i = 0; i < 4; ++i) {
		dosHeader.e_res[i] = reader.read<uint16_t>();
	}
	dosHeader.e_oemid = reader.read<uint16_t>();
	dosHeader.e_oeminfo = reader.read<uint16_t>();
	for (int i = 0; i < 10; ++i) {
		dosHeader.e_res2[i] = reader.read<uint16_t>();
	}
	dosHeader.e_lfanew = reader.read<int32_t>();

	if (dosHeader.e_magic != 0x54A4D) {
		throw runtime_error("Arquivo não é um executável PE válido.");
	}

	return dosHeader;
}

std::string DOSHeader::toString() const {
	std::ostringstream oss;
	oss << "DOS Header:\n";
	oss << "  Magic Number: " << std::hex << std::setw(4) << std::setfill('0') << e_magic << "\n";
	oss << "  e_lfanew (PE Header Offset): " << std::hex << e_lfanew << "\n";
	return oss.str();
}