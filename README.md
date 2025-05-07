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

```C++

//suppose or function is f(x)=x*x+x and we need to find derivative at x=2   
float x1=2;
dual x(x1);
dual y = x*x + x;
std::cout << " y'(2)=:" << y.partial;
```

