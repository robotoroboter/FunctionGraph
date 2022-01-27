# FunctionGraph
A command-line program that draws the graph of a function chosen by the user, either from the generic ones or from the user's custom formula. After choosing the function, it shows its graph, drawn on a cartesian coordinate plane. The user is able to change the zoom which affects the drawing precision, also there is an option to change the plane dimensions. It uses the math library which contains useful functions.<br>
When the user wants to draw a custom function, the program uses the Parser object, which is responsible for parsing the string expression into mathematical computations. It provides the recognition of the following operations: addition, subtraction, multiplication, division, exponentiation. It also supports negative numbers and brackets. It follows the mathematical order of operations.<br>
When receiving a function formula as an input, the Parser firstly removes all the space symbols from the string. Then, it uses the recursive function Compute, which searches the string for the operator symbol (following the operator precedence), and when founds it, it splits the string into two substrings which are given as arguments to the Compute function, in order to get their values, and finally the mathematical operation is performed on them. The Compute function works like a binary-tree. It also treats bracketed parts of the formula as single numbers.

#### Technologies used:
C++
## Compiling & running
Compiled using Visual Studio 2019, all the necessary project files are in the repository<br>
Pre-compiled executable available: "function graph.exe"
#### Controls:
Zooming the graph: Up arrow, Down arrow

## Screenshots
### The menu
![pic](https://i.imgur.com/xDE6MDJ.png)
### Generic functions
![pic](https://i.imgur.com/NmHOu9D.png)
![pic](https://i.imgur.com/3n1h5xb.png)
![pic](https://i.imgur.com/1sQMdfV.png)
![pic](https://i.imgur.com/Ek807fW.png)
### Custom functions
![pic](https://i.imgur.com/q6erCe9.png)
![pic](https://i.imgur.com/4qfZtjb.png)
![pic](https://i.imgur.com/JPGj3Ny.png)
