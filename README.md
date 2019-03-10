Requirements
===
In order to build CppDB you need following:

CMake 2.6 and above
- Decent C++ compiler like GCC, Intel or MSVC.
- SQL library API you want to use:
- Sqlite3 - the library and headers themselfs
- MySQL - libmysqlclient
- PostgreSQL - libpq
- ODBC - unixodbc for POSIX operating systems and Window's build in odbc API for windows.

Build Options
===
Following CMake "ON", "OFF" options options provided for better customizability, all turned off by default:

- DISABLE_SQLITE - don't build sqlite3 backend even if the library was found
- SQLITE_BACKEND_INTERNAL - don't build a separate sqlite3 loadable module but rather build it into the cppdb library itself.
- DISABLE_MYSQL - don't build mysql backend even if the mysqlclient library was found
- MYSQL_BACKEND_INTERNAL - don't build a separate mysql loadable module but rather build it into the cppdb library itself.
- DISABLE_PQ - don't build postgresql backend even if the libpq library was found
- PQ_BACKEND_INTERNAL - don't build a separate postgresql loadable module but rather build it into the cppdb library itself.
- DISABLE_ODBC - don't build odbc backend even if the odbc library was found
- ODBC_BACKEND_INTERNAL - don't build a separate odbc loadable module but rather build it into the cppdb library itself.
Additionally there is a LIBDIR option that allows to provide an install prefix for libraries on RH systems like:
`
cmake -DCMAKE_INSTALL_PREFIX=/usr -DLIBDIR=lib64
`
By default CMake would try to find the libraries and header files and would disable backends that do not have appropriate onces.  

If CMake fails to find the library or header you may provide the path explicitly using XXX_LIB and XXX_PATH variables were XXX is one of ODBC, SQLITE, PQ or MYSQL.  

By default Release with debug info version is build (unless you are using MSVC which by default builds debug version)  

Note:
MSVC Projects are not supported use "NMake Makefiles" generator to build CppDB with MSVC. 
Build Process 
Download latest version of CppDB or fetch one from github:    
```
$ git clone https://github.com/springwind2006/CppDB.git
```
Go to the created directory and make build directory and go to it.     
```
$ cd CppDB   
$ mkdir build   
$ cd build   
```

Run cmake with all options you need and then make, make install    
```
$ cmake -DCMAKE_INSTALL_PREFIX=/usr ..   
$ make   
$ make install  
```
