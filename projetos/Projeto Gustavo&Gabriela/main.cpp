/******************************************************************************
 * PROJETO: Gerenciador de Imóveis
 *
 * DESCRIÇÃO:
 * Este aplicativo gerencia um banco de dados de imóveis, lendo e escrevendo
 * informações em um arquivo texto. Permite ao usuário realizar operações de
 * inclusão, exclusão, busca e geração de relatórios estatísticos sobre os
 * dados carregados em um vetor de registros.
 *
 * AUTORES: Gustavo de Sousa Zimmermann, Gabriela Vinha Feitosa
 * DISCIPLINA: AEDs I
 *****************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip> 
#include <limits>  

// --- ESTRUTURA DE DADOS ---
struct Imovel {
    std::string tipo;
    std::string finalidade;
    std::string endereco;
    std::string bairro;
    std::string cidade;
    double area;
    std::string valor;
    double iptu;
    int quartos;
    int suites;
    int banheiros;
    int vagas;
    bool cozinha;
    bool sala;
    bool varanda;
    bool area_de_servico;
    std::string piso;
    std::string conservacao;
    bool armarios;
    bool ar_condicionado;
    bool aquecedor;
    bool ventilador;
};

// --- FUNÇÕES AUXILIARES ---
bool stringParaBool(const std::string& s) {
    return s == "sim";
}

std::string boolParaString(bool b) {
    return b ? "sim" : "nao";
}

double extrairValorNumerico(const std::string& valorStr) {
    try {
        return std::stod(valorStr);
    } catch (const std::invalid_argument&) {
        size_t pos = valorStr.find('/');
        if (pos != std::string::npos) {
            try {
                return std::stod(valorStr.substr(0, pos));
            } catch (const std::invalid_argument&) {
                return 0.0;
            }
        }
        return 0.0;
    }
}

void limparBufferEntrada() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void exibirImovel(const Imovel& im) {
    std::cout << "----------------------------------------\n"
              << "Tipo: " << im.tipo << " | Finalidade: " << im.finalidade << "\n"
              << "Endereco: " << im.endereco << ", " << im.bairro << ", " << im.cidade << "\n"
              << "Area: " << im.area << " m2 | Valor: " << im.valor << " | IPTU: " << im.iptu << "\n"
              << "Quartos: " << im.quartos << " | Suites: " << im.suites << " | Banheiros: " << im.banheiros << " | Vagas: " << im.vagas << "\n"
              << "Caracteristicas:\n"
              << "  - Cozinha: " << boolParaString(im.cozinha) << " | Sala: " << boolParaString(im.sala)
              << " | Varanda: " << boolParaString(im.varanda) << " | Area de Servico: " << boolParaString(im.area_de_servico) << "\n"
              << "  - Piso: " << im.piso << " | Conservacao: " << im.conservacao << "\n"
              << "Comodidades:\n"
              << "  - Armarios: " << boolParaString(im.armarios) << " | Ar-cond.: " << boolParaString(im.ar_condicionado)
              << " | Aquecedor: " << boolParaString(im.aquecedor) << " | Ventilador: " << boolParaString(im.ventilador) << "\n"
              << "----------------------------------------\n";
}

// --- FUNÇÕES DE MANIPULAÇÃO DE DADOS ---
void carregarDados(std::vector<Imovel>& bd, const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "ERRO: Nao foi possivel encontrar o arquivo de banco de dados '" << nomeArquivo << "'.\n";
        std::cerr << "Verifique se o arquivo esta na mesma pasta do executavel.\n";
        std::cout << "Pressione Enter para sair...";
        limparBufferEntrada();
        exit(1);
    }

    std::string linha;
    std::getline(arquivo, linha); // Pula cabeçalho

    while (std::getline(arquivo, linha)) {
        if (linha.empty() || linha.find_first_not_of(" \t\r\n") == std::string::npos) {
            continue;
        }

        std::stringstream ss(linha);
        Imovel imovel;
        std::string tempBool;

        ss >> imovel.tipo;
        if (imovel.tipo == "fim") {
            break;
        }

        ss >> imovel.finalidade >> imovel.endereco >> imovel.bairro >> imovel.cidade >> imovel.area >>
            imovel.valor >> imovel.iptu >> imovel.quartos >> imovel.suites >> imovel.banheiros >>
            imovel.vagas;

        ss >> tempBool; imovel.cozinha = stringParaBool(tempBool);
        ss >> tempBool; imovel.sala = stringParaBool(tempBool);
        ss >> tempBool; imovel.varanda = stringParaBool(tempBool);
        ss >> tempBool; imovel.area_de_servico = stringParaBool(tempBool);
        ss >> imovel.piso >> imovel.conservacao;
        ss >> tempBool; imovel.armarios = stringParaBool(tempBool);
        ss >> tempBool; imovel.ar_condicionado = stringParaBool(tempBool);
        ss >> tempBool; imovel.aquecedor = stringParaBool(tempBool);
        ss >> tempBool; imovel.ventilador = stringParaBool(tempBool);

        bd.push_back(imovel);
    }
    arquivo.close();
    std::cout << "Banco de dados carregado. Total de " << bd.size() << " imoveis.\n";
}

void salvarDados(const std::vector<Imovel>& bd, const std::string& nomeArquivo) {
    std::ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro: Nao foi possivel salvar os dados no arquivo " << nomeArquivo << ".\n";
        return;
    }
    arquivo << "# Tipo Finalidade Endereco Bairro Cidade Area Valor IPTU Quartos Suites Banheiros Vagas Cozinha Sala Varanda Area_de_Servico Piso Conservacao Armarios Ar-condicionado Aquecedor Ventilador\n";
    for (const auto& imovel : bd) {
        arquivo << imovel.tipo << " " << imovel.finalidade << " " << imovel.endereco << " " << imovel.bairro << " "
                << imovel.cidade << " " << imovel.area << " " << imovel.valor << " " << imovel.iptu << " "
                << imovel.quartos << " " << imovel.suites << " " << imovel.banheiros << " " << imovel.vagas << " "
                << boolParaString(imovel.cozinha) << " " << boolParaString(imovel.sala) << " "
                << boolParaString(imovel.varanda) << " " << boolParaString(imovel.area_de_servico) << " "
                << imovel.piso << " " << imovel.conservacao << " " << boolParaString(imovel.armarios) << " "
                << boolParaString(imovel.ar_condicionado) << " " << boolParaString(imovel.aquecedor) << " "
                << boolParaString(imovel.ventilador) << "\n";
    }
    arquivo << "fim\n";
    arquivo.close();
    std::cout << "Dados salvos com sucesso no arquivo " << nomeArquivo << ".\n";
}

// --- FUNÇÕES DAS OPERAÇÕES DO MENU ---
void incluirImovel(std::vector<Imovel>& bd) {
    if (bd.size() >= 200) {
        std::cout << "Erro: Limite maximo de 200 imoveis atingido.\n";
        return;
    }

    Imovel novo;
    std::string tempBool;
    std::cout << "\n--- Inclusao de Novo Imovel ---\n";
    std::cout << "Digite as informacoes (use _ para espacos quando necessario):\n";

    std::cout << "Tipo (casa, apartamento, etc.): "; std::cin >> novo.tipo;
    std::cout << "Finalidade (venda, aluguel, temporada): "; std::cin >> novo.finalidade;
    std::cout << "Endereco (Rua_Exemplo): "; std::cin >> novo.endereco;
    std::cout << "Bairro: "; std::cin >> novo.bairro;
    std::cout << "Cidade: "; std::cin >> novo.cidade;
    std::cout << "Area (m2): "; std::cin >> novo.area;
    std::cout << "Valor (ex: 500000 ou 300/dia): "; std::cin >> novo.valor;
    std::cout << "IPTU: "; std::cin >> novo.iptu;
    std::cout << "Quartos: "; std::cin >> novo.quartos;
    std::cout << "Suites: "; std::cin >> novo.suites;
    std::cout << "Banheiros: "; std::cin >> novo.banheiros;
    std::cout << "Vagas de garagem: "; std::cin >> novo.vagas;
    std::cout << "Cozinha (sim/nao): "; std::cin >> tempBool; novo.cozinha = stringParaBool(tempBool);
    std::cout << "Sala (sim/nao): "; std::cin >> tempBool; novo.sala = stringParaBool(tempBool);
    std::cout << "Varanda (sim/nao): "; std::cin >> tempBool; novo.varanda = stringParaBool(tempBool);
    std::cout << "Area de Servico (sim/nao): "; std::cin >> tempBool; novo.area_de_servico = stringParaBool(tempBool);
    std::cout << "Piso (ceramica, porcelanato, etc.): "; std::cin >> novo.piso;
    std::cout << "Conservacao (novo, usado, reformado): "; std::cin >> novo.conservacao;
    std::cout << "Armarios (sim/nao): "; std::cin >> tempBool; novo.armarios = stringParaBool(tempBool);
    std::cout << "Ar-condicionado (sim/nao): "; std::cin >> tempBool; novo.ar_condicionado = stringParaBool(tempBool);
    std::cout << "Aquecedor (sim/nao): "; std::cin >> tempBool; novo.aquecedor = stringParaBool(tempBool);
    std::cout << "Ventilador (sim/nao): "; std::cin >> tempBool; novo.ventilador = stringParaBool(tempBool);

    bd.push_back(novo);
    std::cout << "\nImovel incluido com sucesso!\n";
}

void buscarExcluirPorRua(std::vector<Imovel>& bd) {
    std::string rua;
    std::cout << "\n--- Busca e Exclusao por Rua ---\n";
    std::cout << "Digite o nome da rua (endereco) para buscar: ";
    std::cin >> rua;

    int indiceEncontrado = -1;
    for (size_t i = 0; i < bd.size(); ++i) {
        if (bd[i].endereco == rua) {
            std::cout << "\nImovel encontrado:\n";
            exibirImovel(bd[i]);
            indiceEncontrado = i;
            break;
        }
    }

    if (indiceEncontrado != -1) {
        char confirmacao;
        std::cout << "Deseja excluir este imovel? (s/n): ";
        std::cin >> confirmacao;
        if (confirmacao == 's' || confirmacao == 'S') {
            bd.erase(bd.begin() + indiceEncontrado);
            std::cout << "Imovel excluido com sucesso.\n";
        } else {
            std::cout << "Operacao de exclusao cancelada.\n";
        }
    } else {
        std::cout << "Nenhum imovel encontrado no endereco '" << rua << "'.\n";
    }
}

void buscarPorFaixaDeValor(const std::vector<Imovel>& bd) {
    std::string finalidade;
    double min, max;
    std::cout << "\n--- Busca por Faixa de Valor ---\n";
    std::cout << "Digite a finalidade (venda, aluguel, temporada): ";
    std::cin >> finalidade;
    std::cout << "Digite o valor minimo: ";
    std::cin >> min;
    std::cout << "Digite o valor maximo: ";
    std::cin >> max;

    int encontrados = 0;
    std::cout << "\nImoveis encontrados para '" << finalidade << "' entre " << min << " e " << max << ":\n";
    for (const auto& imovel : bd) {
        if (imovel.finalidade == finalidade || (finalidade == "locacao" && imovel.finalidade == "aluguel")) {
            double valorImovel = extrairValorNumerico(imovel.valor);
            if (valorImovel >= min && valorImovel <= max) {
                exibirImovel(imovel);
                encontrados++;
            }
        }
    }
    if (encontrados == 0) {
        std::cout << "Nenhum imovel encontrado com esses criterios.\n";
    }
}

void buscarPorCaracteristicas(const std::vector<Imovel>& bd) {
    bool reqArmarios, reqAr, reqAquecedor, reqVentilador;
    std::string resposta;
    std::cout << "\n--- Busca por Caracteristicas ---\n";
    std::cout << "Deseja com armarios? (sim/nao): "; std::cin >> resposta; reqArmarios = stringParaBool(resposta);
    std::cout << "Deseja com ar-condicionado? (sim/nao): "; std::cin >> resposta; reqAr = stringParaBool(resposta);
    std::cout << "Deseja com aquecedor? (sim/nao): "; std::cin >> resposta; reqAquecedor = stringParaBool(resposta);
    std::cout << "Deseja com ventilador? (sim/nao): "; std::cin >> resposta; reqVentilador = stringParaBool(resposta);

    int encontrados = 0;
    std::cout << "\nImoveis encontrados com as caracteristicas desejadas:\n";
    for (const auto& imovel : bd) {
        if ((!reqArmarios || imovel.armarios) &&
            (!reqAr || imovel.ar_condicionado) &&
            (!reqAquecedor || imovel.aquecedor) &&
            (!reqVentilador || imovel.ventilador)) {
            exibirImovel(imovel);
            encontrados++;
        }
    }
     if (encontrados == 0) {
        std::cout << "Nenhum imovel encontrado com esses criterios.\n";
    }
}

void buscarPorQuartosESuites(const std::vector<Imovel>& bd) {
    int q, s;
    std::cout << "\n--- Busca por Quartos e Suites ---\n";
    std::cout << "Digite o numero de quartos: ";
    std::cin >> q;
    std::cout << "Digite o numero de suites: ";
    std::cin >> s;

    int encontrados = 0;
    std::cout << "\nImoveis encontrados com " << q << " quarto(s) e " << s << " suite(s):\n";
    for (const auto& imovel : bd) {
        if (imovel.quartos == q && imovel.suites == s) {
            exibirImovel(imovel);
            encontrados++;
        }
    }
     if (encontrados == 0) {
        std::cout << "Nenhum imovel encontrado com esses criterios.\n";
    }
}

void exibirRelatorioEstatisticas(const std::vector<Imovel>& bd) {
    if (bd.empty()) {
        std::cout << "Nao ha dados para gerar estatisticas.\n";
        return;
    }

    int total = bd.size();
    int countVenda = 0, countAluguel = 0, countTemporada = 0;
    int countCasas = 0, countCasasComSuite = 0;
    int countSalas = 0, countSalasComCeramica = 0;

    for (const auto& imovel : bd) {
        if (imovel.finalidade == "venda") countVenda++;
        else if (imovel.finalidade == "aluguel") countAluguel++;
        else if (imovel.finalidade == "temporada") countTemporada++;

        if (imovel.tipo == "casa") {
            countCasas++;
            if (imovel.suites > 0) {
                countCasasComSuite++;
            }
        }

        if (imovel.tipo == "sala_comercial") {
            countSalas++;
            if (imovel.piso == "ceramica") {
                countSalasComCeramica++;
            }
        }
    }
    
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "\n--- Relatorio de Estatisticas ---\n";
    std::cout << "Total de imoveis: " << total << "\n\n";

    std::cout << "1. Porcentagem por Finalidade:\n";
    std::cout << "   - Venda: " << (static_cast<double>(countVenda) / total) * 100.0 << "%\n";
    std::cout << "   - Aluguel: " << (static_cast<double>(countAluguel) / total) * 100.0 << "%\n";
    std::cout << "   - Temporada: " << (static_cast<double>(countTemporada) / total) * 100.0 << "%\n\n";

    std::cout << "2. Porcentagem de Casas com Suites:\n";
    if (countCasas > 0) {
        std::cout << "   - " << (static_cast<double>(countCasasComSuite) / countCasas) * 100.0 << "% das casas possuem suite.\n\n";
    } else {
        std::cout << "   - Nenhuma casa cadastrada.\n\n";
    }

    std::cout << "3. Porcentagem de Pisos com Ceramica nas Salas Comerciais:\n";
    if (countSalas > 0) {
        std::cout << "   - " << (static_cast<double>(countSalasComCeramica) / countSalas) * 100.0 << "% das salas comerciais tem piso de ceramica.\n";
    } else {
        std::cout << "   - Nenhuma sala comercial cadastrada.\n";
    }
    std::cout << "-----------------------------------\n";
}

void listarTodosImoveis(const std::vector<Imovel>& bd) {
     if (bd.empty()) {
        std::cout << "Nao ha imoveis cadastrados para listar.\n";
        return;
    }
    std::cout << "\n--- Listagem de Todos os Imoveis (" << bd.size() << ") ---\n";
    for(const auto& imovel : bd){
        exibirImovel(imovel);
    }
}

void exibirMenu() {
    std::cout << "\n===== MENU DE OPCOES =====\n"
              << "1. Incluir Novo Imovel\n"
              << "2. Buscar e Excluir Imovel por Rua\n"
              << "3. Buscar Imoveis por Faixa de Valor\n"
              << "4. Buscar Imoveis por Caracteristicas\n"
              << "5. Buscar Imoveis por Quartos e Suites\n"
              << "6. Relatorio de Estatisticas\n"
              << "7. Listar Todos os Imoveis\n"
              << "8. Sair e Salvar\n"
              << "==========================\n"
              << "Escolha uma opcao: ";
}


// --- FUNÇÃO PRINCIPAL ---
int main() {
    std::vector<Imovel> baseDeDados;
    const std::string nomeArquivo = "BD_Imoveis2.txt";

    carregarDados(baseDeDados, nomeArquivo);

    int opcao;
    do {
        exibirMenu();
        std::cin >> opcao;
        
        if(std::cin.fail()) {
            std::cout << "Opcao invalida. Por favor, digite um numero.\n";
            std::cin.clear();
            limparBufferEntrada();
            opcao = 0;
            continue;
        }
        
        limparBufferEntrada();

        switch (opcao) {
            case 1: incluirImovel(baseDeDados); break;
            case 2: buscarExcluirPorRua(baseDeDados); break;
            case 3: buscarPorFaixaDeValor(baseDeDados); break;
            case 4: buscarPorCaracteristicas(baseDeDados); break;
            case 5: buscarPorQuartosESuites(baseDeDados); break;
            case 6: exibirRelatorioEstatisticas(baseDeDados); break;
            case 7: listarTodosImoveis(baseDeDados); break;
            case 8:
                salvarDados(baseDeDados, nomeArquivo);
                std::cout << "Encerrando o programa...\n";
                break;
            default:
                std::cout << "Opcao invalida. Tente novamente.\n";
        }
    } while (opcao != 8);

    return 0;
}