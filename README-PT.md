# Uma Simples API em C puro
<div align=center>
   <a href="./README.md">
   English Version
   </a>
   |
   <a href="https://medium.com/@pedrofnseca/evoluindo-como-desenvolvedor-minha-experi%C3%AAncia-com-a-api-feita-em-c-69b758801c91" target="_blank">
   Artigo
   </a>
</div>
<br>

Servidor web RESTful em C puro usando [libmicrohttpd](https://www.gnu.org/software/libmicrohttpd/), uma biblioteca de servidor HTTP leve.

Para um exemplo detalhado, você pode se referir ao [manual do libmicrohttpd](https://www.gnu.org/software/libmicrohttpd/manual/libmicrohttpd.html#Simple-HTTP-server-example).

## Por que Escolher C para Este Projeto?

Escolhi deliberadamente a linguagem de programação C para este projeto para me desafiar e revisitar minhas raízes de programação. C foi minha primeira linguagem e continua sendo minha favorita. Além disso, C encontra uso extensivo em sistemas embarcados e aplicações em tempo real, áreas que particularmente gosto de explorar como um entusiasta.

Meu objetivo principal era obter uma compreensão mais profunda de como as APIs funcionam sob o capô e como elas se comunicam com o sistema operacional. A linguagem C é excepcionalmente adequada para esse propósito devido à sua natureza de baixo nível e interação direta com hardware e recursos do sistema.

## Banco de Dados Postgres

Neste projeto, estou usando um banco de dados Postgres para armazenar informações do usuário. O banco de dados é hospedado na nuvem no [supabase](https://supabase.com/), e o servidor se comunica com ele usando a biblioteca [libpq](https://www.postgresql.org/docs/9.1/libpq.html).

## Como Executar o Servidor

### Pré-requisitos:
- [x] Docker instalado em sua máquina (Opcional)
- [x] Compilador GCC instalado
- [x] Utilitário Make instalado

### Passo a Passo:

1. Clone o Repositório
   ```bash	
   git clone
    ```
2. Navegue até o Diretório do Projeto
    ```bash
    cd rest-api-C
    ```
3. Atualize as Credenciais do Banco de Dados
    - Abra o arquivo `pg.h` no diretório `src`.
    - Atualize as variáveis com suas credenciais de banco de dados.

4. Executando o Servidor:
    - Usando Docker:
      ```bash
      docker build -t rest-api-c .
      docker run -d -p 8080:80 --name rest-api-c rest-api-c
      ```
    - Sem Docker (Linux):
      ```bash
      ./main_run.sh
      ```
    - Sem Docker (Windows):
      ```bash
      ./main_run.bat
      ```
5. Acesse o servidor em `http://localhost:8080/` no seu navegador.
```

## Endpoints

Essa API possui os seguintes endpoints:

- `GET /users`: Retorna todos os usuários cadastrados.
- `GET /users/:id`: Retorna um usuário específico com base no ID fornecido.
- `POST /users`: Adiciona um novo usuário ao banco de dados.
- `PUT /users/:id`: Atualiza as informações de um usuário existente.
- `DELETE /users/:id`: Remove um usuário do banco de dados.
