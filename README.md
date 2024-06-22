# RapidCache

RapidCache is a high-performance, in-memory database built in C, designed for fast data retrieval and storage. It supports key-value data structures, persistence, and advanced caching strategies, making it ideal for applications requiring quick access to large volumes of data, such as real-time analytics, caching, and session management.

## Features

- **In-Memory Storage**: Lightning-fast read and write operations.
- **Key-Value Data Structures**: Efficient handling of simple and complex data types.
- **Persistence**: Save data to disk to prevent data loss.
- **Advanced Caching Strategies**: LRU, LFU, and more.
- **Concurrency**: Multi-threaded operations for optimal performance.

## Installation

### Prerequisites

- GCC compiler
- Make

### Steps

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/rapidcache.git
    ```
2. Navigate to the RapidCache directory:
    ```bash
    cd rapidcache
    ```
3. Compile the source code:
    ```bash
    make
    ```

## Usage

### Starting the Server

To start the RapidCache server, run:
```bash
./rapidcache
```
## Using the Client

Interact with the server using the built-in client or any Redis-compatible client.

```bash
./rapidcache-cli set key value
./rapidcache-cli get key
./rapidcache-cli delete key
./rapidcache-cli persist
./rapidcache-cli load
```

## API
```bash
SET key value
GET key
DELETE key
PERSIST // Saves the current state to disk.
LOAD
```
## Contributing
- Fork the repository
- Create a new branch (git checkout -b feature-branch)
- Commit your changes (git commit -am 'Add new feature')
- Push to the branch (git push origin feature-branch)
- Create a new Pull Request

## Acknowledgments
- Inspired by Redis
- Thanks to the open-source community for their invaluable contributions
