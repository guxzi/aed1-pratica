==================================================================
                 PROJETO DE GERENCIAMENTO DE IMÓVEIS
==================================================================

------------------------------------------------------------------
1. INFORMAÇÕES DO PROJETO
------------------------------------------------------------------

Objetivo:
Este projeto tem como finalidade gerenciar um banco de dados de
imóveis disponíveis para venda, aluguel e locação por temporada que
permite a manipulação de registros em vetores e a construção
de estatísticas.

Autores:
Gustavo de Sousa Zimmermann e Gabriela Vinha Feitosa

Disciplina:
AEDs I

------------------------------------------------------------------
2. COMO COMPILAR E EXECUTAR
------------------------------------------------------------------

Requisitos:
- Um compilador C++ (como g++, MinGW, etc.).
- O arquivo de banco de dados "BD_Imoveis2.txt" na mesma pasta
  do executável.

Compilação (via linha de comando):
g++ -std=c++11 -o gerenciador_imoveis main.cpp

Execução:
./gerenciador_imoveis

Ao iniciar, o programa carregará os dados do arquivo "BD_Imoveis2.txt".
Ao encerrar, salvará todas as alterações de volta no mesmo arquivo.

------------------------------------------------------------------
3. INSTRUÇÕES DE USO
------------------------------------------------------------------

O aplicativo funciona com um menu principal. Basta digitar o número
da opção desejada e pressionar Enter.

OPÇÕES DO MENU:

1. Incluir Novo Imóvel:
   - Adiciona um novo imóvel ao banco de dados.
   - Você será solicitado a inserir todas as 22 informações do
     imóvel, uma por uma.
   - Use "sim" ou "nao" para campos de verdadeiro/falso.
   - O banco de dados suporta no máximo 200 imóveis.

2. Buscar e Excluir Imóvel por Rua:
   - Permite procurar um imóvel pelo nome da rua (endereço).
   - O nome da rua deve ser digitado exatamente como no cadastro
     (ex: "Rua_das_Flores").
   - Se um imóvel for encontrado, seus dados serão exibidos e o
     programa perguntará se você deseja excluí-lo.

3. Buscar Imóveis por Faixa de Valor:
   - Lista imóveis (para aluguel, venda ou temporada) dentro de
     um intervalo de preço especificado por você.

4. Buscar Imóveis por Características:
   - Filtra imóveis que possuam um conjunto de características.
   - Você informará "sim" ou "nao" para cada uma das quatro
     características: armários, ar-condicionado, aquecedor e
     ventilador.

5. Buscar Imóveis por Quartos e Suítes:
   - Lista os imóveis que correspondem exatamente ao número de
     quartos e suítes que você informar.

6. Relatório de Estatísticas:
   - Exibe um resumo do banco de dados, incluindo:
     - Porcentagem de imóveis por finalidade (venda, aluguel, temporada).
     - Porcentagem de casas que possuem suítes.
     - Porcentagem de salas comerciais com piso de cerâmica.

7. Listar Todos os Imóveis:
   - Exibe uma lista completa de todos os imóveis atualmente
     cadastrados no sistema.

8. Sair e Salvar:
   - Encerra o programa.
   - IMPORTANTE: Esta é a única opção que salva as alterações
     (inclusões e exclusões) permanentemente no arquivo
     "BD_Imoveis2.txt". Se o programa for fechado de outra forma,
     as alterações serão perdidas.

------------------------------------------------------------------
4. ESTRUTURA DO ARQUIVO "BD_Imoveis2.txt"
------------------------------------------------------------------

Cada linha representa um imóvel e contém 22 campos, separados por
espaço, na seguinte ordem:

Tipo Finalidade Endereco Bairro Cidade Area Valor IPTU Quartos
Suites Banheiros Vagas Cozinha Sala Varanda Area_de_Servico Piso
Conservacao Armarios Ar-condicionado Aquecedor Ventilador

- A primeira linha do arquivo (cabeçalho) é ignorada pelo programa.
- A última linha deve conter a palavra "fim" para sinalizar o
  término dos dados.