//
// Created by João Angeloni e Weslley Cavallaro.
//

#include <stdio.h>

#include "arvoresBinarias.h"

// Constantes
enum {
    OP_NAO_SELECIONADA = 0,
    OP_ADICIONAR,
    OP_ALTERAR,
    OP_EXCLUIR,
    OP_PROCURAR,
    OP_RELATORIO,
    OP_SAIR
};

// Protótipos
int menu();

int main(void) {
    int opcao = OP_NAO_SELECIONADA;
    ld_Usuario usuario;
    ld_Usuario usuario_aux;
    struct ab_no *ab_p;
    int numeroDeRegistro = 0;
    char input[100];

    ab_inicializar();
    ld_iniciar();
    ll_init();

    while(opcao != OP_SAIR)
    {
        opcao = menu();
        switch (opcao) {
            case OP_ADICIONAR:
                printf("Informe o CPF a ser adicionado:\n");
                scanf("%s", usuario.ld_cpf);

                ab_p = ab_buscar(ab_inicio, usuario.ld_cpf);

                if(ab_p!=NULL)
                {
                    printf("CPF %s ja cadastrado!\n", ab_p->ab_cpf);
                }
                else
                {
                    printf("Digite o nome: \n");
                    scanf("%s", usuario.ld_nome);
                    printf("Digite o endereco: \n");
                    scanf("%s", usuario.ld_endereco);
                    printf("Digite o telefone: \n");
                    scanf("%s", usuario.ld_telefone);
                    printf("Digite o email: \n");
                    scanf("%s", usuario.ld_email);

                    usuario.ld_excluido = 0;

                    ld_adicionar(usuario);
                    ab_adicionar(ab_inicio, ab_novoNo(usuario.ld_cpf, numeroDeRegistro));
                    ll_adicionar(usuario.ld_nome, numeroDeRegistro);
                    numeroDeRegistro++;
                    printf("Usuario %s cadastrado com sucesso!\n", usuario.ld_nome);
                }

            break;
            case OP_ALTERAR:
                printf("Informe o CPF a ser alterado:\n");
                scanf("%s", usuario.ld_cpf);

                ab_p = ab_buscar(ab_inicio, usuario.ld_cpf);
                if(ab_p==NULL)
                {
                    printf("CPF nao cadastrado!\n");
                }
                else
                {
                    usuario = ld_buscarUsuario(usuario.ld_cpf);

                    fflush(stdin);
                    printf("Deseja alterar o nome?\n");
                    fgets(input, sizeof(input), stdin);
                    sscanf(input, "%[^\n]", usuario_aux.ld_nome);
                    if(input[0] != '\n'){
                        ll_excluir(usuario.ld_nome);
                        strcpy(usuario.ld_nome, usuario_aux.ld_nome);
                        ll_adicionar(usuario.ld_nome, ab_p->ab_numRegistro);
                    }

                    printf("Deseja alterar o endereço?\n");
                    fgets(input, sizeof(input), stdin);
                    sscanf(input, "%[^\n]", usuario_aux.ld_endereco);
                    if(input[0] != '\n')
                        strcpy(usuario.ld_endereco, usuario_aux.ld_endereco);

                    printf("Deseja alterar o telefone?\n");
                    fgets(input, sizeof(input), stdin);
                    sscanf(input, "%[^\n]", usuario_aux.ld_telefone);
                    if(input[0] != '\n')
                        strcpy(usuario.ld_telefone, usuario_aux.ld_telefone);

                    printf("Deseja alterar o email?\n");
                    fgets(input, sizeof(input), stdin);
                    sscanf(input, "%[^\n]", usuario_aux.ld_email);
                    if(input[0] != '\n')
                        strcpy(usuario.ld_email, usuario_aux.ld_email);

                    ld_atualizar(ab_p->ab_numRegistro, usuario);
                    printf("Usuario %s alterado com sucesso!\n", usuario.ld_nome);
                }
            break;
            case OP_EXCLUIR:
                printf("Informe o CPF a ser excluido:\n");
                scanf("%s", usuario_aux.ld_cpf);
                usuario = ld_buscarUsuario(usuario_aux.ld_cpf);

                ab_p = ab_buscar(ab_inicio, usuario.ld_cpf);
                if(ab_p==NULL)
                {
                    printf("CPF nao cadastrado!\n");
                }
                else
                {

                    ab_excluir(usuario.ld_cpf);
                    ll_excluir(usuario.ld_nome);
                    printf("Usuario %s excluido com sucesso!\n", usuario.ld_nome);

                }
            break;
            case OP_PROCURAR:
                printf("Informe o CPF a ser procurado:\n");
                scanf("%s", usuario.ld_cpf);

                ab_p = ab_buscar(ab_inicio, usuario.ld_cpf);
                if(ab_p==NULL)
                {
                    printf("CPF nao cadastrado!\n");
                }
                else
                {
                    printf("CPF %s cadastrado, buscando dados...\n", ab_p->ab_cpf);
                    ld_imprimir(ab_p->ab_cpf);
                }
            break;
            case OP_RELATORIO:
                ll_imprimir();
            break;
            case OP_SAIR:
            break;
            default:
                printf("Opcao incorreta!\n");
        }
    }

    ab_finalizar(ab_inicio);
    ld_destruir();
    ll_destroy(ll_inicio);
    return EXIT_SUCCESS;
}

int menu()
{
    int op = OP_NAO_SELECIONADA;
    printf("Menu\n");
    printf("%d - Adicionar\n", OP_ADICIONAR);
    printf("%d - Alterar\n", OP_ALTERAR);
    printf("%d - Excluir\n", OP_EXCLUIR);
    printf("%d - Procurar\n", OP_PROCURAR);
    printf("%d - Relatorio\n", OP_RELATORIO);
    printf("%d - Sair\n", OP_SAIR);
    printf("Digite sua opcao: ");
    scanf("%d", &op);

    return op;
}
