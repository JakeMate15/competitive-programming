menu :- 
    repeat,
    write('Elija una opción:'), nl,
    write('1. Opción 1'), nl,
    write('2. Opción 2'), nl,
    write('3. Salir'), nl,
    read(Opcion),
    (Opcion = 1 -> opcion1;
     Opcion = 2 -> opcion2;
     Opcion = 3 -> salir;
     write('Opción no válida, por favor intente de nuevo.'), nl),
    Opcion = 3.

opcion1 :-
    write('Ha elegido la opción 1.'), nl.

opcion2 :-
    write('Ha elegido la opción 2.'), nl.

salir :-
    write('Saliendo del programa. Adiós.'), nl.

