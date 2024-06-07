#include "minishell.h"


//>>>>>>>>>PROPOSTA DE CHATGPT>>>>>>>>>>>>>>>>>>>>>>>><
int parser(t_cmd **cmd, t_tok *tok) {
    if (syntax_check_1(tok) == 1)
        return (1);
    if (syntax_check_2(tok) == 1)
        return (1);
    while (tok && tok->type != NULL_TYPE) {
        t_cmd *node = cmd_new_node();
        process_token(tok, node);
        cmd_add_back(cmd, node);
    }
    return (0);
}

void process_token(t_tok **tok, t_cmd *node) {
    commands_creator(tok, node);
    parse_commands(tok, node);
}

void parse_commands(t_tok **tok, t_cmd *node) {
    size_t i = 0;
    while (*tok && (*tok)->type != NULL_TYPE) {
        if ((*tok)->type == WORD) {
            handle_word(tok, node, &i);
        } else if (is_redirection(*tok)) {
            handle_redirection(tok, node);
        } else if ((*tok)->type == PIPE) {
            *tok = (*tok)->next;
            break;
        }
    }
}

void handle_word(t_tok **tok, t_cmd *node, size_t *i) {
    node->commands[(*i)++] = ft_strdup((*tok)->str);
    *tok = (*tok)->next;
}

void handle_redirection(t_tok **tok, t_cmd *node) {
    if ((*tok)->next->type == WORD) {
        char *str_duplicate = ft_strdup((*tok)->next->str);
        t_redir *node_redir = redir_new_node(str_duplicate, (*tok)->type - 2);
        redir_add_back(&node->redir, node_redir);
        *tok = (*tok)->next->next;
    }
}
