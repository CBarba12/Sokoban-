#include "Sokoban.h"

void Sokoban::guardarPartida(vector<char> m, string nombre_ARCHIVO, int des)
{

    ofstream archivo(nombre_ARCHIVO);
    stringstream s;

    s << des << endl;
    for (int i = 0; i < m.size(); i++)
    {
        s << m[i];
    }

    archivo << s.str();
    archivo.close();

}

void Sokoban::nuevoJuego(int nivel)
{

    string descripcion = "";
    string nombre_archivo = "";
    vector<char> capturar;
    /*   string nombre_archivo;*/
    string nombre_archivo_2;
    string nombre_archivo_3;
    int contador = 1;

    switch (nivel) {
    case 1:
        nombre_archivo = "datos.txt";
        descripcion = "NIVEL 1";
        break;
    case 2:
        nombre_archivo = "Nivel_2.txt";
        descripcion = "NIVEL 2";
        break;
    case 3:
        nombre_archivo = "Nivel_3.txt";
        descripcion = "NIVEL 3";
        break;
    case 4:
        nombre_archivo = "Nivel_4.txt";
        descripcion = "NIVEL 4";
        break;

    default:
        break;
    }

    cout << descripcion << endl;
    utiles util(nombre_archivo);
    Grid grid(util.obtener_Columna(), util.obtener_fila(), nombre_archivo);
    Nodo* nodoInicial = grid.obtenerNodo(grid.pos_jugador().first, grid.pos_jugador().second);
    Jugador jugador('@', nodoInicial, &grid);

    char tecla;
    int opcion;
    bool jugando = true;

    while (jugando) {
        system("cls");
       cout << "  VER LOS COMANDOS DEL JUEGO PRESIONE : q " <<endl<< endl;
        grid.imprimirGrid();
        cout << endl;
        cout << "mueva al jugador  ";  tecla = _getch();


        system("cls");

        if (tecla == 'd'|| tecla == 'D') {
            jugador.moverDerecha();
        }
        else if (tecla == 'a'|| tecla == 'A') {
            jugador.moverIzquierda();
        }
        else if (tecla == 'w' || tecla == 'W') {
            jugador.moverArriba();
        }
        else if (tecla == 's' || tecla == 'S') {
            jugador.moverAbajo();
        }
        else if (tecla == 'g' || tecla == 'G') {
            guardarPartida(capturar, "comandos.txt", nivel);
            jugando = false;
        }
        else if (tecla == 'r' || tecla == 'R') {
            jugando = false;
        }
        else if (tecla == 'q' || tecla == 'Q') {
            system("cls");
            cout << "| mover a la derecha : d" << endl;
            cout << "| mover a la izquierda : a" << endl;
            cout << "| mover a la arriba : w" << endl;
            cout << "| mover a la abajo : s" << endl;
            cout << "| guardar partida : g" << endl;
            cout << "| salir de la partida : r" << endl<<endl;
            system("pause");

        }
        else if (tecla == 't' || tecla == 'T') {
            cout << "¡Gracias por jugar! Hasta luego." << endl;
            jugando = false;
        }
        else {
            cout << "ERROR MARQUE UNA TECLA VALIDA!!" << endl;
           
            system("pause");
        }

        capturar.push_back(tecla);

        if (grid.getStack().empty()) {

            utiles util(nombre_archivo);
            Grid grid(util.obtener_Columna(), util.obtener_fila(), nombre_archivo);
            Nodo* nodoInicial = grid.obtenerNodo(grid.pos_jugador().first, grid.pos_jugador().second);
            Jugador jugador('@', nodoInicial, &grid);


            cout << "FELICIDADES GANASTE!!!!!" << endl;
            cout << "1. Continuar al siguiente nivel" << endl;
            cout << "2. Repetición del juego anterior" << endl;
            cin >> opcion;

            if (opcion == 1) {
                if (nivel < 4) {
                    nuevoJuego(nivel + 1);  // Avanza al siguiente nivel si no estás en el nivel 3
                }
                else {
                    cout << "Has completado todos los niveles. ¡Felicidades!" << endl;
                    system("pause");
                }
                jugando = false;
            }

            if (opcion == 2) {

                cout << "Mostrando repetición del juego anterior" << endl;
                reproducion repr(capturar, &jugador, &grid);
                repr.menu();
                cout << "HAZ GANADO!!!" << endl;
                system("pause");
                jugando = false;
            }

        }
    }



}

