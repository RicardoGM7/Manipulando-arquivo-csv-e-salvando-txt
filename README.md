# Manipulador de Dados CSV de Alunos

Um programa em C++ para ler, buscar e gerenciar dados de alunos armazenados em arquivo CSV. Permite buscar informações de alunos por matrícula e salvar os dados em arquivos de texto individuais.

## Descrição

O programa implementa um sistema de gerenciamento de dados acadêmicos que:
- **Lê** arquivos CSV contendo informações de alunos (matrícula, nome, curso, status, etc.)
- **Busca** alunos por número de matrícula
- **Exibe** informações completas do aluno no console
- **Exporta** dados individuais para arquivos de texto

## Recursos

- ✅ Parsing automático de arquivos CSV
- ✅ Busca eficiente de alunos por matrícula
- ✅ Exibição formatada de dados no console
- ✅ Exportação de dados para arquivos `.txt`
- ✅ Suporte completo a caracteres especiais brasileiros (UTF-8)
- ✅ Tratamento de erros para arquivos inválidos



## Notas sobre a Implementação

- Todos os campos são armazenados como `string` para simpler manipulação
- O programa trata automaticamente aspas duplas nos campos CSV
- Suporta UTF-8 para caracteres acentuados e especiais em português
- A busca é case-sensitive (diferencia maiúsculas de minúsculas)

## Contexto

Este projeto foi desenvolvido como atividade da disciplina de **Engenharia de Dados**, focando em:
- Manipulação de arquivos CSV
- Processamento de dados em larga escala
- Persistência de dados em arquivos
- Implementação de classes em C++

