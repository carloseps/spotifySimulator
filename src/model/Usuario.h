#pragma once

#include "./list/ListaDuplamenteEncadeada.h"
#include "./model/Playlist.h"

#include <string>

class Usuario {
    private:
        std::string username;
        std::string senha;

        //Fila
        ListaDuplamenteEncadeada* musicasFavoritas;

        //Pilha
        ListaDuplamenteEncadeada* playlists;

    public:
        Usuario(void);
        ~Usuario(void);

        std::string getUsername() const;

        void setUsername(std::string u);

        std::string getSenha() const;

        void setSenha(std::string s);

        ListaDuplamenteEncadeada* getMusicasFavoritas() const;

        ListaDuplamenteEncadeada* getPlaylists() const;

};

