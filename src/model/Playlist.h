#pragma once

#include "./list/ListaDuplamenteEncadeada.h"

class Playlist {
    private:
        ListaDuplamenteEncadeada* listaDeMusicas;
        bool isPublica;
        std::string author;

    public:
        ListaDuplamenteEncadeada* getListaDeMusicas() const;

        void setListaDeMusicas(ListaDuplamenteEncadeada* novaLista);

        bool isPublica() const;

        void setIfIsPublica(bool novoValor);

        std::string getAuthor() const;

        void setAuthor(const std::string& novoAuthor);
};