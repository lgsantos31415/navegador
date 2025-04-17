# Navegador

Este projeto foi desenvolvido com o objetivo de explorar e compreender o funcionamento básico de um navegador web. O foco principal foi implementar as funcionalidades essenciais para interpretar e renderizar uma página HTML.

## Funcionalidades Principais

1. **Requisições HTTP**  
   Para realizar requisições do lado do cliente, foi utilizada a biblioteca `httplib`, que oferece suporte a protocolos HTTP e HTTPS. Essa escolha se deve à sua simplicidade e eficiência, permitindo que o navegador obtenha o conteúdo das páginas web de forma direta e confiável.

2. **Análise Sintática de HTML**  
   A interpretação do código HTML foi realizada com o auxílio do **Gumbo Parser**, uma biblioteca completa especializada em análise sintática de HTML5 escrita em C. O Gumbo Parser garante que o navegador seja capaz de processar corretamente a estrutura dos documentos HTML.

3. **Interface Gráfica e Renderização**  
   A interface gráfica e a renderização do conteúdo HTML foram desenvolvidas utilizando o **FLTK (Fast Light Toolkit)**, uma biblioteca gráfica open-source conhecida por sua leveza, simplicidade e eficiência.

## Recursos Implementados

Atualmente, o navegador é capaz de interpretar e renderizar as seguintes tags:

- **`<h1>`**: Exibe títulos principais.
- **`<p>`**: Renderiza parágrafos de texto.

Essas funcionalidades básicas permitem visualizar o conteúdo de páginas simples, servindo como ponto de partida para expandir o suporte a mais elementos HTML e melhorar a experiência do usuário.

## Objetivo do Projeto

O desenvolvimento deste projeto tem como propósito educacional e o estudo prático de tecnologias envolvidas na construção de navegadores modernos.

Além disso, o projeto proporciona uma compreensão mais profunda sobre os processos de comunicação via HTTP, análise sintática de HTML e renderização gráfica.
