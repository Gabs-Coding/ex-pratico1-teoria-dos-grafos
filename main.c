#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>

#if defined(_WIN32) || defined(_WIN64)
    #include <direct.h>
    #define mkdir(path, mode) _mkdir(path)
#else
    #include <sys/stat.h>
    #include <sys/types.h>
#endif

#define TAMANHO_MAXIMO_MATRIZ_ADJACENCIAS 100

int main(int argc, char const *argv[])
{
    const char* NOME_PASTA = "arquivos";
    const char* NOME_ARQUIVO_VERTICES = "arquivos/vertices.txt";

    printf("Criando a pasta '%s' se não existir...\n", NOME_PASTA);
    if (mkdir(NOME_PASTA, 0777) != 0) {
        printf("A pasta '%s' já existe. Prosseguindo...\n", NOME_PASTA);
    }

    printf("Abrindo o arquivo '%s' para leitura...\n", NOME_ARQUIVO_VERTICES);
    FILE *p_arquivo = fopen(NOME_ARQUIVO_VERTICES, "r");
    if (p_arquivo == NULL) {
        perror("Falha ao ler o arquivo");
        return ENOENT;
    }

    printf("Arquivo aberto com sucesso.\n", NOME_ARQUIVO_VERTICES);

    printf("Fechando o conteúdo do arquivo...\n");
    if (fclose(p_arquivo) != 0) {
        perror("Falha ao fechar o arquivo");
        return errno;
    }
    printf("Arquivo fechado com sucesso.\n");
    printf("Fim do programa.\n");
    return 0;
}
