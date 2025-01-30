<p align="center">
  <img src="https://img.shields.io/github/languages/top/PedroFnseca/rest-api-C" alt="Language">
  <img src="https://hits.sh/github.com/PedroFnseca/rest-api-C.svg?view=today-total" alt="Hits">
  <img src="https://img.shields.io/github/license/PedroFnseca/rest-api-C" alt="License">
  <img src="https://img.shields.io/github/stars/PedroFnseca/rest-api-C?style=social" alt="Stars">
  <img src="https://img.shields.io/github/forks/PedroFnseca/rest-api-C?style=social" alt="Forks">
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

This project implements a **RESTful web server** in **C**, leveraging the [libmicrohttpd](https://www.gnu.org/software/libmicrohttpd/) library. libmicrohttpd is a lightweight, designed for simplicity and efficiency, making it an excellent choice for building low-level web servers.

The server handles HTTP requests, manages routing, and interacts with a PostgreSQL database using the **libpq** library. It demonstrates core concepts such as:
- **HTTP request/response handling**
- **Database connectivity** (via PostgreSQL)
- **Memory management** in C
- **Low-level socket programming**

For a deeper dive into the implementation, refer to the official [libmicrohttpd manual](https://www.gnu.org/software/libmicrohttpd/manual/libmicrohttpd.html#Simple-HTTP-server-example), which provides a detailed example of a simple HTTP server.

## Why Choose C for This Project?

The C programming language was chosen for this project due to its low-level capabilities, which provide fine-grained control over system resources and memory management. By implementing a RESTful web server in C, this project demonstrates how to handle HTTP requests, manage sockets, and interact with system libraries like **libmicrohttpd** and **libpq** for database connectivity.

C is particularly well-suited for this type of application because:

- **Performance**: C allows for highly optimized code, making it ideal for building lightweight and efficient servers.
- **Portability**: C code can be compiled and run on a wide range of platforms, from embedded systems to modern servers.
- **Direct System Interaction**: C provides direct access to system calls and hardware, enabling a deeper understanding of how web servers and APIs operate at a lower level.
- **Minimal Dependencies**: Unlike higher-level languages, C minimizes reliance on external frameworks, resulting in a smaller and more self-contained application.

> ✏️ **Note**:: This project serves as a practical example of how to build a RESTful API in a language that is often overlooked for web development but remains foundational in systems programming.

### Key Benefits of Using C:
- **Efficiency**: Low memory footprint and high execution speed.
- **Control**: Full control over memory allocation, pointers, and system resources.
- **Learning Opportunity**: A deeper understanding of networking, HTTP protocols, and database interactions without the abstraction of higher-level frameworks.

---

## Database Configuration

This project uses a **PostgreSQL** database to store user information. The database is hosted on [Supabase](https://supabase.com/), a cloud-based platform that provides a fully managed PostgreSQL database. The server communicates with the database using the [libpq](https://www.postgresql.org/docs/current/libpq.html) library, which is the official C API for PostgreSQL.

### Database Schema

The database consists of a single table named `users`, designed to store user data. Below is the schema for the `users` table:

| Column Name | Data Type | Description                     |
| ----------- | --------- | ------------------------------- |
| `id`        | SERIAL    | Unique identifier for each user.|
| `name`      | TEXT      | The name of the user.           |
| `email`     | TEXT      | The email address of the user.  |

---

## How to Run the Server

### Prerequisites
Before running the server, ensure you have the following installed:
- [x] **GCC Compiler**: Required to compile the C code.
- [x] **Make Utility**: Used to simplify the build process.
- [x] **Docker** (Optional): For running the server in a containerized environment.

### Step-by-Step:

1. **Clone the Repository**
   ```bash	
   git clone https://github.com/PedroFnseca/rest-api-C.git

2. Navigate to the Project Directory
   ```bash
   cd rest-api-C

3. Update the Database Credentials
   - Open the `pg.h` file in the `src` directory.
   - Update the variables with your database credentials.
     ```c
     #define DB_HOST "your_database_host"
     #define DB_NAME "your_database_name"
     #define DB_USER "your_database_user"
     #define DB_PASSWORD "your_database_password"
     #define DB_PORT "your_database_port"

4. Running the Server:
   - Enter the folder `scripts`:
     ```bash
     cd scripts

   - Option 1: Using Docker (Recommended for Linux):
     ```bash
      ./docker_run.sh
     
   - Option 2: Without Docker (Linux):
     ```bash
     ./compiler.sh --run

5. Access the API at `http://localhost:8080`

---

## Endpoints

This RESTful web server provides the following endpoints.

- **GET /users:** Retrieve a list of users.
- **GET /users/{id}:** Retrieve detailed information about a specific user.
- **POST /users:** Create a new user.
- **PUT /users/{id}:** Update information for a specific user.
- **DELETE /users/{id}:** Delete a user.

---

## Related Articles

Here are some articles I’ve written about this project:

- 📚 [Growing as a Developer: My Experience Building an API in C](https://medium.com/@pedrofnseca/evoluindo-como-desenvolvedor-minha-experi%C3%AAncia-com-a-api-feita-em-c-69b758801c91) *(Written in Portuguese)*
- 📝 [How to create an rest api using C](https://pedrofnseca.medium.com/how-to-create-an-rest-api-using-c-9150882320d4) *(Written in English)*
