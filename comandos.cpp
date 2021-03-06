#include "comandos.h"


// M�todo por meio do qual � solicitada a execu��o do comando.
///Metodo que implementa a execucao da inclusao de um livro na estante do usuario.
///O metodo recebe um ponteiro que permite o contato da controladora de interface de usuario com a controladora de logica de negocio.
///O metodo solicita ao usuario o codigo, titulo e g�nero do livro em questao. As entradas do usuario ja sao validadas pelos metodos "set" de cada dominio.
///As informacoes sao passadas como par�metro ao metodo de remocao no servidor.
///O resultado sera negativo apenas se o valor submetido for invalido ou causar falha no sistema.
///O metodo nao retorna nenhum valor, apenas informa se as mudancas realizadas efetivamente pela logica de negocio tiveram ou nao sucesso.
void ComandoIUUsuarioIncluir::executar(ILNUsuario* cntrLNUsuario) throw(runtime_error){

    Resultado resultado;

    Codigo codigo;
    Titulo titulo;
    GeneroLiterario generoLiterario;


    // C�digo de intera��o com o usu�rio.

    while(true){
            system("CLS");
            cout << "CODIGO_SUCESSO       - " << Codigo::CODIGO_SUCESSO << endl;
            cout << "CODIGO_FALHA         - " << Codigo::CODIGO_FALHA << endl;
            cout << "CODIGO_ERRO_SISTEMA  - " << Codigo::CODIGO_ERRO_SISTEMA << endl;

            cout << "TITULO_SUCESSO       - " << Titulo::TITULO_SUCESSO << endl;
            cout << "TITULO_FALHA         - " << Titulo::TITULO_FALHA << endl;
            cout << "TITULO_ERRO_SISTEMA  - " << Titulo::TITULO_ERRO_SISTEMA << endl;

            cout << "GENERO_FALHA         - " << GeneroLiterario::GENERO_FALHA << endl;
            cout << "GENERO_ERRO_SISTEMA  - " << GeneroLiterario::GENERO_ERRO_SISTEMA << endl;
        try{
            string codigoDoLivro;
            string tituloDoLivro;
            string generoDoLivro;
            cout << "Digite o codigo do livro: ";
            cin.sync(); //sincronizar buffer para evitar loop
            cin >> codigoDoLivro;
            codigo.setCodigo(codigoDoLivro);

            cout << "Digite o titulo do livro: ";
            cin.sync(); //sincronizar buffer para evitar loop
            cin >> tituloDoLivro;
            titulo.setTitulo(tituloDoLivro);

            cout << "Digite o genero do livro: "<< endl;
            cout << "CONTO, ENSAIO, EPOPEIA, NOVELA ou ROMANCE." << endl;
            cin.sync(); //sincronizar buffer para evitar loop
            cin >> generoDoLivro;
            generoLiterario.setGeneroLiterario(generoDoLivro);
            cin.sync(); //sincronizar buffer para evitar loop
            break;
        }
        catch(invalid_argument &exp){
            cout << "Codigo com formato incorreto" << endl;
        }
    }

    // Solicitar servi�o.

    resultado = cntrLNUsuario->incluir(codigo, titulo, generoLiterario);

    if(resultado.getValor() == Resultado::SUCESSO){
         cout << "Sucesso na execucao da operacao" << endl;
    }
    else {
        cout << "Falha na execucao da operacao" << endl;
    }
    system("PAUSE");
}

// M�todo por meio do qual � solicitada a execu��o do comando.
///Metodo que implementa a execucao da remocao de um livro na estante do usuario.
///O metodo recebe um ponteiro que permite o contato da controladora de interface de usuario com a controladora de logica de negocio.
///e solicitado ao usuario o codigo do livro em questao e este e enviado como par�metro ao metodo de remocao efetiva no servidor.
///O resultado sera negativo apenas se o valor submetido for invalido ou causar falha no sistema.
///O metodo nao retorna nenhum valor, apenas informa se a exclusao teve ou nao sucesso.
void ComandoIUUsuarioRemover::executar(ILNUsuario* cntrLNUsuario) throw(runtime_error){

    Resultado resultado;

    Codigo codigo;


    // C�digo de intera��o com o usu�rio.

    while(true){
            system("CLS");
            cout << "CODIGO_SUCESSO       - " << Codigo::CODIGO_SUCESSO << endl;
            cout << "CODIGO_FALHA         - " << Codigo::CODIGO_FALHA << endl;
            cout << "CODIGO_ERRO_SISTEMA  - " << Codigo::CODIGO_ERRO_SISTEMA << endl;
        try{
            string codigoDoLivro;
            cout << "Digite o codigo do livro: ";
            cin.sync(); //sincronizar buffer para evitar loop
            cin >> codigoDoLivro;
            codigo.setCodigo(codigoDoLivro);
            cin.sync(); //sincronizar buffer para evitar loop
            break;
        }
        catch(invalid_argument &exp){
            cout << "Codigo com formato incorreto" << endl;
        }
    }

    // Solicitar servi�o.

    resultado = cntrLNUsuario->remover(codigo);

    if(resultado.getValor() == Resultado::SUCESSO){
         cout << "Sucesso na execucao da operacao" << endl;
    }
    else {
        cout << "Falha na execucao da operacao" << endl;
    }
    system("PAUSE");
}

