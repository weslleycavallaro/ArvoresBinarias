//
// Created by João Angeloni e Weslley Cavallaro.
//

#include "arvoresBinarias.h"

// Variáveis
struct ll_no *ll_inicio;
struct ll_no *ll_aux;
struct ll_no *ll_novo;
struct ll_no *ll_anterior;

// Funções
void ll_init()
{
    ll_inicio = NULL;
}

void ll_destroy(struct ll_no *ll_quem)
{
    if(ll_quem == NULL)
    {
        return;
    }
    if(ll_quem->ll_proximo != NULL)
    {
        ll_destroy(ll_quem->ll_proximo);
    }
    printf("Destruindo %d...\n", ll_quem->ll_nome);
    free(ll_quem);
}

void ll_adicionar(char ll_nome[100], int ll_numRegistro)
{
    ll_novo = ll_novoNo(ll_nome, ll_numRegistro);

    if(ll_inicio == NULL)
    {
        ll_inicio = ll_novo;
    }
    else
    {
        if(strcmp(ll_novo->ll_nome, ll_inicio->ll_nome) <= 0) {
            ll_adicionarNoInicio();
        }
        else
        {
            ll_aux = ll_inicio;
            ll_anterior = ll_inicio;
            while(strcmp(ll_aux->ll_nome, ll_novo->ll_nome) < 0 && ll_aux->ll_proximo != NULL)
            {
                ll_anterior = ll_aux;
                ll_aux = ll_aux->ll_proximo;
            }
            if(strcmp(ll_novo->ll_nome, ll_aux->ll_nome) > 0)
            {
                ll_adicionarNoFim();
            }
            else
            {
                ll_adicionarNoMeio();
            }
        }
    }
}

void ll_adicionarNoInicio()
{
    ll_novo->ll_proximo = ll_inicio;
    ll_inicio = ll_novo;
}

void ll_adicionarNoFim()
{
    ll_aux->ll_proximo = ll_novo;
}

void ll_adicionarNoMeio()
{
    ll_novo->ll_proximo = ll_aux;
    ll_anterior->ll_proximo = ll_novo;
}

void ll_excluir(char ll_nome[100])
{
    if(ll_inicio == NULL)
    {
        return;
    }
    else
    {
        if(strcmp(ll_nome, ll_inicio->ll_nome) == 0) {
            ll_excluirNoInicio();
        }
        else
        {
            ll_aux = ll_inicio;
            ll_anterior = ll_inicio;
            while(strcmp(ll_aux->ll_nome, ll_nome) != 0 && ll_aux->ll_proximo != NULL)
            {
                ll_anterior = ll_aux;
                ll_aux = ll_aux->ll_proximo;
            }
            if(strcmp(ll_aux->ll_nome, ll_nome) == 0) {
                if (ll_aux->ll_proximo == NULL) {
                    ll_excluirNoFim();
                } else {
                    ll_excluirNoMeio();
                }
            }
        }
    }
}

void ll_excluirNoInicio()
{
    if(ll_inicio->ll_proximo == NULL)
    {
        free(ll_inicio);
        ll_inicio = NULL;
    }
    else
    {
        ll_aux = ll_inicio;
        ll_inicio = ll_inicio->ll_proximo;
        free(ll_aux);
    }

}

void ll_excluirNoFim()
{
    ll_anterior->ll_proximo = NULL;
    free(ll_aux);
}

void ll_excluirNoMeio()
{
    struct ll_no *proximo;

    proximo = ll_aux->ll_proximo;
    ll_anterior->ll_proximo = proximo;
    free(ll_aux);
}

struct ll_no *ll_novoNo(char ll_nome[100], int ll_numRegistro)
{
    struct ll_no *ll_p = malloc(sizeof(struct ll_no));
    if(!ll_p)
    {
        printf("Erro de alocacao de memoria");
        exit(EXIT_FAILURE);
    }

    strcpy(ll_p->ll_nome, ll_nome);
    ll_p->ll_numRegistro = ll_numRegistro;
    ll_p->ll_proximo = NULL;

    return ll_p;
}

void ll_imprimir()
{
    if(ll_inicio != NULL) {
        ll_aux = ll_inicio;
        while (ll_aux->ll_proximo != NULL) {
            printf("Nome: %s - Registro: %d\n", ll_aux->ll_nome, ll_aux->ll_numRegistro);
            ll_aux = ll_aux->ll_proximo;
        }
        printf("Nome: %s - Registro: %d\n", ll_aux->ll_nome, ll_aux->ll_numRegistro);
    }else {
        printf("A lista ligada está vazia.\n");
    }
}