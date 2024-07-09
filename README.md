# Projeto-Computacional

Projeto Computacional de Jogo da Velha em C++

# Introdução

O projeto de desenvolvimento de um Jogo da Velha (Tic-Tac-Toe) em C++ visa proporcionar uma experiência prática de programação, abordando conceitos fundamentais de lógica, estrutura de dados e interação com o usuário. Este projeto é uma excelente oportunidade para estudantes e entusiastas de programação aplicarem seus conhecimentos em um contexto divertido e desafiador.

# Objetivos

Os principais objetivos do projeto são:

Desenvolver uma aplicação de jogo interativa: Criar uma interface de linha de comando onde dois jogadores podem competir.
Implementar lógica de jogo: Garantir que as regras do Jogo da Velha sejam corretamente aplicadas, incluindo a verificação de vitórias e empates.
Praticar boas práticas de programação: Utilizar princípios de programação estruturada e modular, com ênfase em clareza e manutenção do código.

# Estrutura do Projeto

O projeto é dividido em várias partes principais:

Inicialização do Tabuleiro:

-O tabuleiro de jogo é representado por uma matriz 3x3 de caracteres.
-Uma função inicializa o tabuleiro, preenchendo-o com espaços vazios.

Exibição do Tabuleiro:

-Uma função é responsável por exibir o estado atual do tabuleiro para os jogadores, facilitando a visualização das jogadas.

Controle de Jogadas:

-O jogo alterna entre os jogadores 'X' e 'O', solicitando que cada um insira suas jogadas.
-As jogadas são validadas para garantir que sejam dentro dos limites do tabuleiro e em espaços não ocupados.

Verificação de Condições de Vitória:

-Após cada jogada, o jogo verifica se há uma linha, coluna ou diagonal completa com o mesmo símbolo, determinando o vencedor.
-Também verifica se o tabuleiro está cheio, indicando um empate.

Interatividade e Loop Principal:

-O jogo continua até que haja um vencedor ou um empate.
-Ao final de cada partida, os jogadores são perguntados se desejam jogar novamente.

# Tecnologias Utilizadas
-Linguagem de Programação C++: Escolhida pela sua eficiência e pelo controle detalhado que oferece sobre recursos de sistema.
-Compilador GCC: Utilizado para compilar o código C++.
-Ambiente de Desenvolvimento: Qualquer IDE ou editor de texto compatível com C++, como Visual Studio Code, CLion ou mesmo o terminal com um editor como Vim ou Nano.

# Conclusão
  Este projeto de Jogo da Velha em C++ serve como uma excelente introdução ao desenvolvimento de jogos e à programação em geral. Ele abrange conceitos essenciais como controle de fluxo, manipulação de arrays, e interação com o usuário, além de promover o desenvolvimento de habilidades de resolução de problemas. Ao final, os participantes terão uma compreensão mais profunda das técnicas de programação e uma base sólida para projetos mais complexos.