void Sokoban::cargarPartidaGuardada()
{
    ifstream lectura("comandos.txt");
    string nombre;
    string nivel;
    int contador = 0;
    vector<char>lista_pasos;

    if (lectura.is_open()) {
        while (lectura.good())
        {
            contador++;
            if (contador == 1) {
                getline(lectura, nivel, '\n');
            }
            else
            {
                getline(lectura, nombre, delimitacampo);
                for (int i = 0; i < nombre.length(); i++) {
                    lista_pasos.push_back(nombre[i]);
                }

            }

        }

        if (nivel != "" && !lista_pasos.empty()) {

            string descripcion = "";
            string nombre_archivo = "";
            vector<char> capturar;
            /*   string nombre_archivo;*/
            string nombre_archivo_2;
            string nombre_archivo_3;
            int contador = 1;

            switch (stoi(nivel)) {
            case 1:
                nombre_archivo = "C:\\Users\\alexb\\Videos\\vidual estudio\\proyecto estructura\\proyecto estuctura\\datos.txt";
                descripcion = "NIVEL 1";
                break;
            case 2:
                nombre_archivo = "C:\\Users\\alexb\\Videos\\vidual estudio\\proyecto estructura\\proyecto estuctura\\Nivel_2.txt";
                descripcion = "NIVEL 2";
                break;
            case 3:
                nombre_archivo = "C:\\Users\\alexb\\Videos\\vidual estudio\\proyecto estructura\\proyecto estuctura\\Nivel_3.txt";
                descripcion = "NIVEL 3";
                break;
            case 4:
                nombre_archivo = "Nivel_4.txt";
                descripcion = "NIVEL 4";
                break;
            default:
                break;
            }

            cout << descripcion << endl;
            utiles util(nombre_archivo);
            Grid grid(util.obtener_Columna(), util.obtener_fila(), nombre_archivo);
            Nodo* nodoInicial = grid.obtenerNodo(grid.pos_jugador().first, grid.pos_jugador().second);
            Jugador jugador('@', nodoInicial, &grid);

            char tecla;
            int opcion;
            bool jugando = true;
            int contador_2 = 0;
            int totalcaracter = lista_pasos.size();

            while (jugando) {
                grid.imprimirGrid();

                if (contador_2 < totalcaracter) {
                    tecla = lista_pasos.at(contador_2);
                    system("cls");
                }
                else
                {
                    tecla = _getch();
                    system("cls");
                }
                contador_2++;

                system("cls");

                if (tecla == 'd' || tecla == 'D') {
                    jugador.moverDerecha();
                }
                else if (tecla == 'a' || tecla == 'A') {
                    jugador.moverIzquierda();
                }
                else if (tecla == 'w' || tecla == 'W') {
                    jugador.moverArriba();
                }
                else if (tecla == 's' || tecla == 'S') {
                    jugador.moverAbajo();
                }
                else if (tecla == 'g' || tecla == 'G') {
                    guardarPartida(capturar, "comandos.txt", stoi(nivel));
                    jugando = false;
                }
                else if (tecla == 'r' || tecla == 'R') {
                    jugando = false;
                }
                else if (tecla == 'q' || tecla == 'Q') {
                    system("cls");
                    cout << "| mover a la derecha : d" << endl;
                    cout << "| mover a la izquierda : a" << endl;
                    cout << "| mover a la arriba : w" << endl;
                    cout << "| mover a la abajo : s" << endl;
                    cout << "| guardar partida : g" << endl;
                    cout << "| salir de la partida : r" << endl << endl;
                    system("pause");

                }
                else if (tecla == 't' || tecla == 'T') {
                    cout << "¡Gracias por jugar! Hasta luego." << endl;
                    jugando = false;
                }
                else {
                    cout << "ERROR MARQUE UNA TECLA VALIDA!!" << endl;

                    system("pause");
                }

                capturar.push_back(tecla);

                if (grid.getStack().empty()) {

                    utiles util(nombre_archivo);
                    Grid grid(util.obtener_Columna(), util.obtener_fila(), nombre_archivo);
                    Nodo* nodoInicial = grid.obtenerNodo(grid.pos_jugador().first, grid.pos_jugador().second);
                    Jugador jugador('@', nodoInicial, &grid);


                    cout << "FELICIDADES GANASTE!!!!!" << endl;
                    cout << "1. Continuar al siguiente nivel" << endl;
                    cout << "2. Repetición del juego anterior" << endl;
                    /*      cout << "3. Desea guardar el juego" << endl;*/
                    cin >> opcion;

                    if (opcion == 1) {
                        if (stoi(nivel) < 4) {
                            nuevoJuego(stoi(nivel) + 1);  // Avanza al siguiente nivel si no estás en el nivel 3
                        }
                        else {
                            cout << "Has completado todos los niveles. ¡Felicidades!" << endl;
                            system("pause");
                        }
                        jugando = false;
                    }

                    if (opcion == 2) {

                        cout << "Mostrando repetición del juego anterior" << endl;
                        reproducion repr(capturar, &jugador, &grid);
                        repr.menu();
                        cout << "HAZ GANADO!!!" << endl;
                        system("pause");
                        jugando = false;
                    }
                }
            }


        }
    }
    else { cout << endl << "NO EXISTEN JUEGOS GUARDADOS " << endl;  system("pause"); }

}