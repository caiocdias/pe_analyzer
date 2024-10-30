#include "file_reader.h"

FileReader::FileReader(const string& filename) : file(filename, ios::binary) {
	if (!file.is_open()) {
		throw runtime_error("Erro ao abrir arquivo: " + filename);
	}
}

FileReader::~FileReader() {
	if (file.is_open()) {
		file.close();
	}
}

bool FileReader::isOpen() const {
	return file.is_open();
}

void FileReader::seek(streampos position) {
	if (!file.seekg(position)) {
		throw runtime_error("Erro ao mover o ponteiro no arquivo.");
	}
}

streampos FileReader::tell() {
	return file.tellg();
}

void FileReader::readBytes(char* buffer, std::size_t size) {
	if (!file.read(buffer, size)) {
		throw std::runtime_error("Erro ao ler bytes do arquivo.");
	}
}

template<typename T>
T FileReader::read() {
	T value;
	if (!file.read(reinterpret_cast<char*>(&value), sizeof(T))) {
		throw std::runtime_error("Erro ao ler tipo específico do arquivo.");
	}
	return value;
}