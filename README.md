## Build in release mode

```
    #> mkdir _build ..
    #> cd _build
    #> cmake -DCMAKE_C_COMPILER=gcc \ 
        -DCMAKE_CXX_COMPILER=g++ \
        -DCMAKE_BUILD_TYPE=Release \ ..
    #> make
    #> ls
```
    

## Build in debug mode

```
    #> mkdir _build ..
    #> cd _build
    #> cmake -DCMAKE_C_COMPILER=gcc \ 
        -DCMAKE_CXX_COMPILER=g++ \
        -DCMAKE_BUILD_TYPE=Debug \  ..
    #> make
    #> ls
```
