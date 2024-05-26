# Musical Salon

## Description
Our Musical Salon is a constantly operating music store that sells CDs featuring recordings from specific artists, provided by various production companies. The store management maintains detailed information about CDs, artists, and transactions involving the receipt and sale of CDs. This application helps manage and retrieve detailed information about CDs, their sales, and popular artists as well as offers an opportunity to purchase CDs.

## Installation
### Pre-requirements
- Operating System: Linux Ubuntu
- OpenSSL library installed
- CMake installed
- Google Tests library for testing
- g++ compiler

#### To install the application locally, follow these steps:

1. **Clone the repository**:
    ```bash
    git clone https://github.com/fpmi-tp2024/tpmp-rvn-lab5-the_musical_prodigy.git
	cd tpmp-rvn-lab5-the_musical_prodigy
    ```

2. **Clone SQLiteCpp Library**:
    ```bash
	git clone https://github.com/SRombauts/SQLiteCpp.git
    ```
	- Make sure that SQLiteCpp folder is inside your project folder (tpmp-rvn-lab5-		the_musical_prodigy)
3. **Build the project**:
    ```bash
	cmake CMakeLists.txt
	make
    ```

4. **Enter the following command to launch the application**:
    ```bash
	./solution
	```

### Launching tests

1. **Copy SQLiteCpp directory into tests directory**:
	 ```bash
	cp -r SQLiteCpp/ tests/
	```
2.  **Use create_test_DB script to create test database**:
	 ```bash
	./create_test_DB
	cd tests
	```
3. **Build tests**:
	```bash
	cmake CMakelists.txt
	make
	```
4. **Enter the following command to launch the tests**:
	 ```bash
	./runTests
	```
5. **If you want to generate test coverage instead of just launching tests, use tests_coverage script**:
	```bash
	./tests_coverage
	```
	- The html-coverage files will be generated in tests_coverage_report folder  
6. **After you are done, remove test database**:
	 ```bash
	cd ..
	./remove_test_DB
	```
7. **If you want to launch the tests again, do everything step-by-step from the 2nd step**

## Usage

After installing the application, you can use it to manage and query information about CDs and artists. Here are some examples of what you can do:

- **View CD inventory**: Retrieve information about the quantity of sold and remaining CDs, sorted by the difference in quantity.
- **Query specific CD sales**: Get details about the quantity and total cost of CDs sold within a specified period.
- **Popular CDs and Artists**: Identify the most sold CD and the most popular artist, along with detailed information about their recordings and sales.
- **Author Sales Information**: Obtain sales data for each author, including the number of CDs sold and the total revenue.
- **Buy CDs**: Buy available CDs from our stock.


## Contributing

The project was developed by the following contributors:
- **Maria Gorelik**: Project Manager and team leader, database design, View-Controller implementation, UML-Diagrams. 
- **Timofey Kremko**: Database implementation, Model implementation (queries and functions), README file, GitHub Wiki, writing scripts for tests coverage.
- **Stanislav Napreenko**: QA and testing, continious integration with GitHub Actions, DevOps.

Tasks completed include:

1. Creation of database tables with integrity constraints.
2. Implementation of `SELECT` queries to retrieve various information:
    - CD inventory details.
    - Sales data for specific CDs and periods.
    - Information about the most sold CD and popular artists.
    - Author sales data.
3. Implementation of `INSERT`, `UPDATE`, and `DELETE` operations for updating database information.
4. Creation of functions to:
    - Prevent the sale of CDs if the total sold exceeds the total received.
    - Determine the number of CDs received and sold within a given period.
    - Retrieve sales results for a specific CD within a given period.