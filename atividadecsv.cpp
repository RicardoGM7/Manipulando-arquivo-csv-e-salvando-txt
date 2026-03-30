#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
#include <vector>



using namespace std;


class Aluno{
private:
string matricula; // como nao vou fazer calculos matematicos, manti tudo como string
string nome_discente;     
string ano_ingresso;
string periodo_ingresso;
string tipo_discente;
string status_discente;
string nivel_ensino;
string nome_curso;
string modalidade_educacao;
string nome_unidade;
string nome_unidade_gestora; 

public:
Aluno(
string matriculauser, // constructor 
string nome_discenteuser,     
string ano_ingressouser,
string periodo_ingressouser,
string tipo_discenteuser,
string status_discenteuser,
string nivel_ensinouser,
string nome_cursouser,
string modalidade_educacaouser,
string nome_unidadeuser,
string nome_unidade_gestorauser) : 
matricula(matriculauser),  
nome_discente(nome_discenteuser),     
ano_ingresso(ano_ingressouser),
periodo_ingresso(periodo_ingressouser),
tipo_discente(tipo_discenteuser),
status_discente(status_discenteuser),
nivel_ensino(nivel_ensinouser),
nome_curso(nome_cursouser),
modalidade_educacao(modalidade_educacaouser),
nome_unidade(nome_unidadeuser),
nome_unidade_gestora(nome_unidade_gestorauser)
{}


string getRegistration(){ // obter numero da matricula, necessario pois os dados sao private
    return matricula;}

void ExibirDados(){ // exibir dados no console
    cout << "Matricula: " << matricula << endl;
    cout << "Nome: " << nome_discente << endl;
    cout << "Ano de Ingresso: " << ano_ingresso << endl;
    cout << "Período de Ingresso: " << periodo_ingresso << endl;
    cout << "Tipo do Discente: " << tipo_discente << endl;
    cout << "Status do Discente: " << status_discente << endl;
    cout << "Nivel de Ensino: " << nivel_ensino << endl;
    cout << "Nome do Curso: " << nome_curso << endl;
    cout << "Modalidade de Educação: " << modalidade_educacao << endl;
    cout << "Nome da Unidade: " << nome_unidade << endl;
    cout << "Nome da Unidade Gestora: " << nome_unidade_gestora << endl;
}

void SalvarDados(){ // salvar os dados obtidos 
    string nomedoarquivo = nome_discente + ".txt";
    ofstream arquivo(nomedoarquivo);
    arquivo << "Matricula: " << matricula << endl;
    arquivo << "Nome: " << nome_discente << endl;
    arquivo << "Ano de Ingresso: " << ano_ingresso << endl;
    arquivo << "Período de Ingresso: " << periodo_ingresso << endl;
    arquivo << "Tipo do Discente: " << tipo_discente << endl;
    arquivo << "Status do Discente: " << status_discente << endl;
    arquivo << "Nivel de Ensino: " << nivel_ensino << endl;
    arquivo << "Nome do Curso: " << nome_curso << endl;
    arquivo << "Modalidade de Educação: " << modalidade_educacao << endl;
    arquivo << "Nome da Unidade: " << nome_unidade << endl;
    arquivo << "Nome da Unidade Gestora: " << nome_unidade_gestora << endl;
    arquivo.close();
    cout << "Arquivo Salvo";
}

};



vector<Aluno> interpretandoCsv(string nomecsv) { // pegando os dados do csv
    SetConsoleOutputCP(CP_UTF8); // conseguir usar pontuaçao br
    ifstream arquivo(nomecsv);
    string linha; 
    vector<Aluno> listadealunos;

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo CSV." << endl; // chegagem de erro
        return listadealunos;
    }

    for (int i = 0; getline(arquivo, linha); i++) {
        if (i == 0) continue; // pular a primeira linha, pois ela nao indica um aluno

        stringstream ss(linha); // tratando a linha para conseguir usar o getline
        string coluna; 
        vector<string> campos;

        while (getline(ss, coluna, ',')) {
            if (coluna.front() == '"' && coluna.back() == '"') { // pegando cada campo presente na linha e retirando as aspas
                coluna = coluna.substr(1, coluna.size() - 2);
            }
            campos.push_back(coluna); // colocando cada campo em um vetor para ser usado para criar um objeto aluno
        }

        if (campos.size() >= 11) {
            Aluno novoAluno(
                campos[0], campos[1], campos[2], campos[3], 
                campos[4], campos[5], campos[6], campos[7],  // criando o objeto
                campos[8], campos[9], campos[10]
            );
            
            listadealunos.push_back(novoAluno); // colocando o objeto na lista de alunos
        }
    };
    return listadealunos; 
}


Aluno procuparAlunoporMatricula(vector<Aluno> lista, string matricula){
    for(int i = 0; i < lista.size(); i++){
        if(lista[i].getRegistration() == matricula){ return lista[i];}  // vericando se a matricula especificada existe na lista de alunos
}
    return Aluno("", "Nao encontrado", "", "", "", "", "", "", "", "", "");
}

 int main(){
     string alunoprocurado;
     string respostaparasalvamento = "N";

     vector<Aluno> listadealunos = interpretandoCsv("dis-csv-discentes-de-graduacao-de-2025_1.csv"); // chamando a funçao interpretando csv com o respectivo arquivo

    ////// interaçao com o usuario //////

     cout << "Digite a matricula de um aluno para obter suas informações:" << endl;
     getline(cin, alunoprocurado); // cin que le a linha inteira
     Aluno alunoencontrado = procuparAlunoporMatricula(listadealunos, alunoprocurado);
     alunoencontrado.ExibirDados();
     cout << "Deseja salvar esses dados? (S/N)";
     cin >> respostaparasalvamento;
    if(respostaparasalvamento == "S" || respostaparasalvamento == "s"){
        alunoencontrado.SalvarDados();
    }
    


    return 0; 
    }