<p align="center">

  <img src="https://img.shields.io/github/last-commit/PedroFnseca/rest-api-C" alt="Last Commit">
  
  <img src="https://img.shields.io/github/languages/top/PedroFnseca/rest-api-C" alt="Language">

   <img src="https://hits.sh/github.com/PedroFnseca/rest-api-C.svg?view=today-total" alt="Hits">
</p>

# A Simple RESTful Web Server in PURE C
<div align=center>
   <a href="./README-PT.md">
   Versão em Português
   </a>
   |
   <a href="https://medium.com/@pedrofnseca/evoluindo-como-desenvolvedor-minha-experi%C3%AAncia-com-a-api-feita-em-c-69b758801c91" target="_blank">
   Article
   </a>
</div>
<br>

RESTful web server in C using [libmicrohttpd](https://www.gnu.org/software/libmicrohttpd/), a lightweight HTTP server library.

For a detailed example, you can refer to the [libmicrohttpd manual](https://www.gnu.org/software/libmicrohttpd/manual/libmicrohttpd.html#Simple-HTTP-server-example).

## Why Choose C for This Project?

I've deliberately chosen the C programming language for this project to challenge myself and revisit my programming roots. C was my first language, and it remains my favorite. Additionally, C finds extensive use in embedded systems and real-time applications, which are areas I particularly enjoy exploring as a hobbyist.

My primary goal was to gain a deeper understanding of how APIs function under the hood and how they communicate with the underlying operating system. The C language is exceptionally suited for this purpose due to its low-level nature and direct interaction with hardware and system resources.

## Postgres Database
In this project, I'm using a Postgres database to store user information. The database is hosted on cloud in the [supabase](https://supabase.com/), and the server communicates with it using the [libpq](https://www.postgresql.org/docs/9.1/libpq.html) library.

## How to Run the Server

### Prerequisites:
- [x] Docker installed on your machine (Optional)
- [x] GCC compiler installed
- [x] Make utility installed

### Step-by-Step:

1. Clone the Repository
   ```bash	
   git clone https://github.com/PedroFnseca/rest-api-C.git
   ```

2. Navigate to the Project Directory
   ```bash
   cd rest-api-C
   ```

3. Update the Database Credentials
   - Open the `pg.h` file in the `src` directory.
   - Update the variables with your database credentials.

4. Running the Server:
   - Using Docker (Linux):
     ```bash
      ./scripts/docker_run.sh
     ```
   - Without Docker (Linux):
     ```bash
     ./scripts/main_run.sh
     ```

5. Access the API at http://localhost:8080

## Endpoints

This RESTful web server provides the following endpoints.

- **GET /users:** Retrieve a list of users.
- **GET /users/{id}:** Retrieve detailed information about a specific user.
- **POST /users:** Create a new user.
- **PUT /users/{id}:** Update information for a specific user.
- **DELETE /users/{id}:** Delete a user.
