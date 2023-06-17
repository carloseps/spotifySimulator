#pragma once

#include <string>

class Musica {
    private:
        std::string url;
        double duracaoEmSegundos;
        std::string author;

    public:
        std::string getUrl() const;

        void setUrl(std::string novaUrl);

        double getDuracaoEmSegundos() const;

        void setDuracaoEmSegundos(double novaDuracao);

        std::string getAuthor() const;

        void setAuthor(const std::string& novoAuthor);
};