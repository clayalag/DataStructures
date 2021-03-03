# modeStack ADT

Una cliente de tu compañía necesita una implementación del ADT stack para guardar enteros no negativos de cierto rango.  Además de las operaciones comúnes del stack, esa implementación debe tener una función `int mode() const` que devuelva la **moda** del stack. La moda es el número que más veces se repite en el stack . Si está vacío o hay más de un número que sea el más repetido la función la moda es -1.  Las especificaciones  son:

* que la función `mode`  tenga complejidad **O(1)** en tiempo y que su complejidad en tiempo tampoco dependa del rango de valores del stack.
* que las funciones `push`, `top`, `empty` sigan siendo **O(1)**
* está dispuesta a que el tiempo de la función  `pop()`  dependa del rango de valores guardados, e.g. si el rango es de 0 a 10, tardará menos que para 0 a 1,000,000. Sin embargo, la complejidad de tiempo con respecto a la **cantidad de elementos en el stack** debe ser **O(1)**.
* que proveas un `main.cpp` con pruebas (usando `CHECK()`) que demuestren que las funciones operan correctamente. 
* tienes libertad de implementarla usando lista enlazada o arreglo dinámico. 
* Puedes añadir data members a la implementación base que se te provee.
* no tienes que implementar ni *assignment operator* ni el *copy constructor*. (pero **tienes** que implementar *destructor*)

Ejemplo:

* Si declaramos un objeto `s`  mediante `modeStack s(20);` , entonces si inmediatamente haces `s.mode()`  debe devolver -1.
* Si hacemos `s.push(5)`, entonces `s.mode()` debe devolver `5`.
* Si haces `s.push(8)`, entonces ahora `s.mode()` debe devolver `-1`.
* Si. haces otro `s.push(5)`, entonces ahora `s.mode()` debe devolver `5`.
* Si, ahora haces `s.pop()` , entonces  `s.mode()` debe devolver `-1`.