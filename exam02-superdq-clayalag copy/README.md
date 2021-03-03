# superDeque

Se te provee la declaración de la clase `superDeque`. Implementa la clase `superDeque` que funciona como double ended queue pero que además de permitir inserción/remoción al frente/cola en O(1) permite inserción y remoción en cualquier otra posición de la fila. La inserción/remoción en sitios que no sean el frente o cola pueden ser O(N). La implementación debe ser usando arreglo circular (dinámico).

Ejemplo: Sea `D` un superDeque originalmente vacío

* Luego de `D.push_front(10)`, `D.push_back(20)`, `D.push_front(30)`, el deque luce así:

    `(front) 30, 10, 20 (back)`

* Luego de `D.pop_front()`, luce así:

  `10, 20`

* Luego de `D.push_back(40)`, `D.push_front(50)`, así:

  `50, 10, 20, 40`
  
* Luego de `D.insert(1, 60)`, luce así:

  `50, 60, 10, 20, 40`
  
* Luego de `D.remove(3)`, luce así
    
    `50, 60, 10, 40`  