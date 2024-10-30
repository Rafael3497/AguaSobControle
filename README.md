# Água Sob Controle

### Monitoramento do Nível da Água e Vazão Utilizando Dispositivos IoT

Este projeto foi desenvolvido para monitorar o nível de água e a vazão em caixas d’água utilizando sensores e tecnologia IoT. O objetivo principal é otimizar o uso da água para atividades essenciais de um centro comunitário, facilitando o monitoramento e a gestão hídrica à distância.

## Sumário
- [Introdução](#introdução)
- [Objetivos](#objetivos)
- [Tecnologias Utilizadas](#tecnologias-utilizadas)
- [Componentes do Sistema](#componentes-do-sistema)
- [Arquitetura do Sistema](#arquitetura-do-sistema)
- [Implementação](#implementação)
- [Resultados](#resultados)
- [Equipe](#equipe)

## Introdução
Este projeto atende ao Centro Espírita Beneficente UDV - Núcleo Estrela Brilhante, que enfrenta dificuldades para monitorar a disponibilidade de água em duas caixas de 20 mil litros cada. O sistema de abastecimento depende de uma nascente natural, mas o monitoramento manual tem se mostrado ineficiente, levando a períodos de escassez de água. O projeto propõe uma solução para medir o nível e a vazão de água utilizando sensores conectados via IoT.

## Objetivos
- Desenvolver um protótipo para o monitoramento do nível e da vazão de água.
- Facilitar o acesso ao monitoramento remoto, reduzindo a necessidade de deslocamento.
- Promover a sustentabilidade através de um sistema alimentado por energia solar.

## Tecnologias Utilizadas
- **Placa ESP32**: Microcontrolador com conectividade Wi-Fi e Bluetooth.
- **Firebase**: Banco de dados em tempo real para armazenamento e visualização dos dados.
- **Power BI**: Ferramenta de visualização de dados para dashboards interativos.
- **Sensores**: Sensor de fluxo de água (FS400A) e sensor ultrassônico à prova d'água (JSN-SR04T).
- **Energia Solar**: Utilizada para alimentar o sistema.

## Componentes do Sistema
- **Sensor de Fluxo FS400A**: Mede a vazão da água.
- **Sensor Ultrassônico JSN-SR04T**: Monitora o nível da água.
- **Modem 4G**: Fornece conectividade à internet para a ESP32 em áreas sem Wi-Fi.
- **Placa Solar e Bateria**: Garante o funcionamento contínuo do sistema.

## Arquitetura do Sistema
1. **Sensores** coletam dados sobre o nível e a vazão da água.
2. **ESP32** processa as leituras e envia para o Firebase.
3. **Firebase** armazena os dados em tempo real.
4. **Power BI** exibe os dados em gráficos e relatórios.

## Implementação
O código do sistema foi escrito em Arduino, incluindo bibliotecas para comunicação com Wi-Fi, Firebase e manipulação dos sensores. Veja os arquivos de código neste [repositório](https://github.com/Rafael3497/AguaSobControle.git).

### Instalação
1. Configure a ESP32 com as credenciais Wi-Fi.
2. Carregue o código do Arduino para ESP32.
3. Conecte os sensores e a bateria solar de acordo com o esquema elétrico.
4. Visualize os dados no Firebase e Power BI.

## Resultados
O sistema oferece monitoramento remoto eficiente do nível e da vazão da água, garantindo uma gestão hídrica sustentável e confiável. O projeto impacta diretamente o centro comunitário, reduzindo deslocamentos e prevenindo problemas de abastecimento.

## Equipe
- **Arthur André Carneiro Alves**
- **Fernando Sampaio Costa**
- **Francisco Rafael Silveira Ye**
- **Francisco Rodrigo Rocha Mota**
- **William Santiago Gomes Júnior**
- **Ingridy Crislayne Ferreira Feitosa**

Professor Orientador: Manoel Miqueias Maia

## Licença
Este projeto é distribuído sob a licença MIT. Veja [LICENSE](Rafael_Ye) para mais informações.
