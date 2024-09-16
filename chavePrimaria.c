//
// Created by João Angeloni e Weslley Cavallaro.
//


#include "arvoresBinarias.h"

// Variáveis
struct ab_no *ab_inicio;
struct ab_no *ab_anterior;

// Funções
void ab_inicializar()
{
    ab_inicio = NULL;
}

void ab_finalizar(struct ab_no *ab_quem)
{
    if(ab_quem != NULL) {
        if (ab_quem->ab_esquerda != NULL) {
            ab_finalizar(ab_quem->ab_esquerda);
        }
        if (ab_quem->ab_direita != NULL) {
            ab_finalizar(ab_quem->ab_direita);
        }
        printf("Excluindo %s\n", ab_quem->ab_cpf);
        free(ab_quem);
    }
}

void ab_adicionar(struct ab_no *ab_aonde, struct ab_no *ab_quem)
{
    if(ab_inicio == NULL)
    {
        ab_inicio = ab_quem;
    }
    else
    {
        if(strcmp(ab_quem->ab_cpf, ab_aonde->ab_cpf) > 0)
        {
            // processar lado direito
            if(ab_aonde->ab_direita == NULL)
            {
                ab_aonde->ab_direita = ab_quem;
            }
            else
            {
                ab_adicionar(ab_aonde->ab_direita, ab_quem);
            }
        }
        else
        {
            // processar lado esquerdo
            if(ab_aonde->ab_esquerda == NULL)
            {
                ab_aonde->ab_esquerda = ab_quem;
            }
            else
            {
                ab_adicionar(ab_aonde->ab_esquerda, ab_quem);
            }
        }
    }
}

struct ab_no *ab_novoNo(char ab_cpf[12], int ab_numRegistro)
{
    struct ab_no *ab_p = malloc(sizeof(struct ab_no));
    if(!ab_p)
    {
        printf("Erro de alocacao de memoria\n");
        exit(EXIT_FAILURE);
    }
    ab_p->ab_esquerda = NULL;
    strcpy(ab_p->ab_cpf, ab_cpf);
    ab_p->ab_numRegistro = ab_numRegistro;
    ab_p->ab_direita = NULL;

    return ab_p;
}

struct ab_no *ab_buscar(struct ab_no * ab_aonde, char ab_cpf[12])
{
    if(ab_inicio == NULL)
    {
        return NULL;
    }
    else
    {
        if(ab_aonde == ab_inicio)
        {
            ab_anterior = ab_inicio;
        }
        if(strcmp(ab_aonde->ab_cpf, ab_cpf) == 0)
        {
            return ab_aonde;
        }
        else
        {
            ab_anterior = ab_aonde;
            if(strcmp(ab_cpf, ab_aonde->ab_cpf) > 0)
            {
                // direito
                if(ab_aonde->ab_direita != NULL)
                {
                    return ab_buscar(ab_aonde->ab_direita, ab_cpf);
                }
                else
                {
                    return NULL;
                }
            }
            else
            {
                // esquerdo
                if(ab_aonde->ab_esquerda != NULL)
                {
                    return ab_buscar(ab_aonde->ab_esquerda, ab_cpf);
                }
                else
                {
                    return NULL;
                }
            }
        }
    }
}

void ab_excluir(char ab_cpf[12])
{
    struct ab_no *ab_p = ab_buscar(ab_inicio, ab_cpf);
    if(ab_p != NULL)
    {
        if(ab_p == ab_inicio)
        {
            ab_inicio = NULL;
        }
        else {
            if (strcmp(ab_p->ab_cpf, ab_anterior->ab_cpf) > 0) {
                ab_anterior->ab_direita = NULL;
            } else {
                ab_anterior->ab_esquerda = NULL;
            }
        }
        if(ab_p->ab_esquerda != NULL)
        {
            ab_adicionar(ab_inicio, ab_p->ab_esquerda);
        }
        if(ab_p->ab_direita != NULL)
        {
            ab_adicionar(ab_inicio, ab_p->ab_direita);
        }
        free(ab_p);
    }
}