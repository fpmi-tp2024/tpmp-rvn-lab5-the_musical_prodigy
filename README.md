# The Music Salon
## Installation
### Pre-requirements
- Operating System: Linux Ubuntu
- OpenSSL library installed
- CMake installed
- Google Tests library for testing
### Installation Process
- Clone the repository:
```shell
git clone https://github.com/fpmi-tp2024/tpmp-rvn-lab5-the_musical_prodigy.git
cd tpmp-rvn-lab5-the_musical_prodigy
```
- Clone SQLiteCpp Library
 ```shell
git clone https://github.com/SRombauts/SQLiteCpp.git
```
- Make sure that SQLiteCpp folder is inside your project folder (tpmp-rvn-lab5-the_musical_prodigy)
- Build the project
 ```shell
cmake CMakeLists.txt
make
```
- Enter the following command to launch the application
 ```shell
./solution
```
### Launching tests

1. Copy SQLiteCpp directory into tests directory
 ```shell
cp -r SQLiteCpp/ tests/
```
2.  Use create_test_DB script to create test database
 ```shell
./create_test_DB
cd tests
```
3. Build tests
 ```shell
cmake CMakelists.txt
make
```
4. Enter the following command to launch the tests
 ```shell
./runTests
```
5. After you are done, remove test database
 ```shell
cd ..
./remove_test_DB
```
6. If you want to launch the tests again, do everything step-by-step from the 2nd step
