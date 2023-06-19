# Simulador de Spotify em C++

Este projeto tem como objetivo desenvolver um simulador de Spotify utilizando a linguagem C++ e a API disponibilizada pelo Spotify. A intenção é aplicar conhecimentos técnicos no desenvolvimento da aplicação, proporcionando aos usuários uma experiência similar à do Spotify, permitindo pesquisar músicas, adicionar aos favoritos, criar e editar playlists, entre outras funcionalidades.

## Arquitetura MVC

O projeto foi desenvolvido seguindo o padrão arquitetural Model-View-Controller (MVC). Esse padrão organiza a aplicação em três componentes principais:

1. **Model**: O model representa os dados e a lógica de negócio da aplicação. Neste projeto, temos as classes `Usuario`, `Playlist` e `Musica` que representam os dados do usuário, playlists e músicas respectivamente. Essas classes são responsáveis por armazenar os dados e implementar as operações relacionadas a eles.

2. **View**: A view é responsável pela interface com o usuário. Neste projeto, a interface de usuário pode ser implementada utilizando bibliotecas gráficas ou uma interface de linha de comando (CLI). A view interage com o model para exibir os dados e receber as interações do usuário.

3. **Controller**: O controller atua como intermediário entre a view e o model. Ele recebe as ações do usuário através da view e manipula o model correspondente. Neste projeto, o controller seria responsável por receber as requisições do usuário, chamar os métodos adequados das classes model e atualizar a view de acordo.

## Componentes Técnicos

No desenvolvimento desse projeto, foram aplicados conhecimentos técnicos sobre:

- **Algoritmos de ordenação**: Utilizamos algoritmos de ordenação para classificar as listas de músicas e playlists de acordo com critérios específicos, como nome, mais ouvidas, etc. Isso permite que o usuário tenha uma visualização organizada e fácil de navegar.

- **Filas**: As filas serão um TAD utilizado para armazenar a fila de reprodução de músicas do usuário.

- **Listas Encadeadas e Nós**: As listas encadeadas são estruturas de dados dinâmicas que podem ser usadas para armazenar e manipular listas de músicas e playlists. Cada elemento da lista é representado por um nó, contendo os dados e uma referência para o próximo nó. Essa estrutura permite adicionar, remover e percorrer os elementos de forma eficiente.

## Resultados Esperados

Ao utilizar o simulador de Spotify desenvolvido neste projeto, os usuários poderão realizar as seguintes ações:

- Pesquisar músicas por título, autor.
- Adicionar músicas aos favoritos.
- Criar, renomear e excluir playlists.
- Adicionar músicas às playlists existentes.
- Remover músicas de playlists.
- Navegar pelas playlists e músicas do usuário.
- Reproduzir músicas e controlar a reprodução (pausar, avançar, retroceder).

Essas funcionalidades permitem que os usuários tenham uma experiência semelhante à do Spotify, personalizando suas playlists e desfrutando de suas músicas favoritas.

Esse projeto busca fornecer uma base sólida para o desenvolvimento de um simulador de Spotify em C++, aplicando conceitos avançados da linguagem e estruturas de dados eficientes.