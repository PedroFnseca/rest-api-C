# A Simple RESTful Web Server in PURE C

RESTful web server in C using [libmicrohttpd](https://www.gnu.org/software/libmicrohttpd/), a lightweight HTTP server library.

> For a detailed example, you can refer to the [libmicrohttpd manual](https://www.gnu.org/software/libmicrohttpd/manual/libmicrohttpd.html#Simple-HTTP-server-example).

## Why Choose C for This Project?

I've deliberately chosen the C programming language for this project to challenge myself and revisit my programming roots. C was my first language, and it remains my favorite. Additionally, C finds extensive use in embedded systems and real-time applications, which are areas I particularly enjoy exploring as a hobbyist.

My primary goal was to gain a deeper understanding of how APIs function under the hood and how they communicate with the underlying operating system. The C language is exceptionally suited for this purpose due to its low-level nature and direct interaction with hardware and system resources.

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

3. Running the Server:
   - Using Docker:
     ```bash
     docker build -t rest-api-c .
     docker run -d -p 8080:80 --name rest-api-c rest-api-c
     ```
   - Without Docker (Linux):
     ```bash
     ./main_run.sh
     ```
   - Without Docker (Windows):
     ```bash
     make
     ./bin/main
     ```

4. Access the API at http://localhost:8080

## Endpoints (Work in Progress)

This RESTful web server provides the following endpoints (please note that this section is a work in progress):

- **GET /:** Welcome message and basic information about the API (not yet implemented).
- **GET /users:** Retrieve a list of users (not yet implemented).
- **GET /users/{id}:** Retrieve detailed information about a specific user (not yet implemented).
- **POST /users:** Create a new user (not yet implemented).
- **PUT /users/{id}:** Update information for a specific user (not yet implemented).
- **DELETE /users/{id}:** Delete a user (not yet implemented).

These endpoints will serve as a starting point for interacting with the API once the development is complete. You can use tools like `curl` or web browsers to perform requests and test the server's functionality. Each endpoint adheres to the principles of a RESTful API, providing clear and predictable behavior.
