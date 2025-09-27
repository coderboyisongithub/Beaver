

# Beaver
Automatic Differentiation system. (brewed🍵✅,ready to serve)

Beaver is a library that is capable of computing derivative of given expression on fly automatically. 
## Build instruction.
### windows (x64) 🪟
<details>
    
- `git clone https://github.com/coderboyisongithub/Beaver.git`
- ` cd Beaver`
- ` mkdir build; cd build`
- ` cmake .. -DCMAKE_BUILD_TYPE=Release` will have optimization or `cmake .. -DCMAKE_BUILD_TYPE=Debug `
    
</details>

### Linux (x64/clang compiler only) 💽

<details>
    
Getting your system ready first.
```bash
sudo apt install cmake zip wget curl ninja-build build-essential pkg-config autoconf
```
```bash
sudo apt install clang libc++-dev libc++abi-dev
```
Then

- `git clone https://github.com/coderboyisongithub/Beaver.git`
```
cd Beaver
mkdir build; cd build
export CC=clang 
export CXX=clang++
cmake .. -G "Ninja" -DCMAKE_BUILD_TYPE=Release
```

Or for debugging mode `cmake .. -DCMAKE_BUILD_TYPE=Debug`


</details>

## Example
This example will be compiled when the build is complete and program will compute the derivative and print the result.
```C++

int main()
{
    
   // Example: derivative of sin(x)+cos(x)
    dual x1(0.3f), x2(10.0f);
    dual res =sin(x1) + cos(x1);
    std::cout<<"at x=0.3" << "value:" << res.value << " partial:" << res.partial;
    

  // Example: obtain partial derivative for log(x1)+x1*x2-sin(x2);
	variable x1(2.00), x2(5.0), x3(3.50f), x4(3.213);

	variable expression = log(x1)+x1*x2-sin(x2);

	variable dx1 = expression.differentiate(x1);
	variable dx2 = expression.differentiate(x2);

	variable gradient = dx1 + dx2;


// We verify our result by evaluating: sum of partial shall be equal to gradient of expression evaluated here. It should be equal.
std::cout << "sum of partial:" << gradient.value() << "actual gradient" << expression.partial(); 



    return 0;
}

```

