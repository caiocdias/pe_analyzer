#ifndef FILE_READER_H
#define FILE_READER_H

#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

class FileReader {
public:
	explicit FileReader(const string& filename);
	~FileReader();

	bool isOpen() const;

	void seek(streampos position);

	streampos tell();

	void readBytes(char* buffer, size_t size);

	template<typename T>
	T read();

private:
	ifstream file;
};
#endif // FILE_READER_H