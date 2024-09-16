//
// Created by Weslley on 10/06/2024.
//

#ifndef ARVORESBINARIAS_H
#define ARVORESBINARIAS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Constantes arvore binaria
struct ab_no {
    struct ab_no *ab_esquerda;
    char ab_cpf[12];
    int ab_numRegistro;
    struct ab_no *ab_direita;
};


// Constantes lista dinamica
typedef struct{
    char ld_cpf[12];
    char ld_nome[50];
    char ld_endereco[50];
    char ld_telefone[11];
    char ld_email[50];
    bool ld_excluido;
} ld_Usuario;


// Constantes lista ligada
struct ll_no {
    char ll_nome[100];
    int ll_numRegistro;
    struct ll_no *ll_proximo;
};


// Variáveis arvore binaria
extern struct ab_no *ab_inicio;
extern struct ab_no *ab_anterior;


// Variaveis lista dinamica
extern int ld_tamanhoMaximo;
extern ld_Usuario *ld_usuario;
extern int ld_posicao;


// Variáveis lista ligada
extern struct ll_no *ll_inicio;
extern struct ll_no *ll_aux;
extern struct ll_no *ll_novo;
extern struct ll_no *ll_anterior;


// Protótipos arvore binaria
void ab_inicializar();
void ab_finalizar(struct ab_no *ab_quem);
void ab_adicionar(struct ab_no *ab_aonde, struct ab_no *ab_quem);
struct ab_no *ab_novoNo(char ab_cpf[12], int ab_numRegistro);
struct ab_no *ab_buscar(struct ab_no * ab_aonde, char ab_cpf[12]);
void ab_excluir(char ab_cpf[12]);

// Protótipos lista dinamica
void ld_iniciar();
void ld_destruir();
void ld_adicionar(ld_Usuario ld_usuario);
size_t ld_tamanho();
bool ld_atualizar(int ld_index, ld_Usuario ld_usuario);
void ld_expandir();
void ld_imprimir(char ld_cpf[12]);
ld_Usuario ld_buscarUsuario(char ld_cpf[12]);


// Protótipos lista ligada
void ll_init();
void ll_destroy(struct ll_no *ll_quem);
void ll_adicionar(char ll_nome[100], int ll_numRegistro);
void ll_adicionarNoInicio();
void ll_adicionarNoFim();
void ll_adicionarNoMeio();
void ll_excluir(char ll_nome[100]);
void ll_excluirNoInicio();
void ll_excluirNoFim();
void ll_excluirNoMeio();
struct ll_no *ll_novoNo(char ll_nome[100], int ll_numRegistro);
void ll_imprimir();

#endif //ARVORESBINARIAS_H
