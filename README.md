# Beaver
Automatic Differentiation system. (still brewing...🍵)

## Build instruction.
### windows (x64) 🪟

- `git clone https://github.com/coderboyisongithub/Beaver.git`
- ` cd Beaver`
- ` mkdir build; cd build`
- ` cmake .. -DCMAKE_BUILD_TYPE=Release` will have optimization or `cmake .. -DCMAKE_BUILD_TYPE=Debug `

### Linux (x64/clang compiler only) 💽


Getting your system ready first.
```bash
sudo apt install cmake zip wget curl ninja-build build-essential pkg-config autoconf
```
```bash
sudo apt install clang libc++-dev libc++abi-dev
```
Then

- `git clone https://github.com/coderboyisongithub/Beaver.git`
- ` cd Beaver`
- ` mkdir build; cd build`
- `export CC=clang `
- `export CXX=clang++`
- ` cmake .. -DCMAKE_BUILD_TYPE=Release` will have optimization or `cmake .. -DCMAKE_BUILD_TYPE=Debug `


## Example
This example will be compiled when the build is complete and program will compute the derivative and print the result.
```C++

int main()
{
    
    // Example: derivative of sin(x)+cos(x)
    dual x1(0.3f), x2(10.0f);
    dual res =sin(x1) + cos(x1);
    std::cout<<"at x=0.3" << "value:" << res.value << " partial:" << res.partial;
    

    return 0;
}

```

