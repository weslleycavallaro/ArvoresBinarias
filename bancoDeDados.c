//
// Created by João Angeloni e Weslley Cavallaro.
//

#include "arvoresBinarias.h"

// variáveis
ld_Usuario *ld_usuario = NULL;
int ld_posicao = 0;
int ld_tamanhoMaximo = 5;

// Funções
void ld_iniciar()
{
    ld_usuario = malloc(ld_tamanhoMaximo * sizeof(ld_Usuario));
    if (!ld_usuario) {
        printf("Erro de alocação de memória!\n");
        exit(EXIT_FAILURE);
    }
}

void ld_destruir()
{
    free(ld_usuario);
}

void ld_adicionar(ld_Usuario usuario) {
    if (ld_posicao == ld_tamanhoMaximo) {
        ld_expandir();
    }
    ld_usuario[ld_posicao] = usuario;
    ld_posicao++;
}

size_t ld_tamanho()
{
    return ld_posicao;
}

bool ld_atualizar(int ld_index, ld_Usuario usuario)
{
    if(ld_index < 0 || ld_index > ld_posicao)
    {
        return false;
    }
    else
    {
        ld_usuario[ld_index] = usuario;
        return true;
    }
}

void ld_imprimir(char ld_cpf[12])
{
    printf("{\n");
    for(int i = 0; i < ld_posicao; i++)
    {
        if(strcmp(ld_usuario[i].ld_cpf, ld_cpf) == 0) {
            printf("    'cpf':'%s'\n", ld_usuario[i].ld_cpf);
            printf("    'nome':'%s'\n", ld_usuario[i].ld_nome);
            printf("    'endereco':'%s'\n", ld_usuario[i].ld_endereco);
            printf("    'telefone':'%s'\n", ld_usuario[i].ld_telefone);
            printf("    'email':'%s'\n", ld_usuario[i].ld_email);
            printf("    'excluido':%d\n", ld_usuario[i].ld_excluido);
        }
    }
    printf("}\n");
}

void ld_expandir() {
    ld_Usuario *aux;
    int novoTamanho;

    printf("Expandindo...\n");

    novoTamanho = ld_tamanhoMaximo + 3;
    aux = (ld_Usuario *)malloc(novoTamanho * sizeof(ld_Usuario));

    if (!aux) {
        printf("Erro de alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < ld_tamanhoMaximo; i++) {
        aux[i] = ld_usuario[i];
    }

    ld_tamanhoMaximo = novoTamanho;
    free(ld_usuario);
    ld_usuario = aux;
}

ld_Usuario ld_buscarUsuario(char ld_cpf[12])
{
    for (int i = 0; i < ld_posicao; ++i) {
        if(strcmp(ld_usuario[i].ld_cpf, ld_cpf) == 0){
            return ld_usuario[i];
        }
    }
}