// M�todo por meio do qual � solicitada a execu��o do comando.
///Metodo que implementa a consulta de um livro.
///O metodo recebe um ponteiro que permite o contato da controladora de interface de usuario com a controladora de logica de negocio.
///e solicitado ao usuario o codigo do livro em questao e este e enviado como par�metro ao metodo de consulta efetiva no servidor.
///O resultado sera negativo apenas se o valor submetido for invalido ou causar falha no sistema.
///O metodo nao retorna nenhum valor, apenas informa se a exclusao teve ou nao sucesso. Se teve, as informacoes do livro sao impressas na tela.
void ComandoIUUsuarioConsultar::executar(ILNUsuario* cntrLNUsuario)throw(runtime_error){

    ResultadoLivro resultado;
    Codigo codigo;

     // C�digo de intera��o com o usu�rio.

    while(true){
            system("CLS");
            cout << "CODIGO_SUCESSO       - " << Codigo::CODIGO_SUCESSO << endl;
            cout << "CODIGO_FALHA         - " << Codigo::CODIGO_FALHA << endl;
            cout << "CODIGO_ERRO_SISTEMA  - " << Codigo::CODIGO_ERRO_SISTEMA << endl;
        try{
            string codigoDoLivro;
            cout << "Digite o codigo do livro: ";
            cin.sync(); //sincronizar buffer para evitar loop
            cin >> codigoDoLivro;
            codigo.setCodigo(codigoDoLivro);
            cin.sync(); //sincronizar buffer para evitar loop
            break;
        }
        catch(invalid_argument &exp){
            cout << "Codigo com formato incorreto" << endl;
        }
    }


    // Solicitar servi�o.


    resultado = cntrLNUsuario->consultar(codigo);

    if(resultado.getValor() == Resultado::SUCESSO){
        Livro livro;
        livro = resultado.getLivro();
         cout << "Sucesso na execucao da operacao" << endl;
         cout << "Titulo           - " << livro.getTitulo().getTitulo() << endl;
         cout << "Codigo           - " << livro.getCodigo().getCodigo() << endl;
         cout << "Genero Literario - " << livro.getGeneroLiterario().getGeneroLiterario() << endl;
    }
    else {
        cout << "Falha na execucao da operacao" << endl;
    }

    system("PAUSE");
}

// M�todo por meio do qual � solicitada a execu��o do comando.
///Metodo que implementa a pesquisa de usuario na base de dados.
///O metodo recebe um ponteiro que permite o contato da controladora de interface de usuario com a controladora de logica de negocio.
///e solicitado ao usuario o apelido do usuario em questao e este e enviado como par�metro ao metodo de pesquisa no servidor.
///O resultado sera negativo apenas se o valor submetido for invalido ou causar falha no sistema.
///O metodo nao retorna nenhum valor, apenas informa se a pesquisa teve ou nao sucesso. Se teve, os dados do usuario sao impressos em tela.
void ComandoIUUsuarioPesquisar::executar(ILNUsuario* cntrLNUsuario)throw(runtime_error){

    ResultadoUsuario resultado;
    Usuario usuario;
    Apelido apelido;

    // C�digo de intera��o com o usu�rio.

    while(true){
            system("CLS");
            
        try{
            string apelidoUsuario;
            cout << "Digite o apelido do usuario: ";
            cin.sync(); //sincronizar buffer para evitar loop
            cin >> apelidoUsuario;
            apelido.setApelido(apelidoUsuario);
            cin.sync(); //sincronizar buffer para evitar loop
            break;
        }
        catch(invalid_argument &exp){
            cout << "Apelido com formato incorreto" << endl;
        }
    }

    // Solicitar servi�o.


    resultado = cntrLNUsuario->pesquisar(apelido);

    if(resultado.getValor() == Resultado::SUCESSO){
        usuario = resultado.getUsuario();
        cout << "Sucesso na execucao da operacao" << endl;
        cout << "Nome     - " << usuario.getNome().getNome() << endl;
        cout << "Apelido  - " << usuario.getApelido().getApelido() << endl;
        cout << "Telefone - " << usuario.getTelefone().getTelefone() << endl;
    }
    else {
        cout << "Falha na execucao da operacao" << endl;
    }
    system("PAUSE");
}

