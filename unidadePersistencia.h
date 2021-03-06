//---------------------------------------------------------------------------

#ifndef unidadePersistenciaH
#define unidadePersistenciaH
//---------------------------------------------------------------------------

#include "dominios.h"
#include "entidades.h"
#include <list>

// Posteriomente remover.

#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>

#include "sqlite3.h"

using namespace std;

//---------------------------------------------------------------------------
//Classe EErroPersistencia.

class EErroPersistencia {
private:
        string mensagem;
public:
        EErroPersistencia(string);
        string what();
};

//---------------------------------------------------------------------------
//Classe ElementoResultado.

class ElementoResultado {
private:
        string nomeColuna;
        string valorColuna;
public:
        void setNomeColuna(const string&);
        string getNomeColuna() const;
        void setValorColuna(const string&);
        string getValorColuna() const;
};

//---------------------------------------------------------------------------
//Classe ComandoSQL.

class ComandoSQL {
private:
        const char *nomeBancoDados;
        sqlite3 *bd;
        char *mensagem;
        int rc;
        void conectar() throw (EErroPersistencia);
        void desconectar() throw (EErroPersistencia);
        static int callback(void *, int, char **, char **);

protected:
        static list<ElementoResultado> listaResultado;
        string comandoSQL;
public:
        ComandoSQL() {
             //Informa o nome do banco de dados.
             nomeBancoDados = "bancoEstante.db";
        }
        void executar() throw (EErroPersistencia);
};


//---------------------------------------------------------------------------
//Classe ComandoLerSenha.

class ComandoLerSenha:public ComandoSQL {
public:
        ComandoLerSenha(Usuario);
        string getResultado() throw (EErroPersistencia);
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarUsuario.

class ComandoPesquisarUsuario:public ComandoSQL {
public:
        ComandoPesquisarUsuario(Apelido);
        Usuario getResultado() throw (EErroPersistencia);
};

//---------------------------------------------------------------------------
//Classe ComandoCadastrarUsuario.

class ComandoCadastrarUsuario:public ComandoSQL {
public:
        ComandoCadastrarUsuario(Usuario);
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarUsuario.

class ComandoAtualizarUsuario:public ComandoSQL {
public:
        ComandoAtualizarUsuario(Usuario);
};

//---------------------------------------------------------------------------
//Classe ComandoRemoverUsuario.

class ComandoRemoverUsuario:public ComandoSQL {
public:
        ComandoRemoverUsuario(Apelido);
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarLivro.

class ComandoPesquisarLivro:public ComandoSQL {
public:
        ComandoPesquisarLivro(Codigo);
        ComandoPesquisarLivro(Titulo);
        Livro getResultado() throw (EErroPersistencia);
};


//---------------------------------------------------------------------------
//Classe ComandoCadastrarLivro.

class ComandoCadastrarLivro:public ComandoSQL {
public:
        ComandoCadastrarLivro(Livro);
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarLivro.

class ComandoAtualizarLivro:public ComandoSQL {
public:
        ComandoAtualizarLivro(Livro);
};

//---------------------------------------------------------------------------
//Classe ComandoRemoverLivro.

class ComandoRemoverLivro:public ComandoSQL {
public:
        ComandoRemoverLivro(Codigo);
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarExemplar.

class ComandoPesquisarExemplar:public ComandoSQL {
public:
        ComandoPesquisarExemplar(Codigo);
        ComandoPesquisarExemplar(Apelido);
        Exemplar getResultado() throw (EErroPersistencia);
};


//---------------------------------------------------------------------------
//Classe ComandoCadastrarExemplar.

class ComandoCadastrarExemplar:public ComandoSQL {
public:
        ComandoCadastrarExemplar(Exemplar);
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarExemplar.

class ComandoAtualizarExemplar:public ComandoSQL {
public:
        ComandoAtualizarExemplar(Exemplar);
};

//---------------------------------------------------------------------------
//Classe ComandoRemoverExemplar.

class ComandoRemoverExemplar:public ComandoSQL {
public:
        ComandoRemoverExemplar(Codigo);
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarResenha.

class ComandoPesquisarResenha:public ComandoSQL {
public:
        ComandoPesquisarResenha(Codigo);
        ComandoPesquisarResenha(Apelido);
        Resenha getResultado() throw (EErroPersistencia);
};


//---------------------------------------------------------------------------
//Classe ComandoCadastrarResenha.

class ComandoCadastrarResenha:public ComandoSQL {
public:
        ComandoCadastrarResenha(Resenha);
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarResenha.

class ComandoAtualizarResenha:public ComandoSQL {
public:
        ComandoAtualizarResenha(Resenha);
};

//---------------------------------------------------------------------------
//Classe ComandoRemoverResenha.

class ComandoRemoverResenha:public ComandoSQL {
public:
        ComandoRemoverResenha(Codigo);
};

//---------------------------------------------------------------------------
//Classe ElementoResultado.

inline string ElementoResultado::getNomeColuna() const {
        return nomeColuna;
}

inline string ElementoResultado::getValorColuna() const {
        return valorColuna;
}


#endif
