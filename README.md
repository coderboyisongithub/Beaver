
<img width="128" height="128" alt="Beavericon_transparent" src="https://github.com/user-attachments/assets/6a9a698e-9bd8-4694-acdf-0681b2c53900" />


# Beaver
Automatic Differentiation system. (brewed🍵✅,ready to serve)

This is a C++ framework to compute derivatives automatically of a given expression, it is a core mechanics in every deep learning framework, where it use AD to implement gradient based optimization to train neural networks. AD is almost 50% of what you need to build neural networks.
## Overview
There are various occasion where a machine needs to find derivative of a given function, majority of such occasion is asssociated with computers solving optimization problem using gradient based methods, like training neural networks.  Optimization is in nearly everything. In order to perform such optimization, it generally require human supervision in defining the derivatives of provided cost function. But it becomes very tedious task to perform and not very practical to program each and every derivative for a given linear or non-linear system. Alternative to such solution is to make machine search for derivative. One approach is to use symbolic differentiation, but its painfully slow for certain application like deep learning.

<table>
  <tr>
    <th>Language</th>
    <th>Symbolic Differentiation (MATLAB)</th>
    <th>Automatic Differentiation (Beaver C++)</th>
  </tr>
  <tr>
    <td>Program</td>
    <td>
      <pre><code>clear; clc
tic;
syms x1 x2
f = log(x1) + x1*x2 - sin(x2);
df_dx1 = diff(f, x1);  % ∂f/∂x1
df_dx2 = diff(f, x2);  % ∂f/∂x2

elapsed_time = toc;
elapsed_time_us = elapsed_time * 1e6;
fprintf('Elapsed time: %f microseconds\n', elapsed_time_us);
</code></pre>
    </td>
    <td>
      <pre><code>std::chrono::high_resolution_clock clock;
std::chrono::time_point start = timeIt(clock);
// Example: obtain partial derivative for log(x1)+x1*x2-sin(x2);
variable x1(2.00), x2(5.0), x3(3.50f), x4(3.213);
variable expression = log(x1) + x1 * x2 - sin(x2);
variable dx1 = expression.differentiate(x1);
variable dx2 = expression.differentiate(x2);

std::chrono::time_point stop = timeIt(clock);
std::cout << "Runtime (microSec): "
          << (std::chrono::duration_cast&lt;std::chrono::microseconds&gt;(stop - start)).count();
</code></pre>
    </td>
  </tr>
  <tr>
    <td>Runtime</td>
    <td>
		19,271microseconds
    </td>
    <td>
      30 microseconds
    </td>
  </tr>

</table>




For example, Matlab takes 10,000-20,000 microseconds compute partial derivative for $f(x1,x2) = logx1 +x1x2 −sinx2$ using symbolic differentiation, where as its takes 19-25 microsecond for automatic differentiation to compute the partial derivatives for the same, its 1000 times faster atleast. Although, AD have limitation but it is much better solution in certain situation, over symbolic differentiation. Beaver is one of many C++ framework that is capable of searching derivative of given expression on fly automatically.

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
This example will be compiled when the build is complete and program will compute the derivative and print the result. It does so using two data types provided, "dual" and "variable". You can compute derivative using both, both provides method to describe expression but both have its own use.

## Computing gradient using dual.

```C++
   // Example: derivative of sin(x)+cos(x)
    dual x1(0.3f), x2(10.0f);
    dual res =sin(x1) + cos(x1);
    std::cout<<"at x=0.3" << "value:" << res.value << " partial:" << res.partial;
 ```
Dual can provide gradient of the expression, meaning sum of partial gradient for the provided expression. You cannot compute partial derivative w.r.t each independent variable provided. If you need to compute partial derivative we use variable data type.
## Computing partial derivatives using variable

```C++

  // Example: obtain partial derivative for log(x1)+x1*x2-sin(x2);
	variable x1(2.00), x2(5.0), x3(3.50f), x4(3.213);

	variable expression = log(x1)+x1*x2-sin(x2);
	variable dx1 = expression.differentiate(x1);
	variable dx2 = expression.differentiate(x2);
	variable gradient = dx1 + dx2;

// We verify our result by evaluating: sum of partial shall be equal to gradient of expression evaluated here. It should be equal.
std::cout << "sum of partial:" << gradient.value() << "actual gradient" << expression.partial(); 


```
Expression defined using "variable" will form a computational graph during runtime, and use that graph to search the derivative. 

## Capabilities
- ✅Can define an mathmetical expression using Dual or Variable.
- ✅Can compute partial derivative of expression using Variable
- ✅Can compute gradient(sum of all partial) using Dual or Variable.

## limitation

- ❌ Currently, it cannot compute derivative for updated inputs. Once the expression is defined at particular value for input variables it will stay that way. I am working on fixing this as next update on this.
- ❌ Currently you can work with few infinite series sum functions:exp,log,sin and cos.
  


# License
MIT License

Copyright (c) 2025 Shivanshu 

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