///Metodo que permite o contato da controladora de interface de usuario com a controladora de logica de negocio para escrita de resenha.
///e solicitado ao usuario o titulo do livro, o texto da resenha e a data da submissao. Estes sao enviados como par�metro ao metodo de inclusao efetiva no servidor.
///O resultado sera negativo apenas se o valor submetido for invalido ou causar falha no sistema.
///O metodo nao retorna nenhum valor, apenas informa se a operacao teve ou nao sucesso.
void ComandoIUUsuarioEscrever::executar(ILNUsuario* cntrLNUsuario)throw(runtime_error){

    ResultadoResenha resultado;
    Titulo titulo;
    Texto texto;
    Data data;
    // C�digo de intera��o com o usu�rio.
    while(true){
            system("CLS");
            
        try{
            string tituloResenha;
            cout << "Digite o titulo: ";
            cin.sync(); //sincronizar buffer para evitar loop
            cin >> noskipws >> tituloResenha;

            titulo.setTitulo(tituloResenha);

            string textoResenha;
            cout << "Digite o texto da resenha: (max. 40 carac.)";
            cin.sync(); //sincronizar buffer para evitar loop
            cin >> noskipws >> textoResenha;
            texto.setTexto(textoResenha);

            string dataResenha;
            cout << "Entre com a data no formato (ddmmaa): ";
            cin.sync(); //sincronizar buffer para evitar loop
            cin >> dataResenha;
            data.setData(dataResenha);
            cin.sync(); //sincronizar buffer para evitar loop
            break;
        }
        catch(invalid_argument &exp){
            cout << "Titulo com formato incorreto" << endl;
        }
    }


    // Solicitar servi�o.


    resultado = cntrLNUsuario->escrever(titulo, texto, data);

    if(resultado.getValor() == Resultado::SUCESSO){
         cout << "Sucesso na execucao da operacao" << endl;
    }
    else {
        cout << "Falha na execucao da operacao" << endl;
    }
    system("PAUSE");
}

///O metodo recebe um ponteiro que permite o contato da controladora de interface de usuario com a controladora de logica de negocio.
///e solicitado ao usuario o titulo do livro em questao e este e enviado como par�metro ao metodo de troca efetiva em servidor.
///O resultado sera negativo apenas se o valor submetido for invalido ou causar falha no sistema.
///O metodo nao retorna nenhum valor, apenas informa se a operacao teve ou nao sucesso.
void ComandoIUUsuarioTrocar::executar(ILNUsuario* cntrLNUsuario)throw(runtime_error){

    ResultadoUsuario resultado;
    int opcao;
    Titulo titulo;

    // C�digo de intera��o com o usu�rio.
    while(true){
            system("CLS");
            cout << "1 - Indicar troca" << endl;
            cout << "2 - Procurar livros para troca" << endl;
            cout << "3 - Voltar ao menu principal" << endl;
            cin >> opcao;
        if(opcao == 1){
            string tituloTroca;
            cout << "Digite o titulo para informar troca: ";
            cin.sync(); //sincronizar buffer para evitar loop
            cin >> noskipws>> tituloTroca;
        
            titulo.setTitulo(tituloTroca);
            cin.sync(); //sincronizar buffer para evitar loop
            break;
        }else if(opcao == 2){    
            try{
                string tituloTroca;
                cout << "Digite o titulo: ";
                cin.sync(); //sincronizar buffer para evitar loop
                cin >> noskipws>> tituloTroca;
        
                titulo.setTitulo(tituloTroca);
                cin.sync(); //sincronizar buffer para evitar loop
                break;
            }
            catch(invalid_argument &exp){
                cout << "Titulo com formato incorreto" << endl;
            }
        }else if(opcao == 3){
            return;
        }else{
            cout << "Opcao invalida!" << endl;
        }
    
    }


    // Solicitar servi�o.

    if(opcao == 1){
        resultado = cntrLNUsuario->trocar(titulo, 1);
    }else{
        resultado = cntrLNUsuario->trocar(titulo, 2); 
    }
    

    if((resultado.getValor() == Resultado::SUCESSO)&&(opcao == 2)){
         cout << "Sucesso na execucao da operacao" << endl;
         cout << "Foi encontrado um usuario que possui o livro para troca" << endl;
         cout << "Livro    - " << titulo.getTitulo() << endl;
         cout << "Nome     - " << resultado.getUsuario().getNome().getNome() << endl;
         cout << "Apelido  - " << resultado.getUsuario().getApelido().getApelido() << endl;
         cout << "Telefone - " << resultado.getUsuario().getTelefone().getTelefone() << endl;
    }
    else {
        cout << "Falha na execucao da operacao" << endl;
    }
    system("PAUSE");
}
