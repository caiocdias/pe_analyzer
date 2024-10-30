# Definindo o nome do projeto
cmake_minimum_required(VERSION 3.10)
project(pe_analyzer)

# Definindo a versão do C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Adicionando diretórios para inclusão
include_directories(src/headers src/utils)

# Listando todos os arquivos .cpp em headers e utils
file(GLOB HEADERS_SRC
    "src/headers/*.cpp"
)

file(GLOB UTILS_SRC
    "src/utils/*.cpp"
)

# Adicionando o executável
add_executable(pe_analyzer src/main.cpp ${HEADERS_SRC} ${UTILS_SRC})
